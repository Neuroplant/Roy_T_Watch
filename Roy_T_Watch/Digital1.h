// Roy_T_Watch
// Digital Watchface 1 (Digital1.cpp)
// 05.10.2020 Neuroplant

#ifndef _DIGITAL1_h
#define _DIGITAL1_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "config.h"
/*	Objects on the Digital Watchface
	+--------------+
	|  hourmin     |
	| date         |
	| stat1  stat2 |
	| stat3  stat4 |
	+--------------+
*/
    typedef struct {
        lv_obj_t *hourmin;
        lv_obj_t *date;
        lv_obj_t* stat1;
        lv_obj_t* stat2;
        lv_obj_t* stat3;
        lv_obj_t* stat4;
    } str_datetime_t;
    static str_datetime_t DData, DDataS;

    static lv_style_t
        style_D1,		//Style for hourmin (big)
        style_D1s,		//Style for hourmin shadow (big)
        style_D2,		//Style for all other fields (small)
        style_D2s;		//Style for all other fields shadow (small)

    static lv_style_t bg_style;

    void SetupDigital1(lv_obj_t* face);		//setup Watchface "Digital1" on Parent "face"

    void UpdateDigital1(RTC_Date datetime, float Val1, int Val2, float Val3, int Val4);	//uppdate Watchface "Digital1" with current data (time plus four additional fields)

#endif
