/*
 * Spi_lib.c
 *
 *  Created on: 19 Aug 2025
 *      Author: ratheesh
 */


#include "stdlib.h"
#include "spi.h"
#include "CommonDb.h"
#include "Includesapp/Spi_lib.h"
#include <config.h>
#include <interrupt.h>


#define WRITE_BIT    (1 << 11)
#define SEQ_BIT      (0 << 10)
#define PM1_BIT      (0 << 3) // Power management bits, assuming both are set to 0
#define PM0_BIT      (0 << 2)
#define SHADOW_BIT   (0 << 1)
#define CODING_BIT   (0 << 0)

#define NUM_CHANNELS 16 // Number of ADC channels


/****************************************************************************************************************
Function Name: CuSensor_SPI_Begin
Description : To initialize the current sensor
Input: unsigned char spiNo
outputs: nil.
Status: Tested
****************************************************************************************************************/

void CuSensor_SPI_Begin(unsigned char spiNo)
{
	US LADCVal;
	SPIcntrlRegType CSensorSpiCtrl;

	// Custom SPI control register setup, refer SPI datasheet for more details.
	CSensorSpiCtrl.Bits.PeriphChipSelect = 0;
	CSensorSpiCtrl.Bits.PeriphType = SPI_FIXED_PERIPHERAL; // Fixed peripheral
	CSensorSpiCtrl.Bits.DataOrder = MSB;
	CSensorSpiCtrl.Bits.Mode = 1;						// SPI mode 3
	CSensorSpiCtrl.Bits.SPIrxTxIntr = RX_TX_INTR_DIS; // no interrupts
	CSensorSpiCtrl.Bits.CSAAT = LOW;
	CSensorSpiCtrl.Bits.Dbits = 8; //0=  8-bit SPI operation., 4 - 12 bit , 8 - 16 bit
	//CSensorSpiCtrl.Bits.Mode = 0; // Mode 0

	//SPI_set_CSAAT_pin(currentSpiuse, HIGH);

	//GPIO_write_pin(currentChipSelectGPIO,HIGH); //No chip select
	//usleep(5);

	currentSpiuse = spiNo;
	SPI_init(currentSpiuse);
	SPI_config(currentSpiuse, CSensorSpiCtrl); // modifing spi control register.
	SPI_set_baud(currentSpiuse, SPI_BAUD_CFD_256); // setting spi baud rate. 100/4  ==  SPI_BAUD_CFD_16
	// Disable interrupts
	SPI_set_intr(MDP_SPI_0, TXINTR_DIS, RXINTR_DIS);


	if(LDsense)
	{
		if((LDsense & 0x01) == 1 )
		{
			for ( int indx  =0; indx < 2; indx ++ )
			{
			//SPI_receive(currentSpiuse);
			GPIO_write_pin(SPI_CS1,LOW); //chip select
			usleep(100);
			///SPI_set_CSAAT_pin(currentSpiuse, LOW);  //usleep(1000);

			SPI_transmit(currentSpiuse, 0xFFFF);
			SPI_receive(currentSpiuse);
			usleep(50);
			GPIO_write_pin(SPI_CS1,HIGH); //No chip select

			usleep(100);
			}
			GPIO_write_pin(SPI_CS1,LOW); //chip select
				usleep(100);
			SPI_transmit(currentSpiuse, 0x8311); //0x8311
			SPI_receive(currentSpiuse);
			usleep(50);
			GPIO_write_pin(SPI_CS1,HIGH); //No chip select

			usleep(100);
		}
		if(((LDsense & 0x02) >> 1) == 1)
		{
			for ( int indx  =0; indx < 2; indx ++ )
			{
			//SPI_receive(currentSpiuse);
			GPIO_write_pin(SPI_CS2,LOW); //chip select
			usleep(100);
			///SPI_set_CSAAT_pin(currentSpiuse, LOW);  //usleep(1000);

			SPI_transmit(currentSpiuse, 0xFFFF);
			SPI_receive(currentSpiuse);
			usleep(50);
			GPIO_write_pin(SPI_CS2,HIGH); //No chip select

			usleep(100);
			}
			GPIO_write_pin(SPI_CS2,LOW); //chip select
				usleep(100);
			SPI_transmit(currentSpiuse, 0x8311);
			SPI_receive(currentSpiuse);
			usleep(50);
			GPIO_write_pin(SPI_CS2,HIGH); //No chip select

			usleep(100);
		}
		if(((LDsense & 0x04) >> 2) == 1)
		{
			for ( int indx  =0; indx < 2; indx ++ )
			{
			//SPI_receive(currentSpiuse);
			GPIO_write_pin(SPI_CS3,LOW); //chip select
			usleep(100);
			///SPI_set_CSAAT_pin(currentSpiuse, LOW);  //usleep(1000);

			SPI_transmit(currentSpiuse, 0xFFFF);
			SPI_receive(currentSpiuse);
			usleep(50);
			GPIO_write_pin(SPI_CS3,HIGH); //No chip select

			usleep(100);
			}
			GPIO_write_pin(SPI_CS3,LOW); //chip select
				usleep(100);
			SPI_transmit(currentSpiuse, 0x8311);
			SPI_receive(currentSpiuse);
			usleep(50);
			GPIO_write_pin(SPI_CS3,HIGH); //No chip select

			usleep(100);
		}
		if(((LDsense & 0x08) >> 3) == 1)
		{
			for ( int indx  =0; indx < 2; indx ++ )
			{
			//SPI_receive(currentSpiuse);
			GPIO_write_pin(SPI_CS4,LOW); //chip select
			usleep(100);
			///SPI_set_CSAAT_pin(currentSpiuse, LOW);  //usleep(1000);

			SPI_transmit(currentSpiuse, 0xFFFF);
			SPI_receive(currentSpiuse);
			usleep(50);
			GPIO_write_pin(SPI_CS4,HIGH); //No chip select

			usleep(100);
			}
			GPIO_write_pin(SPI_CS4,LOW); //chip select
				usleep(100);
			SPI_transmit(currentSpiuse, 0x8311);
			SPI_receive(currentSpiuse);
			usleep(50);
			GPIO_write_pin(SPI_CS4,HIGH); //No chip select

			usleep(100);
		}
	}
				//LADCVal = CuSensorRead( 2, 0xFFFF);
				//LADCVal = CuSensorRead( 1, 0x8310);
	printf("\n\r CuADC Sensor %02x: initialized at spi%d.", LADCVal, currentSpiuse);
}
/****************************************************************************************************************
Function Name: Read_ADC7490_CurrentVal
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
unsigned short Read_ADC7490_CurrentVal (unsigned short ADC_Channel) //, unsigned char spi_slave )
{
	// GPIO0 [0] SPI_CS0,  1- CS1, 2- CS2, 3- CS3
	unsigned short ADCCHVAL = 0, Start_previousdataFlag1 = 0, validdataindex = 0;
	currentADCDATA = 0;
	//printf("\n\rChannel:: %d-",ADC_Channel);
	for ( int repet = 0; repet <10; repet ++ )
	{
		float value;
		unsigned char readBuf[2], Read_length = 2, timeout_spi =0;
		//Cmd_Channel[ADC_Channel] = ( 0x8330 | (ADC_Channel<< 10) );
		ADCCHVAL = 0;
		SPI_wait_if_busy(currentSpiuse);		 // Check if SPI controller is busy.
		GPIO_write_pin(SPI_CS1,LOW);
		usleep(7);		// 7 //75  3
		SPI_transmit(currentSpiuse, Cmd_Channel[ADC_Channel] ); // ( 0x8310 | (ADC_Channel<< 10) ));
		//usleep(3);		//75   50

		//printf("\n\r Cmd_Channel %x", Cmd_Channel[ADC_Channel]);
		ADCCHVAL = (SPI_receive(currentSpiuse)) & 0x0FFF; //data
		//printf("\t:: %d-",ADCCHVAL);
		if (( ( ADCCHVAL !=0 ) && ( ADCCHVAL != 0x0FFF ) )  && ( ADCCHVAL > Default_ADCDATA )  )
		{
			previousADCDATA = currentADCDATA;
			currentADCDATA = ADCCHVAL;
			Start_previousdataFlag1 = 1;
			validdataindex ++;
			//
			if ( ( validdataindex > 1  ) && ( ( previousADCDATA >= ( currentADCDATA - 20 ) ) && ( previousADCDATA <= ( currentADCDATA + 20 ) ) ))
			{
				//printf("\n\r\t\t:: %d ",currentADCDATA);
				currentADCDATA = ( currentADCDATA + previousADCDATA ) / 2;
				//printf(":--::current: %d:pre %d-",currentADCDATA, previousADCDATA);
			}
		}
		//usleep(5);
		/*if ( ADCCHVAL == 4095 )
		{
			ADCCHVAL  = 0;
		}*/
		tmp_ADCCHVAL[repet] = ADCCHVAL;
		//printf(":: %d-",ADCCHVAL);		//printf(":val1:- %d -Tx %x-",ADCCHVAL, Cmd_Channel[ADC_Channel]);
		GPIO_write_pin(SPI_CS1,HIGH); //GPIO_write_pin(currentChipSelectGPIO,HIGH);
		usleep(100);     //100    50
	}
	usleep(200);
	return (currentADCDATA);
}

/****************************************************************************************************************
Function Name: Store_ADC7490_CurrentVal_LDC
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
void ReadStore_ADC7490_CurrentVal_LDC (void)
{
	unsigned char ch = 0;
	unsigned short Chk_LampStatus = 0x0000;
	//printf("\n\r ADC current:-   ");


	 if(LDsense)
	 {
		if((LDsense & 0x01) == 1 )
		{
			//Chk_LampStatus	=	( (Chk_Rx_Databuffer[1]<<8) & 0xFF00)  |  Chk_Rx_Databuffer[0];
			Chk_LampStatus = 0x2222;
			//LampSwitchDatapac[0] = ( ~Chk_LampStatus);
			//printf("\n\r OK-Rx packet -%x:%x",Chk_Rx_Databuffer[1],Chk_Rx_Databuffer[0]);
			/*if( Last_Chk_LampStatus != Chk_LampStatus )
			{
				Last_Chk_LampStatus = Chk_LampStatus;
				printf("\n\r Chk Rx1 %x:%x:%x",Chk_LampStatus,Chk_Rx_Databuffer[1], Chk_Rx_Databuffer[0] );
			}*/
			for ( ch = 0; ch < 16; ch++)
			{

				if( ( ( Chk_LampStatus >> ch ) & 0x01 )  ==  0x01 )
				{
					//printf("\n\rLD1- CHN %d: ", ch+1 );
					LampADCVal[ch] = Read_ADC7490_CurrentVal(ch);
					if(LampADCVal[ch] > 0)
					{
						LD_LampCurrentCalculation(ch);
						LampCurrentAVGCount[ch] = LampCurrentAVGCount[ch] + 1;
						LampCurrentAVG[ch] = LampCurrentAVG[ch] + LampCurrent[ch];
						if(LampCurrentAVGCount[ch] == 10)
						{
							LampCurrentAVGSet[ch] = LampCurrentAVG[ch] / 10;
							LampCurrentAVGCount[ch] = 1;
							LampCurrentAVG[ch] = LampCurrentAVGSet[ch];
							LampCurrentAVGSetFlag[ch] = 1;
							//printf("Ch: %d :%d : \t", ch, LampCurrentAVGSet[ch]);
						}
					}
					//printf("\t%d:%d:%d:%d:%d ::%d::%d mA\t ", tmp_ADCCHVAL[0],tmp_ADCCHVAL[1],tmp_ADCCHVAL[2],tmp_ADCCHVAL[3],
					//			 tmp_ADCCHVAL[4], LampADCVal[ch], LampCurrent[ch]);

					//printf("\t%d:%d:%d:%d:%d:%d:%d:%d:%d:%d ::%d::%d mA\t ", tmp_ADCCHVAL[0],tmp_ADCCHVAL[1],tmp_ADCCHVAL[2],tmp_ADCCHVAL[3],
					//			 tmp_ADCCHVAL[4],tmp_ADCCHVAL[5],tmp_ADCCHVAL[6],tmp_ADCCHVAL[7],tmp_ADCCHVAL[8],tmp_ADCCHVAL[9], LampADCVal[ch], LampCurrent[ch]);
				}
				//usleep(50);
			//printf("Ch: %d :%d : \t", ch, LampFBStatus[chn]);
			}
		}
		if(((LDsense & 0x02) >> 1) == 1)
		{
			//Chk_LampStatus	=	( (Chk_Rx_Databuffer[3]<<8) & 0xFF00)  |  Chk_Rx_Databuffer[2];
			Chk_LampStatus = 0x2222;
			//LampSwitchDatapac[1] = ( ~Chk_LampStatus);
			for ( ch = 0; ch < 16; ch++)
			{
				if( ( ( Chk_LampStatus >> ch ) & 0x01 )  ==  0x01 )
				{
					//printf("\n\r LD2- CHN %d: \t ", ch+1 );
					LampADCVal[ch+16] = LD2_Read_ADC7490_CurrentVal(ch);
					if(LampADCVal[ch+16] > 0)
					{
						LD_LampCurrentCalculation(ch + 16);
						LampCurrentAVGCount[ch + 16] = LampCurrentAVGCount[ch + 16] + 1;
						LampCurrentAVG[ch + 16] = LampCurrentAVG[ch + 16] + LampCurrent[ch + 16];
						if(LampCurrentAVGCount[ch + 16] == 10)
						{
							LampCurrentAVGSet[ch + 16] = LampCurrentAVG[ch + 16] / 10;
							LampCurrentAVGCount[ch + 16] = 1;
							LampCurrentAVG[ch + 16] = LampCurrentAVGSet[ch + 16];
							LampCurrentAVGSetFlag[ch + 16] = 1;
							//printf("Ch: %d :%d : \t", ch + 16, LampCurrentAVGSet[ch + 16]);
						}
					}
					//printf("\t%d:%d:%d:%d:%d:::%d::%d mA \t ", LD2_ADCCHVAL[0],LD2_ADCCHVAL[1],LD2_ADCCHVAL[2],LD2_ADCCHVAL[3],
					//		LD2_ADCCHVAL[4], LampADCVal[ch], LampCurrent[ch]);
					//printf("\t%d:%d:%d:%d:%d:%d:%d:%d:%d:%d ::%d::%d mA \t ", LD2_ADCCHVAL[0],LD2_ADCCHVAL[1],LD2_ADCCHVAL[2],LD2_ADCCHVAL[3],
					//		LD2_ADCCHVAL[4],LD2_ADCCHVAL[5],LD2_ADCCHVAL[6],LD2_ADCCHVAL[7],LD2_ADCCHVAL[8],LD2_ADCCHVAL[9], LampADCVal[ch], LampCurrent[ch]);
					//usleep(50);
				}
			}
		}
		if(((LDsense & 0x04) >> 2) == 1)
		{
			Chk_LampStatus	=	( (Chk_Rx_Databuffer[5]<<8) & 0xFF00)  |  Chk_Rx_Databuffer[4];
			//LampSwitchDatapac[2] = ( ~Chk_LampStatus);
			for ( ch = 0; ch < 16; ch++)
			{
				if( ( ( Chk_LampStatus >> ch ) & 0x01 )  ==  0x01 )
				{
					//printf("\n\r LD3- CHN %d: \t ", ch+1 );
					LampADCVal[ch+32] = LD3_Read_ADC7490_CurrentVal(ch);
					if(LampADCVal[ch+32] > 0)
					{
						LD_LampCurrentCalculation(ch + 32);
						LampCurrentAVGCount[ch+32] = LampCurrentAVGCount[ch+32] + 1;
						LampCurrentAVG[ch+32] = LampCurrentAVG[ch+32] + LampCurrent[ch+32];
						if(LampCurrentAVGCount[ch+32] == 10)
						{
							LampCurrentAVGSet[ch+32] = LampCurrentAVG[ch+32] / 10;
							LampCurrentAVGCount[ch+32] = 1;
							LampCurrentAVG[ch+32] = LampCurrentAVGSet[ch+32];
							LampCurrentAVGSetFlag[ch + 32] = 1;
							//printf("Ch: %d :%d : \t", ch+32, LampCurrentAVGSet[ch+32]);
						}
					}
					//printf("\t%d:%d:%d:%d:%d:::%d::%d mA \t ", LD3_ADCCHVAL[0],LD3_ADCCHVAL[1],LD3_ADCCHVAL[2],LD3_ADCCHVAL[3],
					//		LD3_ADCCHVAL[4], LampADCVal[ch], LampCurrent[ch]);
					//printf("\t%d:%d:%d:%d:%d:%d:%d:%d:%d:%d ::%d::%d mA \t ", LD3_ADCCHVAL[0],LD3_ADCCHVAL[1],LD3_ADCCHVAL[2],LD3_ADCCHVAL[3],
					//		LD3_ADCCHVAL[4],LD3_ADCCHVAL[5],LD3_ADCCHVAL[6],LD3_ADCCHVAL[7],LD3_ADCCHVAL[8],LD3_ADCCHVAL[9], LampADCVal[ch], LampCurrent[ch]);
					//usleep(50);
				}
			}
		}
		if(((LDsense & 0x08) >> 3) == 1)
		{
			Chk_LampStatus	=	( (Chk_Rx_Databuffer[7]<<8) & 0xFF00)  |  Chk_Rx_Databuffer[6];
			//LampSwitchDatapac[3] = ( ~Chk_LampStatus);
			for ( ch = 0; ch < 16; ch++)
			{
				if( ( ( Chk_LampStatus >> ch ) & 0x01 )  ==  0x01 )
				{
					//printf("\n\r LD4- CHN %d: \t ", ch+1 );
					LampADCVal[ch+48] = LD4_Read_ADC7490_CurrentVal(ch);
					if(LampADCVal[ch+48] > 0)
					{
						LD_LampCurrentCalculation(ch + 48);
						LampCurrentAVGCount[ch+48] = LampCurrentAVGCount[ch+48] + 1;
						LampCurrentAVG[ch+48] = LampCurrentAVG[ch+48] + LampCurrent[ch+48];
						if(LampCurrentAVGCount[ch+48] == 10)
						{
							LampCurrentAVGSet[ch+48] = LampCurrentAVG[ch+48] / 10;
							LampCurrentAVGCount[ch+48] = 1;
							LampCurrentAVG[ch+48] = LampCurrentAVGSet[ch+48];
							LampCurrentAVGSetFlag[ch + 48] = 1;
							//printf("Ch: %d :%d : \t", ch+48, LampCurrentAVGSet[ch+48]);
						}
					}
					//printf("\t%d:%d:%d:%d:%d:::%d::%d mA \t ", LD4_ADCCHVAL[0],LD4_ADCCHVAL[1],LD4_ADCCHVAL[2],LD4_ADCCHVAL[3],
					//		LD4_ADCCHVAL[4], LampADCVal[ch], LampCurrent[ch]);
					//printf("\t%d:%d:%d:%d:%d:%d:%d:%d:%d:%d ::%d::%d mA \t ", LD4_ADCCHVAL[0],LD4_ADCCHVAL[1],LD4_ADCCHVAL[2],LD4_ADCCHVAL[3],
					//		LD4_ADCCHVAL[4],LD4_ADCCHVAL[5],LD4_ADCCHVAL[6],LD4_ADCCHVAL[7],LD4_ADCCHVAL[8],LD4_ADCCHVAL[9], LampADCVal[ch], LampCurrent[ch]);
					//usleep(50);
				}
			}
		}
	 }
	 Coin_Lampfeedback_Status();

	 StartFeedbackFlag = 0;
	 LampFBReadFlag = 1;
}
// open < 80mA
//short > 3A
// overload 2 to 3 A
// Normal - normal 80ma - 2 A
// Red 400 mA, 24V  - 200 mA
// Amber 400 mA 24 A   - 200 mA
// Green 200 mA 24 V
//brt 120mA
// Ped Red   200mA
//Ped Green  300mA
/****************************************************************************************************************
Function Name: LD_LampCurrentCalculation
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
void LD_LampCurrentCalculation (unsigned char currentchannel)
{
	unsigned short tmp_val = 0;
	if ( LampADCVal[currentchannel] > Default_ADCDATA )
	{
		//printf("\n\r\t\t:: %d :%d ",LampADCVal[currentchannel], currentchannel+1);
		tmp_val = (LampADCVal[currentchannel] - Default_ADCDATA);
		//printf("\n\r\t\t:: %d ",( tmp_val  ));
		//printf("\n\r\t\t:: %d ",( tmp_val * 290 ));
		LampCurrent[currentchannel] =  ( tmp_val * 290 ) / 100;
	}
	else
	{
		//printf("\n\r\t\t:L: %d ",LampADCVal[currentchannel]);
		//tmp_val = ( Default_ADCDATA - LampADCVal[currentchannel] );
		//printf("\n\r\t\t:L: %d ",( tmp_val * 290 ));
		LampCurrent[currentchannel] =  0;  //( tmp_val * 290 ) / 100;
	}
	//printf("\n\rLamp Channel :%d Data : %d Current :%d ",currentchannel + 1, tmp_val, LampCurrent[currentchannel]);
}
/****************************************************************************************************************
Function Name: Coin_Lampfeedback_Status
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
void Coin_Lampfeedback_Status (void)
{
	// open < 80mA - 1
	//short > 3A     - 0
	// overload 2 to 3 A  --2
	// Normal - normal 80ma - 2 A  - 3

	if(LDsense)
	{
	//printf("\n\r Lamp Current: ");
		if((LDsense & 0x01) == 1 )
		{
			for ( unsigned char chn = 0; chn < 16; chn++)
			{
				if(LampCurrentAVGSetFlag[chn] == 1)
				{
				LampCurrentAVGSetFlag[chn] = 0;
			//printf("Ch: %d :%d : \t", chn, LampCurrent[chn]);
					if ( LampCurrentAVGSet[chn] < 80 )  //open
					{
						LampFBStatus[chn] = 1;
					}
					else if ( LampCurrentAVGSet[chn] > 3000 )  //short ckt to gnd
					{
						LampFBStatus[chn] = 0;
					}
					else if (( LampCurrentAVGSet[chn] >= 80 )  && ( LampCurrentAVGSet[chn] < 2000 ))  //normal
					{
						LampFBStatus[chn] = 3;
					}
					else if (( LampCurrentAVGSet[chn] >= 2000 )  && ( LampCurrentAVGSet[chn] <= 3000 ))  //overload
					{
						LampFBStatus[chn] = 2;
					}
				}

			}
		}
		if(((LDsense & 0x02) >> 1) == 1)
		{
			for ( unsigned char chn = 16; chn < 32; chn++)
			{
				if(LampCurrentAVGSetFlag[chn] == 1)
				{
				LampCurrentAVGSetFlag[chn] = 0;
			//printf("Ch: %d :%d : \t", chn, LampCurrent[chn]);
					if ( LampCurrentAVGSet[chn] < 80 )  //open
					{
						LampFBStatus[chn] = 1;
					}
					else if ( LampCurrentAVGSet[chn] > 3000 )  //short ckt to gnd
					{
						LampFBStatus[chn] = 0;
					}
					else if (( LampCurrentAVGSet[chn] >= 80 )  && ( LampCurrentAVGSet[chn] < 2000 ))  //normal
					{
						LampFBStatus[chn] = 3;
					}
					else if (( LampCurrentAVGSet[chn] >= 2000 )  && ( LampCurrentAVGSet[chn] <= 3000 ))  //overload
					{
						LampFBStatus[chn] = 2;
					}
				}

			}
		}
		if(((LDsense & 0x04) >> 2) == 1)
		{
			for ( unsigned char chn = 32; chn < 48; chn++)
			{
				if(LampCurrentAVGSetFlag[chn] == 1)
				{
				LampCurrentAVGSetFlag[chn] = 0;
			//printf("Ch: %d :%d : \t", chn, LampCurrent[chn]);
					if ( LampCurrentAVGSet[chn] < 80 )  //open
					{
						LampFBStatus[chn] = 1;
					}
					else if ( LampCurrentAVGSet[chn] > 3000 )  //short ckt to gnd
					{
						LampFBStatus[chn] = 0;
					}
					else if (( LampCurrentAVGSet[chn] >= 80 )  && ( LampCurrentAVGSet[chn] < 2000 ))  //normal
					{
						LampFBStatus[chn] = 3;
					}
					else if (( LampCurrentAVGSet[chn] >= 2000 )  && ( LampCurrentAVGSet[chn] <= 3000 ))  //overload
					{
						LampFBStatus[chn] = 2;
					}
				}

			}
		}
		if(((LDsense & 0x08) >> 3) == 1)
		{
			for ( unsigned char chn = 48; chn < 64; chn++)
			{
				if(LampCurrentAVGSetFlag[chn] == 1)
				{
				LampCurrentAVGSetFlag[chn] = 0;
			//printf("Ch: %d :%d : \t", chn, LampCurrent[chn]);
					if ( LampCurrentAVGSet[chn] < 80 )  //open
					{
						LampFBStatus[chn] = 1;
					}
					else if ( LampCurrentAVGSet[chn] > 3000 )  //short ckt to gnd
					{
						LampFBStatus[chn] = 0;
					}
					else if (( LampCurrentAVGSet[chn] >= 80 )  && ( LampCurrentAVGSet[chn] < 2000 ))  //normal
					{
						LampFBStatus[chn] = 3;
					}
					else if (( LampCurrentAVGSet[chn] >= 2000 )  && ( LampCurrentAVGSet[chn] <= 3000 ))  //overload
					{
						LampFBStatus[chn] = 2;
					}
				}

			}
		}
	}
	ReportLampFBStatus();
}
/*
 Each lamps status is indicated by 3 bits Previous event.
                Failure type ( 4 Bits) 	:
                                                0000-Short circuit to ground
                                                0001-Open load
                                                0010-Over load
                                                0011-Normal
                                                0100-Not Configured
                                                0101-Configured&notCalled
Each lamps status is indicated by 4 bits New event.
                Failure type ( 4 Bits)
Bit 4 is for Status, 1 new event, 0 Previous event
                                                1000-Short circuit to ground
                                                1001-Open load
                                                1010-Over load
                                                1011-Normal
                                                1100-Not Configured
 */
/****************************************************************************************************************
Function Name: ReportLampFBStatus
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
void ReportLampFBStatus (void)
{
	//unsigned char tmp_ch = 0;
	for ( unsigned char chnl = 0; chnl < 64; chnl++)
	{
		/*CLampFBStatus[tmp_ch] = CLampFBStatus[tmp_ch] & ((0xF0) >> (4*(chnl-(tmp_ch*2) )));   //Rat for Correcting Lamp Outputs
		CLampFBStatus[tmp_ch] |= LampFBStatus[chnl] << (4*(chnl-(tmp_ch*2) ));
		if ( (chnl %2) == 0 )
		{
			tmp_ch++;
		}*/
		CLampFBStatus[chnl] = LampFBStatus[chnl];
	}
}
/****************************************************************************************************************
Function Name: LD2_Read_ADC7490_CurrentVal
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
unsigned short LD2_Read_ADC7490_CurrentVal (unsigned short ADC_Channel2) //, unsigned char spi_slave )
{
	// GPIO0 [0] SPI_CS0,  1- CS1, 2- CS2, 3- CS3
	unsigned short ADCCHVAL = 0, Start_previousdataFlag1 = 0, validdataindex = 0;
	currentADCDATA = 0;
	//printf("\n\rChannel:: %d-",ADC_Channel2);
	for ( int repet = 0; repet <10; repet ++ )
	{
		float value;
		unsigned char readBuf[2], Read_length = 2, timeout_spi =0;
		//Cmd_Channel[ADC_Channel] = ( 0x8330 | (ADC_Channel<< 10) );
		ADCCHVAL = 0;
		SPI_wait_if_busy(currentSpiuse);		 // Check if SPI controller is busy.
		GPIO_write_pin(SPI_CS2,LOW);
		usleep(7);		// 7 //75  3
		SPI_transmit(currentSpiuse, Cmd_Channel[ADC_Channel2] ); // ( 0x8310 | (ADC_Channel<< 10) ));
		//usleep(3);		//75   50
		//printf("\n\r Cmd_Channel %x", Cmd_Channel[ADC_Channel]);
		ADCCHVAL = (SPI_receive(currentSpiuse)) & 0x0FFF; //data
		//printf("\t:: %d-",ADCCHVAL);
		if (( ( ADCCHVAL !=0 ) && ( ADCCHVAL != 0x0FFF ) )  && ( ADCCHVAL > Default_ADCDATA )  )
		{
			previousADCDATA = currentADCDATA;
			currentADCDATA = ADCCHVAL;
			Start_previousdataFlag1 = 1;
			validdataindex ++;
			//
			if ( ( validdataindex > 1  ) && ( ( previousADCDATA >= ( currentADCDATA - 20 ) ) && ( previousADCDATA <= ( currentADCDATA + 20 ) ) ))
			{
				//printf("\n\r\t\t:: %d ",currentADCDATA);
				currentADCDATA = ( currentADCDATA + previousADCDATA ) / 2;
				//printf(":--::current: %d:pre %d-",currentADCDATA, previousADCDATA);
				//printf(":--::: %d: %d-",currentADCDATA, previousADCDATA);
			}
		}
		//usleep(5);
		/*if ( ADCCHVAL == 4095 )
		{
			ADCCHVAL  = 0;
		}*/
		LD2_ADCCHVAL[repet] = ADCCHVAL;
		//printf(":: %d-",ADCCHVAL);		//printf(":val1:- %d -Tx %x-",ADCCHVAL, Cmd_Channel[ADC_Channel]);
		GPIO_write_pin(SPI_CS2,HIGH); //GPIO_write_pin(currentChipSelectGPIO,HIGH);
		usleep(100);     //100    50
	}
	usleep(200);
	return (currentADCDATA);
}
/****************************************************************************************************************
Function Name: LD3_Read_ADC7490_CurrentVal
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
unsigned short LD3_Read_ADC7490_CurrentVal (unsigned short ADC_Channel3) //, unsigned char spi_slave )
{
	// GPIO0 [0] SPI_CS0,  1- CS1, 2- CS2, 3- CS3
	unsigned short ADCCHVAL = 0, Start_previousdataFlag1 = 0, validdataindex = 0;
	currentADCDATA = 0;

	for ( int repet = 0; repet <10; repet ++ )
	{
		float value;
		unsigned char readBuf[2], Read_length = 2, timeout_spi =0;
		//Cmd_Channel[ADC_Channel] = ( 0x8330 | (ADC_Channel<< 10) );
		ADCCHVAL = 0;
		SPI_wait_if_busy(currentSpiuse);		 // Check if SPI controller is busy.
		GPIO_write_pin(SPI_CS3,LOW);
		usleep(7);		//75  3
		SPI_transmit(currentSpiuse, Cmd_Channel[ADC_Channel3] ); // ( 0x8310 | (ADC_Channel<< 10) ));
		//usleep(3);		//75   50
		//printf("\n\r Cmd_Channel %x", Cmd_Channel[ADC_Channel]);
		ADCCHVAL = (SPI_receive(currentSpiuse)) & 0x0FFF; //data

		if (( ( ADCCHVAL !=0 ) && ( ADCCHVAL != 0x0FFF ) )  && ( ADCCHVAL > Default_ADCDATA )  )
		{
			previousADCDATA = currentADCDATA;
			currentADCDATA = ADCCHVAL;
			Start_previousdataFlag1 = 1;
			validdataindex ++;
			//
			if ( ( validdataindex > 1  ) && ( ( previousADCDATA >= ( currentADCDATA - 20 ) ) && ( previousADCDATA <= ( currentADCDATA + 20 ) ) ))
			{
				//printf("\n\r\t\t:: %d ",currentADCDATA);
				currentADCDATA = ( currentADCDATA + previousADCDATA ) / 2;
				//printf(":--::: %d: %d-",currentADCDATA, previousADCDATA);
			}
		}
		//usleep(5);
		/*if ( ADCCHVAL == 4095 )
		{
			ADCCHVAL  = 0;
		}*/
		LD3_ADCCHVAL[repet] = ADCCHVAL;
		//printf(":: %d-",ADCCHVAL);		//printf(":val1:- %d -Tx %x-",ADCCHVAL, Cmd_Channel[ADC_Channel]);
		GPIO_write_pin(SPI_CS3,HIGH); //GPIO_write_pin(currentChipSelectGPIO,HIGH);
		usleep(100);     //100    50
	}
	usleep(200);

	return (currentADCDATA);
}
/****************************************************************************************************************
Function Name: LD4_Read_ADC7490_CurrentVal
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
unsigned short LD4_Read_ADC7490_CurrentVal (unsigned short ADC_Channel4) //, unsigned char spi_slave )
{
	// GPIO0 [0] SPI_CS0,  1- CS1, 2- CS2, 3- CS3
	unsigned short ADCCHVAL = 0, Start_previousdataFlag1 = 0, validdataindex = 0;
	currentADCDATA = 0;

	for ( int repet = 0; repet <10; repet ++ )
	{
		float value;
		unsigned char readBuf[2], Read_length = 2, timeout_spi =0;
		//Cmd_Channel[ADC_Channel] = ( 0x8330 | (ADC_Channel<< 10) );
		ADCCHVAL = 0;
		SPI_wait_if_busy(currentSpiuse);		 // Check if SPI controller is busy.
		GPIO_write_pin(SPI_CS4,LOW);
		usleep(7);		//75  3
		SPI_transmit(currentSpiuse, Cmd_Channel[ADC_Channel4] ); // ( 0x8310 | (ADC_Channel<< 10) ));
		//usleep(3);		//75   50
		//printf("\n\r Cmd_Channel %x", Cmd_Channel[ADC_Channel]);
		ADCCHVAL = (SPI_receive(currentSpiuse)) & 0x0FFF; //data

		if (( ( ADCCHVAL !=0 ) && ( ADCCHVAL != 0x0FFF ) )  && ( ADCCHVAL > Default_ADCDATA )  )
		{
			previousADCDATA = currentADCDATA;
			currentADCDATA = ADCCHVAL;
			Start_previousdataFlag1 = 1;
			validdataindex ++;
			//
			if ( ( validdataindex > 1  ) && ( ( previousADCDATA >= ( currentADCDATA - 20 ) ) && ( previousADCDATA <= ( currentADCDATA + 20 ) ) ))
			{
				//printf("\n\r\t\t:: %d ",currentADCDATA);
				currentADCDATA = ( currentADCDATA + previousADCDATA ) / 2;
				//printf(":--::: %d: %d-",currentADCDATA, previousADCDATA);
			}
		}
		//usleep(5);
		/*if ( ADCCHVAL == 4095 )
		{
			ADCCHVAL  = 0;
		}*/
		LD4_ADCCHVAL[repet] = ADCCHVAL;
		//printf(":: %d-",ADCCHVAL);		//printf(":val1:- %d -Tx %x-",ADCCHVAL, Cmd_Channel[ADC_Channel]);
		GPIO_write_pin(SPI_CS4,HIGH); //GPIO_write_pin(currentChipSelectGPIO,HIGH);
		usleep(100);     //100    50
	}
	usleep(200);

	return (currentADCDATA);
}
/****************************************************************************************************************
Function Name: Initialize_SPI_Chipselect
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
void Initialize_SPI_Chipselect (void)
{
	GPIO_write_pin(SPI_CS1,1);
	GPIO_write_pin(SPI_CS2,1);
	GPIO_write_pin(SPI_CS3,1);
	GPIO_write_pin(SPI_CS4,1);
}

/****************************************************************************************************************
Function Name: Clear_Last_LampCurrent
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
void Clear_Last_LampCurrent(void)
{
	for (unsigned char ch = 0; ch < 64; ch++)
	{
		LampADCVal[ch]  = 0;
		LampCurrent[ch] = 0;
		LampFBStatus[ch]= 0x04;
		LampCurrentAVGCount[ch] = 0;
		LampCurrentAVGSetFlag[ch] = 0;
		LampCurrentAVG[ch] = 0;
	}
	for (unsigned char ch = 0; ch < 64; ch++)
	{
		CLampFBStatus[ch] = 0x00;
	}
	for (unsigned char ch = 0; ch < 50; ch++)
	{
		Rx_Databuffer[ch] = 0x00;
	}
	for (unsigned char ch = 0; ch < 16; ch++)
	{
		Chk_Rx_Databuffer[ch]  =  0x00;
	}
}

/****************************************************************************************************************
Function Name: CuSensorRead
Description : To read registers of CuSensorRead .
Input: char *readBuf, int length, char opcode
outputs: nil.
Status: Tested
****************************************************************************************************************/
unsigned short CuSensorRead( unsigned short opcode)
{
	unsigned char readBuf[2], Read_length = 2, timeout_spi =0, LenOff = 0;
	/*if  (length == 2 )
	{
		SPI_wait_if_busy(currentSpiuse);		 // Check if SPI controller is busy.
		SPI_set_CSAAT_pin(currentSpiuse, LOW); // Setting CSAAT bit LoW.
		//SPI_transmit(currentSpiuse, opcode);
		while (Read_length)
		{
			SPI_transmit(currentSpiuse, opcode);
			//usleep(1000);
			readBuf[Read_length-1] = SPI_receive(currentSpiuse); //data
			//readBuf++;
			Read_length--; // since 2 bytes are read in one time.
		}
		SPI_set_CSAAT_pin(currentSpiuse, HIGH); // Setting CSAAT bit HIGH.
    }
	usleep(3000);*/
	Read_length = 2;
	SPI_wait_if_busy(currentSpiuse);		 // Check if SPI controller is busy.
	SPI_set_CSAAT_pin(currentSpiuse, LOW); // Setting CSAAT bit LoW.
	SPI_transmit(currentSpiuse, opcode);
	/*while (Read_length)
	{
		//SPI_transmit(currentSpiuse, opcode);
		//usleep(1000);
		readBuf[LenOff] = SPI_receive(currentSpiuse); //data
		LenOff++;
		//readBuf++;
		Read_length--; // since 2 bytes are read in one time.
	}*/
	LDC_ADCCurrent.ADCCurrentVal = SPI_receive(currentSpiuse);
	SPI_set_CSAAT_pin(currentSpiuse, HIGH); // Setting CSAAT bit HIGH.
	//LDC_ADCCurrent.ADCCurrentByte[0]	=	readBuf[0];
	//LDC_ADCCurrent.ADCCurrentByte[1]	=	readBuf[1];
	//if ( ( SPI_read_rx_reg(0) == 0 ) && ( ++timeout_spi < 10 ))
	return (LDC_ADCCurrent.ADCCurrentVal);
}
