#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#define SW_TIMER_PERIOD_MS (1000 / portTICK_PERIOD_MS)

SemaphoreHandle_t xMutex;
TimerHandle_t SwTimerHandle = NULL;

static void write_task_1(void *pvParameters);
static void write_task_2(void *pvParameters);

static void SwTimerCallback(TimerHandle_t xTimer);

void delay(void)
{
    uint32_t i = 10000000U; 
    while (i--)
    {
        __NOP(); 
    }
}

static void SwTimerCallback(TimerHandle_t xTimer)
{
    PRINTF("SwTmer Interrupt.\r\n");
}


int main(void)
{
    xMutex = xSemaphoreCreateMutex();
    SwTimerHandle = xTimerCreate("SwTimer", SW_TIMER_PERIOD_MS, pdTRUE, 0, SwTimerCallback);   


    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    if (xTaskCreate(write_task_1, "WRITE_TASK_1", configMINIMAL_STACK_SIZE + 128, NULL, tskIDLE_PRIORITY + 1, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }
    if (xTaskCreate(write_task_2, "WRITE_TASK_2", configMINIMAL_STACK_SIZE + 128, NULL, tskIDLE_PRIORITY + 1, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }

    PRINTF("Lab8 - Mutex - John Trinidad\n\n");

    xTimerStart(SwTimerHandle, 0);

    vTaskStartScheduler();
    for (;;)
        ;
}

static void write_task_1(void *pvParameters)
{
    while (1)
    {
        xSemaphoreTake(xMutex, portMAX_DELAY);
        PRINTF("Task1 is using UART0\r\n");
        delay();
        xSemaphoreGive(xMutex);
        taskYIELD();
    }
}

static void write_task_2(void *pvParameters)
{
    while (1)
    {
        xSemaphoreTake(xMutex, portMAX_DELAY);
        PRINTF("Task2 is using UART0\r\n");
        delay();
        xSemaphoreGive(xMutex);
        taskYIELD();
    }
}
