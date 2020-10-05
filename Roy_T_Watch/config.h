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

#endif // !CONFIG_H
