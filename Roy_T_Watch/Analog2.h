// Roy_T_Watch
// Analog Watchface 1 (Analog1.h)
// 11.10.2020 Neuroplant

#ifndef _ANALOG2_h
#define _ANALOG2_h

#include "config.h"

typedef struct {
 lv_obj_t* Moon;			//Moon Phase
 lv_obj_t* Dial;			//

 lv_obj_t* Hour;	
 lv_obj_t* Minute;
 lv_obj_t* Second;

 lv_obj_t* Val1Gauge; //for Battery Status
} str_Analog2_time_t;
static str_Analog2_time_t A2Data, A2DataS;
static lv_obj_t* Gauge_Style = nullptr;

void SetupAnalog2(lv_obj_t* face);	//setup Watchface "Analog2" on Parent "face"

void UpdateAnalog2(RTC_Date datetime,int GaugeVal1);	//update Watchface "Analog2" with current data

#endif
