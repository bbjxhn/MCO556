/*
 * Copyright 2016-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file    Lab6_PWM_pinPTC2.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    /*
    PRINTF("Lab 6_PWM_pinPTC2");
    PRINTF("\nPWM signal of 10KHz is generated on pin PTC2 by FTM0 channel 1");
    PRINTF("\nDuty Cycle = 10%");

    FTM_StartTimer(FTM0_PERIPHERAL, kFTM_SystemClock);
    */

   

    return 0 ;
}
