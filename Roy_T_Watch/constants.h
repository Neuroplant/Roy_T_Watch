// Roy_T_Watch
// Contants (constants.h)
// 11.10.2020 Neuroplant

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "config.h"

const int shadow_offsetx = 4;				//Shadow offset x
const int shadow_offsety = 5;				//Shadow offset y

#define DEFAULT_SCREEN_TIMEOUT  30*1000			//Screen Timeout

#define WATCH_FLAG_SLEEP_MODE   _BV(1)
#define WATCH_FLAG_SLEEP_EXIT   _BV(2)
#define WATCH_FLAG_BMA_IRQ      _BV(3)
#define WATCH_FLAG_AXP_IRQ      _BV(4)

//some custom Colors
#define LV_COLOR_LCD_BG_BL_ON LV_COLOR_MAKE(0xA8, 0xC6, 0x4E)   //Old Style LCD Simulation Background /Light off
#define LV_COLOR_LCD_BG_BL_OFF LV_COLOR_MAKE(0x3C, 0x41, 0x2C)  //Old Style LCD Simulation Background /Light off
#define LV_COLOR_LCD_SEG_ON LV_COLOR_MAKE(0xF0, 0xFA, 0xF0)     //Old Style LCD Simulation Segment on
#define LV_COLOR_LCD_SEG_OFF LV_COLOR_MAKE(0xFF, 0xFF, 0xFF)    //Old Style LCD Simulation Segment off/Light off/Better use OPA_10
#define LV_COLOR_LCD_SEG_SHAD LV_COLOR_MAKE(0xFF, 0xFF, 0xFF)   //Old Style LCD Simulation Segment Shadow (only if Light on)/Better use OPA_50



LV_IMG_DECLARE(HourHand_S);					// Select image for hand "HourHand_S.c"
LV_IMG_DECLARE(MinuteHand_S);				// Select image for hand "MinuteHand_S.c"
LV_IMG_DECLARE(SecondHand_S);				// Select image for hand "SecondHand_S.c"
LV_IMG_DECLARE(HourHand);					// Select image for hand "HourHand.c"
LV_IMG_DECLARE(MinuteHand);					// Select image for hand "MinuteHand.c"
LV_IMG_DECLARE(SecondHand);					// Select image for hand "SecondHand.c"


//from wikipedia https://de.wikipedia.org/wiki/Unixzeit
// only small changes for using RTC_Date
int32_t unix_zeit(RTC_Date value);
int moon_phase(RTC_Date Value);//0..7
#endif