 /*
 * mq3_gas_sensor.c
 *
 *  Created on: 24-Aug-2022
 *      Author: Saurav
 */


/*
 * FreeRTOS Kernel V10.4.1
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
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
 * NOTE 1:  This project provides two demo applications.  A simple blinky
 * style project, and a more comprehensive test and demo application.  The
 * mainCREATE_SIMPLE_BLINKY_DEMO_ONLY setting in main.c is used to select
 * between the two.  See the notes on using mainCREATE_SIMPLE_BLINKY_DEMO_ONLY
 * in main.c.  This file implements the simply blinky style version.
 *
 * NOTE 2:  This file only contains the source code that is specific to the
 * blinky demo.  Generic functions, such FreeRTOS hook functions, and functions
 * required to configure the hardware are defined in main.c.
 ******************************************************************************
 *
 * main_blinky() creates one queue, and two tasks.  It then starts the
 * scheduler.
 *
 * The Queue Send Task:
 * The queue send task is implemented by the prvQueueSendTask() function in
 * this file.  prvQueueSendTask() sits in a loop that causes it to repeatedly
 * block for 1000 milliseconds, before sending the value 100 to the queue that
 * was created within main_blinky().  Once the value is sent, the task loops
 * back around to block for another 1000 milliseconds...and so on.
 *
 * The Queue Receive Task:
 * The queue receive task is implemented by the prvQueueReceiveTask() function
 * in this file.  prvQueueReceiveTask() sits in a loop where it repeatedly
 * blocks on attempts to read data from the queue that was created within
 * main_blinky().  When data is received, the task checks the value of the
 * data, and if the value equals the expected 100, toggles an LED.  The 'block
 * time' parameter passed to the queue receive function specifies that the task
 * should be held in the Blocked state indefinitely to wait for data to be
 * available on the queue.  The queue receive task will only leave the Blocked
 * state when the queue send task writes to the queue.  As the queue send task
 * writes to the queue every 1000 milliseconds, the queue receive task leaves
 * the Blocked state every 1000 milliseconds, and therefore toggles the LED
 * every 200 milliseconds.
 */

/* Standard includes. */
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
//#include "stdlib.h"
//#include "gpio.h"
//#include "led.h"
#include "i2c.h"
#include "SFE_BMP180.h"
#include "stdlib.h"
#include "config.h"
#include "interrupt.h"
#include "math.h"



/* Priorities used by the tasks. */

#define mainQUEUE_RECEIVE_TASK_PRIORITY		( tskIDLE_PRIORITY + 2 )
#define	mainQUEUE_SEND_TASK_PRIORITY		( tskIDLE_PRIORITY + 1 )

#define GPIO_19_IRQ					19

/* The rate at which data is sent to the queue.  The 200ms value is converted
to ticks using the pdMS_TO_TICKS() macro. */
#define mainQUEUE_SEND_FREQUENCY_MS			pdMS_TO_TICKS(1000)

/* The maximum number items the queue can hold.  The priority of the receiving
task is above the priority of the sending task, so the receiving task will
preempt the sending task and remove the queue items each time the sending task
writes to the queue.  Therefore the queue will never have more than one item in
it at any time, and even with a queue length of 1, the sending task will never
find the queue full. */
#define mainQUEUE_LENGTH					( 1 )

/*-----------------------------------------------------------*/

/*
 * Called by main when mainCREATE_SIMPLE_BLINKY_DEMO_ONLY is set to 1 in
 * main.c.
 */
void gas_detector( void );
void Led_on(void);
void ads1015Begin(unsigned char);
uint16_t ads1015ReadSingleEnded(uint8_t);
void vSendString( const char * const pcString );
//void main_blinky( void );

/*
 * The tasks as described in the comments at the top of this file.
 */
//static void prvQueueReceiveTask( void *pvParameters );
//static void prvQueueSendTask( void *pvParameters );
//static void Interrupt_function( void *pvParameters );
static void periodic_function( void * pvParameters );
//void i2c_read_blocking(uint8_t * rd_buff, uint8_t len);


/*-----------------------------------------------------------*/

/* The queue used by both tasks. */
//static QueueHandle_t xQueue = NULL;

//Semaphore_handle_t SemaphoreTask = 0 ;





/*-----------------------------------------------------------*/
extern const uint32_t uxTimerIncrementsForOneTick;
//#include "adc.h"

/**
 @file MQ3_gas_sensor_demo.c
 @brief Contains routines for Read all ADC channel values and display it via UART
 */

int threshold = 750; //Please change the threshold according to the sensor

/**
 * @brief Read all ADC channel values and display it via UART..
 * @details
 * @param[in] No input parameter
 * @param[Out] No output parameter
*/

void gpio_intr_handler(void)
{




	//BaseType_t xHigherPriorityTaskWoken;

	//xHigherPriorityTaskWoken = pdFALSE;




	/*double T=0, P=0;
	UC status = 0;
	getTemperature(&T); // init reading temperature
	printf("\n\r Temperature = %f ", T);



	getPressure(&P, T); // init reading pressure
	printf("\n\r Pressure = %f ", P);

	//status = I2CReg(1).I2C_SR1;
	printf("in ISR\n\r");
	//i2c_data_read(I2C_1_IRQ, *read_data, 8);
	I2C_enable_intr(I2C_1, 0, 0);
	//interrupt_disable(I2C_1_IRQ);*/

	/*BaseType_t xHigherPriorityTaskWoken;
	xHigherPriorityTaskWoken = pdFALSE;
*/
       //printf("before  xHigherPriorityTaskWoken=%d\n\r ", xHigherPriorityTaskWoken);

      /*The transfer is completed so give the semaphore
      xSemaphoreGiveFromISR(SemaphoreTask, NULL);
      Context switch if higher priority task is blocking on the semaphore*/
	  //portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

	  //while(GPIO_read_pin(0)==1)
	    //{

	      //for(int i=0; i< 0xA7D8C0;i++);
	    //  printf("In ISR\n\r");
	    //}
		printf("In ISR\n\r");
		interrupt_disable(GPIO_0_IRQ);

	     // xSemaphoreGiveFromISR(SemaphoreTask, NULL);



	  //printf("after interrupt_disable\n\r");

	 // xSemaphoreGiveFromISR(get, xHigherPriorityTaskWoken );

	/*  printf("after interrupt xHigherPriorityTaskWoken=%d\n\r ", xHigherPriorityTaskWoken);
	  portYIELD_FROM_ISR(xHigherPriorityTaskWoken);*/



	  //I2C_enable_intr(I2C_1, 0, 0);


     }

void gas_detector(void)
{



     //printf("1");

   //  begin(); // init

    // printf("I2C initialized\n\r");


     //while(1)
       //{

/*
	    startPressure(0);
            startTemperature();*/


              // Select mode 0-3

            //usleep(1000000);

     //interrupt_enable(I2C_1_IRQ);


     // vSemaphoreCreateBinary(SemaphoreTask);

    xTaskCreate( periodic_function, "Reg2", 2048, NULL, 2, NULL );
    //xTaskCreate( Interrupt_function, "Reg2", 1000, NULL, 3, NULL );

    vTaskStartScheduler();

  /*US pin_data0 = 0;

 		printf("\n\r ***************************************************************************");
 		printf("\n\r INFO: Connect any sensor to GPIO 0 ");
 		printf("\n\r ***************************************************************************");

 		pin_data0 = GPIO_read_pin(0); //for GPIO 0
 		irq_register_handler(GPIO_0_IRQ, gpio_intr_handler);

 		interrupt_enable(GPIO_0_IRQ);
 		while(1)
 		  {
 		printf("in main\n\r");
 		  }*/

      for(;;);
  //}
}

static void periodic_function(void * parameter){



  static TickType_t xNextWakeTime;
  xNextWakeTime = xTaskGetTickCount();




		US pin_data0 = 0;
      		pin_data0 = GPIO_read_pin(0);

      		printf("pin data = %d\n\r",pin_data0);
      		irq_register_handler(GPIO_0_IRQ, gpio_intr_handler);


      		//vTaskDelay(1000);
        //printf("About to generate SW interrupt\n\r" );




  		//xSemaphoreTake( SemaphoreTask, 0 );
      	     printf("2");



      		/*irq_register_handler(GPIO_0_IRQ, gpio_intr_handler);
      		interrupt_enable(GPIO_0_IRQ);*/

        for(;;)
            {
			//xSemaphoreTake( SemaphoreTask, 0 );

			    vTaskDelayUntil(&xNextWakeTime, pdMS_TO_TICKS(500));
        		// To get here the event must have occurred. Process the event.





			      	    // printf("3");




			      	     //printf("4");

				interrupt_enable(GPIO_0_IRQ);

			      	    // printf("5");


                  		//printf( "Handler task ->> Processing event.rn\n\r" );





            }

        //printf("out of the periodic_function\n\r");
       // vTaskDelete( NULL );
  }


/*static void Interrupt_function(void *pvParameters)
{
		 //for GPIO 0
  TickType_t xNextWakeTime;
    xNextWakeTime = xTaskGetTickCount();

		while(1)
		    {
		// Use the semaphore to wait for an event.
		        if (xSemaphoreTake( SemaphoreTask, 1000 ) == pdTRUE)
		        //{
		// To get here the event must have occurred. Process the event.

		          //  printf( "got interrupt\n\r" );
		        //}
		        //else
		          vTaskDelayUntil(&xNextWakeTime, pdMS_TO_TICKS(2000));
		          printf("Back in interrupt_function\n\r");
		    }
		vTaskDelete( NULL );
}*/



/*freertos_i2c_rd_task( void * pvParameters ) {
    //uint8_t data_buff[10];

     Create binary semaphore
    //uint8_t data_buff[10];
    i2c_sem = xSemaphoreCreateBinary();
     Here an initialization of the I2C driver can be perfomed
      begin();



    while (1) {
      //  i2c_read_blocking(I2C_SLV_ADDR, &data_buff, 2);
         Wait for 1s and repeat the I2C read transfer
        //vTaskDelay( 1000/portTICK_PERIOD_MS );


	     interrupt_enable(I2C_1_IRQ);

	     irq_register_handler(I2C_1_IRQ, intr_I2C_handler);

	     I2C_enable_intr(I2C_1, 1, 0);

	     printf("main over\n\r");

	     xSemaphoreTake(i2c_sem, 1000);



    }
}*/

/*
void i2c_read_blocking(uint8_t slv_addr, uint8_t * rd_buff, uint8_t len) {

     Configure I2C peripheral for I2C read transfer
     Enable I2C interrupts
      interrupt_enable(I2C_1_IRQ);
      irq_register_handler(I2C_1_IRQ, intr_I2C_handler);
      I2C_enable_intr(I2C_1, 1, 0);

     Start transfer


     Block (wait) on semaphore
    xSemaphoreTake(i2c_sem, portMAX_DELAY);
    Get the received data from I2C HW fifo buffer
    for (int i=0; i<len;i++) {
      rd_buff[i] = I2C_DATA_REG;
    }
}

*/

