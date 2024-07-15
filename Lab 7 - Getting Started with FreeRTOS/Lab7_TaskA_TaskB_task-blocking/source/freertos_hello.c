/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Task priorities. */
#define TaskA_task_PRIORITY (configMAX_PRIORITIES - 1)
#define TaskB_task_PRIORITY (configMAX_PRIORITIES - 1)

/*******************************************************************************
 * Variables
 ******************************************************************************/
TaskHandle_t xTaskHandle = NULL;
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void TaskA_task(void *pvParameters);
static void TaskB_task(void *pvParameters);

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Application entry point.
 */
int main(void)
{
    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    if (xTaskCreate(TaskA_task, "TaskA_task", configMINIMAL_STACK_SIZE + 100, NULL, TaskA_task_PRIORITY, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }

    if (xTaskCreate(TaskB_task, "TaskB_task", configMINIMAL_STACK_SIZE + 100, NULL, TaskB_task_PRIORITY, NULL) !=
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

/*!
 * @brief Task responsible for printing of "Hello world." message.
 */
static void TaskA_task(void *pvParameters)
{
    for (;;)
    {
        PRINTF("TaskA is running.\r\n");
        //vTaskSuspend(NULL);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

static void TaskB_task(void *pvParameters)
{
    for (;;)
    {
        PRINTF("TaskB is running.\r\n");
        //vTaskSuspend(NULL);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
