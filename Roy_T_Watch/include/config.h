// => Hardware select
// #define LILYGO_WATCH_2019_WITH_TOUCH     // To use T-Watch2019 with touchscreen, please uncomment this line
// #define LILYGO_WATCH_2019_NO_TOUCH          // To use T-Watch2019 Not touchscreen , please uncomment this line
#define LILYGO_WATCH_2020_V1             //To use T-Watch2020, please uncomment this line


// NOT SUPPORT ...
//// #define LILYGO_WATCH_BLOCK
// NOT SUPPORT ...

// => Function select
#define LILYGO_WATCH_LVGL                   //To use LVGL, you need to enable the macro LVGL

#include <LilyGoWatch.h>

// Personal Configuration

#define SLEEP_TIMER 20			//comment to disenable Sleep after 20s
#define DIGITAL_1				//comment to disenable Digital Watchface
#define ANALOG_1				//comment to disenable Analog Watchface
#define BAT_LVL				//comment to disenable Battery Level Gauge