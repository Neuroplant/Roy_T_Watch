// Roy_T_Watch
// Analog Watchface 1 (Analog1.h)
// 05.10.2020 Neuroplant

#ifndef _ANALOG1_h
#define _ANALOG1_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "config.h"

static lv_obj_t* Second_Hand_s = nullptr;
static lv_obj_t* Minute_Hand_s = nullptr;
static lv_obj_t* Hour_Hand_s = nullptr;

static lv_obj_t* Hour_Hand = nullptr;
static lv_obj_t* Minute_Hand = nullptr;
static lv_obj_t* Second_Hand = nullptr;

static lv_style_t bg_style2;


void SetupAnalog1(lv_obj_t* face);	//setup Watchface "Analog1" on Parent "face"

void UpdateAnalog1(RTC_Date datetime);	//uppdate Watchface "Analog1" with current data

#endif
