/***************************************************************************
 * Project                               :  MDP
 * Name of the file                      :  interrupt.c
 * Brief Description of file             :  Driver to control the Interrupt.
 * Name of Author                        :  Sreeju G R
 * Email ID                              :  sreeju@cdac.in

  Copyright (C) 2020  CDAC(T). All rights reserved.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.

***************************************************************************/

/**
 @file interrupt.c
 @brief Contains routines for Iinterrupt handler, IRQ enable functions
 @detail Includes software functions to enable, handling functions for intterrupt
 */

#include "stdlib.h"
#include "interrupt.h"
#include "timer.h"
#include "config.h"
#include "encoding.h"



#if __riscv_xlen == 64
#define MAXIMUM_INTR_COUNT 64
#else
#define MAXIMUM_INTR_COUNT 32
#endif

#define read_const_csr(reg) ({ unsigned long __tmp; \
  asm ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })


//extern volatile UL INTERRUPT_Handler_0;
//extern volatile UL trap_entry;

volatile fp irq_table[32]; //Array of Function pointer.
fp sw_irq_function; //Software IRQ Function pointer.


/** @fn    enable_irq
  @brief   Enable processor interrupt and Global interrupt in machine mode.
  @details The function "set_csr" will set the external interrupt bit in MIE register and Machine mode interrupt in MSTATUS register.

  @param[in]  No input parameter.
  @param[Out] No output parameter.
*/
void enable_irq(void) {
    set_csr(mie, MIP_MEIP);			// Set MEIE bit in MIE register for Machine External Intr.
    set_csr(mstatus, MSTATUS_MIE);		// Set global machine intr bit (3rd bit) in MSTATUS register.
#if __riscv_xlen == 64
	//For 64 Bit processors		
    //write_csr(mtvec,(UL)&INTERRUPT_Handler_0);		// Set MTVEC register with vector address.
#else
	//For32 Bit processors
   // write_csr(mtvec,(UI)&INTERRUPT_Handler_0);		// Set MTVEC register with vector address.
#endif
}


/** @fn   disable_irq
  @brief   disable processor interrupt and Global interrupt in machine mode.
  @details The function "set_csr" will set the external interrupt bit in MIE register and Machine mode interrupt in MSTATUS register.

  @param[in]  No input parameter.
  @param[Out] No output parameter.
*/
void disable_irq(void) {
    clear_csr(mie, MIP_MEIP);			// clear MEIE bit in MIE register for Machine External Intr.
    clear_csr(mstatus, MSTATUS_MIE);		// clear global machine intr bit (3rd bit) in MSTATUS register.
#if __riscv_xlen == 64
	//For 64 Bit processors		
    //write_csr(mtvec,(UL)&INTERRUPT_Handler_0);		// Set MTVEC register with vector address.
#else
	//For32 Bit processors
   // write_csr(mtvec,(UI)&INTERRUPT_Handler_0);		// Set MTVEC register with vector address.
#endif
}

/** @fn    enable_sw_irq

  @brief   Enable processor interrupt and Global interrupt in machine mode.
  @details The function "set_csr" will set the software interrupt bit in MIE register and Machine mode interrupt in MSTATUS register.

  @param[in]  No input parameter.
  @param[Out] No output parameter.
*/
void enable_sw_irq(void) {
#if __riscv_xlen == 64
	//For 64 Bit processors		
    //write_csr(mtvec,(UL)&INTERRUPT_Handler_0);		// Set MTVEC register with vector address.
    
#else
	//For32 Bit processors
   // write_csr(mtvec,(UI)&INTERRUPT_Handler_0);		// Set MTVEC register with vector address.
    
#endif
    set_csr(mie, MIP_MSIP); // Set MSIE bit in MIE register for Machine SW intr.
    set_csr(mstatus, MSTATUS_MIE); // Set global machine intr bit (3rd bit) in MSTATUS register.
    clear_csr(mideleg, MIP_MSIP);
   
}


/** @fn    disable_sw_irq

  @brief   Disable machine software interrupt in MIE register
  @details 

  @param[in]  No input parameter.
  @param[Out] No output parameter.
*/
void disable_sw_irq(void) {

  clear_csr(mie, MIP_MSIP);	// Clear MSIP bit in MIE register for Machine 
   
}


/** @fn void interrupt_enable(UC intr_number)
  @brief  Enable interrupt in controller.
  @details The interrupt enable register is set with the enable value of peripheral selected.
 
  @param[in] unsigned char intr_number: The number at which the periphral will interrupt
  @param[Out] No output parameter.
*/

void interrupt_enable(UC intr_number)
{
	enable_irq();	// Enable global interrupt and external interrupt of the processor.
	intr_regs.INTR_EN |= ((UI)1 << intr_number);	// Enable interrupt for peripheral in interrupt controller.
	__asm__ __volatile__ ("fence");	
}





/** @fn void interrupt_disable(UC intr_number)
  @brief  Disable interrupt in controller.
  @details The interrupt disable register is set with the disable value of peripheral selected.
 
  @param[in] unsigned char intr_number: The number at which the periphral will interrupt
  @param[Out] No output parameter.
*/

void interrupt_disable(UC intr_number)
{
	//enable_irq();	/disable global interrupt and external interrupt of the processor.
	intr_regs.INTR_EN &= ~((UL)1 << intr_number);	// disable interrupt for peripheral in interrupt controller.
	__asm__ __volatile__ ("fence");	
}

/** @fn void interrupt_disable_all(void)
  @brief  Disable interrupt in controller.
  @details The interrupt disable register is set with the disable value of peripheral selected.
 
  @param[in] unsigned char intr_number: The number at which the periphral will interrupt
  @param[Out] No output parameter.
*/

void interrupt_disable_all(void)
{
	intr_regs.INTR_EN = 0;	// disable interrupts
	__asm__ __volatile__ ("fence");	
}


 
/** @fn void irq_register_handler(UC irq_no, void (*irq_handler)())
 @brief  Initialise peripheral interrupt handler to a table.
 @details Enable processor interrupt and Global interrupt in machine mode  and init irq_table.
 @warning 
 @param[in] No input parameter.
 @param[Out] No output parameter.
*/
void irq_register_handler(UC irq_no, void (*irq_handler)()){///*irq_handler is function pointer to user defined intr handler
    	irq_table[irq_no] = irq_handler;
}

/** @fn void sw_irq_register_handler(UC irq_no, void (*irq_handler)())
 @brief  Initialise peripheral interrupt handler to a table.
 @details Enable processor interrupt and Global interrupt in machine mode  and init irq_table.
 @warning 
 @param[in] No input parameter.
 @param[Out] No output parameter.
*/
void sw_irq_register_handler( void (*irq_handler)()){///*irq_handler is function pointer to user defined intr handler
    	sw_irq_function = irq_handler;
}


/** @fn interrupt_handler
 @brief  Invoke the peripheral interrupt handler.
 @details The interrupt controller's status register is read to identify the interrupted peripheral and then the corresponding
	  handler for the peripheral is invoked.
 @warning 
 @param[in] No input parameter.
 @param[Out] No output parameter.
*/


#if __riscv_xlen == 64
	#define portWORD_SIZE 8
	#define store_x sd
	#define load_x ld
#elif __riscv_xlen == 32
	#define store_x sw
	#define load_x lw
	#define portWORD_SIZE 4
#else
	#error Assembler did not define __riscv_xlen
#endif

#define portCONTEXT_SIZE ( 30 * portWORD_SIZE )



void print_csr(void){

  if(read_const_csr(mcause) == 0xb)
    return;

//  if(read_const_csr(mcause) == 0x80000007)
 //   return;

	printf("save mepc : %x\n\r",read_const_csr(mepc));
	register void* sp __asm__("sp"); // Declare a register variable bound to `sp`
	printf("save sp = %p\n\r", sp);
	printf("save mcause: %x\n\r",read_const_csr(mcause));

	printf("save mstatus: %x\n\r\n\r",read_const_csr(mstatus));
}

void print_csr_r(void){

  if(read_const_csr(mcause) == 0xb)
    return;

//  if(read_const_csr(mcause) == 0x80000007)
  //  return;

	printf("restore mepc : %x\n\r",read_const_csr(mepc));
	register void* sp __asm__("sp"); // Declare a register variable bound to `sp`
	printf("restore sp = %p\n\r", sp);
	printf("restore mcause: %x\n\r",read_const_csr(mcause));
	printf("restore mstatus: %x\n\r\n\r",read_const_csr(mstatus));
	printf("+++++++++++++++++++++++++++++++\n\r");

}



void interrupt_handler(void){

		
	UI intr_status = intr_regs.INTR_STATUS; // Read interrupt status register.
		

	//printf("EPC : %lx\n\r",read_const_csr(mepc));
	//printf("Cause : %lx\n\r",read_const_csr(mcause));
	//printf("badaddress: %lx\n\r",read_const_csr(mbadaddr));
	
	//UI macuse_val = read_csr(mcause);
	
	
	//printf("intr_status= %d\n\r", intr_status);
	//printf("mcause_val= %d\n\r", macuse_val);
	for(UI i = 0; i < MAXIMUM_INTR_COUNT ; i++)  /*MAXIMUM_INTR_COUNT*/
	{
		if ((intr_status >> i) & (UI)1){
		    /////push

		    asm volatile ("addi sp, sp, -120");
		    asm volatile ("sw x1, 4( sp )");
		asm volatile ("sw x5, 8( sp )  ");
		asm volatile ("sw x6, 12( sp )  ");
		asm volatile ("sw x7, 16( sp )  ");
		asm volatile ("sw x8, 20( sp )  ");
		asm volatile ("sw x9, 24( sp )  ");
		asm volatile ("sw x10, 28( sp ) ");
		asm volatile ("sw x11, 32( sp ) ");
		asm volatile ("sw x12, 36( sp ) ");
		asm volatile ("sw x13, 40( sp )");
		asm volatile ("sw x14, 44( sp )");
		asm volatile ("sw x15, 48( sp )");
		asm volatile ("sw x16, 52( sp )");
		asm volatile ("sw x17, 56( sp )");
		asm volatile ("sw x18, 60( sp )");
		asm volatile ("sw x19, 64( sp )");
		asm volatile ("sw x20, 68( sp )");
		asm volatile ("sw x21, 72( sp )");
		asm volatile ("sw x22, 76( sp )");
		asm volatile ("sw x23, 80( sp )");
		asm volatile ("sw x24, 84( sp )");
		asm volatile ("sw x25, 88( sp )");
		asm volatile ("sw x26, 92( sp )");
		asm volatile ("sw x27, 96( sp )");
		asm volatile ("sw x28, 100( sp )");
		asm volatile ("sw x29, 104( sp )");
		asm volatile ("sw x30, 108( sp )");
		asm volatile ("sw x31, 112( sp )");


			irq_table[i]();// Invoke the peripheral handler as function pointer.	
			//pop

		asm volatile ("lw  x1, 4( sp )");
		asm volatile ("lw  x5, 8( sp )");
		asm volatile ("lw  x6, 12( sp )");
		asm volatile ("lw  x7, 16( sp )");
		asm volatile ("lw  x8, 20( sp )");
		asm volatile ("lw  x9, 24( sp )");
		asm volatile ("lw  x10,28( sp )");
		asm volatile ("lw  x11,32( sp )");
		asm volatile ("lw  x12,36( sp )");
		asm volatile ("lw  x13,40( sp )");
		asm volatile ("lw  x14,44( sp )");
		asm volatile ("lw  x15,48( sp )");
		asm volatile ("lw  x16,52( sp )");
		asm volatile ("lw  x17,56( sp )");
		asm volatile ("lw  x18,60( sp )");
		asm volatile ("lw  x19,64( sp )");
		asm volatile ("lw  x20,68( sp )");
		asm volatile ("lw  x21,72( sp )");
		asm volatile ("lw  x22,76( sp )");
		asm volatile ("lw  x23,80( sp )");
		asm volatile ("lw  x24,84( sp )");
		asm volatile ("lw  x25,88( sp )");
		asm volatile ("lw  x26,92( sp )");
		asm volatile ("lw  x27,96( sp )");
		asm volatile ("lw  x28,100( sp )");
		asm volatile ("lw  x29,104( sp )");
		asm volatile ("lw  x30,108( sp )");
		asm volatile ("lw  x31,112( sp )");
		asm volatile ("addi sp, sp, 120");

			//printf( "isr over\n\r" );
			return;		
		}
	}
		
	
}

/** @fn generate_sw_irq
 @brief  Generates machine mode software interrupt if already enabled
 @details 
 @warning 
 @param[in] No input parameter.
 @param[Out] No output parameter.
*/


void generate_sw_irq(void){

#if __riscv_xlen == 64
  sw_interrupt_enable = 1; //ON sw intr
#else
  set_csr(mip, MIP_MSIP); // Set MSIP bit in MIP register for Machine SW intr.
#endif  	

}


