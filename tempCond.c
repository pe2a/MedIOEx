/* tempCond.c
 * Compile gcc -o tempCond tempCond.c -lbcm2835 pmedex.c -std=gnu11
 * Copyright (C) 2016 Polly Electronics & Automation
 * If you have any troubles on MedIoEx, please do no not hesiate to contact support@pe2a.com
 * */
 
#include <stdio.h>
#include "pmedex.h" /* you must have it in compile directory */
#include <bcm2835.h>
#define MinTemp 25
#define MaxTemp 28

int main(){
	
	pe2a_getTemperature_init(); 
	pe2a_DO_DI_init();
	
	for(;;){

	
	printf("pe2a_getTemperature(1) : %.2f \n",pe2a_getTemperature(1));

 	if ( pe2a_getTemperature(1) > MaxTemp){ //if temp. > Max. temp J4_1 and J4_2 will be activated 
		printf("pe2a_getTemperature(1) : %.2f \n",pe2a_getTemperature(1));
		pe2a_DO_setHigh(pe2a_GPIO_J4_1);
		pe2a_DO_setHigh(pe2a_GPIO_J4_2);
	}
		
	else if( pe2a_getTemperature(1) < MinTemp){
		printf("pe2a_getTemperature(1) : %.2f \n",pe2a_getTemperature(1));
		pe2a_DO_setHigh(pe2a_GPIO_J4_1);
		pe2a_DO_setHigh(pe2a_GPIO_J4_2);
	}
	
	delay(1000);
	printf("\n\n");
	


	}
	

 	pe2a_bcm2835_close(); //All SPI port will be closed. 
 	
 	return 0;
}
