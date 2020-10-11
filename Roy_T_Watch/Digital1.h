// Roy_T_Watch
// Digital Watchface 1 (Digital1.h)
// 11.10.2020 Neuroplant

#ifndef _DIGITAL1_h
#define _DIGITAL1_h

#include "config.h"
/*	Objects on the Digital Watchface
	+-------------------+
	|  hourmin (hh:mm)	| 	<- 64p
	|					|
	| date (dd.mm.yyyy) | 	<- 32p
	| stat1(f) stat2(i) | 	<- 32p
	| stat3(f) stat4(i) | 	<- 32p
	+-------------------+
*/
    typedef struct {
        lv_obj_t *hourmin;	// Time in the Format hh:mm 
        lv_obj_t *date;		// Date in the Format dd.mm.yyyy
        lv_obj_t* stat1;	// for e.g. BattDischargeCurrent
        lv_obj_t* stat2;	// for e.g. BattPercentage
        lv_obj_t* stat3;	// for e.g. BattVoltage
        lv_obj_t* stat4;	// for e.g. Seconds
    } str_Digital1_time_t;
    static str_Digital1_time_t DData,DDataS;

    static lv_style_t style_D1;	//Style for hourmin (big)
    static lv_style_t style_D1s;		//Style for hourmin shadow (big)
    static lv_style_t style_D2;		//Style for all other fields (small)
    static lv_style_t style_D2s;		//Style for all other fields shadow (small)


    void SetupDigital1(lv_obj_t* face);		//setup Watchface "Digital1" on Parent "face"

    void UpdateDigital1(RTC_Date datetime, float Val1, int Val2, float Val3, int Val4);	//uppdate Watchface "Digital1" with current data (time plus four additional fields)
    
#endif
