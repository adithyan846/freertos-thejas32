/*
 * i2c_api.h
 *
 *  Created on: 19 Aug 2025
 *      Author: ratheesh
 */

#ifndef INCLUDESAPP_I2C_API_H_
#define INCLUDESAPP_I2C_API_H_

#include "stdlib.h"
#include "i2c.h"

#define BUFFER_LENGTH	3
#define I2C_READ	1
#define I2C_WRITE	0

#define System_clock 	100000000	//75MHz
#define I2C_clock		400000	   //400KHz

extern UC lamp_data[8];


void i2c_init(unsigned char i2c_num);
void i2c_beginTransmission(unsigned char i2c_address);
UC i2c_data_write(UC i2c_number, UC *write_data, UC write_length);
int i2c_write(unsigned char data);
int i2c_multiWrite(unsigned char *data,int length);
//char i2c_read(void);
void i2cRead_request(unsigned char address, unsigned char size,unsigned char sendstop);
unsigned char i2c_endTransmission(unsigned char sendstop);

#endif /* INCLUDESAPP_I2C_API_H_ */
