/*
 * SystemInitialization.c
 *
 *  Created on: 19 Aug 2025
 *      Author: ratheesh
 */


#include "SystemInitialization.h"
#include "stdlib.h"
#include "spi.h"


void Initialization (void)
{
	//UART_Initialization();
	Initialize_SPI_Chipselect ();
	Clear_Last_LampCurrent();
	ReadLampDriverCardAvailability();
	printf("\n\r|    start SPI0  Initialization    |");
	//CuSensor_SPI_Begin(MDP_SPI_0);      //commented by me
	printf("\n\r|    SPI0  Initialization    |");

}
