/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: $
   Last changed date:  $Date:  $
   ID:                 $Id:  $

**********************************************************************/
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "FreeRTOS.h"
#include "task.h"

#define TASK_PRIORITY	(tskIDLE_PRIORITY + 1)
#define STACK_SIZE     (configMINIMAL_STACK_SIZE + 100)


// Task prototypes
void LedTaskFunction( void *pvParameters );
void BtnTaskFunction( void *pvParameters );


int main(void)
{
    // Initialization
    HAL_Init();

    // create the task
    xTaskCreate( LedTaskFunction,   /* Pointer to the function that implements the task. */
                 "Flash Led",       /* Text name for the task. This is to facilitate debugging only. */
                 STACK_SIZE,        /* Stack depth */
                 NULL,              /* We are not using the task parameter. */
                 TASK_PRIORITY,     /* This task will run at priority 1. */
                 NULL );            /* We are not going to use the task handle. */

    // Create the BTN task
    xTaskCreate( BtnTaskFunction, "BTN Task", STACK_SIZE, NULL, TASK_PRIORITY, NULL );

    // Start the scheduler so the tasks start executing
    vTaskStartScheduler();

    while(1) ;
}

void LedTaskFunction( void *pvParameters )
{
    BSP_LED_Init(LED6);
    for (;;)
    {
        BSP_LED_Toggle(LED6);
        vTaskDelay(500);    // Delay 500 ms
    }
}

void BtnTaskFunction( void *pvParameters )
{
    BSP_LED_Init(LED3);
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
    for (;;)
    {
        if (BSP_PB_GetState(BUTTON_KEY))
            BSP_LED_On(LED3);
        else
            BSP_LED_Off(LED3);
    }
}
