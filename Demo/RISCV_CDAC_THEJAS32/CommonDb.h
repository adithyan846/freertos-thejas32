/*
 * CommonDb.h
 *
 *  Created on: 20 Jun 2025
 *      Author: ratheesh
 */

#ifndef INCLUDESAPP_COMMONDB_H_
#define INCLUDESAPP_COMMONDB_H_

#define TRUE 1
#define FALSE 0
#define SAVE_PATTERN_ToFLASH 		0x01
#define FLASH_PATTERN 			0x02
#define START_AMBER_PATTERN		0x03
#define ALL_RED_PATTERN			0x04
#define SWITCHOFF_PATTERN		0x05
#define SWITCH_STAGE_INTERSTAGE 	0x06
#define SWITCH_STAGE_INTERSTAGE_FL  	0x07
#define MINIMUM_PLAN_PATTERN        	0x08
#define SMARC_FAIL_UPTIME_PKT		0x09
#define MALFUN_MGT_ACKNOWLEDGEMENT	0x0A
#define INTENSITY			0x0B
#define PING_RESPONCE			0x0C
#define LAMPFLASHPATTERNTOEEPROM	0x0D

#define PACKET_RX_ACKNOWLEDGEMENT	0x01
#define LAMP_SWITCH_FEEDBACK		0x02
#define LAMP_FEEDBACK_STATUS		0x03
#define Ack_Sent_Header             0xe6

#define LAMP_1_TO_16   0x20 // The PCF8575 sensor I2C address for switching
#define LAMP_17_TO_32  0x22 // The PCF8575 sensor I2C address for switching
#define LAMP_33_TO_48  0x24 // The PCF8575 sensor I2C address for switching
#define LAMP_49_TO_64  0x26 // The PCF8575 sensor I2C address for switching

#define LAMP_FeedBack_1_TO_16   0x21 // The PCF8575 sensor I2C address for feedback
#define LAMP_FeedBack_17_TO_32  0x23 // The PCF8575 sensor I2C address for feedback
#define LAMP_FeedBack_33_TO_48  0x25 // The PCF8575 sensor I2C address for feedback
#define LAMP_FeedBack_49_TO_64  0x27 // The PCF8575 sensor I2C address for feedback

typedef unsigned char UC; //1 Byte
typedef unsigned short US; //2 Bytes
typedef unsigned int UI; //4 Bytes
typedef unsigned long UL; //8 Bytes

typedef struct
{
	unsigned char 	Flash_Pattern[8], Timeout, JunctionID, Total_LDCard,
					Flash_PatternSW[8], SA_PatternSW[8], AR_PatternSW[8],
					OFF_PatternSW[8], Stg_PatternSW[8], StgWithFl_PatternSW[16],
					Ack_PacketID_SMARC_Rx_Packet, SMARC_FailTime[3],
					SMARC_UP_TIME[3], TotalStages, MinPlan_StgPat[80],
					MinPlan_AmbPat[80], MinPlan_DPL[3], Pkt_Typ, Std_PatternSW[8],
					LampFeedbackInput[8];
}RxlampSWPattern;

//RxlampSWPattern RxSMARCSWPattern;

#endif /* INCLUDESAPP_COMMONDB_H_ */
