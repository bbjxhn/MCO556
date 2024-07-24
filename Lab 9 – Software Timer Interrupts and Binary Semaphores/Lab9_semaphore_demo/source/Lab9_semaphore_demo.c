/***************************************************************************************************************
File:	Lab9_semaphore_demo.c
Author:	B. Shefler
Date:	October 5, 2021
Description: This demo program demonstrates usage of software timer interrupts and the interrupt safe version
of the Binary Semaphore API that is used to unblock a task each time a particular interrupt occurs, effectively
synchronizing the task with the interrupt.
The timer callback function executes every 2 seconds.
The timer callback "gives" the semaphore to the task (Task1), and the task transitions from the Blocked state
to the Running state because it "takes" the semaphore.
Program's repetitive output:

SwTimer ISR - Sensor is read
Task1 - Sensor is processed
*****************************************************************************************************************/

/* Standard includes */
#include <assert.h>
#include <stdio.h>
#include <string.h>

/* Kernel includes */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"

/* Freescale includes */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
//#include "peripherals.h" /* un-comment this statement when adding peripheral devices! */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* The software timer period */
#define SW_TIMER_PERIOD_MS (2000 / portTICK_PERIOD_MS)

#define Task1_PRIORITY (tskIDLE_PRIORITY + 1)

SemaphoreHandle_t xSemaphore_Task1;	/* semaphore reference variable */
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* The software timer callback function prototype */
static void SwTimerCallback(TimerHandle_t xTimer);
/* Task1 function prototype */
static void Task1(void *pvParameters);
/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    TimerHandle_t SwTimerHandle = NULL; /* swtimer reference variable */
    /* create one binary semaphore */
    xSemaphore_Task1 = xSemaphoreCreateBinary();

    /* Initialize board hardware */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    //BOARD_InitBootPeripherals(); /* un-comment this statement when adding peripheral devices! */
    BOARD_InitDebugConsole();
    SystemCoreClockUpdate();

    /* Create the software timer */
    SwTimerHandle = xTimerCreate("SwTimer",          /* Text name */
                                 SW_TIMER_PERIOD_MS, /* Timer period */
                                 pdTRUE,             /* Enable auto reload */
                                 0,                  /* ID is not used */
                                 SwTimerCallback);   /* The callback function */
    /* Create Task1 */
    if (xTaskCreate(Task1, "TASK1", configMINIMAL_STACK_SIZE + 128, NULL, Task1_PRIORITY, NULL) != pdPASS)
   	       {
   	           PRINTF("Task creation failed!.\r\n");
   	           while (1)
   	               ;
   	       }

    /* Start timer */
    xTimerStart(SwTimerHandle, 0);
    /* Start scheduling */
    vTaskStartScheduler();
    for (;;)
        ;
}
/*!
 * @brief Software timer callback
 */
static void SwTimerCallback(TimerHandle_t xTimer)
{
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	PRINTF("SwTimer ISR - Sensor is read\r\n");
	xSemaphoreGiveFromISR(xSemaphore_Task1, &xHigherPriorityTaskWoken);
	portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}
/*!
 * @brief Task1 function
 */
static void Task1(void *pvParameters)
{
	 while (1)
		{
		xSemaphoreTake(xSemaphore_Task1, portMAX_DELAY);
		PRINTF("Task1 - Sensor is processed\r\n\n");
		}
}

