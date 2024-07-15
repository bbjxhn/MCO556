/*
 * Copyright 2016-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file    MK64F12_Project.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"

void SW2_GPIOC_IRQHANDLER(void) /*Interrupt Service Routine for SW2*/
{
/* clear interrupt flag set by button SW2 connected to pin PTC6 */
	GPIO_PortClearInterruptFlags(GPIOC, 1U << 6U);
	LED_BLUE_TOGGLE();
	GPIO_PinWrite(GPIOC, 16U, 1U); /* make pin PTC16 Low */
	PRINTF("\nSystem Status: Armed");
}

void SW3_GPIOA_IRQHANDLER(void) /*Interrupt Service Routine for SW3*/
{
	GPIO_PortClearInterruptFlags(GPIOA, 1U << 4U);
	GPIO_PinWrite(GPIOC, 16U, 0U); /* make pin PTC16 High */
	PRINTF("\nSystem Status: Disarmed");
}

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
    PRINTF("Lab 4_Part 3 - John Trinidad");
    PRINTF("\nPress SW2 to turn RED LED ON");
    PRINTF("\nPress SW3 to turn RED LED OFF");
	*/

    PRINTF("Lab4_Part 5 - John Trinidad");
    PRINTF("\nPress SW2 to turn RED LED ON and make PTC16 High to Arm System");
    PRINTF("\nPress SW3 to turn RED LED OFF and make PTC16 Low to Disarm System");

    LED_BLUE_TOGGLE();
    LED_RED_OFF();

    return 0 ;
}
