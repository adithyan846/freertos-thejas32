/***********************************************************************************
 * FILE ID 		: Main.c
 * VERSION NUMBER 	: 1.0.0
 * PROJECT CODE 	: ITS04T
 * PROJECT NAME 	: Test FreeRTOS- for Universal Traffic Control System CUTE Adv
 * ARCHITECT            : Hemant
 * DESIGNER             :
 * AUTHOR 	     	: Hemant
 * DATE OFLAST UPDATION : 05.11.2022
 * DESCRIPTION 		:
 ************************************************************************************/

/* FreeRTOS kernel includes. */
//#include <FreeRTOS.h>
//#include <task.h>
/* thejas64 includes. */
#include "uart.h"

#include "gpio.h"
#include "led.h"
#include "stdlib.h"

#include "adc.h"
#include "i2c.h"
#include "interrupt.h"
#include "spi.h"
#include "at25sf161.h"

////////////////////////////////////////////////////////////
/* Standard includes. */

#include <stdio.h>
#include <string.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "semphr.h"

/* thejas64 incldues. */
//#include "riscv_hal.h"

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

#include "stdlib.h"
#include "pwmc.h"
//#include "i2c.h"
#include "config.h"
//#include "gpio.h"






/////////////////////////////////////////////////////////////////////////
#define mainCREATE_DEMO_ONLY	0
#define mainHART_0 		0

//Prototypes for the standard FreeRTOS callback/hook  https://www.freertos.org/a00016.html
void
vApplicationMallocFailedHook (void);
void
vApplicationIdleHook (void);
void
vApplicationStackOverflowHook (TaskHandle_t pxTask, char *pcTaskName);
void
vApplicationTickHook (void);

static void
prvSetupHardware (void);	//Prepare haredware to run the demo.
/* Send a messaage to the UART initialised in prvSetupHardware. */

//void Init_uart(void);
void
vSendString (const char *const pcString);
void
Transmit_uart (UC*);


#define mainCHECK_TASK_PRIORITY  (tskIDLE_PRIORITY+3)

//extern volatile uint64_t * pullMachineTimerCompareRegister ;

extern uint64_t ullNextTime;
extern volatile uint32_t *pullMachineTimerCompareRegister;
extern volatile uint32_t *pullMachineTimerCompareRegisterMSB;

extern const uint32_t uxTimerIncrementsForOneTick;

void
vPortSetupTimerInterrupt (void)
{
  pullMachineTimerCompareRegister = (volatile uint32_t* const ) ( configMTIMECMP_BASE_ADDRESS);
  //uint64_t ulCurrentTime;
  //volatile uint64_t *const pulTime = (volatile uint64_t* const ) ( configCLINT_BASE_ADDRESS + 0x580);

  uint32_t ulCurrentTimeHigh, ulCurrentTimeLow;

  volatile uint32_t *const pulTimeHigh = (volatile uint32_t* const ) (( configMTIME_BASE_ADDRESS) + 4UL); //8-byte typer so high 32-bit word is 4 bytes up.
  volatile uint32_t *const pulTimeLow = (volatile uint32_t* const ) ( configMTIME_BASE_ADDRESS);

  volatile uint32_t *const pulTimeCmpHigh = (volatile uint32_t* const ) (( configMTIMECMP_BASE_ADDRESS) + 4UL); //8-byte typer so high 32-bit word is 4 bytes up.
  volatile uint32_t *const pulTimeCmpLow = (volatile uint32_t* const ) ( configMTIMECMP_BASE_ADDRESS);
  //pullMachineTimerCompareRegister = (volatile uint32_t*) ( configMTIMECMP_BASE_ADDRESS);
  // Prepare the time to use after the next tick interrupt.
  do
    {
      ulCurrentTimeHigh = *pulTimeHigh;
      ulCurrentTimeLow = *pulTimeLow;
    }
  while (ulCurrentTimeHigh != *pulTimeHigh);
  ullNextTime = (uint64_t) ulCurrentTimeHigh;
  ullNextTime <<= 32ULL;  //High 4-byte word is 32-bits up.
  ullNextTime |= (uint64_t) ulCurrentTimeLow;
  //printf ("1 val of uxTimerIncrementsForOneTick %d, currentTime %ld\n", uxTimerIncrementsForOneTick, ullNextTime);
  ullNextTime += (uint64_t) uxTimerIncrementsForOneTick;
  *pulTimeCmpHigh = (uint32_t) (ullNextTime >> 32ULL);
  *pulTimeCmpLow = (uint32_t) ullNextTime;
  ullNextTime += (uint64_t) uxTimerIncrementsForOneTick;
  // printf ("2 val of uxTimerIncrementsForOneTick %d, ullNextTime %ld\n", uxTimerIncrementsForOneTick, ullNextTime);
  //printf ("uint64_t %d\n", sizeof(uint64_t));
}


static void TestTask1 (void *pvParameters);
static void TestTask2 (void *pvParameters);
static void TestTask3 (void *pvParameters);

extern void
vSendString (const char *const pcString);
unsigned char task1_stat = 0, task2_stat = 0, task3_stat = 0;
extern void
vToggleLED (void);



int
main (void)
{
  prvSetupHardware ();
  vSendString ("Thejas32 FreeRTOS Demo\n\r");

  if (xTaskCreate (TestTask1, "Reg1", configMINIMAL_STACK_SIZE, NULL, mainCHECK_TASK_PRIORITY, NULL))
    {
        vSendString ("EEPROM_Task Created \n\r");
    }

  if (xTaskCreate (TestTask2, "Reg2", configMINIMAL_STACK_SIZE, NULL, mainCHECK_TASK_PRIORITY, NULL))
    {
        vSendString ("To control SPI lines \n\r");
    }

  if (xTaskCreate (TestTask3, "Reg3", configMINIMAL_STACK_SIZE, NULL, mainCHECK_TASK_PRIORITY, NULL))
    {
        vSendString ("To control WDT \n\r");
    }


  /* Start the scheduler. */
  vTaskStartScheduler ();
  for (;;)
    ;
}


static void
prvSetupHardware (void)
{

  //PLIC_init();
  //Init_uart();
  interrupt_disable_all ();
  disable_irq ();
  // GPIO_write_pin(25, 1);
  //  GPIO_write_pin(20, 1);
  //Initialization();
  // ullNextTime = 0ULL;		// Used to program the machine timer compare register.
  //GPIO_write_pin(GPIOI2CSW, LOW);

  vSendString ("UART [OK]\n\r");
}

/*------------------------------------------------------------*/



static void
TestTask1 (void *pvParameters)
{

     static TickType_t xNextWakeTime;

     int task1_time = 0;
     while(1)
     {

         vSendString("Task 1 !\n\r");
         vTaskDelay(pdMS_TO_TICKS(2000));
     }
      vTaskDelete( NULL );

}

static void
TestTask2 (void *pvParameters)
{

      int task2_time = 0;

      while(1)
      {
  	vSendString("Task 2 !\n\r");
  	vTaskDelay(pdMS_TO_TICKS(2000));
      }
      vTaskDelete( NULL );
}

static void
TestTask3 (void *pvParameters)
{

     int task3_time = 0;

      while(1)
      {
  	vSendString("Task 3 !\n\r");
  	vTaskDelay(pdMS_TO_TICKS(3000));
      }
      vTaskDelete( NULL );
}





/*-----------------------------------------------------------*/
void
vSendString (const char *const pcString)
{
  Transmit_uart ((char*) pcString);
}

/*-----------------------------------------------------------*/

void
vApplicationMallocFailedHook (void)
{
  /* vApplicationMallocFailedHook() will only be called if
   configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
   function that will get called if a call to pvPortMalloc() fails.
   pvPortMalloc() is called internally by the kernel whenever a task, queue,
   timer or semaphore is created.  It is also called by various parts of the
   demo application.  If heap_1.c or heap_2.c are used, then the size of the
   heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
   FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
   to query the size of free heap space that remains (although it does not
   provide information on how the remaining heap might be fragmented). */
  vSendString ("@ ApplicationMallocFailedHook\n\r");
  taskDISABLE_INTERRUPTS();
  __asm volatile( "ebreak" );
  for (;;)
    ;
}
/*-----------------------------------------------------------*/

void
vApplicationIdleHook (void)
{
  //vSendString("\r @ vApplicationIdleHook\n\r");
  /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
   to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
   task.  It is essential that code added to this hook function never attempts
   to block in any way (for example, call xQueueReceive() with a block time
   specified, or call vTaskDelay()).  If the application makes use of the
   vTaskDelete() API function (as this demo application does) then it is also
   important that vApplicationIdleHook() is permitted to return to its calling
   function, because it is the responsibility of the idle task to clean up
   memory allocated by the kernel to any task that has since been deleted. */
}
/*-----------------------------------------------------------*/

void
vApplicationStackOverflowHook (TaskHandle_t pxTask, char *pcTaskName)
{
  (void) pcTaskName;
  (void) pxTask;

  printf ("stack overflow %x %s\r\n", pxTask, (portCHAR*) pcTaskName);
  vSendString ("@ vApplicationStackOverflowHook\n\r");
  //printf("taskname =%s\n\r",pcTaskName);
  /* Run time stack overflow checking is performed if
   configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
   function is called if a stack overflow is detected. */
  taskDISABLE_INTERRUPTS();
  //  __asm volatile( "ebreak" );
  for (;;)
    ;
}
/*-----------------------------------------------------------*/

void
vApplicationTickHook (void)
{
  vSendString ("@ vApplicationTickHook\n\r");
  /* The tests in the full demo expect some interaction with interrupts. */
}




