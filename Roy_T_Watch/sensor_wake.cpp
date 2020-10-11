// Roy_T_Watch
// Wake by Sensor (sensor_wake.cpp)
// 11.10.2020 Neuroplant

#include "sensor_wake.h"

void SetupSensorWake(TTGOClass *Value, BMA* sw_sensor)
{
    // Accel parameter structure
    Acfg cfg;
    cfg.odr = BMA4_OUTPUT_DATA_RATE_100HZ;
    cfg.range = BMA4_ACCEL_RANGE_2G;
    cfg.bandwidth = BMA4_ACCEL_NORMAL_AVG4;
    cfg.perf_mode = BMA4_CONTINUOUS_MODE;

    // Configure the BMA423 accelerometer
    sw_sensor->accelConfig(cfg);
    sw_sensor->enableAccel();

    // Disable BMA423 isStepCounter feature
    sw_sensor->enableFeature(BMA423_STEP_CNTR, false);
    // Enable BMA423 isTilt feature
    sw_sensor->enableFeature(BMA423_TILT, true);
    // Enable BMA423 isDoubleClick feature
    sw_sensor->enableFeature(BMA423_WAKEUP, true);
    // Reset steps
    sw_sensor->resetStepCounter();
    // Turn off feature interrupt
    // sw_sensor->enableStepCountInterrupt();
    sw_sensor->enableTiltInterrupt();
    // It corresponds to isDoubleClick interrupt
    sw_sensor->enableWakeupInterrupt();
};

void StartSensorWake(TTGOClass *Value)
{
	    // Set screen and touch to sleep mode
    Value->displaySleep();
    Value->powerOff();


    // Use ext1 for external wakeup
    esp_sleep_enable_ext1_wakeup(GPIO_SEL_35, ESP_EXT1_WAKEUP_ALL_LOW);
    esp_deep_sleep_start();
};

