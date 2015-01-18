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

#include <usbd_core.h>
#include <usbd_desc.h>
#include <usbd_cdc_if_template.h>

USBD_HandleTypeDef USBD_Device;

int NonBlockingTimer(uint32_t delay)
{
    static uint32_t tickStart = 0;

    // Just for the first init
    if (tickStart == 0)
        tickStart = HAL_GetTick();

    // Test if if delay is done
    if ((HAL_GetTick() - tickStart) < delay)
        return 0;

    // delay done, update the new time
    tickStart = HAL_GetTick();
    return 1;
}


int main(void)
{
    char byte;

    HAL_Init();
    BSP_LED_Init(LED4);
    BSP_LED_Init(LED5);
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

    // USB CDC initialization
    USBD_Init(&USBD_Device, &VCP_Desc, 0);

    USBD_RegisterClass(&USBD_Device, &USBD_CDC);
    USBD_CDC_RegisterInterface(&USBD_Device, &USBD_CDC_Template_fops);
    USBD_Start(&USBD_Device);

    // wait the end of the USB initialization
    while (!g_VCPInitialized) {}

    while(1)
    {
        // copy button state to LED
        if (BSP_PB_GetState(BUTTON_KEY))
            BSP_LED_On(LED4);
        else
            BSP_LED_Off(LED4);

        // Blink LED
        if (NonBlockingTimer(1000))
            BSP_LED_Toggle(LED5);

        // Echo USB UART input char to USB UART output
        if (VCP_read(&byte, 1) == 1)
        {
            VCP_write(&byte, 1);
        }

    }
}

