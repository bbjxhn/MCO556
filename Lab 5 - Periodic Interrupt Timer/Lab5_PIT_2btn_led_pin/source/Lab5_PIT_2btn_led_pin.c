/*
 * Copyright 2016-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file    Lab5_PIT_2btn_led_pin.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"

void PIT_CHANNEL_0_IRQHANDLER(void) /*ISR to process PIT channel 0 interrupts*/
{
	PIT_ClearStatusFlags(PIT, PIT_CHANNEL_0, kPIT_TimerFlag); /*clear PIT channel 0 interrupt status flag*/
	LED_RED_TOGGLE(); /*toggle RED LED*/
}

void PIT_CHANNEL_1_IRQHANDLER(void) /*ISR to process PIT channel 0 interrupts*/
{
	PIT_ClearStatusFlags(PIT, PIT_CHANNEL_1, kPIT_TimerFlag);
	LED_RED_OFF();
	PIT_StopTimer(PIT_PERIPHERAL, PIT_CHANNEL_1);
	PIT_StopTimer(PIT_PERIPHERAL, PIT_CHANNEL_0);
	GPIO_PinWrite(GPIOC, 16U, 0U);
	PRINTF("\nSystem Overload Timeout");
	PRINTF("\nRegular System Operation");
}

void SW2_GPIOC_IRQHANDLER(void) /*Interrupt Service Routine for SW2*/
{
/* clear interrupt flag set by button SW2 connected to pin PTC6 */
	GPIO_PortClearInterruptFlags(GPIOC, 1U << 6U);
	GPIO_PinWrite(GPIOC, 16U, 1U); /* make pin PTC16 Low */
	PIT_StartTimer(PIT_PERIPHERAL, PIT_CHANNEL_0);
	PIT_StartTimer(PIT_PERIPHERAL, PIT_CHANNEL_1);
	//LED_RED_ON();
	PRINTF("\n\nSystem Overload Operation - 3 Cycles Max");
}

void SW3_GPIOA_IRQHANDLER(void) /*Interrupt Service Routine for SW3*/
{
/* clear interrupt flag set by button SW3 connected to pin PTA4 */
	GPIO_PortClearInterruptFlags(GPIOA, 1U << 4U);
	GPIO_PinWrite(GPIOC, 16U, 0U); /* make pin PTC16 High */
    PIT_StopTimer(PIT_PERIPHERAL, PIT_CHANNEL_1);
    PIT_StopTimer(PIT_PERIPHERAL, PIT_CHANNEL_0);
	PRINTF("\n\nRegular System Operation");
	LED_RED_OFF();
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

    PRINTF("Lab5_PIT_2btn_led_pin - John Trinidad");
    PRINTF("\nRegular System Operation");
    PRINTF("\nPress SW2 to enable system overload");
    PRINTF("\nPress SW3 to switch to regular operation");

    LED_RED_OFF();
    //PIT_StartTimer(PIT_PERIPHERAL, PIT_CHANNEL_0);
    //PIT_StopTimer(PIT_PERIPHERAL, PIT_CHANNEL_0);
    PIT_StartTimer(PIT_PERIPHERAL, PIT_CHANNEL_1); /*start PIT timer-channel 1*/
    PIT_StopTimer(PIT_PERIPHERAL, PIT_CHANNEL_1);

    return 0 ;
}
