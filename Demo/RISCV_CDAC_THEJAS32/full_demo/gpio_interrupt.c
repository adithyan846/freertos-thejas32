/*
 * FreeRTOS Kernel V10.2.1
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/******************************************************************************
 * NOTE 1:  This project provides two demo applications.  A simple blinky style
 * project, and a more comprehensive test and demo application.  The
 * mainCREATE_SIMPLE_BLINKY_DEMO_ONLY setting in main.c is used to select
 * between the two.  See the notes on using mainCREATE_SIMPLE_BLINKY_DEMO_ONLY
 * in main.c.  This file implements the comprehensive test and demo version.
 *
 * NOTE 2:  This file only contains the source code that is specific to the
 * full demo.  Generic functions, such FreeRTOS hook functions, and functions
 * required to configure the hardware, are defined in main.c.
 *
 ******************************************************************************
 *
 * main_full() creates all the demo application tasks and software timers, then
 * starts the scheduler.  The web documentation provides more details of the
 * standard demo application tasks, which provide no particular functionality,
 * but do provide a good example of how to use the FreeRTOS API.
 *
 * In addition to the standard demo tasks, the following tasks and tests are
 * defined and/or created within this file:
 *
 * "Reg test" tasks - These fill both the core registers with known values, then
 * check that each register maintains its expected value for the lifetime of the
 * task.  Each task uses a different set of values.  The reg test tasks execute
 * with a very low priority, so get preempted very frequently.  A register
 * containing an unexpected value is indicative of an error in the context
 * switching mechanism.
 *
 * "Check" task - The check executes every three seconds.  It checks that all
 * the standard demo tasks, and the register check tasks, are not only still
 * executing, but are executing without reporting any errors.  If the check task
 * discovers that a task has either stalled, or reported an error, then it
 * prints an error message to the UART, otherwise it prints "Pass.".
 */

/* Standard includes. */

#include <stdio.h>
#include <string.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "timer.h"
#include "semphr.h"

/* thejas64 incldues. */
#include "riscv_hal.h"

/* Standard demo application includes. */
#include "dynamic.h"
#include "blocktim.h"
#include "GenQTest.h"
#include "recmutex.h"
#include "TimerDemo.h"
#include "EventGroupsDemo.h"
#include "TaskNotify.h"
#include "AbortDelay.h"
#include "countsem.h"
#include "death.h"

#include "encoding.h"
//#include "enc28j60.h"
#include "gpio.h"
//#include "FreeRTOS_IP.h"
#include "string.h"

//#include "FreeRTOS_IP.h"
//#include "FreeRTOS_Sockets.h"
//#include "FreeRTOS_IP_Private.h"
//#include "FreeRTOS_ARP.h"
//#include "FreeRTOS_UDP_IP.h"
//#include "FreeRTOS_DHCP.h"
//#include "NetworkInterface.h"
//#include "NetworkBufferManagement.h"
//#include "FreeRTOS_DNS.h"
#include "pwmc.h"
#include "interrupt.h"
#include "ads1015.h"
#include "i2c_api.h"
//#include "mfrc522.h"
#include "spi.h"


static BaseType_t xReturned;
volatile TaskHandle_t pxCreatedTaskgpio;

//BaseType_t
//vSendPing (const char *pcIPAddress);

/* Called by main() to run the full demo (as opposed to the blinky demo) when
 * mainCREATE_SIMPLE_BLINKY_DEMO_ONLY is set to 0.
 */
void
gpio_interrupt (void);

/*
 * The check task, as described at the top of this file.
 */
//static void prvCheckTask( void *pvParameters );
/*
 * Initialise and start the peripheral timers that are used to exercise external
 * interrupt processing.
 */
//static void prvSetupPeripheralTimers( void );
/*
 * Register check tasks as described at the top of this file.  The nature of
 * these files necessitates that they are written in an assembly file, but the
 * entry points are kept in the C file for the convenience of checking the task
 * parameter.
 */
static void
gpio_interrupt_task (void *pvParameters);


//static void vHandlingTask( void *pvParameters);
extern void
vSendString (const char *const pcString);

//static BaseType_t xReturned;
//volatile TaskHandle_t pxCreatedTaskISR;




/*-----------------------------------------------------------*/

void
gpio_interrupt (void)
{



  /* Start the reg test tasks which test the context switching mechanism. */

  if (xTaskCreate (gpio_interrupt_task, "Reg2", 1024, NULL, 2, &pxCreatedTaskgpio))

    {
      vSendString ("gpio_interrupt_task created\n\r");
    }
//  if (xTaskCreate (three_led, "Reg2", 1024, NULL, 3, &pxCreatedTaskISR))
//
//    {
//      vSendString ("three_led task created\n\r");
//    }
//  if (xTaskCreate (dot_matrix_display, "Reg2", 1024, NULL, 2, &pxCreatedTaskISR))
//
//    {
//      vSendString ("led3 task created\n\r");
//    }

  /* Start the scheduler. */

  vTaskStartScheduler ();

  /* If all is well, the scheduler will now be running, and the following
   line will never be reached.  If the following line does execute, then
   there was insufficient FreeRTOS heap memory available for the Idle and/or
   timer tasks to be created.  See the memory management section on the
   FreeRTOS web site for more details on the FreeRTOS heap
   http://www.freertos.org/a00111.html. */

  for (;;)
    ;
}

//void pwmc_continuous_mode(UC channel_no,UC opc,UI period, UI on_offtime)
//{
//	UC rx = 0;
//	PWMC_Set_Period(channel_no,period);
//	PWMC_Set_OnOffTime(channel_no,on_offtime);
//	PWMC_init(channel_no,PWM_CONTINUOUS_MODE,PWM_LEFT_ALIGN,PWM_LOC_INTR_DIS,opc,PWM_REPEAT_COUNT);
//
//	PWMC_Enable();
//}
void gpio_intr_handler(void) {

	printf("External GPIO interrupt handler\n");
	// User can add their code for GPIO 0 interrupt.
	return;
}


static void
gpio_interrupt_task (void *pvParameters)
{
  US pin_data0 = 0;

  vSendString("\n\r ***************************************************************************");
  vSendString("\n\r INFO: Connect any sensor to GPIO 0 ");
  vSendString("\n\r ***************************************************************************");

 		pin_data0 = GPIO_read_pin(0); //for GPIO 0
 		irq_register_handler(GPIO_0_IRQ, gpio_intr_handler);

 		interrupt_enable(GPIO_0_IRQ);

 		while(1);



  vTaskDelete ( NULL);
}

