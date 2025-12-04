/*
 * lampdrivercard.h
 *
 *  Created on: 19 Aug 2025
 *      Author: ratheesh
 */

#ifndef INCLUDESAPP_LAMPDRIVERCARD_H_
#define INCLUDESAPP_LAMPDRIVERCARD_H_

#define TRUE 1
#define FALSE 0
#define BUFFER_LENGTH	3

// GPIO25 for LD1sense
// GPIO26 for LD2sense
// GPIO27 for LD3sense
unsigned char AvailableLampsForSwitching[10], LDsense = 0x00;
unsigned int NoOfLDCardAvailable = 0;

extern unsigned char txAddress;
extern unsigned char txBuffer[BUFFER_LENGTH];
extern unsigned char txBufferIndex;
extern unsigned char txBufferLength;

void ReadLampDriverCardAvailability(void);
void LampInput (UI I2C_num,UC Switching_Data1,UC Switching_Data2,UC Lamp_No);
void SwitchOffAllLamps (void);


#endif /* INCLUDESAPP_LAMPDRIVERCARD_H_ */
