#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#define TaskA_task_PRIORITY (configMAX_PRIORITIES - 1)
#define TaskB_task_PRIORITY (configMAX_PRIORITIES - 1)
#define TaskC_task_PRIORITY (configMAX_PRIORITIES - 1)

TaskHandle_t xTaskHandle = NULL;

static void TaskA_RED(void *pvParameters);
static void TaskB_GREEN(void *pvParameters);
static void TaskC_BLUE(void *pvParameters);

void delay(void)
{
    uint32_t i = 10000000U; 
    while (i--)
    {
        __NOP(); 
    }
}

int main(void)
{
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    if (xTaskCreate(TaskA_RED, "TaskA_task", configMINIMAL_STACK_SIZE + 100, NULL, TaskA_task_PRIORITY, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }

    if (xTaskCreate(TaskB_GREEN, "TaskB_task", configMINIMAL_STACK_SIZE + 100, NULL, TaskB_task_PRIORITY, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }

    if (xTaskCreate(TaskC_BLUE, "TaskC_task", configMINIMAL_STACK_SIZE + 100, NULL, TaskC_task_PRIORITY, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }

    vTaskStartScheduler();
    for (;;)
        ;
}

static void TaskA_RED(void *pvParameters)
{
    for (;;)
    {
        LED_RED_ON();
        LED_GREEN_OFF();
        LED_BLUE_OFF();
        delay();
        taskYIELD();
    }
}

static void TaskB_GREEN(void *pvParameters)
{
    for (;;)
    {
        LED_GREEN_ON();
        LED_RED_OFF();
        LED_BLUE_OFF();
        delay();
        taskYIELD();
    }
}

static void TaskC_BLUE(void *pvParameters)
{
    for (;;)
    {
        LED_BLUE_ON();
        LED_GREEN_OFF();
        LED_RED_OFF();
        delay();
        taskYIELD();
    }
}
