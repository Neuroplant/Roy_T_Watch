// Roy_T_Watch
// Timesync via Wifi with NTP (wifi_ntp.cpp)
// 05.10.2020 Neuroplant

#include "wifi_ntp.h"
#include <WiFi.h>
#include "time.h"
#include "secret.h"
#include "config.h"
#include "LilyGoWatch.h"

// Wifi variables 
// The credetials are stored in secret.h file that doesnt need to be synched with the repo. The following format is used:
// #define SSID "MY_SSID"
// #define PASSWORD "MY_PASSWORD"
const char* ssid       = SSID;
const char* ssid_passphrase   = PASSWORD;

// NTP Settings : for more ionformations, https://lastminuteengineers.com/esp32-ntp-server-date-time-tutorial/
//const char* ntpServer = "pool.ntp.org"; // (for worlwide NTP server)
const char* ntpServer = "europe.pool.ntp.org";
const long gmtOffset_sec = 3600;
const int  daylightOffset_sec = 3600;

bool syncRtc2Ntp(PCF8563_Class *wwatch)
{
    WiFi.begin(ssid, ssid_passphrase);
 // after 6 sec if WiFi is not found abort and avoid locking the setup
    int timeoutMs = 6000; 
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        timeoutMs -= 500;
        if(timeoutMs <= 0){
            WiFi.mode(WIFI_OFF);
            return false;
        } 
    }

//init and get the time from NTP server
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    struct tm timeinfo;
    if(!getLocalTime(&timeinfo))
    {
        return false;
    }

    RTC_Date updateRTC;
    updateRTC.year = timeinfo.tm_year;
    updateRTC.month = timeinfo.tm_mon;
    updateRTC.day = timeinfo.tm_mday;
    updateRTC.hour = timeinfo.tm_hour;
    updateRTC.minute = timeinfo.tm_min;
    updateRTC.second = timeinfo.tm_sec;
    wwatch->setDateTime(updateRTC);

    //disconnect WiFi as it's no longer needed
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    return true;
}
