// Roy_T_Watch
// Wake by Button (button_wake.h)
// 09.10.2020 Neuroplant

#ifndef BUTTON_WAKE_H
#define BUTTON_WAKE_H

#include "config.h"
static bool bw_irq = false;

void SetupButtonWake(TTGOClass *Value, AXP20X_Class *bw_power); //init ButtonWake

void StartButtonWake(TTGOClass *Value);	//Sent to Sleep
#endif