// Roy_T_Watch
// Wake by Sensor (sensor_wake.h)
// 11.10.2020 Neuroplant

#ifndef SENSOR_WAKE_H
#define SENSOR_WAKE_H

#include "config.h"
static bool sw_irq = false;

void SetupSensorWake(TTGOClass *Value, BMA* sw_sensor); //init SensorWake

void StartSensorWake(TTGOClass *Value);	//Sent to Sleep
#endif