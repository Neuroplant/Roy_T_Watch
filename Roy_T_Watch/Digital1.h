// Digital1.h

#ifndef _DIGITAL1_h
#define _DIGITAL1_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "config.h"

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

    static lv_style_t
        style_D1,
        style_D1s,
        style_D2,
        style_D2s;

    void SetupDigital1(lv_obj_t* face);

    void UpdateDigital1(RTC_Date datetime, float Val1, int Val2, float Val3, int Val4);


#endif

