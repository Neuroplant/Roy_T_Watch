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

// Personal Configuration Comment out to disable
//#define SERIAL_OUT 115200       // Serial output at 115288 Baud
#define SLEEP_TIMER 20			// Sleep after 20s
//#define DIGITAL_1				// Digital Watchface
#define ANALOG_1				// Analog Watchface
#define BAT_LVL				    // Battery Level Bar
#define TICKER                // Ticker will be used for Notifications etc. in a later Version
#define BACKGROUND_PIC	Drache
