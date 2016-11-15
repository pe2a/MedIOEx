
/* pmedex.h
 * (EN) MedIOEx is completely industrial Raspberry IO shield. Supply voltage is 24V. 
 * (TR) MedIOEx endüstriyel Raspberry IO genişleme kartıdır. Giriş beslemesi 24V'dur.
 *
 * this library consist of->
 * 4ch 12 bit analog input   : via max11627 
 * 4ch 12 bit analog output  : via dac124s085
 * 16ch 24VDC digital output : via msp23s17
 * 16ch 24VDC digital input  : directly connect RPI pins
 * VERSION 1.0 
 * The basic library provides to use digital and analog pins on MedIOEx. 
 * It is tested on Raspberry2 B, Raspberry2 B+ and Raspberry 3. 
 *
 * Copyright (C) 2016 Polly Electronics & Automation
 * If you have any troubles on MedIoEx, please do no not hesiate to contact support@pe2a.com
 * */

 

 /*defines for pmedex , vd2440111 rpi IO expander card*/
 #ifndef PMEDEX_H
 #define PMEDEX_H
 
#include <stdio.h>
#include <bcm2835.h>
#include <stdlib.h>

#define PMEDEX_H_VERSION 10000 /*VERSION 1.00 */

/*DIGITAL OUTPUT mcp23s17 variable decleration*/
static unsigned char pe2a_mcp23s17_adr = 0b01000000;  // MCP23S17 SPI Address
static unsigned char set_DO_apin = 0b00000000;
static unsigned char set_DO_bpin = 0b00000000;
static unsigned char setGPIOAorB = 0;

/*ANALOG OUTPUT dac124s085 variable decleration*/
static char AO_tbuf1[2] = {0};
static char AO_rbuf1[2] = {0};

#define pe2a_mcp23s17_IODIRB 0x01
#define pe2a_mcp23s17_IODIRA 0x00

#define pe2a_mcp23s17_GPIOA  0x12
#define pe2a_mcp23s17_GPIOB  0x13

/*pe2a SPI Clock */
#define pe2a_SPI_Clock_1024 1024 //244kHz



#define pe2a_GPIO_AI_CS3 25  //analog input SPI chip select
#define pe2a_GPIO_DO_CS1 7   //digital output SPI chip select


typedef enum e_do_pe2aGPIO{

 	pe2a_GPIO_J4_4 = 0, // <!> 24VDC <!> transistor output or <!> buzzer <!> Use SW2 for switching
	pe2a_GPIO_J4_3,     // <!> 24VDC <!> transistor output
	pe2a_GPIO_J4_2,     // <!> 24VDC <!> transistor output
	pe2a_GPIO_J4_1,     // <!> 24VDC <!> transistor output

 	pe2a_GPIO_J3_4,     //relay output ch1, up to <!> 250V <!>
	pe2a_GPIO_J3_3,	    //relay output ch2, up to <!> 250V <!>
	pe2a_GPIO_J3_2,	    //relay output ch3, up to <!> 250V <!>
	pe2a_GPIO_J3_1,	    //relay output ch4, up to <!> 250V <!>

 	pe2a_GPIO_J6_4,    // <!> 24VDC <!> transistor output
	pe2a_GPIO_J6_3,    // <!> 24VDC <!> transistor output
	pe2a_GPIO_J6_2,    // <!> 24VDC <!> transistor output
	pe2a_GPIO_J6_1,    // <!> 24VDC <!> transistor output
	
 	pe2a_GPIO_J5_4,    // <!> 24VDC <!> transistor output
	pe2a_GPIO_J5_3,    // <!> 24VDC <!> transistor output
	pe2a_GPIO_J5_2,    // <!> 24VDC <!> transistor output
	pe2a_GPIO_J5_1     // <!> 24VDC <!> transistor output


}DO_pe2aGPIO;


typedef enum e_di_pe2aGPIO{
	
/*DIGITAL INPUT  */
 pe2a_GPIO_J17_1 = 16, // <!> 24VDC <!> isolated transistor input 
 pe2a_GPIO_J17_2 = 20, // <!> 24VDC <!> isolated transistor input 
 pe2a_GPIO_J17_3 = 21, // <!> 24VDC <!> isolated transistor input 
 pe2a_GPIO_J17_4 = 26, // <!> 24VDC <!> isolated transistor input 

 pe2a_GPIO_J16_5 = 19, // <!> 24VDC <!> isolated transistor input 
 pe2a_GPIO_J16_6 = 13, // <!> 24VDC <!> isolated transistor input 
 pe2a_GPIO_J16_7 = 6,  // <!> 24VDC <!> isolated transistor input 
 pe2a_GPIO_J16_8 = 5,  // <!> 24VDC <!> isolated transistor input 

 pe2a_GPIO_J15_9 = 22, // <!> 24VDC <!> isolated transistor input 
 pe2a_GPIO_J15_10 = 12, // <!> 24VDC <!> isolated transistor input 
 pe2a_GPIO_J15_11 = 27, // <!> 24VDC <!> isolated transistor input 
 pe2a_GPIO_J15_12 = 17, // <!> 24VDC <!> isolated transistor input 

 pe2a_GPIO_J14_13 = 4,  // <!> 24VDC <!> isolated transistor input 
 pe2a_GPIO_J14_14 = 23, // <!> 24VDC <!> isolated transistor input 
 pe2a_GPIO_J14_15 = 24, // <!> 24VDC <!> isolated transistor input 
 pe2a_GPIO_J14_16 = 18 // <!> 24VDC <!> isolated transistor input 


}DI_pe2aGPIO;


typedef enum e_ai_pe2aGPIO{

 	pe2a_GPIO_J13_1 = 0, // <!> 0 - 10V DC <!> analog input ch0, no need resistor or external supply 
	pe2a_GPIO_J13_2,     // <!> 0 - 10V DC <!> analog input ch1
	pe2a_GPIO_J13_3,     // <!> 0 - 10V DC <!> analog input ch2
	pe2a_GPIO_J13_4,     // <!> 0 - 10V DC <!> analog input ch3, use (24V sense -> SW2) switch to meas. power supply voltage

}AI_pe2aGPIO;



typedef enum e_ao_pe2aGPIO{

 	pe2a_GPIO_J1_1 = 0, // <!> 0 - 10V DC <!> analog output ch0, no need resistor or external supply 
	pe2a_GPIO_J1_2,     // <!> 0 - 10V DC <!> analog output ch1
	pe2a_GPIO_J1_3,     // <!> 0 - 10V DC <!> analog output ch2
	pe2a_GPIO_J1_4,     // <!> 0 - 10V DC <!> analog output ch3, 
}AO_pe2aGPIO;



//controlling DO bit as 1 
static void pe2a_DO_getHigh(unsigned char *ptr, size_t size);



//controlling DO bit as 0 
static void pe2a_DO_getLow(unsigned char *ptr, size_t size);


// MPC23S17 SPI Data Transfer
static void pe2a_mcp23s17_tr(unsigned char device, unsigned char tx_data);
//DO pin should be 1 
void pe2a_DO_setHigh(const int device);


//DO pin should be 0
void pe2a_DO_setLow(const int device);

//all DO pin should be 0
void pe2a_DO_clear_bits();

//digital input return 1 or 0
uint8_t pe2a_DI_getVal(const int PIN);


//DI and DO init function
int pe2a_DO_DI_init();


/*Analog input max11627*/
int pe2a_AI_init();

//AI bit shifting
static int pe2a_AI_getVal_cond1(const char *ptr);

//AI choosing channel
static int pe2a_AI_getVal_cnv_choosing(const int PIN, char *ptr) ;

//return AI val as chosen channel 
int pe2a_AI_getVal(const int PIN);


/* Analog Output decleration DAC124S085*/ 

//left bit shifting for setting AO produces between 0-4095 
static void pe2a_AO_wrHigh(unsigned char *ptr, size_t bitNumber);

//right bit shifting for setting AO produces between 0-4095 
static void pe2a_AO_wrLow(unsigned char *ptr, size_t bitNumber);


//like function overloading
static void pe2a_AO_writeHigh_int(unsigned int *ptr, size_t bitNumber);


//transfer function for AO first array 
static char pe2a_AO_wrBits_firstArr(const int getVal);
//transfer function for AO second array  

static char pe2a_AO_wrBits_secArr(const int getVal);

static void pe2a_AO_OP1OP2_choosing(const int val,char *ptr);


static void pe2a_AO_ch_choosing(const int setVal, char *ptr);
	
	
//void showbits(const char val){
//from csd
//int i = sizeof(char) * 8 - 1;
	//for(; i >= 0; i--)
		//putchar(val >> i & 1 ? '1' : '0');
	
	//putchar('\n');

//}

void pe2a_AO_writeVal(const int PIN,const int getVal);
	

int pe2a_AO_init();
	

void pe2a_bcm2835_close();

#endif //PMEDEX_H
