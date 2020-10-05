
#include <WiFi.h>
#iclude "time.h"
#include "secret.h"
#include "config.h"

bool syncRtc2Ntp()
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
    watch->rtc->setDateTime(updateRTC);
    Serial.println("RTC time synched with NTP");

    //disconnect WiFi as it's no longer needed
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    return true;
}
