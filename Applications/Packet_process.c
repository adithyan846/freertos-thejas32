/*
 * Packet_process.c
 *
 *  Created on: 19 Aug 2025
 *      Author: ratheesh
 */


#include "CommonDb.h"
#include "i2c.h"
#include "stdlib.h"
#include "Includesapp/i2c_api.h"
#include "Packet_process.h"

/****************************************************************************************************************
Function Name:
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
void Identify_AssignBuffer (void)
{
	if ( halfsec_sw_flag == 1 )
	{
		printf("\n\r Normal, %d", Switch_Type_Flash);
		for( unsigned char j=0; j < 8; j++  )
		{
			if (Switch_Type_Flash == 2 )
			{
				Switching_Data[j]	=	RxSMARCSWPattern.Flash_PatternSW[j];
				//printf(":%x", Switching_Data[j] );
			}
			else if (Switch_Type_Flash == 5 )
			{
				Switching_Data[j]	=	0xFF;

			}
			else if ( (Switch_Type_Flash == 3 ) || (Switch_Type_Flash == 4 ) || (Switch_Type_Flash == 6 ) )
			{
				Switching_Data[j]	=	RxSMARCSWPattern.Std_PatternSW[j];
			}
			else if (Switch_Type_Flash == 7 )
			{
				Switching_Data[j]	=	RxSMARCSWPattern.StgWithFl_PatternSW[j];
			}
		}
	}
	else
	{
		printf("\n\r NormalFL");
		for( unsigned char j=0; j < 8; j++  )
		{
			if ( (Switch_Type_Flash == 2 ) || (Switch_Type_Flash == 5 ) )
			{
				Switching_Data[j]	=	0xFF;
			}
			else if ( (Switch_Type_Flash == 3 ) || (Switch_Type_Flash == 4 ) || (Switch_Type_Flash == 6 ) )
			{
				Switching_Data[j]	=	RxSMARCSWPattern.Std_PatternSW[j];
			}
			else if (Switch_Type_Flash == 7 )
			{
				Switching_Data[j]	=	RxSMARCSWPattern.StgWithFl_PatternSW[j+8];
			}
		}
	}
}
/****************************************************************************************************************
Function Name:
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
void Switching_pattern_process (void)
{
	//unsigned char NumberOfLDCard = 0,Switching_data[256];
//NoOfLDCardAvailable
	//NumberOfLDCard = UartReceivedBuffer[3];

	/*for(int i = 0; i < 8; i++)
	{
		Switching_data[i] = UartReceivedBuffer[i + 5];
	}*/
	unsigned short LADCVal;
	//RxSMARCSWPattern.Total_LDCard = 1;
	printf("\n\r Switching pattern process %d ", RxSMARCSWPattern.Total_LDCard);
	/*if(RxSMARCSWPattern.Total_LDCard == 1)
	{
		LampInput(I2C_0,Switching_Data[0],Switching_Data[1],LAMP_1_TO_16);
		usleep(2000);
		i2cRead_request(LAMP_FeedBack_1_TO_16,2,TRUE);
	}
	if(RxSMARCSWPattern.Total_LDCard == 2)
	{
		LampInput(I2C_0,Switching_Data[0],Switching_Data[1],LAMP_1_TO_16);
		LampInput(I2C_0,Switching_Data[2],Switching_Data[3],LAMP_17_TO_32);
		//usleep(2000);
		i2cRead_request(LAMP_FeedBack_1_TO_16,2,TRUE);
		i2cRead_request(LAMP_FeedBack_17_TO_32,2,TRUE);
	}
	if(RxSMARCSWPattern.Total_LDCard == 3)
	{
		LampInput(I2C_0,Switching_Data[0],Switching_Data[1],LAMP_1_TO_16);
		LampInput(I2C_0,Switching_Data[2],Switching_Data[3],LAMP_17_TO_32);
		LampInput(I2C_0,Switching_Data[4],Switching_Data[5],LAMP_33_TO_48);

		i2cRead_request(LAMP_FeedBack_1_TO_16,2,TRUE);
		i2cRead_request(LAMP_FeedBack_17_TO_32,2,TRUE);
		i2cRead_request(LAMP_FeedBack_33_TO_48,2,TRUE);
	}
	if(RxSMARCSWPattern.Total_LDCard == 4)
	{
		LampInput(I2C_0,Switching_Data[0],Switching_Data[1],LAMP_1_TO_16);
		LampInput(I2C_0,Switching_Data[2],Switching_Data[3],LAMP_17_TO_32);
		LampInput(I2C_0,Switching_Data[4],Switching_Data[5],LAMP_33_TO_48);
		LampInput(I2C_0,Switching_Data[6],Switching_Data[7],LAMP_49_TO_64);
		i2cRead_request(LAMP_FeedBack_1_TO_16,2,TRUE);
		i2cRead_request(LAMP_FeedBack_17_TO_32,2,TRUE);
		i2cRead_request(LAMP_FeedBack_33_TO_48,2,TRUE);
		i2cRead_request(LAMP_FeedBack_49_TO_64,2,TRUE);
	}*/
	unsigned short CurrentValADC [18];
	printf("\n\r Cu Sensor");
	/*for(unsigned short ichn = 0 ; ichn < 16; ichn++)
	{
		CurrentValADC[ichn] = Read_ADC7490_CurrentVal(ichn,1);
		if ( ( ichn % 4) == 0 )
		{
			printf("\n\r");
		}
		printf("-CH-%02x:%02x:\t", ichn+1, CurrentValADC[ichn]);


	}*/
	ReadStore_ADC7490_CurrentVal_LDC ();
	printf("\n\r Cu Sensor");
	Send_Acknowledgement_WithLampFeedback_ToSMARC ();
}
