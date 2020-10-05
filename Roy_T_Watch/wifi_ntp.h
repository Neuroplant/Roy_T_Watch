// Roy_T_Watch
// Timesync via Wifi with NTP (wifi_ntp.h)
// 05.10.2020 Neuroplant

#ifndef WIFI_NTP_H
#define WIFI_NTP_H
#include "config.h"

bool syncRtc2Ntp(PCF8563_Class  *wwatch);

#endif
