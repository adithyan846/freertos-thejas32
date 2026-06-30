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




/*
extern uint32_t     __sdata_load;
extern uint32_t     __sdata_start;
extern uint32_t     __sdata_end;

extern uint32_t     __data_load;
extern uint32_t     __data_start;
extern uint32_t     __data_end;

extern uint32_t     __sbss_start;
extern uint32_t     __sbss_end;
extern uint32_t     __bss_start;
extern uint32_t     __bss_end;


extern uint32_t	    __stack_bottom;
extern uint32_t	    __stack_top;
*/



/*
 * Called by main() to run the full demo (as opposed to the blinky demo) when
 * mainCREATE_SIMPLE_BLINKY_DEMO_ONLY is set to 0.
 */
void main_full( void );

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
static void prvRegTestTaskEntry1( void *pvParameters );
static void prvRegTestTaskEntry2( void *pvParameters );
static void prvRegTestTaskEntry3( void *pvParameters );
extern void vSendString( const char * const pcString );
void vToggleLED (void);

//extern const StackType_t xISRStackTop;
/*-----------------------------------------------------------*/

void main_full( void )
{
	/* Create the register check tasks, as described at the top of this	file.
	Use xTaskCreateStatic() to create a task using only statically allocated
	memory. */
	/*printf("__stack_bottom=%x\n\r",&__stack_bottom);
	printf("__stack_top=%x\n\r",&__stack_top);
	printf("__sdata_load=%x\n\r",&__sdata_load);
	printf("__sdata_start=%x\n\r",&__sdata_start);
	printf("__sdata_end=%x\n\r",&__sdata_end);

	printf("__data_load=%x\n\r",&__data_load);
	printf("__stack_top=%x\n\r",&__stack_top);
	printf("__stack_top=%x\n\r",&__stack_top);

	register int *stack_p asm ("sp");



	printf("stack_p=%x\n\r",stack_p);
	printf("*stack_p=%x\n\r",*stack_p);
	printf("xISRStackTop=%x",xISRStackTop);*/



	/* Start the reg test tasks which test the context switching mechanism. */
	/*xTaskCreate( prvRegTestTaskEntry1, "RegTst1", 1000, NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate( prvRegTestTaskEntry2, "RegTst2", 1000, NULL, tskIDLE_PRIORITY, NULL );*/


	//while(1);
	if (xTaskCreate( prvRegTestTaskEntry1, 		//	 The function that implements the task.
				 "Reg1", 						// The name of the task.
				 100, // Size of stack to allocate for the task - in words not bytes!.
				 NULL, // Parameter passed into the task.
				 3, 				// Priority of the task.
				 NULL ))			//Can be used to pass out a handle to the created task.
	  {
		vSendString("Task 1 Created \n\r");

	}
/*
	if (xTaskCreate( prvRegTestTaskEntry2, "Reg2", 100, NULL, 2, NULL )){
		vSendString("Task 2 Created \n\r");
	}
	if (xTaskCreate( prvRegTestTaskEntry3, "Reg3", 100, NULL, 1, NULL )){
			vSendString("Task 3 Created \n\r");
		}*/
	/* Start the scheduler. */
	vTaskStartScheduler();
	/* If all is well, the scheduler will now be running, and the following
	line will never be reached.  If the following line does execute, then
	there was insufficient FreeRTOS heap memory available for the Idle and/or
	timer tasks to be created.  See the memory management section on the
	FreeRTOS web site for more details on the FreeRTOS heap
	http://www.freertos.org/a00111.html. */


	for( ;; );
}
static void prvRegTestTaskEntry1( void *pvParameters )
{

  static TickType_t xNextWakeTime;

	 /*Although the regtest task is written in assembler, its entry point is
	written in C for convenience of checking the task parameter is being passed
	in correctly.*/

	xNextWakeTime = xTaskGetTickCount();
	//const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;

	while(1){




		vToggleLED();
		vTaskDelay(500);
		//vTaskDelayUntil(&xNextWakeTime, pdMS_TO_TICKS(1000));


		vSendString("Task 1 !\n\r");


		//taskYIELD();



	}
	/* The following line will only execute if the task parameter is found to
	be incorrect.  The check task will detect that the regtest loop counter is
	not being incremented and flag an error.*/
	vTaskDelete( NULL );
}
/*-----------------------------------------------------------*/

static void prvRegTestTaskEntry2( void *pvParameters )
{
  static TickType_t xNextWakeTime;
	 /*Although the regtest task is written in assembler, its entry point is
	written in C for convenience of checking the task parameter is being passed
	in correctly.*/

      xNextWakeTime = xTaskGetTickCount();

	while(1){


		vTaskDelayUntil(&xNextWakeTime, pdMS_TO_TICKS(2000));




		vSendString("Task 2 !\n\r");

		//taskYIELD();

	//	vTaskDelay(2000);

	}

	 /*The following line will only execute if the task parameter is found to
	be incorrect.  The check task will detect that the regtest loop counter is
	not being incremented and flag an error.*/
	vTaskDelete( NULL );
}


/*-----------------------------------------------------------*/
static void prvRegTestTaskEntry3( void *pvParameters )
{
  TickType_t xNextWakeTime;
	 /*Although the regtest task is written in assembler, its entry point is
	written in C for convenience of checking the task parameter is being passed
	in correctly.*/

      xNextWakeTime = xTaskGetTickCount();

	while(1){


		vTaskDelayUntil(&xNextWakeTime, pdMS_TO_TICKS(3000));



		vSendString("Task 3 !\n\r");
		//taskYIELD();


		//vTaskDelay(3000);


	 /*The following line will only execute if the task parameter is found to
	be incorrect.  The check task will detect that the regtest loop counter is
	not being incremented and flag an error.*/

	}
	vTaskDelete( NULL );
}
/*-----------------------------------------------------------*/

