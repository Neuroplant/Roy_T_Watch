/**
 * Simple clock display interface, power consumption is about 20mA
 * Written by lewishe
 * */
#include "config.h"
#include "background.h"
#include "LCDFace.h"

#define LV_COLOR_LCD_BG_BL_ON LV_COLOR_MAKE(0xA8, 0xC6, 0x4E)
#define LV_COLOR_LCD_BG_BL_OFF LV_COLOR_MAKE(0x3C, 0x41, 0x2C)
#define LV_COLOR_LCD_SEG_ON LV_COLOR_MAKE(0xF0, 0xFA, 0xF0)
#define LV_COLOR_LCD_SEG_OFF LV_COLOR_MAKE(0xFF, 0xFF, 0xFF) //Better use OPA_1
#define LV_COLOR_LCD_SEG_SHAD LV_COLOR_MAKE(0xFF, 0xFF, 0xFF) //Better use OPA_5
#define LV_COLOR_PHOSPHOR LV_COLOR_MAKE(0x88, 0xFF, 0x88) 
int Angel_S, Angel_M, Angel_H;
typedef struct {
    lv_obj_t *hour;
    lv_obj_t *minute;
    lv_obj_t *second;
    lv_obj_t *day;
    lv_obj_t *month;
    lv_obj_t *year;
} str_datetime_t;


static str_datetime_t g_data, g_data_shadow;

int Sleeptimer_End, Sleeptimer_Now;

TTGOClass *watch = nullptr;
PCF8563_Class *rtc;
AXP20X_Class *power;
BMA *sensor;

void setup()
{
    Serial.begin(115288);
    watch = TTGOClass::getWatch();
    watch->begin();
    watch->lvgl_begin();
    rtc = watch->rtc;

    // Use compile time
    rtc->check();

    // Turn on the backlight
    watch->openBL();

    //Lower the brightness
    watch->bl->adjust(150);

    //Receive objects for easy writing
    power = watch->power;
    sensor = watch->bma;

    // Accel parameter structure
    Acfg cfg;
    cfg.odr = BMA4_OUTPUT_DATA_RATE_100HZ;
    cfg.range = BMA4_ACCEL_RANGE_2G;
    cfg.bandwidth = BMA4_ACCEL_NORMAL_AVG4;
    cfg.perf_mode = BMA4_CONTINUOUS_MODE;
    sensor->accelConfig(cfg);
    sensor->enableAccel();
    // Enable BMA423 isTilt feature
    sensor->enableFeature(BMA423_TILT, true);
    // Enable BMA423 isDoubleClick feature
    sensor->enableFeature(BMA423_WAKEUP, true);
    // Turn off feature interrupt
    // sensor->enableStepCountInterrupt();
    sensor->enableTiltInterrupt();
    // It corresponds to isDoubleClick interrupt
    sensor->enableWakeupInterrupt();


    lv_obj_t *img1 = lv_img_create(lv_scr_act(), NULL);

//Background
    LV_IMG_DECLARE(Logo_lvgl);
    lv_img_set_src(img1, &Logo_lvgl);
    lv_obj_align(img1, NULL, LV_ALIGN_CENTER, 0, 0);
    static lv_style_t bg_style;
    lv_style_set_bg_color(&bg_style, LV_STATE_DEFAULT, LV_COLOR_LCD_BG_BL_ON);
    lv_style_set_bg_opa(&bg_style,LV_STATE_DEFAULT,LV_OPA_50);
    lv_obj_add_style(img1,LV_STATE_DEFAULT ,&bg_style);
    lv_obj_move_background(img1);

// LCDFace
 //   LV_FONT_DECLARE(digital_7_64p);
    LV_FONT_DECLARE(Matrix_Dot_64p);
    static lv_style_t style, style_shadow;
    lv_style_init(&style);
    lv_style_init(&style_shadow);

    lv_style_set_text_color(&style, LV_STATE_DEFAULT, LV_COLOR_LIME);  
    lv_style_set_text_color(&style_shadow, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_style_set_text_font(&style, LV_STATE_DEFAULT, &Matrix_Dot_64p);
    lv_style_set_text_font(&style_shadow, LV_STATE_DEFAULT, &Matrix_Dot_64p);

    lv_style_set_text_opa(&style,LV_STATE_DEFAULT,LV_OPA_COVER);
    lv_style_set_text_opa(&style_shadow,LV_STATE_DEFAULT,LV_OPA_50);

    g_data_shadow.hour = lv_label_create(img1, nullptr);
    g_data.hour = lv_label_create(img1, nullptr);
    
    lv_obj_add_style(g_data_shadow.hour, LV_OBJ_PART_MAIN, &style_shadow);
    lv_obj_add_style(g_data.hour, LV_OBJ_PART_MAIN, &style);

    lv_label_set_text(g_data_shadow.hour, "88");
    lv_label_set_text(g_data.hour, lv_label_get_text(g_data_shadow.hour));

    lv_obj_align(g_data_shadow.hour, img1, LV_ALIGN_IN_TOP_LEFT, 14, 24);
    lv_obj_align(g_data.hour, img1, LV_ALIGN_IN_TOP_LEFT, 10, 20);

    g_data_shadow.minute = lv_label_create(img1, nullptr);
    g_data.minute = lv_label_create(img1, nullptr);

    lv_obj_add_style(g_data_shadow.minute, LV_OBJ_PART_MAIN, &style_shadow);
    lv_obj_add_style(g_data.minute, LV_OBJ_PART_MAIN, &style);

    lv_label_set_text(g_data_shadow.minute, ":88");
    lv_label_set_text(g_data.minute, lv_label_get_text(g_data_shadow.minute));
    
    lv_obj_align(g_data_shadow.minute, img1, LV_ALIGN_IN_TOP_LEFT, 79, 24);
    lv_obj_align(g_data.minute, img1, LV_ALIGN_IN_TOP_LEFT, 75, 20);

    g_data_shadow.second = lv_label_create(img1, nullptr);
    g_data.second = lv_label_create(img1, nullptr);
    
    lv_obj_add_style(g_data_shadow.second, LV_OBJ_PART_MAIN, &style_shadow);
    lv_obj_add_style(g_data.second, LV_OBJ_PART_MAIN, &style);

    lv_label_set_text(g_data_shadow.second, ":88");
    lv_label_set_text(g_data.second, lv_label_get_text(g_data_shadow.second));

    lv_obj_align(g_data_shadow.second, img1, LV_ALIGN_IN_TOP_LEFT, 144, 24);
    lv_obj_align(g_data.second, img1, LV_ALIGN_IN_TOP_LEFT, 140, 20);
  
    g_data.day = lv_label_create(img1, nullptr);
    lv_obj_add_style(g_data.day, LV_OBJ_PART_MAIN, &style);
   lv_label_set_text(g_data.day, "88");
    lv_obj_align(g_data.day, img1, LV_ALIGN_IN_LEFT_MID, 1, 20);

    g_data.month = lv_label_create(img1, nullptr);
    lv_obj_add_style(g_data.month, LV_OBJ_PART_MAIN, &style);
    lv_label_set_text(g_data.month, ".88");
    lv_obj_align(g_data.month, img1, LV_ALIGN_IN_LEFT_MID, 62, 20);

    g_data.year = lv_label_create(img1, nullptr);
    lv_obj_add_style(g_data.year, LV_OBJ_PART_MAIN, &style);
    lv_label_set_text(g_data.year, ".8888");
    lv_obj_align(g_data.year, img1, LV_ALIGN_IN_LEFT_MID, 125, 20);    

// Watchface

    static lv_obj_t *Second_Hand_s = lv_img_create(img1, NULL);
    static lv_obj_t *Minute_Hand_s = lv_img_create(img1, NULL);
    static lv_obj_t *Hour_Hand_s = lv_img_create(img1, NULL);
    
    static lv_obj_t *Hour_Hand = lv_img_create(img1, NULL);
    static lv_obj_t *Minute_Hand = lv_img_create(img1, NULL);
    static lv_obj_t *Second_Hand = lv_img_create(img1, NULL);



// Dial to do..maybe

// HourHand
    LV_IMG_DECLARE(Hour_Hand_C);
    lv_img_set_src(Hour_Hand, &Hour_Hand_C);
    lv_img_set_antialias(Hour_Hand,true);
    lv_img_set_pivot(Hour_Hand,20,5);
    lv_obj_align(Hour_Hand, img1, LV_ALIGN_IN_TOP_LEFT, 100, 120);
    lv_img_set_angle(Hour_Hand,0);
// MinuteHand
    LV_IMG_DECLARE(Minute_Hand_C);
    lv_img_set_src(Minute_Hand, &Minute_Hand_C);
    lv_img_set_antialias(Minute_Hand,true);
    lv_img_set_pivot(Minute_Hand,20,5);
    lv_img_set_antialias(Minute_Hand,true);
    lv_obj_align(Minute_Hand, img1,  LV_ALIGN_IN_TOP_LEFT, 100, 120);
    lv_img_set_angle(Minute_Hand,900);
// SecondHand
    LV_IMG_DECLARE(Second_Hand_C);
    lv_img_set_src(Second_Hand, &Second_Hand_C);
    lv_img_set_antialias(Second_Hand,true);
    lv_img_set_pivot(Second_Hand,20,5);
    lv_obj_align(Second_Hand, img1,  LV_ALIGN_IN_TOP_LEFT, 100, 120);
    lv_img_set_angle(Second_Hand,0);

   
///HandShadow
// HourHand
    LV_IMG_DECLARE(Hour_Hand_S);
    lv_img_set_src(Hour_Hand_s, &Hour_Hand_S);
    lv_img_set_antialias(Hour_Hand_s,true);
    lv_img_set_pivot(Hour_Hand_s,20,6);
    lv_obj_align(Hour_Hand_s, img1, LV_ALIGN_IN_TOP_LEFT, 105, 125);
    lv_img_set_angle(Hour_Hand_s,0);
// MinuteHand
    LV_IMG_DECLARE(Minute_Hand_S);
    lv_img_set_src(Minute_Hand_s, &Minute_Hand_S);
    lv_img_set_antialias(Minute_Hand_s,true);
    lv_img_set_pivot(Minute_Hand_s,20,6);
    lv_img_set_antialias(Minute_Hand_s,true);
    lv_obj_align(Minute_Hand_s, img1,  LV_ALIGN_IN_TOP_LEFT, 105, 125);
    lv_img_set_angle(Minute_Hand_s,900);
// SecondHand
    LV_IMG_DECLARE(Second_Hand_S);
    lv_img_set_src(Second_Hand_s, &Second_Hand_S);
    lv_img_set_antialias(Second_Hand_s,true);
    lv_img_set_pivot(Second_Hand_s,20,6);
        static lv_style_t hand_style;

        lv_style_set_image_recolor(&hand_style, LV_OBJ_PART_MAIN, LV_COLOR_BLACK);

    lv_obj_align(Second_Hand_s, img1,  LV_ALIGN_IN_TOP_LEFT, 105, 125);
    lv_img_set_angle(Second_Hand_s,0);

    static lv_style_t hand_s_style;

    lv_style_set_image_opa(&hand_s_style, LV_STATE_DEFAULT, LV_OPA_80);
    lv_style_set_image_recolor(&hand_s_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_obj_add_style(Second_Hand_s,LV_OBJ_PART_MAIN ,&hand_s_style);
    lv_obj_add_style(Hour_Hand_s,LV_OBJ_PART_MAIN ,&hand_s_style);
    lv_obj_add_style(Minute_Hand_s,LV_OBJ_PART_MAIN ,&hand_s_style);
//
    lv_task_create([](lv_task_t *t) 
    {
            RTC_Date curr_datetime = rtc->getDateTime();
              
    Angel_S = (int) curr_datetime.second;
    Angel_M = (int) curr_datetime.minute;
    Angel_H = (int) curr_datetime.hour;

    Angel_S = Angel_S * 60;
    Angel_M = Angel_M * 60;
    Angel_H = (Angel_H * 5) *60;

    Angel_S = Angel_S + 2700;
    Angel_M = Angel_M + 2700;
    Angel_H = Angel_H + 2700;

    if (Angel_S >= 3600) Angel_S = Angel_S - 3600;
    if (Angel_M >= 3600) Angel_M = Angel_M - 3600;
    if (Angel_H >= 3600) Angel_H = Angel_H- 3600;

    lv_img_set_angle(Second_Hand,Angel_S);
    lv_img_set_angle(Minute_Hand,Angel_M);
    lv_img_set_angle(Hour_Hand,Angel_H);
    
    //Shadow
    lv_img_set_angle(Second_Hand_s,Angel_S);
    lv_img_set_angle(Minute_Hand_s,Angel_M);
    lv_img_set_angle(Hour_Hand_s,Angel_H);

    lv_label_set_text_fmt(g_data.second, "%02u", curr_datetime.second);
    lv_label_set_text_fmt(g_data.minute, "%02u", curr_datetime.minute);
    lv_label_set_text_fmt(g_data.hour, "%02u", curr_datetime.hour);
    lv_label_set_text_fmt(g_data.day, "%02u", curr_datetime.day);
    lv_label_set_text_fmt(g_data.month, "%02u", curr_datetime.month);
    lv_label_set_text_fmt(g_data.year, "%02u", curr_datetime.year);
    }, 999, LV_TASK_PRIO_MID, nullptr);

    // Set 20MHz operating speed to reduce power consumption
    setCpuFrequencyMhz(20);

    RTC_Date SleepTimer = rtc->getDateTime();
    Sleeptimer_End = (int)20+(SleepTimer.second)+(SleepTimer.minute*60)+(SleepTimer.hour*360);
     
    }

void loop()
{
    lv_task_handler();
    RTC_Date Timer = rtc->getDateTime();
        Sleeptimer_Now = (int)Timer.second+(Timer.minute*60)+(Timer.hour*360);

    if (Sleeptimer_Now>=Sleeptimer_End) 
    {
        watch->powerOff();
        esp_sleep_enable_ext1_wakeup(GPIO_SEL_39, ESP_EXT1_WAKEUP_ANY_HIGH);
        esp_deep_sleep_start();
    }
}
