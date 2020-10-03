// Roy_T_Watch
// main
// 03.10.2020 Neuroplant

#include "config.h"
#include <iostream>
#include <string>

#define LV_COLOR_LCD_BG_BL_ON LV_COLOR_MAKE(0xA8, 0xC6, 0x4E)   //Old Style LCD Simulation Background /Light off
#define LV_COLOR_LCD_BG_BL_OFF LV_COLOR_MAKE(0x3C, 0x41, 0x2C)  //Old Style LCD Simulation Background /Light off
#define LV_COLOR_LCD_SEG_ON LV_COLOR_MAKE(0xF0, 0xFA, 0xF0)     //Old Style LCD Simulation Segment on
#define LV_COLOR_LCD_SEG_OFF LV_COLOR_MAKE(0xFF, 0xFF, 0xFF)    //Old Style LCD Simulation Segment off/Light off/Better use OPA_10
#define LV_COLOR_LCD_SEG_SHAD LV_COLOR_MAKE(0xFF, 0xFF, 0xFF)   //Old Style LCD Simulation Segment Shadow (only if Light on)/Better use OPA_50

#define LV_COLOR_PHOSPHOR LV_COLOR_MAKE(0x88, 0xFF, 0x88) 

TTGOClass *watch = nullptr;
PCF8563_Class *rtc;

#ifdef DIGITAL_1
    typedef struct {
        lv_obj_t *hourmin;
        //lv_obj_t *second;
        lv_obj_t *day;
        lv_obj_t *month;
        lv_obj_t *year;
        lv_obj_t* stat1;
        lv_obj_t* stat2;
        lv_obj_t* stat3;
        lv_obj_t* stat4;
    } str_datetime_t;
    static str_datetime_t DData, DDataS;
#endif //DIGITAL_1

#ifdef ANALOG_1
    int Angle_S, Angle_M, Angle_H;
#endif //ANALOG_1

#ifdef SLEEP_TIMER
    int Sleeptimer_End, Sleeptimer_Now;
    AXP20X_Class *power;
    BMA *sensor;

    int epoch_r(RTC_Date Value)
    {
        int i =
            (Value.second)
            + (Value.minute * 60)
            + (Value.hour * 60 * 60)
            + (Value.day * 60 * 60 * 24)
            + (Value.month * 60 * 60 * 24 * 30)
            + ((Value.year - 1970) * 60 * 60 * 24 * 30 * 12);
        return i;
    }
#endif //SLEEP_TIMER

#ifdef BAT_LVL
    int BatLvl;
#endif //BAT_LVL

void setup()
{
#ifdef SERIAL_OUT
    Serial.begin(SERIAL_OUT);
#endif //SERIAL_OUT
    
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

#ifdef SLEEP_TIMER
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
// Disable BMA423 isStepCounter feature
    sensor->enableFeature(BMA423_STEP_CNTR, false);
// Enable BMA423 isTilt feature
    sensor->enableFeature(BMA423_TILT, true);
// Enable BMA423 isDoubleClick feature
    sensor->enableFeature(BMA423_WAKEUP, true);
// Reset steps
    sensor->resetStepCounter();
// Turn off feature interrupt
// sensor->enableStepCountInterrupt();
    sensor->enableTiltInterrupt();
// It corresponds to isDoubleClick interrupt
    sensor->enableWakeupInterrupt();
#endif //SLEEP_TIMER

    lv_obj_t *img1 = lv_img_create(lv_scr_act(), NULL);
//Background
    LV_IMG_DECLARE(BACKGROUND_PIC);
    lv_img_set_src(img1, &BACKGROUND_PIC);
    lv_obj_align(img1, NULL, LV_ALIGN_CENTER, 0, 0);
    static lv_style_t bg_style;
    lv_style_set_bg_color(&bg_style, LV_STATE_DEFAULT, LV_COLOR_LCD_BG_BL_ON);
    lv_style_set_bg_opa(&bg_style,LV_STATE_DEFAULT,LV_OPA_50);
    lv_obj_add_style(img1,LV_STATE_DEFAULT ,&bg_style);
    lv_obj_move_background(img1);

#ifdef BAT_LVL
	static lv_obj_t *BatBar = lv_bar_create(img1, NULL);
    static lv_style_t BatBar_Style, BatBar_V_Style;
    lv_style_set_bg_opa(&BatBar_Style, LV_STATE_DEFAULT, LV_OPA_50);
    lv_style_set_bg_color(&BatBar_Style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_bg_opa(&BatBar_V_Style, LV_STATE_DEFAULT, LV_OPA_0);
    lv_style_set_bg_color(&BatBar_V_Style, LV_STATE_DEFAULT, LV_COLOR_BLUE);
    lv_obj_add_style(BatBar, LV_BAR_PART_BG, &BatBar_Style);
    lv_obj_add_style(BatBar, LV_BAR_PART_INDIC, &BatBar_V_Style);
    lv_bar_set_range(BatBar, 0, 100);
	lv_bar_set_start_value(BatBar,0,LV_ANIM_ON);
	lv_obj_set_size(BatBar, 220, 10);
    lv_obj_align(BatBar, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 15);
#endif //BAT_LVL

#ifdef DIGITAL_1
    LV_FONT_DECLARE(D14Seg_32p);
    LV_FONT_DECLARE(D14Seg_64p);
    static lv_style_t 
        style_D1, 
        style_D1s, 
        style_D2,
        style_D2s;
    lv_style_init(&style_D1);
    lv_style_init(&style_D1s);
    lv_style_init(&style_D2);
    lv_style_init(&style_D2s);

    lv_style_set_text_color(&style_D1, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_text_color(&style_D1s, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_text_color(&style_D2, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_text_color(&style_D2s, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_style_set_text_font(&style_D1, LV_STATE_DEFAULT, &D14Seg_64p);
    lv_style_set_text_font(&style_D1s, LV_STATE_DEFAULT, &D14Seg_64p);
    lv_style_set_text_font(&style_D2, LV_STATE_DEFAULT, &D14Seg_32p);
    lv_style_set_text_font(&style_D2s, LV_STATE_DEFAULT, &D14Seg_32p);

    lv_style_set_text_opa(&style_D1, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_text_opa(&style_D1s, LV_STATE_DEFAULT, LV_OPA_40);
    lv_style_set_text_opa(&style_D2, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_text_opa(&style_D2s, LV_STATE_DEFAULT, LV_OPA_40);

    DDataS.hourmin = lv_label_create(img1, nullptr);
    //DDataS.second = lv_label_create(img1, nullptr);
    DDataS.day = lv_label_create(img1, nullptr);
    DDataS.month = lv_label_create(img1, nullptr);
    DDataS.year = lv_label_create(img1, nullptr);
    DDataS.stat1 = lv_label_create(img1, nullptr);
    DDataS.stat2 = lv_label_create(img1, nullptr);
    DDataS.stat3 = lv_label_create(img1, nullptr);
    DDataS.stat4 = lv_label_create(img1, nullptr);

    DData.hourmin = lv_label_create(img1, nullptr);
    //DData.second = lv_label_create(img1, nullptr);
    DData.day = lv_label_create(img1, nullptr);
    DData.month = lv_label_create(img1, nullptr);
    DData.year = lv_label_create(img1, nullptr);
    DData.stat1 = lv_label_create(img1, nullptr);
    DData.stat2 = lv_label_create(img1, nullptr);
    DData.stat3 = lv_label_create(img1, nullptr);
    DData.stat4 = lv_label_create(img1, nullptr);

    lv_obj_add_style(DDataS.hourmin, LV_OBJ_PART_MAIN, &style_D1s);
  //  lv_obj_add_style(DDataS.second, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.day, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.month, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.year, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.stat1, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.stat2, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.stat3, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.stat4, LV_OBJ_PART_MAIN, &style_D2s);

    lv_obj_add_style(DData.hourmin, LV_OBJ_PART_MAIN, &style_D1);
 //   lv_obj_add_style(DData.second, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.day, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.month, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.year, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.stat1, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.stat2, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.stat3, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.stat4, LV_OBJ_PART_MAIN, &style_D2);

    lv_label_set_text(DDataS.hourmin, "~~:~~");
    //lv_label_set_text(DDataS.second, "~~");
    lv_label_set_text(DDataS.day, "~~.");
    lv_label_set_text(DDataS.month, "~~.");
    lv_label_set_text(DDataS.year, "~~~~");
    lv_label_set_text(DDataS.stat1, "~.~~A");
    lv_label_set_text(DDataS.stat2, "~.~~V");
    lv_label_set_text(DDataS.stat3, "~.~~h");
    lv_label_set_text(DDataS.stat4, "~.~~s");

    lv_label_set_text(DData.hourmin, "~~:~~");
    //lv_label_set_text(DData.second, "~~");
    lv_label_set_text(DData.day, "~~.");
    lv_label_set_text(DData.month, "~~.");
    lv_label_set_text(DData.year, "~~~~");
    lv_label_set_text(DData.stat1, "~.~~A");
    lv_label_set_text(DData.stat2, "~.~~V");
    lv_label_set_text(DData.stat3, "~.~~h");
    lv_label_set_text(DData.stat4, "~.~~s");

    lv_obj_align(DDataS.hourmin, img1, LV_ALIGN_IN_TOP_LEFT, 9, 14);
   // lv_obj_align(DDataS.second, img1, LV_ALIGN_IN_TOP_LEFT, 204, 14);
    lv_obj_align(DDataS.day, img1, LV_ALIGN_IN_TOP_LEFT, 9, 80);
    lv_obj_align(DDataS.month, img1, LV_ALIGN_IN_TOP_LEFT, 54, 80);
    lv_obj_align(DDataS.year, img1, LV_ALIGN_IN_TOP_LEFT, 104, 78);
    lv_obj_align(DDataS.stat1, img1, LV_ALIGN_IN_TOP_LEFT, 14, 130);
    lv_obj_align(DDataS.stat2, img1, LV_ALIGN_IN_TOP_LEFT, 114, 130);
    lv_obj_align(DDataS.stat3, img1, LV_ALIGN_IN_TOP_LEFT, 14, 167);
    lv_obj_align(DDataS.stat4, img1, LV_ALIGN_IN_TOP_LEFT, 114, 167);

    lv_obj_align(DData.hourmin, img1, LV_ALIGN_IN_TOP_LEFT, 5, 10);
   // lv_obj_align(DData.second, img1, LV_ALIGN_IN_TOP_LEFT, 200, 10);
    lv_obj_align(DData.day, img1, LV_ALIGN_IN_TOP_LEFT, 5, 76);
    lv_obj_align(DData.month, img1, LV_ALIGN_IN_TOP_LEFT, 50, 76);
    lv_obj_align(DData.year, img1, LV_ALIGN_IN_TOP_LEFT, 100, 76);
    lv_obj_align(DData.stat1, img1, LV_ALIGN_IN_TOP_LEFT, 10, 126);
    lv_obj_align(DData.stat2, img1, LV_ALIGN_IN_TOP_LEFT, 110, 126);
    lv_obj_align(DData.stat3, img1, LV_ALIGN_IN_TOP_LEFT, 10, 163);
    lv_obj_align(DData.stat4, img1, LV_ALIGN_IN_TOP_LEFT, 110, 163);


#endif // DIGITAL_1

#ifdef TICKER
    LV_FONT_DECLARE(Segoe_24p);

    static lv_obj_t *Ticker = lv_label_create (img1,NULL);
    static lv_style_t style_small;
    lv_style_set_text_font(&style_small, LV_STATE_DEFAULT, &Segoe_24p);
    lv_style_set_text_color(&style_small,LV_STATE_DEFAULT,LV_COLOR_GRAY);//as long as it is onla stats Grey is enough
    lv_style_set_text_opa(&style_small,LV_STATE_DEFAULT,LV_OPA_COVER);
    lv_style_set_shadow_width(&style_small, LV_STATE_DEFAULT, 8);
    lv_style_set_shadow_opa(&style_small, LV_STATE_DEFAULT, LV_OPA_50);
    lv_style_set_shadow_color(&style_small, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_shadow_ofs_x(&style_small, LV_STATE_DEFAULT, 3);
    lv_style_set_shadow_ofs_y(&style_small, LV_STATE_DEFAULT, 6);

    lv_label_set_long_mode(Ticker,LV_LABEL_LONG_DOT);
    lv_obj_set_width(Ticker, 220);
    lv_obj_add_style(Ticker, LV_OBJ_PART_MAIN, &style_small);
    lv_label_set_text(Ticker, "");
 //   lv_label_set_text(Ticker, "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. \n At vero eos et accusam et justo duo dolores et ea rebum. \n Stet clita kasd gubergren, no sea takimata sanctus est \n Lorem ipsum dolor sit amet. \n Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. \n At vero eos et accusam et justo duo dolores et ea rebum. \n Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.\n");
#ifdef DIGITAL_1
    lv_obj_set_height(Ticker, 55);
    lv_obj_align(Ticker, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 180);
#endif //DIGITAL1
#ifndef DIGITAL_1
    lv_obj_set_height(Ticker, 230);
    lv_obj_align(Ticker, NULL, LV_ALIGN_IN_TOP_LEFT, 15, 5);
#endif //Not DIGITAL_1


#endif // TICKER
	
#ifdef ANALOG_1
// Watchface
    static lv_obj_t *Second_Hand_s = lv_img_create(img1, NULL);
    static lv_obj_t *Minute_Hand_s = lv_img_create(img1, NULL);
    static lv_obj_t *Hour_Hand_s = lv_img_create(img1, NULL);
    
    static lv_obj_t *Hour_Hand = lv_img_create(img1, NULL);
    static lv_obj_t *Minute_Hand = lv_img_create(img1, NULL);
    static lv_obj_t *Second_Hand = lv_img_create(img1, NULL);

// Dial   to do..maybe


///HandShadow
// HourHand 
    LV_IMG_DECLARE(HourHand_S);
    lv_img_set_src(Hour_Hand_s, &HourHand_S);
    lv_img_set_antialias(Hour_Hand_s,true);
    lv_img_set_pivot(Hour_Hand_s,20,8);
    lv_obj_align(Hour_Hand_s, img1, LV_ALIGN_IN_TOP_LEFT, 105, 130);
    lv_img_set_angle(Hour_Hand_s,3300);
// MinuteHand
    LV_IMG_DECLARE(MinuteHand_S);
    lv_img_set_src(Minute_Hand_s, &MinuteHand_S);
    lv_img_set_antialias(Minute_Hand_s,true);
    lv_img_set_pivot(Minute_Hand_s,20,8);
    lv_img_set_antialias(Minute_Hand_s,true);
    lv_obj_align(Minute_Hand_s, img1,  LV_ALIGN_IN_TOP_LEFT, 105, 130);
    lv_img_set_angle(Minute_Hand_s,2100);
// SecondHand
    LV_IMG_DECLARE(SecondHand_S);
    lv_img_set_src(Second_Hand_s, &SecondHand_S);
    lv_img_set_antialias(Second_Hand_s,true);
    lv_img_set_pivot(Second_Hand_s,20,8);
    lv_obj_align(Second_Hand_s, img1,  LV_ALIGN_IN_TOP_LEFT, 105, 130);
    lv_img_set_angle(Second_Hand_s,900);

// Normal Hand

// HourHand
    LV_IMG_DECLARE(HourHand);
    lv_img_set_src(Hour_Hand, &HourHand);
    lv_img_set_antialias(Hour_Hand,true);
    lv_img_set_pivot(Hour_Hand,20,8);
    lv_obj_align(Hour_Hand, img1, LV_ALIGN_IN_TOP_LEFT, 100, 120);
    lv_img_set_angle(Hour_Hand,3300);
// MinuteHand
    LV_IMG_DECLARE(MinuteHand);
    lv_img_set_src(Minute_Hand, &MinuteHand);
    lv_img_set_antialias(Minute_Hand,true);
    lv_img_set_pivot(Minute_Hand,20,8);
    lv_img_set_antialias(Minute_Hand,true);
    lv_obj_align(Minute_Hand, img1,  LV_ALIGN_IN_TOP_LEFT, 100, 120);
    lv_img_set_angle(Minute_Hand,2100);
// SecondHand
    LV_IMG_DECLARE(SecondHand);
    lv_img_set_src(Second_Hand, &SecondHand);
    lv_img_set_antialias(Second_Hand,true);
    lv_img_set_pivot(Second_Hand,20,8);
    lv_obj_align(Second_Hand, img1,  LV_ALIGN_IN_TOP_LEFT, 100, 120);
    lv_img_set_angle(Second_Hand,900);
	
// Shadow Style
  static lv_style_t hand_s_style;
    lv_style_set_image_opa(&hand_s_style, LV_STATE_DEFAULT, LV_OPA_20);
    lv_obj_add_style(Second_Hand_s,LV_OBJ_PART_MAIN ,&hand_s_style);
    lv_obj_add_style(Hour_Hand_s,LV_OBJ_PART_MAIN ,&hand_s_style);
    lv_obj_add_style(Minute_Hand_s,LV_OBJ_PART_MAIN ,&hand_s_style);

// Normal Style
   static lv_style_t hand_style;
    lv_obj_add_style(Second_Hand,LV_OBJ_PART_MAIN ,&hand_style);
    lv_obj_add_style(Hour_Hand,LV_OBJ_PART_MAIN ,&hand_style);
    lv_obj_add_style(Minute_Hand,LV_OBJ_PART_MAIN ,&hand_style);
	
#endif //ANALOG_1

///////////////////////////////////////////////////////
    lv_task_create([](lv_task_t *t) 
    {
    RTC_Date curr_datetime = rtc->getDateTime();
#ifdef ANALOG_1	

    Angle_S = ((int) curr_datetime.second 	*60) 	+ 2700;
    Angle_M = ((int) curr_datetime.minute	*60) 	+ 2700;
    Angle_H = ((int) curr_datetime.hour		*300)	+ ((int) curr_datetime.minute	*5)	+ 2700;

    while (Angle_S >= 3600) Angle_S = Angle_S - 3600;
    while (Angle_M >= 3600) Angle_M = Angle_M - 3600;
    while (Angle_H >= 3600) Angle_H = Angle_H - 3600;

	//Normal
    lv_img_set_angle(Second_Hand,Angle_S);
    lv_img_set_angle(Minute_Hand,Angle_M);
    lv_img_set_angle(Hour_Hand,Angle_H);
    
    //Shadow
    lv_img_set_angle(Second_Hand_s,Angle_S);
    lv_img_set_angle(Minute_Hand_s,Angle_M);
    lv_img_set_angle(Hour_Hand_s,Angle_H);
	
#endif //ANALOG_1
#ifdef DIGITAL_1

    if (((curr_datetime.second / 2) * 2) == (curr_datetime.second))//":" only on even seconds
    {
        lv_label_set_text_fmt(DDataS.hourmin, "%02u:%02u", curr_datetime.hour, curr_datetime.minute);
    }
    else {
        lv_label_set_text_fmt(DDataS.hourmin, "%02u %02u", curr_datetime.hour, curr_datetime.minute);
    };
  //  lv_label_set_text_fmt(DDataS.second, "%02u", curr_datetime.second);
    lv_label_set_text_fmt(DDataS.day, "%02u.%02u.%04u", curr_datetime.day, curr_datetime.month, curr_datetime.month);
    lv_label_set_text(DDataS.month, "");
    lv_label_set_text(DDataS.year, "");
    lv_label_set_text_fmt(DDataS.stat1, "%0.02f A", watch->power->getBattDischargeCurrent());
    lv_label_set_text_fmt(DDataS.stat2, "%02u", watch->power->getBattPercentage());
    lv_label_set_text_fmt(DDataS.stat3, "%0.02f V", watch->power->getBattVoltage());
    lv_label_set_text_fmt(DDataS.stat4, "%02u", curr_datetime.second);

    if (((curr_datetime.second / 2) * 2) == (curr_datetime.second)) //":" only on even seconds
    {
        lv_label_set_text_fmt(DData.hourmin, "%02u:%02u", curr_datetime.hour, curr_datetime.minute);
    }
    else {
        lv_label_set_text_fmt(DData.hourmin, "%02u %02u", curr_datetime.hour, curr_datetime.minute);
    };  //  lv_label_set_text_fmt(DData.second, "%02u", curr_datetime.second);
    lv_label_set_text_fmt(DData.day, "%02u.%02u.%04u", curr_datetime.day,curr_datetime.month,curr_datetime.year);
    lv_label_set_text(DData.month, "" );
    lv_label_set_text(DData.year, "" );
    lv_label_set_text_fmt(DData.stat1, "%.3f A", (float)watch->power->getBattDischargeCurrent());
    lv_label_set_text_fmt(DData.stat2, "%02u", watch->power->getBattPercentage());
    lv_label_set_text_fmt(DData.stat3, "%.3f V",(float)watch->power->getBattVoltage());
    lv_label_set_text_fmt(DData.stat4, "%02u", curr_datetime.second);

#endif //DIGITAL_1  
#ifdef BAT_LVL
    BatLvl = watch->power->getBattPercentage();
    if (BatLvl <= 20)     lv_style_set_bg_color(&BatBar_V_Style, LV_STATE_DEFAULT, LV_COLOR_RED);
	lv_bar_set_value(BatBar,0,(uint16_t)(BatLvl));
#endif //BAT_LVL
#ifdef TICKER
    lv_label_set_text_fmt(Ticker, "\nVBus: %02u mV \nVBus: %02u mA \nBatt: %02u mV \nPer:  %02u %% ", (uint16_t)watch->power->getVbusVoltage(), (uint16_t)watch->power->getVbusCurrent(), (uint16_t)watch->power->getBattVoltage(), (uint16_t)watch->power->getBattPercentage());
#endif //TICKER
#ifdef SERIAL_OUT
  Serial.print("Vbus: "); Serial.print(watch->power->getVbusVoltage()); Serial.println(" mV");
  Serial.print("Vbus: "); Serial.print(watch->power->getVbusCurrent()); Serial.println(" mA");
  Serial.print("BATT: "); Serial.print(watch->power->getBattVoltage()); Serial.println(" mV");
  Serial.print("Per:  "); Serial.print(watch->power->getBattPercentage()); Serial.println(" %");
  Serial.println();
  Serial.print("Time:"); Serial.print(curr_datetime.hour); Serial.print(":");Serial.print(curr_datetime.minute); Serial.print(":");Serial.print(curr_datetime.second); Serial.println();
    Serial.println();
#endif //SERIAL_OUT
////


	}, 1000, LV_TASK_PRIO_MID, nullptr);
/////////////////////////////////////////////////////////////
    // Set 20MHz operating speed to reduce power consumption
    setCpuFrequencyMhz(40);
#ifdef SLEEP_TIMER

    RTC_Date SleepTimer = rtc->getDateTime();
    Sleeptimer_End = epoch_r(rtc->getDateTime()) + 60;
#endif //SLEEP_TIMER
    t = rtc->getDayOfWeek(curr_datetime);
    }


void loop()
{
    lv_task_handler();
	
#ifdef SLEEP_TIMER
	
    Sleeptimer_Now = epoch_r(rtc->getDateTime());

    if (Sleeptimer_Now>=Sleeptimer_End) 
    {
        Sleeptimer_End = Sleeptimer_End +60;
        watch->displaySleep();
        watch->powerOff();
    // LDO2 is used to power the display, and LDO2 can be turned off if needed
    // power->setPowerOutPut(AXP202_LDO2, false);
        esp_sleep_enable_ext1_wakeup(GPIO_SEL_39, ESP_EXT1_WAKEUP_ANY_HIGH);
        esp_deep_sleep_start();
    }
#endif //SLEEP_TIMER
}
