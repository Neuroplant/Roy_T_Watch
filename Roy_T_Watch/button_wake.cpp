// Roy_T_Watch
// Wake by Button (button_wake.cpp)
// 11.10.2020 Neuroplant

#include "button_wake.h"

void SetupButtonWake(TTGOClass* Value, AXP20X_Class* bw_power)
{
	pinMode(AXP202_INT, INPUT_PULLUP);
    attachInterrupt(AXP202_INT, [] 
	{
        bw_irq = true;
    }, FALLING);

    bw_power->enableIRQ(AXP202_PEK_SHORTPRESS_IRQ, true);
    //  Clear interrupt status
    bw_power->clearIRQ();
};

void StartButtonWake(TTGOClass *Value)
{
	    // Set screen and touch to sleep mode
    Value->displaySleep();
    Value->powerOff();

    // Use ext0 for wakeup

    esp_sleep_enable_ext1_wakeup(GPIO_SEL_35, ESP_EXT1_WAKEUP_ALL_LOW);
    esp_deep_sleep_start();
};

