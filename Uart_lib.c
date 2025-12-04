/*
 * Uart_lib.c
 *
 *  Created on: 20 Jun 2025
 *      Author: ratheesh
 */

#include "CommonDb.h"
#include "Uart_lib.h"
#include <uart.h>
#include "stdlib.h"
#include "config.h"
#include "interrupt.h"


RxlampSWPattern RxSMARCSWPattern;

extern volatile  unsigned char USART_Rx_IndexT, Uart_received_CompleteFlagT, Received_bufferT[500];

extern unsigned char LampFBStatus[64], CLampFBStatus[32], LampFBReadFlag, CurrentReadingFlag;
extern unsigned short LampCurrent[64],LampCurrentAVGSet[64];
extern unsigned short  LampFBDataSendtoSMARC[4], LampFBDataSendtoSMARCCon[4], LampFBDataSendtoSMARCConLast[4];



/****************************************************************************************************************
Function Name:
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
/*
void uart_intr_handler1(void) // interrupt handler
{
	//unsigned char status = 0, error = 0, data = 0;
  vSendString("ISR\n");
	status = UartReg(UART_1).UART_IIR_FCR; // clearing interrupt
	//if(status)
	//{
		data = uart_getchar(UART_1, &error);
		if(data == 0xE5)
		{
			USART_Rx_Index = 0;
			rx_count = 0;
			//printf("\n\r New");
		}
		Received_buffer[USART_Rx_Index] = data ;
		if( USART_Rx_Index == 0x01)
		{

			USART1_data_length = data;
		}
		if(Received_buffer[0] == 0xE5)
		{
			USART_Rx_Index++;
		}
		if( ( USART1_data_length == USART_Rx_Index ) && (Received_buffer[0] == 0xE5) )
		{
			Uart_received_CompleteFlag = 1;
			//printf("\n\r InterUart_received_CompleteFlag is -%x",Uart_received_CompleteFlag);
			//USART1_data_length = 0;
			//USART_Rx_Index = 0;
			//SmarcPktReceiveFlag = 1;
		}
		else
		{

		}
		//uart_putchar(UART_0, data, &error);	   // echoing data
	//}
	//uart_putchar(UART_0, data, &error);	   // echoing data
	return;
}*/

/****************************************************************************************************************
Function Name:
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
/*void UART_Initialization(void)
{

	uart_set_baud_rate(UART_1, 9600, 100000000);
	printf("+------[ uart%d in interrupt mode ]------+\n", UART_1);
//Enable interrupt in controller.
	interrupt_enable(1);   //UART1_INTR_NUM

	irq_register_handler(1, uart_intr_handler1);
// enabling uart1 interrupt
	uart_intr_enable(UART_1, TX_DISABLE, RX_ENABLE);

	UartReg(UART_1).UART_IIR_FCR = 1;

	printf("\n uart init completed", UART_1);

	// idle loop
}*/

//volatile int data_processsing;

/****************************************************************************************************************
Function Name:
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
void SMARCRxUART_PacketValidation(void)
{
  static led_state = 0;
	unsigned char calc_crc = 0;
	/*if ( Last_Uart_received_CompleteFlag != Uart_received_CompleteFlag )
	{
		Last_Uart_received_CompleteFlag = Uart_received_CompleteFlag;
		//printf("\n\r Uart_received_CompleteFlag is -%x:%x:%x",Uart_received_CompleteFlag,USART_Rx_Index,USART1_data_length);
	}*/

	/*Received_bufferT[0] = 0xe5;//:8:1:2:c:1:0:e3
	    Received_bufferT[1] = 0x08;
	    Received_bufferT[2] = 0x01;
	    Received_bufferT[3] = 0x02;
	    Received_bufferT[4] = 0x0c;
	    Received_bufferT[5] = 0x01;
	    Received_bufferT[6] = 0x00;
	    Received_bufferT[7] = 0xe3;*/
	if(Uart_received_CompleteFlagT == 1 )
	{

	    Uart_received_CompleteFlagT = 0;
		//data_processsing = 1;
//		vSendString("\n\r OK-Rx packet BF -");
//		for(unsigned char i=0;i<( Received_bufferT[1]  );i++)
//		{
//			printf(":%x",Received_bufferT[i]);
//		}

		//



		/*for(int i=0;i< Received_bufferT[1] ;i++)  //40
		{
			Rx_Databuffer[i]	=	Received_bufferT[i];
			//vSendString("\n\r main packet -");
		}*/
		USART_Rx_IndexT = 0;

		for(int i=0;i<( Rx_Databuffer[1]-1  );i++)
		{
			calc_crc = calc_crc ^ Rx_Databuffer[i];
			// vSendString("\n\r crc packet -");
			//uart_putchar(UART_1, Received_buffer[i] ,0);
			//printf(" -%x:%x",Received_buffer[i],calc_crc);
		}
		//printf("   crc    -%x:%x",Rx_Databuffer[ Rx_Databuffer[1] - 1 ],calc_crc);
		//uart_putchar(UART_1, calc_crc,0);

		if(  calc_crc == Rx_Databuffer[ Rx_Databuffer[1] - 1 ])
		{
		    //vSendString("\n\r Packet OK-");
			//unsigned char checksum_flag=1;
		    vSendString("\n\r OK-Rx packet -");

			for(unsigned char i=0;i<( Rx_Databuffer[1]  );i++)
			{

			    GPIO_write_pin(23,led_state);
			    led_state = !led_state;
			      //  vSendString("\n\rOK -");
			//	printf(":%x",Rx_Databuffer[i]);
			}
			//printf("\n\r");

			SMARCRxUART_PacketProcessing();
			//Send_Acknowledgement_ToSMARC();
			CurrentReadingFlag = 1;
		}
		else
		{


			vSendString("Error\n\r");



			/*for(unsigned char i=0;i<( Rx_Databuffer[1]  );i++)
			{
				printf(":%x",Rx_Databuffer[i]);
			}*/
			//for(unsigned char i=0;i<( Rx_Databuffer[1]  );i++)
			//{
			//	printf(":%x",Rx_Databuffer[i]);
			//	uart_putchar(UART_1, Rx_Databuffer[i], 0);
			//	//printf("\n\r Rx packet is -%x:",Rx_Databuffer[i]);
			//}
		}
		//Received_bufferT[0] = 0;

		//data_processsing = 0;
		//Uart_received_CompleteFlagT = 0;
		 //interrupt_enable(1);
		//uart_intr_enable(UART_1, TX_DISABLE, RX_ENABLE);

	}


	if( USART_Rx_Index > 50 )
	{
		//USART_Rx_IndexT = 0;
	}

}
/****************************************************************************************************************
Function Name:
Description :
Input: nil
outputs: nil.
Status: Tested
***************************************************************************************************************/
void SMARCRxUART_PacketProcessing(void)
{
	//Received_buffer
	RxSMARCSWPattern.Timeout      = Rx_Databuffer[9];
	RxSMARCSWPattern.JunctionID   = Rx_Databuffer[2];
	RxSMARCSWPattern.Total_LDCard = Rx_Databuffer[3];
	RxSMARCSWPattern.Pkt_Typ      = Rx_Databuffer[3];
	Switch_Type_Flash = Rx_Databuffer[4];
	switch( Rx_Databuffer[4]  )
	{
		case SAVE_PATTERN_ToFLASH:
						for( unsigned char j=0; j < 8; j++  )
						{
							RxSMARCSWPattern.Flash_Pattern[j]  = Rx_Databuffer[j+5];
							Chk_Rx_Databuffer[j] = ~Rx_Databuffer[j+5];
						}
						Save_Pattern_Flash = 0;
						Lamp_switching_flag = 0;
						break;
		case FLASH_PATTERN:
						for( unsigned char j=0; j < 8; j++  )
						{
							RxSMARCSWPattern.Flash_PatternSW[j]  = Rx_Databuffer[j+5];
							Chk_Rx_Databuffer[j] = ~Rx_Databuffer[j+5];
							Chk_Rx_Databuffer[j+8] = 0x00;
						}
						Save_Pattern_Flash = 0;
						Lamp_switching_flag = 1;
						LampflashSelection = 1;
						StagePatternreceivedOKFlag = 1;
						break;
		case START_AMBER_PATTERN:
						for( unsigned char j=0; j < 8; j++  )
						{
							RxSMARCSWPattern.SA_PatternSW[j]  = Rx_Databuffer[j+5];
							Chk_Rx_Databuffer[j] = ~Rx_Databuffer[j+5];
						}
						Save_Pattern_Flash = 0;
						Lamp_switching_flag = 1;
						LampflashSelection = 0;
						StagePatternreceivedOKFlag = 1;
						break;
		case ALL_RED_PATTERN	:
						for( unsigned char j=0; j < 8; j++  )
						{
							RxSMARCSWPattern.AR_PatternSW[j]  = Rx_Databuffer[j+5];
							Chk_Rx_Databuffer[j] = ~Rx_Databuffer[j+5];
						}
						Save_Pattern_Flash = 0;
						Lamp_switching_flag = 1;
						LampflashSelection = 0;
						StagePatternreceivedOKFlag = 1;
						break;
		case SWITCHOFF_PATTERN:
						for( unsigned char j=0; j < 8; j++  )
						{
							RxSMARCSWPattern.OFF_PatternSW[j]  = Rx_Databuffer[j+5];
							Chk_Rx_Databuffer[j] = ~Rx_Databuffer[j+5];
						}
						Save_Pattern_Flash = 0;
						Lamp_switching_flag = 1;
						LampflashSelection = 0;
						StagePatternreceivedOKFlag = 1;
						break;
		case SWITCH_STAGE_INTERSTAGE :
						for( unsigned char j=0; j < 8; j++  )
						{
							RxSMARCSWPattern.Stg_PatternSW[j]  = Rx_Databuffer[j+5];
							Chk_Rx_Databuffer[j] = ~Rx_Databuffer[j+5];
						}
						Save_Pattern_Flash = 0;
						Lamp_switching_flag = 1;
						Rx_New_Pattern_Flag = 1;
						LampflashSelection = 0;
						for(unsigned int i = 0; i<4; i++)
						{
							LampFBDataSendtoSMARC[i] = 0x0000;
							LampFBDataSendtoSMARCCon[i] = 0x0000;
							LampFBDataSendtoSMARCConLast[i] = 0x0000;
							LampFBDataSendtoSMARCConCount[i] = 0;
						}
						StagePatternreceivedOKFlag = 1;
						break;
		case SWITCH_STAGE_INTERSTAGE_FL :
						for( unsigned char j=0; j < 16; j++  )
						{
							RxSMARCSWPattern.StgWithFl_PatternSW[j]  = Rx_Databuffer[j+5];
							Chk_Rx_Databuffer[j] = ~Rx_Databuffer[j+5];
						}
						Save_Pattern_Flash = 0;
						Lamp_switching_flag = 1;
						Rx_New_Pattern_Flag = 1;
						for(unsigned int i = 0; i<4; i++)
						{
							LampFBDataSendtoSMARC[i] = 0x0000;
							LampFBDataSendtoSMARCCon[i] = 0x0000;
							LampFBDataSendtoSMARCConLast[i] = 0x0000;
							LampFBDataSendtoSMARCConCount[i] = 0;
						}
						StagePatternreceivedOKFlag = 1;
						break;
		case MINIMUM_PLAN_PATTERN :
						RxSMARCSWPattern.TotalStages = Rx_Databuffer[5];
						unsigned char Rx_PktLen = 0;
						for( unsigned char j=0; j < RxSMARCSWPattern.TotalStages; j++  )
						{
							for( unsigned char j=0; j < 8; j++  )
							{
								RxSMARCSWPattern.MinPlan_StgPat[Rx_PktLen]  =  Rx_Databuffer[Rx_PktLen+6];
								Rx_PktLen++;
							}
							for( unsigned char j=0; j < 8; j++  )
							{
								RxSMARCSWPattern.MinPlan_AmbPat[Rx_PktLen]  =  Rx_Databuffer[Rx_PktLen+6];
								Rx_PktLen++;
							}
						}
						for( unsigned char j=0; j < 3; j++  )
						{
							RxSMARCSWPattern.MinPlan_DPL[Rx_PktLen]  =  Rx_Databuffer[Rx_PktLen+6];
							Rx_PktLen++;
						}
						Save_Pattern_Flash = 1;
						Lamp_switching_flag = 0;
						StagePatternreceivedOKFlag = 1;
						break;
		case SMARC_FAIL_UPTIME_PKT :
						for( unsigned char j=0; j < 3; j++  )
						{
							RxSMARCSWPattern.SMARC_FailTime[j] = Rx_Databuffer[j+5];
							RxSMARCSWPattern.SMARC_UP_TIME[j]  = Rx_Databuffer[j+8];
						}
						Save_Pattern_Flash = 0;
						Lamp_switching_flag = 0;
						break;
		case MALFUN_MGT_ACKNOWLEDGEMENT :
						RxSMARCSWPattern.Ack_PacketID_SMARC_Rx_Packet = Rx_Databuffer[5];
						Save_Pattern_Flash = 0;
						Lamp_switching_flag = 0;
						break;
		case INTENSITY			:
						intensitydata = Rx_Databuffer[5];
						IntensityChangeFlag = 1;
						break;
		case PING_RESPONCE		:
						LampFeedbackPing = Rx_Databuffer[5];
						LampFeedbackPingFlag = 1;
						LampFeedbackPingEnableRead = Rx_Databuffer[6];
						break;
		case LAMPFLASHPATTERNTOEEPROM   :
						Lamp_switching_flag = 0;
						RxFlashPattBufSavetoEEPROM[0] = RxSMARCSWPattern.Total_LDCard ;
						for( unsigned int l=0; l < 16; l++)
						{
						    RxFlashPattBufSavetoEEPROM[l+1]  = Rx_Databuffer[l+5];
							//Chk_Rx_Databuffer[j] = ~Rx_Databuffer[j+5];
						}
						Save_Pattern_Flash = 1;
						printf("\n\rFlash Pattern flagset :%x", Save_Pattern_Flash);
						break;
		default:
						Save_Pattern_Flash = 0;
						Lamp_switching_flag = 0;
						Switch_Type_Flash = 0;
						break;

	}
	SMARCCommtoVEGAContinuous = 0;
	for( unsigned int j=0; j < 16;)
	{
		LampSwitchDatapac[j / 2] = (~(( (Chk_Rx_Databuffer[j+1]<<8) & 0xFF00)  |  Chk_Rx_Databuffer[j]));
		j = j+2;
	}
}
/****************************************************************************************************************
Function Name:
Description :
Input: nil
outputs: nil.
Status: Tested
***************************************************************************************************************/
void Send_Acknowledgement_ToSMARC (void)
{
	char status_reg;
	Reset_Ack_Sent_Buffer();
	unsigned char sent_calc_crc = 0;
	Ack_Sent_Buffer[0] = Ack_Sent_Header;
	Ack_Sent_Buffer[1] = 0x07;
	Ack_Sent_Buffer[2] = Junction_ID;
	Ack_Sent_Buffer[3] = RxSMARCSWPattern.Total_LDCard;
	Ack_Sent_Buffer[4] = 0x01;
	Ack_Sent_Buffer[5] = Switch_Type_Flash;
	for(int i=0;i<( Ack_Sent_Buffer[1] - 1 );i++)
	{
		sent_calc_crc = sent_calc_crc ^ Ack_Sent_Buffer[i];
		uart_putchar(UART_1, Ack_Sent_Buffer[i] ,&status_reg);
	}
	uart_putchar(UART_1, sent_calc_crc, &status_reg);
}

/****************************************************************************************************************
Function Name:Intensity ACK
Description :
Input: nil
outputs: nil.
Status: Tested
***************************************************************************************************************/
void Send_IntensityChangeAck_ToSMARC (void)
{
      char status_reg;
	Reset_Ack_Sent_Buffer();
	unsigned char sent_calc_crc = 0;
	Ack_Sent_Buffer[0] = Ack_Sent_Header;
	Ack_Sent_Buffer[1] = 0x07;
	Ack_Sent_Buffer[2] = Junction_ID;
	Ack_Sent_Buffer[3] = RxSMARCSWPattern.Total_LDCard;
	Ack_Sent_Buffer[4] = 0x01;
	Ack_Sent_Buffer[5] = INTENSITY;
	for(int i=0;i<( Ack_Sent_Buffer[1] - 1 );i++)
	{
		sent_calc_crc = sent_calc_crc ^ Ack_Sent_Buffer[i];
		uart_putchar(UART_1, Ack_Sent_Buffer[i] ,&status_reg);
	}
	uart_putchar(UART_1, sent_calc_crc,&status_reg);
}


/****************************************************************************************************************
Function Name:
Description :
Input: nil
outputs: nil.
Status: Tested
***************************************************************************************************************/
void Send_Acknowledgement_WithLampFeedback_ToSMARC (void)
{
	char status_reg;
	unsigned char crc_index = 0;
	Reset_Ack_Sent_Buffer();
	if ( ( Switch_Type_Flash >=2 ) && ( Switch_Type_Flash <= 7) )
	{
		unsigned char sent_calc_crc = 0;
		Ack_Sent_Buffer[0] = Ack_Sent_Header;
		Ack_Sent_Buffer[1] = 0x46;  //70
		Ack_Sent_Buffer[2] = Junction_ID;
		Ack_Sent_Buffer[3] = RxSMARCSWPattern.Total_LDCard;
		Ack_Sent_Buffer[4] = 0x02;
//LampCurrent
		for( int i = 5 ; i < 69 ; i++)
		{
			Ack_Sent_Buffer[i]  = 0x00;
		}
		if(RxSMARCSWPattern.Total_LDCard == 1)
		{
			for( int i = 0 ; i < 16 ; i++)
			{
				Ack_Sent_Buffer[i+5]  = LampFBStatus[i];
			}
			crc_index = 21;
		}
		if(RxSMARCSWPattern.Total_LDCard == 2)
		{
			for( int i = 0 ; i < 32 ; i++)
			{
				Ack_Sent_Buffer[i+5]  = LampFBStatus[i];
			}
			crc_index = 37;
		}
		if(RxSMARCSWPattern.Total_LDCard == 3)
		{
			for( int i = 0 ; i < 48 ; i++)
			{
				Ack_Sent_Buffer[i+5]  = LampFBStatus[i];
			}
			crc_index = 53;
		}
		if(RxSMARCSWPattern.Total_LDCard == 4)
		{
			for( int i = 0 ; i < 64 ; i++)
			{
				Ack_Sent_Buffer[i+5]  = LampFBStatus[i];
			}
			crc_index = 69;
		}
		/*for( int i = 0 ; i < 64 ; i++)
		{
			Ack_Sent_Buffer[i+5]  = LampFBStatus[i];
		}*/
		Ack_Sent_Buffer[1] = crc_index + 1;
		for(int i=0;i<( Ack_Sent_Buffer[1] - 1 );i++)
		{
			sent_calc_crc = sent_calc_crc ^ Ack_Sent_Buffer[i];
			uart_putchar(UART_1, Ack_Sent_Buffer[i] , &status_reg);
		}

		Ack_Sent_Buffer[crc_index] = sent_calc_crc;
		uart_putchar(UART_1, sent_calc_crc, &status_reg);
		/*printf("\n\r Tx LB1 ");
		for(unsigned char i=0;i<( Ack_Sent_Buffer[1]  );i++)
		{
			printf(":%x",Ack_Sent_Buffer[i]);
		}*/
	}
}


/****************************************************************************************************************
Function Name:
Description :
Input: nil
outputs: nil.
Status: Tested
***************************************************************************************************************/
void Send_PingReplyFBEverySec_ToSMARC (void)
{
        char status_reg;
	unsigned char crc_index = 0;
	Reset_Ack_Sent_Buffer();
	//if ( ( Switch_Type_Flash >=2 ) && ( Switch_Type_Flash <= 7) )
	//{
		unsigned char sent_calc_crc = 0;
		Ack_Sent_Buffer[0] = Ack_Sent_Header;
		Ack_Sent_Buffer[1] = 0x14;  //70
		Ack_Sent_Buffer[2] = Junction_ID;
		Ack_Sent_Buffer[3] = RxSMARCSWPattern.Total_LDCard;
		Ack_Sent_Buffer[4] = 0x05;
		crc_index = 5;
		for( int i = 5 ; i < 9 ; i++)
		{
			Ack_Sent_Buffer[i]  = 0x00;
		}
		if(RxSMARCSWPattern.Total_LDCard == 1)
		{
			for( int i = 0 ; i < 1; i++)
			{
				Ack_Sent_Buffer[crc_index]  	= (LampFBDataSendtoSMARC[i] & 0x00FF);
				Ack_Sent_Buffer[crc_index+1]  = ((LampFBDataSendtoSMARC[i] & 0xFF00) >> 8);
				crc_index = crc_index + 2;
			}
		}
		if(RxSMARCSWPattern.Total_LDCard == 2)
		{
			for( int i = 0 ; i < 2; i++)
			{
				Ack_Sent_Buffer[crc_index]  	= (LampFBDataSendtoSMARC[i] & 0x00FF);
				Ack_Sent_Buffer[crc_index+1]  = ((LampFBDataSendtoSMARC[i] & 0xFF00) >> 8);
				crc_index = crc_index + 2;
			}
		}
		if(RxSMARCSWPattern.Total_LDCard == 3)
		{
			for( int i = 0 ; i < 3; i++)
			{
				Ack_Sent_Buffer[crc_index]  	= (LampFBDataSendtoSMARC[i] & 0x00FF);
				Ack_Sent_Buffer[crc_index+1]  = ((LampFBDataSendtoSMARC[i] & 0xFF00) >> 8);
				crc_index = crc_index + 2;
			}
		}
		if(RxSMARCSWPattern.Total_LDCard == 4)
		{
			for( int i = 0 ; i < 4; i++)
			{
				Ack_Sent_Buffer[crc_index]  	= (LampFBDataSendtoSMARC[i] & 0x00FF);
				Ack_Sent_Buffer[crc_index+1]  = ((LampFBDataSendtoSMARC[i] & 0xFF00) >> 8);
				crc_index = crc_index + 2;
			}
		}
		/*for( int i = 0 ; i < 64 ; i++)
		{
			Ack_Sent_Buffer[i+5]  = LampFBStatus[i];
		}*/
		Ack_Sent_Buffer[1] = crc_index+1;
		for(int i=0;i<( Ack_Sent_Buffer[1] - 1 );i++)
		{
			sent_calc_crc = sent_calc_crc ^ Ack_Sent_Buffer[i];
			uart_putchar(UART_1, Ack_Sent_Buffer[i] , &status_reg);
		}

		Ack_Sent_Buffer[crc_index] = sent_calc_crc;
		uart_putchar(UART_1, sent_calc_crc, &status_reg);
		/*printf("\n\r Tx LB1 Ping");
		for(unsigned char i=0;i<( Ack_Sent_Buffer[1]  );i++)
		{
			printf(":%x",Ack_Sent_Buffer[i]);
		}*/
	//}
}

/****************************************************************************************************************
Function Name:
Description :
Input: nil
outputs: nil.
Status: Tested
***************************************************************************************************************/
void Send_Acknowledgement_WithLampCurrent_ToSMARC (void)
{
	char status_reg;
	unsigned char crc_index = 0;
	Reset_Ack_Sent_Buffer();
	if ( ( Switch_Type_Flash >=2 ) && ( Switch_Type_Flash <= 7) )
	{
		unsigned char sent_calc_crc = 0;
		Ack_Sent_Buffer[0] = Ack_Sent_Header;
		Ack_Sent_Buffer[1] = 0x46;  //70
		Ack_Sent_Buffer[2] = Junction_ID;
		Ack_Sent_Buffer[3] = RxSMARCSWPattern.Total_LDCard;
		Ack_Sent_Buffer[4] = 0x03;

		for( int i = 5 ; i < 69 ; i++)
		{
			Ack_Sent_Buffer[i]  = 0x00;
		}
		if(RxSMARCSWPattern.Total_LDCard == 1)
		{
			for( int i = 0 ; i < 16; i++)
			{
				Ack_Sent_Buffer[(2*i)+5]  = LampCurrentAVGSet[i] & 0x0FF;
				Ack_Sent_Buffer[(2*i)+6]  = ( LampCurrentAVGSet[i] >> 8 )& 0x0FF;
			}
			crc_index = 37;
		}
		if(RxSMARCSWPattern.Total_LDCard == 2)
		{
			for( int i = 0 ; i < 32 ; i++)
			{
				Ack_Sent_Buffer[(2*i)+5]  = LampCurrentAVGSet[i] & 0x0FF;
				Ack_Sent_Buffer[(2*i)+6]  = ( LampCurrentAVGSet[i] >> 8 )& 0x0FF;
			}
			crc_index = 69;
		}
		if(RxSMARCSWPattern.Total_LDCard == 3)
		{
			for( int i = 0 ; i < 48 ; i++)
			{
				Ack_Sent_Buffer[(2*i)+5]  = LampCurrentAVGSet[i] & 0x0FF;
				Ack_Sent_Buffer[(2*i)+6]  = ( LampCurrentAVGSet[i] >> 8 )& 0x0FF;
			}
			crc_index = 101;
		}
		if(RxSMARCSWPattern.Total_LDCard == 4)
		{
			for( int i = 0 ; i < 64 ; i++)
			{
				Ack_Sent_Buffer[(2*i)+5]  = LampCurrentAVGSet[i] & 0x0FF;
				Ack_Sent_Buffer[(2*i)+6]  = ( LampCurrentAVGSet[i] >> 8 )& 0x0FF;
			}
			crc_index = 133;
		}
		/*for( int i = 0 ; i < 64 ; i++)
		{
			Ack_Sent_Buffer[i+5]  = LampFBStatus[i];
		}*/
		Ack_Sent_Buffer[1] = crc_index + 1;
		for(int i=0;i<( Ack_Sent_Buffer[1] - 1 );i++)
		{
			sent_calc_crc = sent_calc_crc ^ Ack_Sent_Buffer[i];
			uart_putchar(UART_1, Ack_Sent_Buffer[i] , &status_reg);
		}

		Ack_Sent_Buffer[crc_index] = sent_calc_crc;
		uart_putchar(UART_1, sent_calc_crc, &status_reg);
		/*printf("\n\r Tx LB1 ");
		for(unsigned char i=0;i<( Ack_Sent_Buffer[1]  );i++)
		{
			printf(":%x",Ack_Sent_Buffer[i]);
		}*/
	}
}
/****************************************************************************************************************
Function Name:
Description :
Input: nil
outputs: nil.
Status: Tested
***************************************************************************************************************/
void Send_Acknowledgement_WithLampFBBytes_ToSMARC (void)
{
	char status_reg;
	unsigned char crc_index = 0;
	Reset_Ack_Sent_Buffer();
 	if ( ( Switch_Type_Flash >=2 ) && ( Switch_Type_Flash <= 7) )
	{
		unsigned char sent_calc_crc = 0;
		Ack_Sent_Buffer[0] = Ack_Sent_Header;
		Ack_Sent_Buffer[1] = 0x0E;
		Ack_Sent_Buffer[2] = Junction_ID;
		Ack_Sent_Buffer[3] = RxSMARCSWPattern.Total_LDCard;
		Ack_Sent_Buffer[4] = 0x04;

		/*for( int i = 5 ; i < 20 ; i++)
		{
			Ack_Sent_Buffer[i]  = 0x00;
		}*/
		crc_index = 5;
		if(RxSMARCSWPattern.Total_LDCard == 1)
		{
			for( int i = 0 ; i < 16 ; i++)
			{
				Ack_Sent_Buffer[i+5]  = CLampFBStatus[i];
			}
			crc_index = crc_index + 16;
		}
		if(RxSMARCSWPattern.Total_LDCard == 2)
		{
			for( int i = 0 ; i < 32 ; i++)
			{
				Ack_Sent_Buffer[i+5]  = CLampFBStatus[i];
			}
			crc_index = crc_index + 32;
		}
		if(RxSMARCSWPattern.Total_LDCard == 3)
		{
			for( int i = 0 ; i < 48 ; i++)
			{
				Ack_Sent_Buffer[i+5]  = CLampFBStatus[i];
			}
			crc_index = crc_index + 48;
		}
		if(RxSMARCSWPattern.Total_LDCard == 4)
		{
			for( int i = 0 ; i < 64 ; i++)
			{
				Ack_Sent_Buffer[i+5]  = CLampFBStatus[i];
			}
			crc_index = crc_index + 64;
		}
		//Ack_Sent_Buffer[5] = Switch_Type_Flash;
		Ack_Sent_Buffer[1] = crc_index + 1;
		for(int i=0;i<( Ack_Sent_Buffer[1] - 1 );i++)
		{
			sent_calc_crc = sent_calc_crc ^ Ack_Sent_Buffer[i];
			uart_putchar(UART_1, Ack_Sent_Buffer[i] , &status_reg);
		}

		Ack_Sent_Buffer[crc_index] = sent_calc_crc;
		uart_putchar(UART_1, sent_calc_crc, &status_reg);
		/*printf("\n\r Tx LB2 ");
		for(unsigned char i=0;i<( Ack_Sent_Buffer[1]  );i++)
		{
			printf(":%x",Ack_Sent_Buffer[i]);
		}*/

	}
}
/****************************************************************************************************************
Function Name: Reset_Ack_Sent_Buffer
Description :
Input: nil
outputs: nil.
Status: Tested
***************************************************************************************************************/
void Reset_Ack_Sent_Buffer (void)
{
	for(unsigned char i=0;i< 140 ; i++)
	{
		Ack_Sent_Buffer[i]  =  0x00;
	}
}
//LampCurrent[64]
/*
 	 	//rx_flag=1;

	 	rx_buffer[rx_count]=data;
	 	//rx_count++;
	 	if(rx_buffer[0] == 0xE5)
	 	{
	 		rx_count++;
	 				//printf(":%x",Received_buffer[USART_Rx_Index] );
	 	}

	 	if( ( rx_buffer[1] == rx_count ) && (rx_buffer[0] == 0xE5) )
	 	{
	 		rx_flag=1;
	 	}
 */
