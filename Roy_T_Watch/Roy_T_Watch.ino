// Roy_T_Watch
// Main Programm (Roy_T_Watch.ino)
// 05.10.2020 Neuroplant

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
	#include "Digital1.h"
#endif //DIGITAL_1

#ifdef ANALOG_1
	#include "Analog1.h"
#endif //ANALOG_1

#ifdef SLEEP_TIMER
    int Sleeptimer_End, Sleeptimer_Now;
    AXP20X_Class *power;
    BMA *sensor;

int epoch_r(RTC_Date Value) // not correct epoch, but close enough for my purposes (can not finde PCF8563_Class(RTC) providing epoch
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
	
// Create Screen with two horizontal Tiles
	static lv_point_t valid_pos[] = { {0,0}, {1, 0} }; 
    	static lv_obj_t* tileview;
    	tileview = lv_tileview_create(lv_scr_act(), NULL);
    	lv_tileview_set_valid_positions(tileview, valid_pos, 2);
    	lv_tileview_set_edge_flash(tileview, true);

	lv_obj_t* tile1 = lv_obj_create(tileview, NULL);
    	lv_obj_set_size(tile1, LV_HOR_RES, LV_VER_RES);
    	lv_tileview_add_element(tileview, tile1);

    	lv_obj_t* tile2 = lv_obj_create(tileview, tile1);
    	lv_obj_set_pos(tile2, LV_HOR_RES, 0);
    	lv_tileview_add_element(tileview, tile2);

    lv_obj_t* watchface1 = lv_img_create(tile1, NULL); 		//Create "watchface1" on tile1
    lv_obj_t* watchface2 = lv_img_create(tile2, NULL); 		//Create "watchface2" in tile2
	
 //Background
    LV_IMG_DECLARE(BACKGROUND_PIC);
    lv_img_set_src(watchface1, &BACKGROUND_PIC);
    lv_obj_align(watchface1, NULL, LV_ALIGN_CENTER, 0, 0);
    static lv_style_t bg_style;
    lv_style_set_bg_color(&bg_style, LV_STATE_DEFAULT, LV_COLOR_LCD_BG_BL_ON);
    lv_style_set_bg_opa(&bg_style, LV_STATE_DEFAULT, LV_OPA_50);
    lv_obj_add_style(watchface1, LV_STATE_DEFAULT, &bg_style);

    LV_IMG_DECLARE(BACKGROUND_PIC2);
    lv_img_set_src(watchface2, &BACKGROUND_PIC2);
    lv_obj_align(watchface2, NULL, LV_ALIGN_CENTER, 0, 0);
    static lv_style_t bg_style2;
    lv_style_set_bg_color(&bg_style2, LV_STATE_DEFAULT, LV_COLOR_LCD_BG_BL_ON);
    lv_style_set_bg_opa(&bg_style2, LV_STATE_DEFAULT, LV_OPA_50);
    lv_obj_add_style(watchface2, LV_STATE_DEFAULT, &bg_style2);

#ifdef BAT_LVL
	static lv_obj_t *BatBar = lv_bar_create(watchface2, NULL);
    static lv_style_t BatBar_Style, BatBar_V_Style;
    lv_style_set_bg_opa(&BatBar_Style, LV_STATE_DEFAULT, LV_OPA_50);
    lv_style_set_bg_color(&BatBar_Style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_bg_opa(&BatBar_V_Style, LV_STATE_DEFAULT, LV_OPA_0);
    lv_style_set_bg_color(&BatBar_V_Style, LV_STATE_DEFAULT, LV_COLOR_BLUE);
    lv_obj_add_style(BatBar, LV_BAR_PART_BG, &BatBar_Style);
    lv_obj_add_style(BatBar, LV_BAR_PART_INDIC, &BatBar_V_Style);
    lv_bar_set_range(BatBar, 0, 100);
	lv_bar_set_start_value(BatBar,0,LV_ANIM_ON);
	lv_obj_set_size(BatBar, LV_HOR_RES -10 , 10);
    	lv_obj_align(BatBar, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 5);
#endif //BAT_LVL

#ifdef DIGITAL_1
    SetupDigital1(watchface1);
#endif // DIGITAL_1

#ifdef ANALOG_1
    SetupAnalog1(watchface2);
#endif //ANALOG_1

	///////////////////////////////////////////////////////
	lv_task_create([](lv_task_t* t)
        {
            RTC_Date curr_datetime = rtc->getDateTime();
#ifdef ANALOG_1	
            UpdateAnalog1(curr_datetime);
#endif //ANALOG_1

#ifdef DIGITAL_1
            UpdateDigital1(curr_datetime, watch->power->getBattDischargeCurrent(), watch->power->getBattPercentage(), watch->power->getBattVoltage(), curr_datetime.second);
#endif //DIGITAL_1  

#ifdef BAT_LVL
            BatLvl = watch->power->getBattPercentage();
            if (BatLvl <= 20)     lv_style_set_bg_color(&BatBar_V_Style, LV_STATE_DEFAULT, LV_COLOR_RED);
            lv_bar_set_value(BatBar, 0, (uint16_t)(BatLvl));
#endif //BAT_LVL
	}, 1000, LV_TASK_PRIO_MID, nullptr);
/////////////////////////////////////////////////////////////
    setCpuFrequencyMhz(80);
#ifdef SLEEP_TIMER
    RTC_Date SleepTimer = rtc->getDateTime();
    Sleeptimer_End = epoch_r(rtc->getDateTime()) + 60;
#endif //SLEEP_TIMER
}


void loop()
{
    lv_task_handler();
	
#ifdef SLEEP_TIMER
    Sleeptimer_Now = epoch_r(rtc->getDateTime());
    if (Sleeptimer_Now>=Sleeptimer_End) 
    {
        Sleeptimer_End =+ 60;
        watch->displaySleep();
        watch->powerOff();
        esp_sleep_enable_ext1_wakeup(GPIO_SEL_39, ESP_EXT1_WAKEUP_ANY_HIGH);
        esp_deep_sleep_start();
    }
#endif //SLEEP_TIMER
}
