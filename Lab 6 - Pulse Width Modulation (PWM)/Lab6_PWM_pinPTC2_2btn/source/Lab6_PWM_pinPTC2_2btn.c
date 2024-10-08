#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"

volatile bool SW2btn_press = false;
volatile uint8_t updatedDutycycle = 0;

void delay(void)
{
    volatile uint32_t i = 0U;
    for (i = 0U; i < 1000000U; ++i) {
        __asm("NOP");
    }
}

void SW2_GPIOC_IRQHANDLER(void) {
	GPIO_PortClearInterruptFlags(GPIOC, 1U << 6U);
    SW2btn_press = true;
    PRINTF("Duty Cycle is sweeping from 0%% -> 100%% -> 0%%\r\n");
}

void SW3_GPIOA_IRQHANDLER(void) {
    GPIO_PortClearInterruptFlags(GPIOA, 1U << 4U);
    SW2btn_press = false;
    
    FTM_StopTimer(FTM0_PERIPHERAL);

    updatedDutycycle = 0;
    FTM_UpdatePwmDutycycle(FTM0_PERIPHERAL, kFTM_Chnl_1, kFTM_EdgeAlignedPwm, updatedDutycycle);
    FTM_SetSoftwareTrigger(FTM0_PERIPHERAL, true);
    PRINTF("FTM0 is stopped\r\n");
}

int main(void) {
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    BOARD_InitDebugConsole();
#endif

    PRINTF("Lab6_PWM_pinPTC2_2btn - John Trinidad");
    PRINTF("\nPWM signal of 10KHz is generated on pin PTC2 by FTM0 channel 1");
    PRINTF("\nPress SW2 to sweep the Dutycycle from 0% -> 100% -> 0% coninuously");
    PRINTF("\nPress SW3 to stop the process");

    while (true) {
        FTM_StartTimer(FTM0_PERIPHERAL, kFTM_SystemClock);

        if (SW2btn_press) {
            for (updatedDutycycle = 0; updatedDutycycle < 100 && SW2btn_press; updatedDutycycle += 10) {
                FTM_UpdatePwmDutycycle(FTM0_PERIPHERAL, kFTM_Chnl_1, kFTM_EdgeAlignedPwm, updatedDutycycle);
                FTM_SetSoftwareTrigger(FTM0_PERIPHERAL, true);
                delay();
            }

            for (updatedDutycycle = 100; updatedDutycycle > 0 && SW2btn_press; updatedDutycycle -= 10) {
                FTM_UpdatePwmDutycycle(FTM0_PERIPHERAL, kFTM_Chnl_1, kFTM_EdgeAlignedPwm, updatedDutycycle);
                FTM_SetSoftwareTrigger(FTM0_PERIPHERAL, true);
                delay();
            }
        }
        __asm volatile ("nop");
    }
    return 0 ;
}
