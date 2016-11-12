/* author : yanikgo@itu.edu.tr
 * DIGITAL OUTPUT TEST PROGRAMI
 * !@ j4,j5,j6 @! 24VDC, max. 80mA yuk anahtarlayabilir. 
 * !@ j3 @! Role cikisidir. 250V, 5A yuk anahtarlayabilir.  
 * SW2 buzzer anahtarini kullanarak eger pe2a_GPIO_J4_1 aktif hale getirirseniz buzzer
 * sesini duyabilirsiniz.  
 * Guc kaynaginin eksisi ile karta gelen eksi uc kısa devre ise digital output'da eksi kablosunu takmaya gerek yoktur. 
 * 
 * compile:
 * gcc -std=gnu11 -o Do_test Do_test.c pmedex.c -lbcm2835
 * 
 * Run: 
 * ./Do_test
 * */


#include <stdio.h>
#include "pmedex.h"
#include <bcm2835.h>

int main(){
	

    pe2a_DO_DI_init(); //DO ve DI pinlerin gpio ayarlari bu fonksiyon ile yapiliyor


	
	for(;;){

//DO gpio 1 konumuna getiriliyor.  	
	pe2a_DO_setHigh(pe2a_GPIO_J4_1); //buzzer, use SW2
	pe2a_DO_setHigh(pe2a_GPIO_J4_2);
	pe2a_DO_setHigh(pe2a_GPIO_J4_3);
	pe2a_DO_setHigh(pe2a_GPIO_J4_4);
	
	pe2a_DO_setHigh(pe2a_GPIO_J5_1);
	pe2a_DO_setHigh(pe2a_GPIO_J5_2);
	pe2a_DO_setHigh(pe2a_GPIO_J5_3);
	pe2a_DO_setHigh(pe2a_GPIO_J5_4);
	
	pe2a_DO_setHigh(pe2a_GPIO_J6_1);
	pe2a_DO_setHigh(pe2a_GPIO_J6_2);
	pe2a_DO_setHigh(pe2a_GPIO_J6_3);
	pe2a_DO_setHigh(pe2a_GPIO_J6_4);
	
	delay(100);
	

//DO gpio 0 konumuna getiriliyor.  		
	pe2a_DO_setLow(pe2a_GPIO_J4_1);
	pe2a_DO_setLow(pe2a_GPIO_J4_2);
	pe2a_DO_setLow(pe2a_GPIO_J4_3);
	pe2a_DO_setLow(pe2a_GPIO_J4_4);
	
	pe2a_DO_setLow(pe2a_GPIO_J5_1);
	pe2a_DO_setLow(pe2a_GPIO_J5_2);
	pe2a_DO_setLow(pe2a_GPIO_J5_3);
	pe2a_DO_setLow(pe2a_GPIO_J5_4);
	
	
	pe2a_DO_setLow(pe2a_GPIO_J6_1);
	pe2a_DO_setLow(pe2a_GPIO_J6_2);
	pe2a_DO_setLow(pe2a_GPIO_J6_3);
	pe2a_DO_setLow(pe2a_GPIO_J6_4);
	
	delay(100);

	}
	

 	pe2a_bcm2835_close();
 	
 	return 0;
}

