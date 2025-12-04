/*
 * Packet_process.h
 *
 *  Created on: 20 Jun 2025
 *      Author: ratheesh
 */

#ifndef INCLUDESAPP_PACKET_PROCESS_H_
#define INCLUDESAPP_PACKET_PROCESS_H_

unsigned char PacketType, halfsec_sw_flag =0;
unsigned char Checksum_correct_flag,UartReceivedBuffer[50];

extern UC LAMP_1_16; // The PCF8575 sensor I2C address for switching
extern UC LAMP_17_32; // The PCF8575 sensor I2C address for switching
extern UC LAMP_33_48; // The PCF8575 sensor I2C address for switching
extern UC LAMP_47_64; // The PCF8575 sensor I2C address for switching
extern UC LAMP_FeedBack_1_16; // The PCF8575 sensor I2C address for feedback
extern UC LAMP_FeedBack_17_32; // The PCF8575 sensor I2C address for feedback
extern UC LAMP_FeedBack_33_48; // The PCF8575 sensor I2C address for feedback
extern UC LAMP_FeedBack_49_64; // The PCF8575 sensor I2C address for feedback
extern UC Switching_Data[20], Cnt_Delay_1ms, Switch_Type_Flash;

extern unsigned int NoOfLDCardAvailable;

extern RxlampSWPattern RxSMARCSWPattern;

void Identify_AssignBuffer (void);
void Switching_pattern_process (void);
extern void LampInput (UI I2C_num,UC Switching_Data1,UC Switching_Data2,UC Lamp_No);
extern void Send_Acknowledgement_WithLampFeedback_ToSMARC (void);
extern unsigned short CuSensorRead(  unsigned short opcode);
extern void ReadStore_ADC7490_CurrentVal_LDC (void);
extern unsigned short Read_ADC7490_CurrentVal (unsigned char ADC_Channel, unsigned char spi_slave );

#endif /* INCLUDESAPP_PACKET_PROCESS_H_ */
