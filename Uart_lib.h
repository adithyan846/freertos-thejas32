/*
 * Uart_lib.h
 *
 *  Created on: 20 Jun 2025
 *      Author: ratheesh
 */

#ifndef INCLUDESAPP_UART_LIB_H_
#define INCLUDESAPP_UART_LIB_H_

#define UART0_INTR_NUM 0 // Note : this number is for thejas32, number may change on other SoCs
#define UART1_INTR_NUM 1

volatile unsigned char Ack_Sent_Buffer[140], Rx_Databuffer[50] , Received_buffer[500], Chk_Rx_Databuffer[16] ;
volatile unsigned char USART_Rx_Index = 0, USART1_data_length = 0, Uart_received_CompleteFlag = 0;
volatile unsigned char status = 0, error = 0, data = 0;
volatile int rx_flag, rx_count;

volatile unsigned char rx_buffer[100];

unsigned char RxFlashPattBufSavetoEEPROM[19];
unsigned short SMARCCommtoVEGAContinuous = 0;

unsigned char  Save_Pattern_Flash = 0, Junction_ID = 1, Last_Uart_received_CompleteFlag =0;
unsigned char Lamp_switching_flag = 0, Switch_Type_Flash = 0, Ack_Lamp_Feedback_Flag =0, Rx_New_Pattern_Flag = 0;

extern unsigned char LampFBStatus[64], CLampFBStatus[32], LampFBReadFlag, CurrentReadingFlag;
extern unsigned int NoOfLDCardAvailable;
extern unsigned short LampCurrent[64],LampCurrentAVGSet[64];

extern unsigned char LampFBDataSendtoSMARCConCount[4];


unsigned char LampflashSelection = 0;
unsigned short LampSwitchDatapac[8];



void UART_Initialization(void);
void uart_interrupt_receive_init(void);
void SMARCRxUART_PacketValidation(void);

void SMARCRxUART_PacketProcessing (void);
void Send_Acknowledgement_ToSMARC (void);
void Send_Acknowledgement_WithLampFeedback_ToSMARC (void);
void Reset_Ack_Sent_Buffer (void);
void Send_PingReplyFBEverySec_ToSMARC (void);

unsigned char intensitydata = 4, IntensityChangeFlag = 0, LampFeedbackPing = 0, LampFeedbackPingFlag = 0, LampFeedbackPingEnableRead = 0;
unsigned char StagePatternreceivedOKFlag = 0;
void Send_IntensityChangeAck_ToSMARC (void);

void uart_intr_handler1(void);

#endif /* INCLUDESAPP_UART_LIB_H_ */
