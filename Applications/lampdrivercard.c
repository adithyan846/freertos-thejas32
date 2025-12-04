/*
 * lampdrivercard.c
 *
 *  Created on: 19 Aug 2025
 *      Author: ratheesh
 */


#include <CommonDb.h>
#include "i2c.h"
#include "i2c_api.h"
#include "stdlib.h"
#include "gpio.h"
#include "Includesapp/lampdrivercard.h"

/****************************************************************************************************************
Function Name:
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
void ReadLampDriverCardAvailability(void)
{    //19,18,17,16
	//LDsense = ((~GPIO_read_pin(19)) | ((~GPIO_read_pin(18)) <<1) | ((~GPIO_read_pin(17)) << 2) | ((~GPIO_read_pin(16)) << 3));
	LDsense = ~( ((unsigned char) GPIO_read_pin(19) ) | ((unsigned char)( GPIO_read_pin(18) << 1 )) |
				       (unsigned char)( GPIO_read_pin(17) << 2 ) | ((unsigned char)( GPIO_read_pin(16)) << 3 ))&0X0f;

	printf("\n\rLDsense : %d:%d:%d:%d : %x",GPIO_read_pin(19),GPIO_read_pin(18),GPIO_read_pin(17),GPIO_read_pin(16),LDsense);
	if(LDsense)
	{
		if((LDsense & 0x01) == 1 )
		{
			AvailableLampsForSwitching[0] = LAMP_1_TO_16;
			NoOfLDCardAvailable++;
			printf("\n\rCard 1 present");
		}
		if(((LDsense & 0x02) >> 1) == 1)
		{
			AvailableLampsForSwitching[1] = LAMP_17_TO_32;
			NoOfLDCardAvailable++;
			printf("\n\rCard 2 is present");
		}
		if(((LDsense & 0x04) >> 2) == 1)
		{
			AvailableLampsForSwitching[2] = LAMP_33_TO_48;
			NoOfLDCardAvailable++;
			printf("\n\rCard 3 is present");
		}
		if(((LDsense & 0x08) >> 3) == 1)
		{
			AvailableLampsForSwitching[3] = LAMP_49_TO_64;
			NoOfLDCardAvailable++;
			printf("\n\rCard 4 is present");
		}
	}
	else
	{
		NoOfLDCardAvailable = 0;
		printf("\n\rNo Cards present");
	}
}
/****************************************************************************************************************
Function Name:
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
void LampInput (UI I2C_num,UC Switching_Data1,UC Switching_Data2,UC Lamp_No)
{
			i2c_start(I2C_num,0,0);
			txAddress=Lamp_No<<1|I2C_WRITE;
			txBufferIndex = 0;
			txBufferLength = 0;

			i2c_data_write(I2C_0, &txAddress, 1);

			txBuffer[0] = Switching_Data1;
			txBuffer[1] = Switching_Data2;
			txBufferLength = 2;
			i2c_data_write(I2C_num, txBuffer, txBufferLength);
			i2c_stop(I2C_num);
			txBufferLength = 0;
}
/****************************************************************************************************************
Function Name:
Description :
Input: nil
outputs: nil.
Status: Tested
****************************************************************************************************************/
void SwitchOffAllLamps (void)
{
	/**********Switch off Lamps**********/
	for(unsigned int i = 0; i < NoOfLDCardAvailable; i++)
	{
		i2c_beginTransmission(AvailableLampsForSwitching[i]); // Start with device write address
		i2c_write(0xff);
		i2c_write(0xff);
		i2c_endTransmission(TRUE);
	}
	/**********Switch off Lamps**********/

}
