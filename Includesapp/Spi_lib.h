/*
 * Spi_lib.h
 *
 *  Created on: 19 Aug 2025
 *      Author: ratheesh
 */

#ifndef INCLUDESAPP_SPI_LIB_H_
#define INCLUDESAPP_SPI_LIB_H_

#define HIGH 1
#define LOW 0

// opcodes
#define READ_DEV_ID 0x9F     // Read Manufacturer and Device ID
#define READ_EEPROM 0x03     // Read Array
#define WRITE_EEPROM 0x02    // Byte/Page Program
#define CHIP_ERASE 0x60      // Chip Erase
#define READ_STATUS_1 0x05   // Read Status Register - Byte 1
#define READ_STATUS_2 0x35   // Read Status Register - Byte 2
#define WRITE_ENABLE 0x06    // Write Enable
#define BLOCK_ERASE_4K 0x20  // Block Erase (4 Kbytes)
#define BLOCK_ERASE_32K 0x52 // Block Erase (32 Kbytes)
#define BLOCK_ERASE_64K 0xD8 // Block Erase (64 Kbytes)

#define DUMMY_DATA 0x00
#define EEPROM_BUSY 0x01
#define PAGE_SIZE 256
#define ERASE_4K 1
#define ERASE_32K 2
#define ERASE_64K 3
#define Default_ADCDATA 2048
#define SPI_CS1 0
#define SPI_CS2 1
#define SPI_CS3 2
#define SPI_CS4 3

typedef union
{
	unsigned short ADCCurrentVal;
	unsigned char ADCCurrentByte[2];
}LD_ADCCurrent;
LD_ADCCurrent LDC_ADCCurrent, LDC_ADCOpCode ;

//extern RxlampSWPattern RxSMARCSWPattern;
unsigned char currentSpiuse = 0, LampFBReadFlag = 0, StartFeedbackFlag = 1, LampFBStatus[64], CurrentReadingFlag = 0;
unsigned char CLampFBStatus[64];



US currentChipSelectGPIO = 0; //SPI_CS1 = 0, SPI_CS2 = 1 , SPI_CS3 = 2, SPI_CS4 = 3;

unsigned int tmp_ADCCHVAL[15], LD2_ADCCHVAL[15], LD3_ADCCHVAL[15], LD4_ADCCHVAL[15];
unsigned short LampCurrent[64], LampADCVal[64],LampCurrentAVG[64],LampCurrentAVGSet[64];
unsigned short previousADCDATA = 0, currentADCDATA = 0, Last_Chk_LampStatus = 0;
unsigned char LampCurrentAVGCount[64],LampCurrentAVGSetFlag[64];
//unsigned short Cmd_Channel[16] = { 0x8310, 0x8710, 0x8B10, 0x8F10, 0x9310, 0x9710, 0x9B10, 0x9F10,
//	                               0xA310, 0xA710, 0xAB10, 0xAF10, 0xB310, 0xB710, 0xBB10, 0xBF10 };
unsigned short Cmd_Channel[16] = { 0x8311, 0x8711, 0x8B11, 0x8F11, 0x9311, 0x9711, 0x9B11, 0x9F11,
	                               0xA311, 0xA711, 0xAB11, 0xAF11, 0xB311, 0xB711, 0xBB11, 0xBF11 };
extern unsigned char LDsense;
extern unsigned char  Rx_Databuffer[50], Chk_Rx_Databuffer[16];
void CuSensor_SPI_Begin(unsigned char spi_no);
void Coin_Lampfeedback_Status (void);
void ReportLampFBStatus (void);
unsigned short CuSensorRead( unsigned short opcode);
/*oid at25sf161Write(char *writeBuf, int length);
void at25sf161ReadEeprom(char *readBuf, int length, unsigned int eepromAddress);
void at25sf161WriteEeprom(char *writeBuf, int length, unsigned int eepromAddress);
void at25sf161BlockErase(unsigned int eepromAddress, int eraseMode);
void at25sf161ChipErase(void);
void at25sf161BusyWait(void);*/
void ReadStore_ADC7490_CurrentVal_LDC (void);
void Initialize_SPI_Chipselect (void);
unsigned short Read_ADC7490_CurrentVal (unsigned short ADC_Channel);//, unsigned char spi_slave );
void Clear_Last_LampCurrent(void);
void LD_LampCurrentCalculation (unsigned char currentchannel);
unsigned short LD2_Read_ADC7490_CurrentVal (unsigned short ADC_Channel2);
unsigned short LD3_Read_ADC7490_CurrentVal (unsigned short ADC_Channel3);
unsigned short LD4_Read_ADC7490_CurrentVal (unsigned short ADC_Channel4);

#endif /* INCLUDESAPP_SPI_LIB_H_ */
