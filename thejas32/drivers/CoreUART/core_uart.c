/***************************************************
* Module name: uart.c 
*
* Copyright 2007 Company CDAC(T)
* All Rights Reserved.
*
*  The information contained herein is confidential 
* property of Company. The user, copying, transfer or 
* disclosure of such information is prohibited except
* by express written agreement with Company.
*
* First written on 12/07 by Sreenadh.S, S.R.F..
*
* Module Description:
* UART routines 
*
***************************************************/

/*  Include section
* 
*
***************************************************/

#include <core_uart.h>
#include "datatype.h"


/**************************************************
* Function name	: void Init_uart(void)
* returns		    	: Nil
* Created by		: Sreenadh.S
* Date created		: 04/01/2007
* Description		: Initialize UART.   
* Notes			: To initialize UART - Baud Rate = 115200 Clock 25MHz
*                     	8 Data bits, 1 Stop bit, no Parity,disable DR intrpt & 
*                     	THRE intrpt     
**************************************************/

void Init_uart(void)
{
	uart_regs.UART_LCR = 0x83; //Divisor latch enabled
	uart_regs.UART_DR  = 0x0d;//0x10-30mHz;//0x0d-25mHz;0x1b-50mHz//0x36; //Divisor LSB
	uart_regs.UART_IE  = 0x00; //Divisor MSB
	uart_regs.UART_LCR = 0x03; //Divisor latch disabled, stop-bits = 1, parity = none, data-bits = 8
	uart_regs.UART_IE  = 0x00; //Interrupts disabled
} 

/**************************************************
* Function name	: void Transmit_uart(UC *data_ptr)
*    returns		: Nil
*   *Char           	: Pointer to the string to be transmitted
* Created by		: Sreenadh.S
* Date created		: 04/01/2007
* Description		: Tx character through UART upto '\0'  
* Notes			:   
**************************************************/


/**************************************************
 * Function name	: void Transmit_string_uart(ee_u8 *data_ptr)
 *    returns	: Nil
 *   *Char           : Pointer to the string to be transmitted
 * Created by		: Sreenadh.S
 * Date created		: 04/01/2007
 * Description		: Tx character through UART upto '\0'
 * Notes			:
 **************************************************/

void Transmit_uart(UC *data_ptr) {
	UC lsr;

	while (*data_ptr != '\0') {
		tx_uart(*data_ptr);
		data_ptr++;
	}
}

/**************************************************
 * Function name	: void tx_uart(UC tx_char)
 *    returns		: Nil
 * Tx_char           : Character to Tx
 * Created by		: Sreenadh.S
 * Date created		: 04/01/2007
 * Description		: Tx 1 character through UART
 * Notes			:
 *************************************************/

void tx_uart(UC tx_char) {
	UC lsr;

	//__asm volatile( "csrc mie, %0" :: "r"(0x880) );

	uart_regs.UART_DR = tx_char;
	__asm__ __volatile__ ("fence");
	do {
		lsr = uart_regs.UART_LSR;
		__asm__ __volatile__ ("fence");
		lsr = lsr & 0x20;
	} while (lsr != 0x20);
	//__asm volatile( "csrs mie, %0" :: "r"(0x880) );

	//uart_regs.UART_LSR &= ~0x20; //For emulation only FIXME
}

/**************************************************
 * Function name	: UC tx_uart(void)
 *    returns		: Nil
 * Tx_char           : Character to Rx
 * Created by		: Sreenadh.S
 * Date created		: 04/01/2007
 * Description		: Rx 1 character through UART
 * Notes			:
 **************************************************/

UC Rx_uart(void) {
	UC lsr, Rx_char;

	do {
		lsr = uart_regs.UART_LSR;
		__asm__ __volatile__ ("fence");
	} while ((lsr&1) == 0);

	Rx_char = uart_regs.UART_DR;
	__asm__ __volatile__ ("fence");

	//uart_regs.UART_LSR &= ~0x1;  //For emulation only FIXME
	return Rx_char;
}

/**************************************************
* Function name		: UC check_rx_uart()
*   returns			: LSR status
* Created by		: Sreeju.G.R.
* Date created		: 22/07/2009
* Description		: Data display    
**************************************************/

UC check_rx_uart()
{

	return ((uart_regs.UART_LSR)&0x01);
}


/**************************************************
* Function name		: UC check_rx_uart()
*   returns			: LSR status
* Created by		: Sreeju.G.R.
* Date created		: 22/07/2009
* Description		: Data display    
**************************************************/

UC check_rx_uart_test(UC *x,UC *y)
{
	UC ch=0;
	*x=((uart_regs.UART_LSR)&0x01);
	ch = uart_regs.UART_DR;
	*y=ch;
	return(*x,*y);
}


/************************************************************
* Function name		: UC get_hex()
* returns		    : 1 byte unsigned character (number).
* Date created		: 22/07/2009
* Description		: To get hex value and display it to HT.   
*************************************************************/

UC get_hex()
{
	unsigned char number=0,dig1,dig2,count=2,rx;
	while(count)
	{
		rx = Rx_uart();
		if((rx>=0x30) && (rx<=0x39))
		{
			tx_uart(rx);
			rx=rx-0x30;
		}
		else if((rx >= 'A') && (rx <= 'F'))  
		{
			tx_uart(rx);
			rx=rx-0x37;
		}
		else if ((rx >= 'a') && (rx <= 'f'))
		{
			tx_uart(rx);
			rx=rx-0x57;
		}
	
		else
			continue;
		if (count==2)
		dig1=rx;
		else
		dig2=rx;
		count--;
	}
	number = (dig1 << 4);
	number |= dig2;
	return number;
}	
 
/************************************************************
* Function name		:UC disp_hex()
* returns		    : 1 byte unsigned character (number).
* Date created		: 22/07/2009
* Description		: To get hex value and display it to HT (only one nibbble).   
*************************************************************/
 
UC disp_hex()
{
	unsigned char number=0,count=1,rx;
	while(count)
	{
		rx = Rx_uart();
		if((rx>=0x30) && (rx<=0x39))
		{
			tx_uart(rx);
			rx=rx-0x30;
		}
		else if((rx >= 'A') && (rx <= 'F'))  
		{
			tx_uart(rx);
			rx=rx-0x37;
		}
		else if ((rx >= 'a') && (rx <= 'f'))
		{
			tx_uart(rx);
			rx=rx-0x57;
		}
	
		else
			continue;
		if (count==1)
			number=rx;
			count--;
		
	}
	
	return number;
}	

/************************************************************
* Function name		: void disp_decimal(UI data)
* returns		    : 1 byte unsigned character (number).
* Date created		: 22/07/2009
* Description		: To display decimal value corresponding to entered hex value.   
*************************************************************/
 
void disp_decimal(UI data)
{
    unsigned int digits[10],loop=0,value;
    value = data;
            //value=0;
    if( value )
    {
    	while(value)
        {
    		digits[loop] = ( value % 0x0A ) + 0x30; 
			value /= 0x0A;// 0x0F/0x0A=1 so 0x0F= decimal 15
            loop++;
        }
	}
	else
	{
		tx_uart(0x30);
	}

	while(loop--)
        tx_uart(digits[loop]);
}


/************************************************************
* Function name		: void disp_Rx_data(UI data)
* returns		    : 1 byte unsigned character (number).
* Date created		: 22/07/2009
* Description		: To get hex value and display it to HT (only one nibbble).   
*************************************************************/

void disp_Rx_data(UI data)
{
		UC temp=0;
		temp = data>>24;
		datadisp_hex(temp);
		temp = data>>16;
		datadisp_hex(temp);
		temp = data>>8;
		datadisp_hex(temp);
		temp = (data);
		datadisp_hex(temp);
}

void disp_Rx_data_UL(unsigned long long data)
{
		UC temp=0;
		temp = data>>56;
		datadisp_hex(temp);
		temp = data>>48;
		datadisp_hex(temp);
		temp = data>>40;
		datadisp_hex(temp);
		temp = data>>32;
		datadisp_hex(temp);
		temp = data>>24;
		datadisp_hex(temp);
		temp = data>>16;
		datadisp_hex(temp);
		temp = data>>8;
		datadisp_hex(temp);
		temp = (data);
		datadisp_hex(temp);
}

/**************************************************
* Function name	: void datadisp_hex(UC disp_data)
* returns		: Nil
* Created by		: Sreenadh.S
* Date created		: 04/08/2007
* Description		: Data display    
* Notes			:   
**************************************************/

void datadisp_hex(UC disp_data)
{
	UC temp;
	UC ascii;

	temp=disp_data;

	temp=(temp&0xf0)>>4;
	if(temp>9)
	{

		temp=temp-9;
		ascii=temp+0x40;

	}
	else ascii=temp+0x30;
	tx_uart(ascii);

	temp=disp_data;
	temp=temp&0xf;
	if(temp>9)
	{

		temp=temp-9;
		ascii=temp+0x40;

	}
	else ascii=temp+0x30;
	tx_uart(ascii);
}
void disp_Rx_data_16(US data)
{
		UC temp=0;
		temp = (data);
		datadisp_hex(temp);
		temp = data>>8;
		datadisp_hex(temp);
}

void disp_sim_hex_16(US data)
{
		UC temp=0;
		temp = data>>8;
		tx_uart(temp);
		temp = (data);
		tx_uart(temp);
}

 /************************************************************
* Function name		: UC get_decimal()
* returns		    : 1 byte unsigned character (number).
* Date created		: 22/07/2009
* Description		: To get hex value and display it to HT.   
*************************************************************/
/*
US Receive_Decimal(UC NofDigits, UI Max)
{                                                 
    UC Index, Temp = 0;  
    US Decimal = 0;
    while(1)
    {
	    for(Index = 0; Index < NofDigits; Index++) 
	    {
	        Temp = Get_Choice('9'); 
	        if (Temp == 0x0d) // Enter key
	          break;
	        Temp  = Temp - 0x30;
	        Decimal = (Decimal)*10 +Temp;
	    }
	    
	    if ((Decimal > Max)|(Decimal == 0))
	    {
	        Transmit_uart((UC *)"\r\n\tMAC - Enter a Valid length !");
	        Transmit_uart((UC *)"\n\r\tMAC - Enter Length of Frame in bytes : "); 
	        Decimal = 0;
	        continue; 
	    } 
	    else
	    {
	        return Decimal; 
	    } 
	}      
   // Transmit_uart((UC *)"\r\nDecimal= %xH %dD",*Decimal,*Decimal); 
}
*/
/**************************************************
* Function name	: UC Get_Choice(UC Max)
*    returns		: Nil
* Tx_char           : Character to Rx
* Created by		: Sreeju. G.R
* Date created		: 15/09/2011
* Description		: Rx 1 character through UART    
* Notes			:   
**************************************************/
/*
UC Get_Choice(UC Max)
{
	UC lsr,Rx_char;
    while(1)
    {
    	do
    	{
    		lsr=uart_regs.UART_LSR;
    		lsr=lsr&1;
    	}while(!lsr);
    	Rx_char = uart_regs.UART_DR; 
    	
    	if((Rx_char >='0') && (Rx_char <= Max) || (Rx_char == 0x0d))
    	{
    		tx_uart(Rx_char);
    	    break;
    	}    
    	else
    	    continue;
 
	}
	return Rx_char;
} 

void Tx_style(UC *data_ptr)
{
	UC ch,i=0,j,k;
	UC arr[25],temp[25];
	while(*data_ptr!='\0')
	{
		arr[i]=*data_ptr;
		temp[i] = arr[i];// Keeping original copy
		data_ptr++;
		i++;
	}	
	for(i=0;arr[i]!='\0';i++)
	{
		if((arr[i]>=0x41) && (arr[i]<=0x5A))
		{  
			ch = arr[i];
			ch+=0x20;
			arr[i] = ch;
			Transmit_uart((UC *)"\r\t");
			for(j=0;arr[j]!='\0';j++)
				tx_uart(arr[j]);
			for(k=0;temp[k]!='\0';k++)
				arr[k] = temp[k];
		}
		delay();   
	} 
	Transmit_uart((UC *)"\r\t");
	for(j=0;arr[j]!='\0';j++)
		tx_uart(arr[j]);
}	*/
