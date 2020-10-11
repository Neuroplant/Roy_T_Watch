// Roy_T_Watch
// Weltraum Watchface (Weltraum.h)
// 11.10.2020 Neuroplant

#ifndef _WELTRAUM_H
#define _WELTRAUM_H

#include "config.h"

typedef struct {
 lv_obj_t* Second;
 lv_obj_t* Minute;
 lv_obj_t* Hour;
} str_Space_time_t;

static str_Space_time_t SData;

void SetupWeltraum(lv_obj_t* face);	//setup Watchface "Weltraum" on Parent "face"

void UpdateWeltraum(RTC_Date datetime);	//update Watchface "Weltraum" with current data

#endif
