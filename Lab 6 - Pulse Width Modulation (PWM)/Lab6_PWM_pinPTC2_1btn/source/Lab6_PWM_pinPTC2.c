#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"

volatile uint8_t updatedDutycycle = 100U; 
volatile btnPress = 0;

void delay(void)
{
    volatile uint32_t i = 0U;
    for (i = 0U; i < 1000000U; ++i) {
        __asm("NOP");
    }
}

void SW2_GPIOC_IRQHANDLER(void) {
	GPIO_PortClearInterruptFlags(GPIOC, 1U << 6U);

    switch (btnPress) {
        case 0:
            updatedDutycycle = 100U;
            btnPress++;
            break;
        case 1:
            updatedDutycycle = 50U;
            btnPress++;
            break;
        default:
            updatedDutycycle = 0U;
            btnPress = 0;
            break;
    }

    FTM_UpdatePwmDutycycle(FTM0_PERIPHERAL, kFTM_Chnl_1, kFTM_EdgeAlignedPwm, updatedDutycycle);
    FTM_SetSoftwareTrigger(FTM0_PERIPHERAL, true);
    delay();
}

int main(void) {
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    BOARD_InitDebugConsole();
#endif

    PRINTF("Lab6_PWM_pinPTC2_1btn - John Trinidad");
    PRINTF("\nPWM signal of 10KHz is generated on pin PTC2 by FTM0 channel 1");
    PRINTF("\nPressing SW2 repeatedly will cycle LED brightness through 100%, 50%, 0%");

    FTM_StartTimer(FTM0_PERIPHERAL, kFTM_SystemClock);

    return 0 ;
}
