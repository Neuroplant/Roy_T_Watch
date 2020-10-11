// Roy_T_Watch
// Analog Watchface 1 (Analog1.h)
// 11.10.2020 Neuroplant

#ifndef _ANALOG1_h
#define _ANALOG1_h

#include "config.h"

typedef struct {
 lv_obj_t* Second;
 lv_obj_t* Minute;
 lv_obj_t* Hour;
} str_Analog1_time_t;

static str_Analog1_time_t AData, ADataS;

void SetupAnalog1(lv_obj_t* face);	//setup Watchface "Analog1" on Parent "face"

void UpdateAnalog1(RTC_Date datetime);	//update Watchface "Analog1" with current data

#endif
