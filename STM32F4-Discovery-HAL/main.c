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

int main(void)
{
    HAL_Init();
    BSP_LED_Init(LED4);
    BSP_LED_Init(LED5);
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

    while(1)
    {
        if (BSP_PB_GetState(BUTTON_KEY))
            BSP_LED_On(LED4);
        else
            BSP_LED_Off(LED4);
        BSP_LED_Toggle(LED5);
        HAL_Delay(100);
    }
}

