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

#include "ads1015.h"
#include "i2c_api.h"
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

#include "CommonDb.h"
#include "stdlib.h"
#include "main.h"
#include "pwmc.h"
//#include "i2c.h"
#include "config.h"
//#include "gpio.h"

#include "CommonDb.h"
#include "main.h"


/////////////////////////////////////////////////////////////////////////
#define mainCREATE_DEMO_ONLY	5
#define mainHART_0 		0

#define I2C_FREQ 200000 //200KHz   //400000  400KHz

#define ADDRESS_PCF1_LAMP1TO16		0x20
#define ADDRESS_PCF2_LAMP17TO32		0x22
#define ADDRESS_PCF3_LAMP33TO48		0x24
#define ADDRESS_PCF4_LAMP49TO64		0x26

#define ADDRESS_PCF1_FEEDBACK1TO16	0x21
#define ADDRESS_PCF2_FEEDBACK17TO32	0x23
#define ADDRESS_PCF3_FEEDBACK33TO48	0x25
#define ADDRESS_PCF4_FEEDBACK49TO64	0x27

#define GPIO_BASE_ADDR  0x10080000  // Replace with actual base address

#define GPIOI2CSW 15
#define GPIOWDT 10
#define GPIOWDTLD 14

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

extern volatile unsigned char USART_Rx_Index, USART1_data_length, Uart_received_CompleteFlag;
extern volatile unsigned char status, error, data;

extern unsigned short LampSwitchDatapac[8],SMARCCommtoVEGAContinuous;
extern unsigned char LampflashSelection, RxFlashPattBufSavetoEEPROM[19];
extern unsigned char StagePatternreceivedOKFlag;  //for receive first pattern
extern unsigned char LDsense;
unsigned char LampflashSelectionswitchcount = 0, LampFeedbackPingEnableReadRdDne = 0, LDCWriteI2Ccount125 = 0, RxFlashPattReadfromEEPROM[18];
unsigned short Lamppatterndummy = 0x0203;

extern unsigned char Save_Pattern_Flash, Junction_ID, Last_Uart_received_CompleteFlag;
extern unsigned char Lamp_switching_flag, LampFBReadFlag, Switch_Type_Flash, Ack_Lamp_Feedback_Flag,
    Rx_New_Pattern_Flag;

extern unsigned char StartFeedbackFlag;  //currentspi_val,
//US currentChipSelectGPIO;
extern unsigned short previousADCDATA, currentADCDATA, Last_Chk_LampStatus;

extern volatile int rx_flag, rx_count;

extern volatile unsigned char rx_buffer[100];
extern volatile unsigned char USART_Rx_IndexT, Uart_received_CompleteFlagT;
//unsigned char PacketType, halfsec_sw_flag = 0, LDCSwitchDelay = 0;

static void vgpiointTask (void *pvParameters);
static void vEepromTask (void *pvParameters);
static void vI2CSPITask (void *pvParameters);
static void vWDTTask (void *pvParameters);
//static void vSPITask (void *pvParameters);
//static void TestTask2( void *pvParameters );
//static void TestTask3( void *pvParameters );
extern void
vSendString (const char *const pcString);
unsigned char task1_stat = 0, task2_stat = 0, task3_stat = 0;
extern void
vToggleLED (void);
//extern const StackType_t xISRStackTop;
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

//extern volatile int data_processsing;


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

  uart_interrupt_receive_init ();

  vSendString ("UART [OK]\n\r");
}

/*------------------------------------------------------------*/

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







void pwmc_continuous_mode(UC channel_no,UC opc,UI period, UI on_offtime)
{
	UC rx = 0;
	PWMC_Set_Period(channel_no,period);
	PWMC_Set_OnOffTime(channel_no,on_offtime);
	PWMC_init(channel_no,PWM_CONTINUOUS_MODE,PWM_LEFT_ALIGN,PWM_LOC_INTR_DIS,opc,PWM_REPEAT_COUNT);

	PWMC_Enable();
}

void i2c_Write2Byte(unsigned char i2c_num, unsigned char Slave_Address_Wr, unsigned short WBdata)
{
	unsigned char Word_addr_MSB = (WBdata >> 8) & 0xFF;
	unsigned char Word_addr_LSB = (WBdata) & 0xFF;

	while (1) {
		i2c_start(i2c_num, 0x00, I2C_WRITE);

		if (i2c_data_write(i2c_num, &Slave_Address_Wr, 01)) { //writes slave address

			continue; //received NACK
		}
		//printf("\n\rLDC 1 Write Start1");
		if (i2c_data_write(i2c_num, &Word_addr_LSB, 01)) { //writes data

			continue; //received NACK
		}
		//printf("\n\rLDC 1 Write Start2");
		if (i2c_data_write(i2c_num, &Word_addr_MSB, 01)) { //writes data

			continue; //received NACK
		}

		i2c_stop(i2c_num);
		break;

	}
}

void i2c_Read2Byte(unsigned char i2c_num, unsigned char Slave_Address_Rd, unsigned int LDCidFB_Number)
{

	unsigned char rxd_dataValid0 = 0, rxd_dataValid1 = 0;
	//unsigned short rxd_dataout = 0;

	while (1)
	{
		i2c_start(i2c_num, 0x02, I2C_READ); //start sequence for reading data
		if (i2c_data_write(i2c_num, &Slave_Address_Rd, 01))
		{
			continue; //received NACK
		}
		i2c_data_read(i2c_num, &rxd_dataValid0, 01);
		i2c_data_read(i2c_num, &rxd_dataValid1, 01);
		i2c_stop(i2c_num);
		usleep(1000);
		i2c_start(i2c_num, 0x02, I2C_READ); //start sequence for reading data
		if (i2c_data_write(i2c_num, &Slave_Address_Rd, 01))
		{
			continue; //received NACK
		}
		i2c_data_read(i2c_num, &rxd_dataValid0, 01);
		i2c_data_read(i2c_num, &rxd_dataValid1, 01);
		LampFBDataSendtoSMARCCon[LDCidFB_Number] = (~((rxd_dataValid1 << 8 ) | rxd_dataValid0));

		//printf("\n\rAddress :%x  Data is %x:%x ::: %x", Slave_Address_Rd, rxd_dataValid0,rxd_dataValid1, 						LampFBDataSendtoSMARC[LDCidFB_Number]);

		if((LampFBDataSendtoSMARCConLast[LDCidFB_Number] == LampFBDataSendtoSMARCCon[LDCidFB_Number]) && 									(LampFBDataSendtoSMARCConCount[LDCidFB_Number] == 3))
		{
			LampFBDataSendtoSMARCConCount[LDCidFB_Number] = 0;
			LampFBDataSendtoSMARC[LDCidFB_Number] = LampFBDataSendtoSMARCConLast[LDCidFB_Number];
		}

		if(LampFBDataSendtoSMARCConLast[LDCidFB_Number] == LampFBDataSendtoSMARCCon[LDCidFB_Number])
		{
			LampFBDataSendtoSMARCConCount[LDCidFB_Number] = LampFBDataSendtoSMARCConCount[LDCidFB_Number] + 1;
		}
		else
		{
			LampFBDataSendtoSMARCConCount[LDCidFB_Number] = 0;
			LampFBDataSendtoSMARCConLast[LDCidFB_Number] = LampFBDataSendtoSMARCCon[LDCidFB_Number];
		}
		i2c_stop(i2c_num);
		break;
	}
}










static void
vEepromTask (void *pvParameters)
{
  //static TickType_t xNextWakeTime;
  //xNextWakeTime = xTaskGetTickCount();
  // static uint8_t writeData[256], readData[512];
  int task1_time = 0;

  //printf ("\n\rIntensity setting");
  //pwmc_continuous_mode(PWM_CH_3,PWM_OPC_LOW,800000,100000); //8ms :1ms
  //pwmc_continuous_mode(PWM_CH_3,PWM_OPC_LOW,600000,150000); //6ms:1.5ms
  //pwmc_continuous_mode(PWM_CH_3,PWM_OPC_LOW,1200000,300000); //12ms:3ms
  //pwmc_continuous_mode(PWM_CH_3,PWM_OPC_LOW,1200000,1200000);
 // printf ("\n\r Malfunction management unit");
  //printf ("\n\rIntensity setting Completed");
  rx_flag = 0;
  rx_count = 0;

  USART_Rx_Index = 0;
  USART1_data_length = 0;
  Uart_received_CompleteFlag = 0;
  status = 0;
  error = 0;
  data = 0;
  Lamp_UART_SendFlag = 0;
  Save_Pattern_Flash = 0;
  Junction_ID = 1;
  Last_Uart_received_CompleteFlag = 0;
  Lamp_switching_flag = 0;
  Switch_Type_Flash = 0;
  Ack_Lamp_Feedback_Flag = 0;
  Rx_New_Pattern_Flag = 0;
  Last_halfsec_sw_flag = 0;
  Cnt_Delay_1ms = 0;
  multiWrite_rtn = 0;

  //currentspi_val = 0;
  LampFBReadFlag = 0;
  StartFeedbackFlag = 1;
  //currentChipSelectGPIO = 0;
  previousADCDATA = 0;
  currentADCDATA = 0;
  Last_Chk_LampStatus = 0;


		static uint8_t writeData[20], readData[20];
		// Initialize the EEPROM
         	at25sf161Begin(MDP_SPI_3);
         	//at25sf161ChipErase(); // Complete erase chip


         	// Read data from eeprom
         	at25sf161ReadEeprom(readData, 18, 0x0);
         	//printf("\n at25sf161 read data :");
         	for (int i = 0; i < 18; i++)
         	{

         	    if((readData[0] > 0) && (readData[0] <= 4) && (readData[17] == 0xAA))
         	      {
         		RxFlashPattReadfromEEPROM[i] = readData[i];  //read data for flash switch
         		//printf("%02x :: %02x :", readData[i], RxFlashPattReadfromEEPROM[i]);
         	      }
         	    else
         	      {
         		RxFlashPattReadfromEEPROM[i] = 0xFF;
         	      }
         	}
         	//printf("\n");

         	// Erase first 64K block
         	//at25sf161BlockErase(0x0, ERASE_64K);


  while (1)
    {
     // vTaskDelay(pdMS_TO_TICKS(200)); // Sleep for 1 second (prevents CPU blocking)
      //Uart_received_CompleteFlagT = 1;
      //USART_Rx_IndexT = 8;


      SMARCRxUART_PacketValidation ();
      //printf("\n\r application Run");
     // interrupt_enable(1);


      //interrupt_enable(1);

      if (Lamp_UART_SendFlag == 1)
	{
	  Lamp_UART_SendFlag = 0;
	  Send_Acknowledgement_WithLampCurrent_ToSMARC ();
	  //usleep(1000);    //50000
	  vTaskDelay (1);
	}
	if(Save_Pattern_Flash == 1)
	  {
	    Save_Pattern_Flash = 0;
	  //  printf("\n\rFlash Pattern Received successfully");
	    //at25sf161Begin(MDP_SPI_3);
	   // at25sf161ChipErase(); // Complete erase chip
	    // Generate data for writing
	    for (int i = 1; i < 17; i++)
	    {
		    writeData[i] = RxFlashPattBufSavetoEEPROM[i];
	    }
	    writeData[0] = RxFlashPattBufSavetoEEPROM[0];
	    writeData[17] = 0xAA;
	    // Write data to EEPROM
	   // at25sf161WriteEeprom(writeData, 18, 0x0);	 // Writing to Page 1


	    //at25sf161WriteEeprom(writeData, 256, 0x100); // Writing to Page 2

	    // Read data from eeprom
	    //at25sf161ReadEeprom(readData, 18, 0x0);
	  //  printf("\n at25sf161 read data :");
	    for (int i = 0; i < 18; i++)
	    {
		//printf("%02x ", readData[i]);
	    }

	  }

      /*if (CurrentReadingFlag == 1)
	{
	  CurrentReadingFlag = 0;
	  //Send_Acknowledgement_WithLampFeedback_ToSMARC ();
	  Send_Acknowledgement_WithLampFBBytes_ToSMARC ();
	  //usleep(1000);   //100000
	  vTaskDelay (1);
	  if (halfsec_sw_flag == 1)
	    {
	      halfsec_sw_flag = 0;
	      Lamp_UART_SendFlag = 1;
	    }
	  //Send_Acknowledgement_WithLampFBBytes_ToSMARC ();
	  //usleep(20000);
	}
      if (Cnt_Delay_1ms >= 2400)  // 1 min
	{
	  Cnt_Delay_1ms = 0;
	  halfsec_sw_flag = 1;  //halfsec_sw_flag + 1;
	  //printf("\n\r  N= %d", halfsec_sw_flag);
	}
      else
	{
	  Cnt_Delay_1ms++;
	  //printf("\n\r  Nx= %d", Cnt_Delay_1ms);
	}*/
      //usleep(105000);   //20000
      //vTaskDelay (105);
      if (IntensityChangeFlag == 1)
	{
	 // printf ("\n\rIntensity %d", intensitydata * 25);
	  IntensityChangeFlag = 0;
	  pwmc_continuous_mode(PWM_CH_3,PWM_OPC_LOW,1200000,intensitydata * 300000);
	  Send_IntensityChangeAck_ToSMARC ();
	}

      if (LampFeedbackPingFlag == 1)
	{
	  //if(LampFeedbackPingEnableReadRdDne == 1)
	  //{
	  LampFeedbackPingFlag = 0;
	  Send_PingReplyFBEverySec_ToSMARC ();
	  //}
	}

      if(SMARCCommtoVEGAContinuous >= 400)
	{
	  SMARCCommtoVEGAContinuous = 0;
	  StagePatternreceivedOKFlag = 0;
	}
      else
	{
	  SMARCCommtoVEGAContinuous = SMARCCommtoVEGAContinuous + 1;
	}

      vTaskDelay (1); //50
    }

}

/*static void
vSPITask (void *pvParameters)
{
  for(;;)
    {
      //printf("\n\rSPI Working");


      if ((LampFBReadFlag == 1) || (StartFeedbackFlag == 1))
	{
	  //printf ("\n\r test SPI ");
	  ReadStore_ADC7490_CurrentVal_LDC();
	}

      vTaskDelay (125);
    }
}*/



static void
vI2CSPITask (void *pvParameters)
{


  LampSwitchDatapac[0] = 0xFFFF;
 // vTaskDelay (2000000);
  LampSwitchDatapac[1] = 0xFFFF;
  LampSwitchDatapac[2] = 0xFFFF;
  LampSwitchDatapac[3] = 0xFFFF;

	printf("i2c write initialise\n\r");
		//i2c_init(I2C_0);
		i2c_configure(I2C_0, SYSTEM_FREQUENCY, I2C_FREQ); //System clock =100MHz and I2C clock =400 kHz

		GPIO_write_pin(GPIOI2CSW, LOW);


  for(;;)
    {
      //printf("i2c write initialise\n\r");




      if( LDCWriteI2Ccount125 == 120 )  //4
	{
	  //printf("\n\rI2C Working");

		      if ((LampFBReadFlag == 1) || (StartFeedbackFlag == 1))
	        	{
	        	  //printf ("\n\r test SPI ");
	        	  //ReadStore_ADC7490_CurrentVal_LDC();     // commented by me for spi0
	        	}


		      /*if(LDCSwitchDelay == 1)
		            {
		            i2c_Write2Byte(I2C_0,((ADDRESS_PCF1_LAMP1TO16 << 1)& 0xFE), Lamppatterndummy);
		            //usleep(2000);
		            Lamppatterndummy = ~Lamppatterndummy;
		            i2c_Write2Byte(I2C_0,((ADDRESS_PCF2_LAMP17TO32 << 1)& 0xFE), Lamppatterndummy);
		            }
		          else if(LDCSwitchDelay == 125)
		            {
		     	 i2c_Write2Byte(I2C_0,((ADDRESS_PCF1_LAMP1TO16 << 1)& 0xFE), Lamppatterndummy);
		     	        //usleep(2000);
		     	 Lamppatterndummy = ~Lamppatterndummy;
		     	 i2c_Write2Byte(I2C_0,((ADDRESS_PCF2_LAMP17TO32 << 1)& 0xFE), Lamppatterndummy);
		            }
		          else if(LDCSwitchDelay == 250)
		            {
		     	 LDCSwitchDelay = 0;
		            }
		            //usleep(2000);
		            //vTaskDelay(16);
		            LDCSwitchDelay++;*/


		           //setWireData(15, 1);
		           //GPIO_write_pin(GPIOI2CSW, HIGH);


	  LDCWriteI2Ccount125 = 0;
	  if(StagePatternreceivedOKFlag == 1)
	    {
	    if(LampflashSelection == 0)
	      {
		      if((LDsense & 0x01) == 1 )
		      {
			  //commented i2c write byte by me for i2c0
		      //printf("\n\rLDC 1 Lamp Data %X", (~LampSwitchDatapac[0]));
			  //i2c_Write2Byte(I2C_0,((ADDRESS_PCF1_LAMP1TO16 << 1)& 0xFE), LampSwitchDatapac[0]);
			  vTaskDelay (1);
		      }
		      if(((LDsense & 0x02) >> 1) == 1)
		      {
		      //printf("\n\rLDC 2 Lamp Data %X", (~LampSwitchDatapac[1]));
			 // i2c_Write2Byte(I2C_0,((ADDRESS_PCF2_LAMP17TO32 << 1)& 0xFE), LampSwitchDatapac[1]);
			  vTaskDelay (1);
		      }
		      if(((LDsense & 0x04) >> 2) == 1)
		      {
		      //printf("\n\rLDC 3 Lamp Data %X", (~LampSwitchDatapac[2]));
			//  i2c_Write2Byte(I2C_0,((ADDRESS_PCF3_LAMP33TO48 << 1)& 0xFE), LampSwitchDatapac[2]);
			  vTaskDelay (1);
		      }
		      if(((LDsense & 0x08) >> 3) == 1)
		      {
		      //printf("\n\rLDC 4 Lamp Data %X", (~LampSwitchDatapac[3]));
			 // i2c_Write2Byte(I2C_0,((ADDRESS_PCF4_LAMP49TO64 << 1)& 0xFE), LampSwitchDatapac[3]);
			  vTaskDelay (1);
		      }
		      LampflashSelectionswitchcount = 0;
	      }
	      else
	      {
		      if(LampflashSelectionswitchcount < 5)
		      {
			      if((LDsense & 0x01) == 1 )
			      {
				  //i2c_Write2Byte(I2C_0,((ADDRESS_PCF1_LAMP1TO16 << 1)& 0xFE), LampSwitchDatapac[0]);
			      //printf("\n\rLDC 1 Lamp Data F %X", (~LampSwitchDatapac[0]));
				  vTaskDelay (1);
			      }
			      if(((LDsense & 0x02) >> 1) == 1)
			      {
				 // i2c_Write2Byte(I2C_0,((ADDRESS_PCF2_LAMP17TO32 << 1)& 0xFE), LampSwitchDatapac[1]);
			      //printf("\n\rLDC 2 Lamp Data F %X", (~LampSwitchDatapac[2]));
				  vTaskDelay (1);
			      }
			      if(((LDsense & 0x04) >> 2) == 1)
			      {
				 // i2c_Write2Byte(I2C_0,((ADDRESS_PCF3_LAMP33TO48 << 1)& 0xFE), LampSwitchDatapac[2]);
				  vTaskDelay (1);
			      }
			      if(((LDsense & 0x08) >> 3) == 1)
			      {
				  //i2c_Write2Byte(I2C_0,((ADDRESS_PCF4_LAMP49TO64 << 1)& 0xFE), LampSwitchDatapac[3]);
				  vTaskDelay (1);
			      }
		      }
		      else
		      {
			      if((LDsense & 0x01) == 1 )
			      {
				  //i2c_Write2Byte(I2C_0,((ADDRESS_PCF1_LAMP1TO16 << 1)& 0xFE), LampSwitchDatapac[4]);
				  vTaskDelay (1);
			      }
			      if(((LDsense & 0x02) >> 1) == 1)
			      {
				 // i2c_Write2Byte(I2C_0,((ADDRESS_PCF2_LAMP17TO32 << 1)& 0xFE), LampSwitchDatapac[5]);
				  vTaskDelay (1);
			      }
			      if(((LDsense & 0x04) >> 2) == 1)
			      {
				  //i2c_Write2Byte(I2C_0,((ADDRESS_PCF3_LAMP33TO48 << 1)& 0xFE), LampSwitchDatapac[6]);
				  vTaskDelay (1);
			      }
			      if(((LDsense & 0x08) >> 3) == 1)
			      {
				 // i2c_Write2Byte(I2C_0,((ADDRESS_PCF4_LAMP49TO64 << 1)& 0xFE), LampSwitchDatapac[7]);
				  vTaskDelay (1);
			      }
			      if(LampflashSelectionswitchcount == 8)
			      {
				      LampflashSelectionswitchcount = 0;
			      }
		      }
	      }
	      LampflashSelectionswitchcount = LampflashSelectionswitchcount + 1;
	      if(LampFeedbackPingEnableRead == 1)
	      {
		      if((LDsense & 0x01) == 1 )
		      {
			      //i2c_Read2Byte(I2C_0, (((ADDRESS_PCF1_FEEDBACK1TO16 << 1) & 0xFE) | 0x01), 0);
			      //printf("\n\rLDC1 Read Complete %x : Patt: %x", LampFBDataSendtoSMARC[0], (~LampSwitchDatapac[0]));
			      vTaskDelay (1);
		      }
		      if(((LDsense & 0x02) >> 1) == 1)
		      {
			      //i2c_Read2Byte(I2C_0, (((ADDRESS_PCF2_FEEDBACK17TO32 << 1) & 0xFE) | 0x01), 1);
			      //printf("\n\rLDC2 Read Complete %x : Patt: %x", LampFBDataSendtoSMARC[1], (~LampSwitchDatapac[1]));
			      vTaskDelay (1);
		      }
		      if(((LDsense & 0x04) >> 2) == 1)
		      {
			      //i2c_Read2Byte(I2C_0, (((ADDRESS_PCF3_FEEDBACK33TO48 << 1) & 0xFE) | 0x01), 2);
			      //printf("\n\rLDC3 Read Complete %x : Patt: %x", LampFBDataSendtoSMARC[2], (~LampSwitchDatapac[2]));
			      vTaskDelay (1);
		      }
		      if(((LDsense & 0x08) >> 3) == 1)
		      {
			      //i2c_Read2Byte(I2C_0, (((ADDRESS_PCF4_FEEDBACK49TO64 << 1) & 0xFE) | 0x01), 3);
			      //printf("\n\rLDC4 Read Complete %x : Patt: %x", LampFBDataSendtoSMARC[3], (~LampSwitchDatapac[3]));
			      vTaskDelay (1);
		      }
		      LampFeedbackPingEnableReadRdDne = 1;
	      }
	      else
	      {
		      LampFeedbackPingEnableReadRdDne = 0;
		      vTaskDelay (4);
	      }
	    }
	  else
	    {
	      if(LampflashSelectionswitchcount < 5)
		  {
			  if((LDsense & 0x01) == 1 )
			  {
			      //i2c_Write2Byte(I2C_0,((ADDRESS_PCF1_LAMP1TO16 << 1)& 0xFE), (( (RxFlashPattReadfromEEPROM[2]<<8) & 0xFF00)  |  RxFlashPattReadfromEEPROM[1]));
			  //printf("\n\rLDC 1 Lamp Data F %X", (~LampSwitchDatapac[0]));
			      vTaskDelay (1);
			  }
			  if(((LDsense & 0x02) >> 1) == 1)
			  {
			      //i2c_Write2Byte(I2C_0,((ADDRESS_PCF2_LAMP17TO32 << 1)& 0xFE), (( (RxFlashPattReadfromEEPROM[4]<<8) & 0xFF00)  |  RxFlashPattReadfromEEPROM[3]));
			  //printf("\n\rLDC 2 Lamp Data F %X", (~LampSwitchDatapac[2]));
			      vTaskDelay (1);
			  }
			  if(((LDsense & 0x04) >> 2) == 1)
			  {
			      //i2c_Write2Byte(I2C_0,((ADDRESS_PCF3_LAMP33TO48 << 1)& 0xFE), (( (RxFlashPattReadfromEEPROM[6]<<8) & 0xFF00)  |  RxFlashPattReadfromEEPROM[5]));
			      vTaskDelay (1);
			  }
			  if(((LDsense & 0x08) >> 3) == 1)
			  {
			      //i2c_Write2Byte(I2C_0,((ADDRESS_PCF4_LAMP49TO64 << 1)& 0xFE), (( (RxFlashPattReadfromEEPROM[8]<<8) & 0xFF00)  |  RxFlashPattReadfromEEPROM[7]));
			      vTaskDelay (1);
			  }
		  }
		  else
		  {
			  if((LDsense & 0x01) == 1 )
			  {
			     // i2c_Write2Byte(I2C_0,((ADDRESS_PCF1_LAMP1TO16 << 1)& 0xFE), (( (RxFlashPattReadfromEEPROM[10]<<8) & 0xFF00)  |  RxFlashPattReadfromEEPROM[9]));
			      vTaskDelay (1);
			  }
			  if(((LDsense & 0x02) >> 1) == 1)
			  {
			     // i2c_Write2Byte(I2C_0,((ADDRESS_PCF2_LAMP17TO32 << 1)& 0xFE), (( (RxFlashPattReadfromEEPROM[12]<<8) & 0xFF00)  |  RxFlashPattReadfromEEPROM[11]));
			      vTaskDelay (1);
			  }
			  if(((LDsense & 0x04) >> 2) == 1)
			  {
			     // i2c_Write2Byte(I2C_0,((ADDRESS_PCF3_LAMP33TO48 << 1)& 0xFE), (( (RxFlashPattReadfromEEPROM[14]<<8) & 0xFF00)  |  RxFlashPattReadfromEEPROM[13]));
			      vTaskDelay (1);
			  }
			  if(((LDsense & 0x08) >> 3) == 1)
			  {
			     // i2c_Write2Byte(I2C_0,((ADDRESS_PCF4_LAMP49TO64 << 1)& 0xFE), (( (RxFlashPattReadfromEEPROM[16]<<8) & 0xFF00)  |  RxFlashPattReadfromEEPROM[15]));
			      vTaskDelay (1);
			  }
			  if(LampflashSelectionswitchcount == 8)
			  {
				  LampflashSelectionswitchcount = 0;
			  }
		  }
	    LampflashSelectionswitchcount = LampflashSelectionswitchcount + 1;
	    }
	}
      else
	{
	  LDCWriteI2Ccount125 = LDCWriteI2Ccount125 + 1;
	}
      vTaskDelay (1); //24
    }
}

static void
vWDTTask (void *pvParameters)
{
  static led_state = 0;
  for(;;)
      {
	//printf("\n\rWDT Working");
       GPIO_write_pin(21,led_state);    //21 gpio for trisul
       led_state = !led_state;

	GPIO_write_pin(GPIOWDT, LOW);    //for reseting vega
	GPIO_write_pin(GPIOWDTLD, LOW);  //for LD off when hanging

	vTaskDelay (250);

	GPIO_write_pin(GPIOWDT, HIGH);
	GPIO_write_pin(GPIOWDTLD, HIGH);

	vTaskDelay (250);
      }
}



int
main (void)
{

  Initialization();
  //register void* sp __asm__("sp"); // Declare a register variable bound to `sp`
    		//  printf("\n\r main Stack Pointer (sp) = %p\n", sp);


    //		  register void* gp __asm__("gp"); // Declare a register variable bound to `gp`
    	//	  printf("\n\ main global Pointer (gp) = %p\n", gp);
  prvSetupHardware ();
  vSendString ("Thejas32 FreeRTOS Demo\n\r");

  if (xTaskCreate (vEepromTask, "Reg1", 1024, NULL, 2, NULL))
    {
      vSendString ("EEPROM_Task Created \n\r");
    }
  if (xTaskCreate (vI2CSPITask, "SPII2CWr", 1024, NULL, 3, NULL))
      {
        vSendString ("To control SPI lines \n\r");
      }
  if (xTaskCreate (vWDTTask, "WDT", 1024, NULL, 4, NULL))
        {
          vSendString ("To control WDT \n\r");
        }
  /*if (xTaskCreate (vSPITask, "SPI", 1024, NULL, 5, NULL))
          {
            vSendString ("To control WDT \n\r");
          }*/



  /* Start the scheduler. */
  vTaskStartScheduler ();
  for (;;)
    ;
}

