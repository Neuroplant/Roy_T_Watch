// Analog1.h

#ifndef _ANALOG1_h
#define _ANALOG1_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "config.h"


void SetupAnalog1(lv_obj_t* face);

void UpdateAnalog1(RTC_Date datetime);

#endif

