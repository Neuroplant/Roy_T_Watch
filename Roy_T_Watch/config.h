// Roy_T_Watch
// Configuration (config.h)
// 05.10.2020 Neuroplant

#ifndef CONFIG_H
#define CONFIG_H


// => Hardware select
// #define LILYGO_WATCH_2019_WITH_TOUCH // To use T-Watch2019 with touchscreen, please uncomment this line
// #define LILYGO_WATCH_2019_NO_TOUCH   // To use T-Watch2019 Not touchscreen , please uncomment this line
#define LILYGO_WATCH_2020_V1            //To use T-Watch2020, please uncomment this line


// NOT SUPPORT ...
//// #define LILYGO_WATCH_BLOCK
// NOT SUPPORT ...

// => Function select
#define LILYGO_WATCH_LVGL               //To use LVGL, you need to enable the macro LVGL

#include <LilyGoWatch.h>

// Personal Configuration - Comment out to disable
#define SLEEP_TIMER 20			            // Sleep after 20s
#define DIGITAL_1				                // Digital Watchface
#define ANALOG_1				                // Analog Watchface
#define BAT_LVL				                  // Battery Level Bar
#define BACKGROUND_PIC	Drache          // use "Drache.c" as Background for first Watchface - see https://lvgl.io/tools/imageconverter to create your own
#define BACKGROUND_PIC2	Logo_lvgl       // use "Logo_lvgl.c" as Backgroud for second Watchface ...
#define WIFI_NTP                        // activate wifi to sync time with ntp

const int shadow_offsetx = 3;				//Shadow offset x
const int shadow_offsety = 4;
const int HOR_RES = 240, VER_RES = 240;

#define LV_COLOR_LCD_BG_BL_ON LV_COLOR_MAKE(0xA8, 0xC6, 0x4E)   //Old Style LCD Simulation Background /Light off
#define LV_COLOR_LCD_BG_BL_OFF LV_COLOR_MAKE(0x3C, 0x41, 0x2C)  //Old Style LCD Simulation Background /Light off
#define LV_COLOR_LCD_SEG_ON LV_COLOR_MAKE(0xF0, 0xFA, 0xF0)     //Old Style LCD Simulation Segment on
#define LV_COLOR_LCD_SEG_OFF LV_COLOR_MAKE(0xFF, 0xFF, 0xFF)    //Old Style LCD Simulation Segment off/Light off/Better use OPA_10
#define LV_COLOR_LCD_SEG_SHAD LV_COLOR_MAKE(0xFF, 0xFF, 0xFF)   //Old Style LCD Simulation Segment Shadow (only if Light on)/Better use OPA_50

#define LV_COLOR_PHOSPHOR LV_COLOR_MAKE(0x88, 0xFF, 0x88) 

#endif // !CONFIG_H
