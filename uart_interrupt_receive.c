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
#include "uart.h"

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
//#include "Uart_lib_new.h"

#define UART1_INTR_NUM 1

static BaseType_t xReturned;
volatile TaskHandle_t pxCreatedTaskuart;

volatile unsigned char USART_Rx_IndexT = 0, USART1_data_lengthT = 0, Uart_received_CompleteFlagT = 0, rx_countT = 0, Received_bufferT[500];
extern volatile unsigned char Rx_Databuffer[50];
//BaseType_t
//vSendPing (const char *pcIPAddress);

/* Called by main() to run the full demo (as opposed to the blinky demo) when
 * mainCREATE_SIMPLE_BLINKY_DEMO_ONLY is set to 0.
 */
void
uart_interrupt (void);

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
void uart_interrupt_receive_init (void);


//static void vHandlingTask( void *pvParameters);
extern void
vSendString (const char *const pcString);




/*-----------------------------------------------------------*/


//extern volatile int data_processsing;

//void pwmc_continuous_mode(UC channel_no,UC opc,UI period, UI on_offtime)
//{
//	UC rx = 0;
//	PWMC_Set_Period(channel_no,period);
//	PWMC_Set_OnOffTime(channel_no,on_offtime);
//	PWMC_init(channel_no,PWM_CONTINUOUS_MODE,PWM_LEFT_ALIGN,PWM_LOC_INTR_DIS,opc,PWM_REPEAT_COUNT);
//
//	PWMC_Enable();
//}





//
//void uart1_intr_handler(void) {
//
//  volatile unsigned char status, error, data;
//
//  	status = UartReg(UART_1).UART_IIR_FCR; // clearing interrupt
//  	data =   UartReg(UART_1).UART_DR;
//        //uart_getchar(UART_1, &error);   // reading data
//
//
//  	if(data == 0xE5)
//	{
//		USART_Rx_IndexT = 0;
//		//rx_countT = 0;
//
//	}
//	Received_bufferT[USART_Rx_IndexT] = data ;
//	if( USART_Rx_IndexT == 0x01)
//	{
//
//		USART1_data_lengthT = data;
//
//	}
//	if(Received_bufferT[0] == 0xE5)
//	{
//		USART_Rx_IndexT++;
//	}
//	if( ( USART1_data_lengthT == USART_Rx_IndexT ) && (Received_bufferT[0] == 0xE5) )
//	{
//
//
//		//printf("\n\r OK-Rx packet ISR-");
//
////		register void* sp __asm__("sp"); // Declare a register variable bound to `sp`
////		  printf("\n\r isr Stack Pointer (sp) = %p\n", sp);
////
////
////		  register void* gp __asm__("gp"); // Declare a register variable bound to `gp`
////		  printf("\n\ isr global Pointer (gp) = %p\n", gp);
//		for(unsigned char i=0;i<USART1_data_lengthT;i++)
//		{
//		    Rx_Databuffer[i]	=	Received_bufferT[i];
//			//printf(":%x", Rx_Databuffer[i]);
//		}
//		//printf("\n\r InterUart_received_CompleteFlag is -%x",Uart_received_CompleteFlag);
//		//USART1_data_length = 0;
//		//USART_Rx_Index = 0;
//		//SmarcPktReceiveFlag = 1;
//		Uart_received_CompleteFlagT = 1;
//	}
//	else
//	{
//
//	}
//
//  	return;
//}


static uint8_t rx_index = 0;
static uint8_t rx_length = 0;
static enum { WAIT_FOR_HEADER, WAIT_FOR_LENGTH, WAIT_FOR_DATA } rx_state = WAIT_FOR_HEADER;

void uart1_intr_handler(void) {

  volatile unsigned char status, error, data;

    	//status = UartReg(UART_1).UART_IIR_FCR; // clearing interrupt


    //	printf("data=%x\n\r",data);


    while(1)
      {
	  if( UartReg(UART_1).UART_LSR & 0x01)
	  data =   UartReg(UART_1).UART_DR;

	  else
	    continue;

    switch (rx_state) {
        case WAIT_FOR_HEADER:
            if (data == 0xE5) {
                Received_bufferT[0] = data;

                rx_index = 1;
                rx_state = WAIT_FOR_LENGTH;
            }
            break;

        case WAIT_FOR_LENGTH:
            rx_length = data; // store packet length
            Received_bufferT[rx_index++] = data;
            rx_state = WAIT_FOR_DATA;
            break;

        case WAIT_FOR_DATA:
            Received_bufferT[rx_index++] = data;
            if (rx_index == rx_length) {
                // packet complete
                for (uint8_t i = 0; i < rx_length; i++) {
                    Rx_Databuffer[i] = Received_bufferT[i];
                }
                Uart_received_CompleteFlagT = 1;

                // reset state
                rx_state = WAIT_FOR_HEADER;
                rx_index = 0;
                rx_length = 0;
            }
            break;
    }

	if(Uart_received_CompleteFlagT)
	  break;

      }
}










void
uart_interrupt_receive_init (void )
{
  //uart_set_baud_rate(UART_1, 9600, 100000000); // initializing uart0
  uart_set_baud_rate(UART_1, 115200, 100000000); // initializing uart0
  	//printf("+------[ uart%d in interrupt mode ]------+\n", UART_1);

  	interrupt_enable(UART1_INTR_NUM); //Enable interrupt in controller.
  	irq_register_handler(UART1_INTR_NUM, uart1_intr_handler);
  	uart_intr_enable(UART_1, TX_DISABLE, RX_ENABLE); // enabling uart0 interrupt
	//UartReg(UART_1).UART_IIR_FCR = 1;
  	//printf("\nStart typing anything on uart%d.\n\n", UART_1);

  	USART_Rx_IndexT = 0;
  	USART1_data_lengthT = 0;
  	Uart_received_CompleteFlagT = 0;
  	rx_countT = 0;
  		///* idle loop */
  		//while (1);

  //vTaskDelete ( NULL);
}

