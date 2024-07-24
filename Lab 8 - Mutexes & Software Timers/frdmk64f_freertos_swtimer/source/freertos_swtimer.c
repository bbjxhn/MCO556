#include <assert.h>
#include <stdio.h>
#include <string.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#define SW_TIMER_PERIOD_MS (1000 / portTICK_PERIOD_MS)

static void SwTimerCallback(TimerHandle_t xTimer);

int main(void)
{
    TimerHandle_t SwTimerHandle = NULL;

    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    SystemCoreClockUpdate();

    SwTimerHandle = xTimerCreate("SwTimer", SW_TIMER_PERIOD_MS, pdTRUE, 0, SwTimerCallback);   
    
    xTimerStart(SwTimerHandle, 0);

    vTaskStartScheduler();
    for (;;)
        ;
}

static void SwTimerCallback(TimerHandle_t xTimer)
{
    PRINTF("Tick.\r\n");
}
