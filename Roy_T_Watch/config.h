// Roy_T_Watch
// Configuration (config.h)
// 11.10.2020 Neuroplant

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
#include <WiFi.h>
#include <math.h>
#include <iostream>
#include <string>
#include <LilyGoWatch.h>
#include "constants.h"


// Personal Configuration - Comment out to disable

// !!! only use one of the Sleep/Wakup-Funktions !!!! Testing
//#define BUTTON_WAKE 20 * 1000
#define SENSOR_WAKE 20 * 1000
#define DIGITAL_1				                // Digital Watchface
#define ANALOG_1				                // Analog Watchface
#define ANALOG_2				                // Analog2 Watchface
#define WELTRAUM				                // Weltraum Watchface

#define BACKGROUND_D1	 Drache          // use "Drache.c" as Background for first Watchface - see https://lvgl.io/tools/imageconverter to create your own
#define BACKGROUND_A1	 Logo_lvgl       // use "Logo_lvgl.c" as Backgroud for second Watchface ...
#define BACKGROUND_A2	 Logo_lvgl 
#define BACKGROUND_SPACE sonne 
#define WIFI_NTP                        // activate wifi to sync time with ntp
/*
when using WIFI_NTP also create a "secret.h" containing :
	#ifndef SECRET_H
	#define SECRET_H

	#define SSID "YOURSSID"
	#define PASSWORD "YOURPASSWORD"

	#endif
*/



#endif // !CONFIG_H
