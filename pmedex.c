
/* pmedex.c
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
#include <stdio.h>
#include "pmedex.h"


//controlling DO bit as 1 
static void pe2a_DO_getHigh(unsigned char *ptr, size_t size)
{

		if(ptr != NULL)
			(*ptr)  |= ( 1 <<size);


}


//controlling DO bit as 0 
static void pe2a_DO_getLow(unsigned char *ptr, size_t size)
{

		if(ptr != NULL)
			(*ptr)  &= ~ (1 <<size);


}

// MPC23S17 SPI Data Transfer
static void pe2a_mcp23s17_tr(unsigned char device, unsigned char tx_data)
{
	//when you work with do or ao, you can provide ai cs High cause of reading/writing properly 
	 bcm2835_gpio_write(pe2a_GPIO_AI_CS3, HIGH); //analog input chip select high, so ai disabled 
	 
	 bcm2835_spi_chipSelect(BCM2835_SPI_CS1);  //DO chip select  
	 bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS1, LOW);  //DO chip select active  
 
	 char do_tbuf[3];
	 
	 device = device & 0b11111110; // Clear last bit for a write
	 do_tbuf[0]=device;
	 do_tbuf[1]=setGPIOAorB; //from coming global val. 
	 do_tbuf[2]=tx_data;
	  
	  bcm2835_spi_transfern(do_tbuf,sizeof(do_tbuf));
	
	//  delay(1); 
		
	
	 
}
//DO pin should be 1 
void pe2a_DO_setHigh(const int device)
{

		
		 if(device <= pe2a_GPIO_J3_1){
			setGPIOAorB = pe2a_mcp23s17_GPIOB;
			pe2a_DO_getHigh(&set_DO_bpin,device);    
			pe2a_mcp23s17_tr(pe2a_mcp23s17_adr,set_DO_bpin);
		
		} 

		else if(device >= pe2a_GPIO_J6_4){
			setGPIOAorB = pe2a_mcp23s17_GPIOA;
			pe2a_DO_getHigh(&set_DO_apin,device - (pe2a_GPIO_J3_1 + 1));     
			pe2a_mcp23s17_tr(pe2a_mcp23s17_adr,set_DO_apin);
			
		} 
						

}



//DO pin should be 0
void pe2a_DO_setLow(const int device)
{

		if(device <= pe2a_GPIO_J3_1){
			setGPIOAorB = pe2a_mcp23s17_GPIOB;
			pe2a_DO_getLow(&set_DO_bpin,device);  
			pe2a_mcp23s17_tr(pe2a_mcp23s17_adr,set_DO_bpin);  
		
		} 
		
		else if(device >= pe2a_GPIO_J6_4){
			setGPIOAorB = pe2a_mcp23s17_GPIOA;
			pe2a_DO_getLow(&set_DO_apin,device - (pe2a_GPIO_J3_1 + 1));     
			pe2a_mcp23s17_tr(pe2a_mcp23s17_adr,set_DO_apin);  
		
		
		} 
			
}

//all DO pin should be 0
void pe2a_DO_clear_bits()
{

	unsigned char arrClearBits[4] = {0x01,0x00,0x12,0x13};

	for(int i = 0; i < 4; ++i){
		setGPIOAorB = arrClearBits[i];
		pe2a_mcp23s17_tr(pe2a_mcp23s17_adr ,0b00000000);  
        }

}

//digital input return 1 or 0
uint8_t pe2a_DI_getVal(const int PIN)
{	
	return (bcm2835_gpio_lev(PIN) && 1) ? LOW : HIGH; 
}	



//DI and DO init function
int pe2a_DO_DI_init()
{
	
	 if (bcm2835_init() == -1) {
	   printf("bmc2835_init Error\n"); //if there is not, you can face !segmentation fault!
	   return 1;
	  }
	
	/*please use as default */	
	 bcm2835_spi_begin();
	 bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST); 
	 bcm2835_spi_setDataMode(BCM2835_SPI_MODE0); 
	 bcm2835_spi_setClockDivider(pe2a_SPI_Clock_1024);

	 pe2a_DO_clear_bits(); //clear MCP23S17 GPIOs 

	/*DIGITAL INPUT init decleration*/
	static const int pe2a_GPIO_Arr_in[] = {  pe2a_GPIO_J14_16 ,pe2a_GPIO_J14_15 ,pe2a_GPIO_J14_14 ,pe2a_GPIO_J14_13,
											 pe2a_GPIO_J15_12 ,pe2a_GPIO_J15_11 ,pe2a_GPIO_J15_10 ,pe2a_GPIO_J15_9,
											 pe2a_GPIO_J16_8 ,pe2a_GPIO_J16_7 ,pe2a_GPIO_J16_6 ,pe2a_GPIO_J16_5,
											 pe2a_GPIO_J17_4 ,pe2a_GPIO_J17_3 ,pe2a_GPIO_J17_2 ,pe2a_GPIO_J17_1 };
		
	for(int i = 0; i < sizeof(pe2a_GPIO_Arr_in) / sizeof(pe2a_GPIO_Arr_in[0]);++i)
	{	 
		 bcm2835_gpio_fsel(pe2a_GPIO_Arr_in[i], BCM2835_GPIO_FSEL_INPT); 
		 bcm2835_gpio_set_pud(pe2a_GPIO_Arr_in[i], BCM2835_GPIO_PUD_UP); 
	}
 	
	 	 
	return 0;

}



/*Analog input max11627*/
int pe2a_AI_init(){
	

    if (!bcm2835_init())
    {
      printf("bcm2835_init failed. Are you running as root??\n");
      return 1;
    }

    bcm2835_spi_begin();
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   
    bcm2835_spi_setClockDivider(pe2a_SPI_Clock_1024); 
	bcm2835_gpio_fsel(pe2a_GPIO_AI_CS3, BCM2835_GPIO_FSEL_OUTP); 
}

//AI bit shifting
static int pe2a_AI_getVal_cond1(const char *ptr)
{
	
	
	if(ptr[0] < 16 )
		return (int)(ptr[0] * (1 << 8) + ptr[1]); 
	else
		return (int)(ptr[1] * (1 << 8) + ptr[0]);
	
	
}
//AI choosing channel
static int pe2a_AI_getVal_cnv_choosing(const int PIN, char *ptr) 
{


	
	if(PIN < 0 || PIN > 3)
	{
		return -1;
	}
	
	else if(PIN == pe2a_GPIO_J13_1)
	{
		ptr[0] = 0b10000100; //conversion
		ptr[1] = 0b01100000; //setup
		ptr[2] = 0b00111100; //ave
		
		return 0;
	}
	
	else if(PIN == pe2a_GPIO_J13_2)
	{
		ptr[0] = 0b10001100; //conversion ch1
		ptr[1] = 0b01100000; //setup
		ptr[2] = 0b00111100; //ave
		return 0;
	}
	
	else if(PIN == pe2a_GPIO_J13_3)
	{
		ptr[0] = 0b10010100; //conversion ch2
		ptr[1] = 0b01100000; //setup
		ptr[2] = 0b00111100; //ave
		return 0;
	}
	
	else if(PIN == pe2a_GPIO_J13_4)
	{
		ptr[0] = 0b10011100; //conversion ch3
		ptr[1] = 0b01100000; //setup
		ptr[2] = 0b00111100; //ave
		
		return 0;
	}

		
	
}

//return AI val as chosen channel 
int pe2a_AI_getVal(const int PIN)
{
		 
		 
	char ai_tbuf[3],ai_rbuf[3];
    
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, HIGH);   //analog output cs disabled
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS1, HIGH);   //digital output cs disabled
   
	
	bcm2835_gpio_write(pe2a_GPIO_AI_CS3, LOW); //analog input chip select active
	
	
	if(pe2a_AI_getVal_cnv_choosing(PIN,ai_tbuf) < 0)
		return -1;
	else
	{
		bcm2835_spi_transfernb(ai_tbuf,ai_rbuf,sizeof(ai_tbuf));
		return (int)pe2a_AI_getVal_cond1(ai_rbuf);
		

	}
	
	return 0; //maybe no voltage 
	

	
}




/* Analog Output decleration DAC124S085*/ 

//left bit shifting for setting AO produces between 0-4095 
static void pe2a_AO_wrHigh(unsigned char *ptr, size_t bitNumber)
{

		if(ptr != NULL)
			(*ptr)  |= ( 1 << bitNumber);


}

//right bit shifting for setting AO produces between 0-4095 
static void pe2a_AO_wrLow(unsigned char *ptr, size_t bitNumber)
{

		if(ptr != NULL)
			(*ptr)  &= ~( 1 << bitNumber);


}

//like function overloading
static void pe2a_AO_writeHigh_int(unsigned int *ptr, size_t bitNumber)
{

	if (ptr != NULL)
		(*ptr) |= (1 << bitNumber);

}


//transfer function for AO first array 
static char pe2a_AO_wrBits_firstArr(const int getVal){

	/*
	have two array of AO. c1 = 0b00000000 , c2 = 0b00000000
	11,10,9,8 bit setting = pe2a_AO_wrBits_firstArr()
	c2 shall be transferred directly but not c1.
	setting AO channels and the other stuff over c1 array
	*/

	int i = 11; //12bit
	unsigned int c1 = 0; 
	

	for (; i >= 8; --i)
	if (getVal >> i & 1) 
			pe2a_AO_writeHigh_int(&c1, i - 8);
		
		return (char)c1;
			

}

//transfer function for AO second array  
static char pe2a_AO_wrBits_secArr(const int getVal){

	/*
	have two array of AO. c1 = 0b00000000 , c2 = 0b00000000
	7,6...0 bit setting = pe2a_AO_wrBits_secArr()
	c2 shall be transferred directly but not c1. 
	setting AO channels and the other stuff over c1 array 
	*/
	int i = 7; //12bit 
	unsigned int c2 = 0; 

	for (; i >= 0; --i)
	if (getVal >> i & 1)
			pe2a_AO_writeHigh_int(&c2, i);

	return (char)c2;
}

static void pe2a_AO_OP1OP2_choosing(const int val,char *ptr){
	
	//detailed information TI dac124s085 datasheet
	//OP1 & OP2
	// 00 : write specified register but do not update outputs
	if( val == 0){
		pe2a_AO_wrLow(ptr,5);
		pe2a_AO_wrLow(ptr,4); }
		
	//01 : write to specified register and update outputs
	else if(val == 1){
		pe2a_AO_wrLow(ptr,5);
		pe2a_AO_wrHigh(ptr,4); 	
	}
	
	//10 : write all registers and update outputs
	else if(val == 2){
		pe2a_AO_wrLow(ptr,4);
		pe2a_AO_wrHigh(ptr,5);
	}
	
	//11 : power down outputs
	else if(val == 3){
		pe2a_AO_wrHigh(ptr,5);
		pe2a_AO_wrHigh(ptr,4);
	}
	
	
}


static void pe2a_AO_ch_choosing(const int setVal, char *ptr){
	
	//daca 00
	if( setVal == 0){
		pe2a_AO_wrLow(ptr,7);
		pe2a_AO_wrLow(ptr,6); }
		
	//dacb	01
	else if(setVal == 1){
		pe2a_AO_wrLow(ptr,7);
		pe2a_AO_wrHigh(ptr,6); 	
	}
	//dacc 10
	else if(setVal == 2){
		pe2a_AO_wrLow(ptr,6);
		pe2a_AO_wrHigh(ptr,7); 
	}
	
	//dacd 11
	 else if(setVal == 3){
		pe2a_AO_wrHigh(ptr,7);
		pe2a_AO_wrHigh(ptr,6); 
	}
}
//void showbits(const char val){
//from csd
//int i = sizeof(char) * 8 - 1;
	//for(; i >= 0; i--)
		//putchar(val >> i & 1 ? '1' : '0');
	
	//putchar('\n');

//}
void pe2a_AO_writeVal(const int PIN,const int getVal){ 
	//0: 0V, 4095 : 10V
	//in normal operation, you should use delay function at least <!> " < = 100ms " <!>
	
	//when you work with ao or do, you can provide ai cs High cause of reading/writing properly 
	 bcm2835_gpio_write(pe2a_GPIO_AI_CS3, HIGH); //analog input chip select high, so ai disabled 
	
	bcm2835_spi_chipSelect(BCM2835_SPI_CS0);      //analog output cs               
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);   //analog output cs active

	AO_tbuf1[0] = pe2a_AO_wrBits_firstArr(getVal);
	AO_tbuf1[1] = pe2a_AO_wrBits_secArr(getVal);
	
	//choosing channel number just setting tbuf1[0]
	pe2a_AO_ch_choosing(PIN,&AO_tbuf1[0]);
	
	//default value 01 and it can be changed according to needed
	pe2a_AO_OP1OP2_choosing(1,&AO_tbuf1[0]);
	
	//transferring to dac124s085 by TI
	bcm2835_spi_transfernb(AO_tbuf1,AO_rbuf1,sizeof(AO_tbuf1));
	
}

int pe2a_AO_init(){
	
	//<!> AO transfer array is global static var. <!>
    if (!bcm2835_init()) //from bcm2835.h
    {
      printf("bcm2835_init failed. Are you running as root??\n");
      return 1;
    }


    bcm2835_spi_begin();
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   
    bcm2835_spi_setClockDivider(pe2a_SPI_Clock_1024); 

	
	//it would be 'op1 1 && op2 0' for no voltage 
	pe2a_AO_writeVal(-1,0); //all register would be 0 as starting position (init), -1 can be ignored
	pe2a_AO_OP1OP2_choosing(2,&AO_tbuf1[0]); //mode 2: write all registers and update outputs  
	
	//transferring to dac124s085 by TI
	bcm2835_spi_transfernb(AO_tbuf1,AO_rbuf1,sizeof(AO_tbuf1));

}


void pe2a_bcm2835_close()
{

	bcm2835_close(); //comes from bcm2835.h

}


