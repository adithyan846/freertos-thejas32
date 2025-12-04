/*
 * SystemInitialization.h
 *
 *  Created on: 19 Aug 2025
 *      Author: ratheesh
 */

#ifndef INITIALIZATION_SYSTEMINITIALIZATION_H_
#define INITIALIZATION_SYSTEMINITIALIZATION_H_

extern void Clear_Last_LampCurrent(void);
void Initialization (void);

extern void UART_Initialization(void);
extern void CuSensor_SPI_Begin(unsigned char spiNo);
extern void Initialize_SPI_Chipselect (void);
extern void ReadLampDriverCardAvailability(void);

#endif /* INITIALIZATION_SYSTEMINITIALIZATION_H_ */
