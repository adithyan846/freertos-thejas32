#ifndef __UART_H
#define __UART_H

/***************************************************
* Module name: uart.h 
*
* Copyright 2007 Company CDAC(T). 
* All Rights Reserved.
*
*  The information contained herein is confidential 
* property of Company. The user, copying, transfer or 
* disclosure of such information is prohibited except
* by express written agreement with Company.
*
*
* Module Description:
* UART registers and function declarations
*
***************************************************/

/*  Include section
*
***************************************************/

#include "datatype.h"	//for datatypes 
#include "hw_platform.h"

/*  Defines section
*
***************************************************/

typedef struct uart_reg
{
	UI   UART_DR; //0x00
	UI   UART_IE; //0x4
	UI   UART_IIR; //0x8	
	UI   UART_LCR; //0xc	
	UI   Dummy10; //0x10	
	UI   UART_LSR; //0x14
}UART_REG;
/*  Function declaration section
* 
*
***************************************************/

void Init_uart(void);
void tx_uart(UC tx_char);
UC Rx_uart(void);
void datadisp(UC disp_data);
void Transmit_uart(UC *data_ptr);
UC check_rx_uart(void);
UC get_hex(void);
UC disp_data(void);
void disp_decimal(UI data);
void disp_Rx_data(UI data);
void disp_Rx_data_UL(unsigned long long data);
void datadisp_hex(UC disp_data); 
void disp_Rx_data_16(US data);
void disp_sim_hex_16(US data);
void Tx_style(UC *data_ptr);

US Receive_Decimal(UC NofDigits, UI Max);
//UC Get_Choice(UC Max);

UC check_rx_uart_test(UC *x,UC *y);

#define uart_regs (*((volatile UART_REG *)CORE_UART_BASE))
#endif /*__UART_H*/


