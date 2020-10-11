// Roy_T_Watch
// Main Programm (Roy_T_Watch.ino)
// 11.10.2020 Neuroplant

#include "config.h"

TTGOClass *watch = nullptr;
PCF8563_Class *rtc;
AXP20X_Class* power = nullptr;
BMA* sensor;

#ifdef DIGITAL_1
	#include "Digital1.h"
#endif //DIGITAL_1

#ifdef ANALOG_1
	#include "Analog1.h"
#endif //ANALOG_1

#ifdef ANALOG_2
	#include "Analog2.h"
#endif //ANALOG_1

#ifdef WELTRAUM
	#include "weltraum.h"
#endif //WELTRAUM

#ifdef BUTTON_WAKE
	#include "button_wake.h"
#endif //BUTTON_WAKE

#ifdef SENSOR_WAKE
	#include "sensor_wake.h"
#endif //SENSOR_WAKE

#ifdef WIFI_NTP
	#include "wifi_ntp.h"
#endif //WIFI_NTP

void setup()
{
    watch = TTGOClass::getWatch();
    watch->begin();
    watch->lvgl_begin();
    rtc = watch->rtc;
    power = watch->power;
	sensor = watch->bma;
	
// Use compile time if no NTP reached

#ifdef WIFI_NTP
    if (!GetNTP_Time(rtc))
#endif //WIFI_NTP
		rtc->check();

// Turn on the backlight
    watch->openBL();
//Lower the brightness
    watch->bl->adjust(150);

#ifdef BUTTON_WAKE
        SetupButtonWake(watch,power);
#endif //BUTTON_WAKE

#ifdef SENSOR_WAKE
        SetupSensorWake(watch,sensor);
#endif //SENSOR_WAKE


// Create Screen with 4 horizontal Tiles
        static lv_point_t valid_pos[] = { {0,0}, {1,0} , {2,0} , {3,0} };
   	    static lv_obj_t* tileview;
    	tileview = lv_tileview_create(lv_scr_act(), NULL);
    	lv_tileview_set_valid_positions(tileview, valid_pos, 4);
    	lv_tileview_set_edge_flash(tileview, true);

	    lv_obj_t* tile1 = lv_obj_create(tileview, NULL);
    	lv_obj_set_size(tile1, LV_HOR_RES, LV_VER_RES);
        lv_obj_set_pos(tile1, LV_HOR_RES * 0, 0);
    	lv_tileview_add_element(tileview, tile1);
        
        lv_obj_t* tile2 = lv_obj_create(tileview, tile1);
        lv_obj_set_size(tile2, LV_HOR_RES, LV_VER_RES);
        lv_obj_set_pos(tile2, LV_HOR_RES*1, 0);
        lv_tileview_add_element(tileview, tile2);

        lv_obj_t* tile3 = lv_obj_create(tileview, tile1);
        lv_obj_set_size(tile3, LV_HOR_RES, LV_VER_RES);
        lv_obj_set_pos(tile3, LV_HOR_RES*2, 0);
        lv_tileview_add_element(tileview, tile3);
        
        lv_obj_t* tile4 = lv_obj_create(tileview, tile1);
        lv_obj_set_size(tile4, LV_HOR_RES, LV_VER_RES);
        lv_obj_set_pos(tile4, LV_HOR_RES*3, 0);
        lv_tileview_add_element(tileview, tile4);

    lv_obj_t* watchface1 = lv_img_create(tile1, NULL); 		//Create "watchface1" on tile1
    lv_obj_t* watchface2 = lv_img_create(tile2, NULL); 		//Create "watchface2" in tile2
    lv_obj_t* watchface3 = lv_img_create(tile3, NULL); 		//Create "watchface...
    lv_obj_t* watchface4 = lv_img_create(tile4, NULL); 		//Create "watchface...

 
#ifdef DIGITAL_1
    SetupDigital1(watchface3);
#endif // DIGITAL_1

#ifdef ANALOG_1
    SetupAnalog1(watchface1);
#endif //ANALOG_1

#ifdef ANALOG_2
    SetupAnalog2(watchface4);
#endif //ANALOG_2

#ifdef WELTRAUM
    SetupWeltraum(watchface2);
#endif //WELTRAUM

	///////////////////////////////////////////////////////
	lv_task_create([](lv_task_t* t)
        {
            RTC_Date curr_datetime = rtc->getDateTime();
#ifdef ANALOG_1	
            UpdateAnalog1(curr_datetime);
#endif //ANALOG_1

#ifdef ANALOG_2	
//         BattPer = (power->getBattPercentage());
            UpdateAnalog2(curr_datetime, power->getBattPercentage());
#endif //ANALOG_2

#ifdef WELTRAUM	
            UpdateWeltraum(curr_datetime);
#endif //WELTRAUM

#ifdef DIGITAL_1
            UpdateDigital1(curr_datetime,power->getBattDischargeCurrent(), power->getBattPercentage(), power->getBattVoltage(), curr_datetime.second);
#endif //DIGITAL_1  

	}, 500, LV_TASK_PRIO_MID, nullptr);
/////////////////////////////////////////////////////////////
  //  setCpuFrequencyMhz(80);

};


void loop()
{
	#ifdef BUTTON_WAKE
	if (watch->power->isVBUSPlug() || lv_disp_get_inactive_time(NULL) < BUTTON_WAKE)
    {
        lv_task_handler();
    } else {
        StartButtonWake(watch);
    }
#endif //BUTTON_WAKE

#ifdef SENSOR_WAKE
if (watch->power->isVBUSPlug() || lv_disp_get_inactive_time(NULL) < SENSOR_WAKE)
    {
        lv_task_handler();
    } else {
        StartSensorWake(watch);
    }
#endif //SENSOR_WAKE
//lv_task_handler();
delayMicroseconds(5);
}
