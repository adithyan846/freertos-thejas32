/*
 * main.h
 *
 *  Created on: 20 Jun 2025
 *      Author: ratheesh
 */

#ifndef INCLUDESAPP_MAIN_H_
#define INCLUDESAPP_MAIN_H_

UC lamp_data[8], Switching_Data[20], Last_halfsec_sw_flag = 0, Lamp_UART_SendFlag;

extern unsigned char halfsec_sw_flag, LampFBReadFlag, StartFeedbackFlag, CurrentReadingFlag;
unsigned short Cnt_Delay_1ms = 0;
unsigned short LampFBDataSendtoSMARC[4] = {0x0000, 0x0000, 0x0000, 0x0000}, LampFBDataSendtoSMARCCon[4] = {0x0000, 0x0000, 0x0000, 0x0000}, LampFBDataSendtoSMARCConLast[4] = {0x0000, 0x0000, 0x0000, 0x0000};
unsigned char LampFBDataSendtoSMARCConCount[4] = {0x00, 0x00, 0x00, 0x00};
int multiWrite_rtn;

extern void SwitchOffAllLamps (void);

extern void SMARCRxUART_PacketValidation(void);
extern void SMARCRxUART_PacketProcessing (void);
extern void Initialization (void);

extern void Switching_pattern_process (void);
extern void Identify_AssignBuffer (void);
extern void ReadLampDriverCardAvailability(void);
extern void ReadStore_ADC7490_CurrentVal_LDC (void);
extern void Send_Acknowledgement_WithLampFeedback_ToSMARC (void);
extern void Send_Acknowledgement_WithLampFBBytes_ToSMARC (void);
extern void Send_Acknowledgement_WithLampCurrent_ToSMARC (void);
extern void Send_PingReplyFBEverySec_ToSMARC (void);

extern unsigned char intensitydata, IntensityChangeFlag,LampFeedbackPing, LampFeedbackPingFlag, LampFeedbackPingEnableRead;
extern void Send_IntensityChangeAck_ToSMARC (void);

#endif /* INCLUDESAPP_MAIN_H_ */
