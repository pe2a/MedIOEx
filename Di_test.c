/* Di_test.c
 * 16ch DIGITAL OUTPUT Test Program
 * J3 relay output 5A, 250V ; J4, J5, J6 transistor output 24VDC, 80mA.
 * (EN) MedIOEx is completely industrial Raspberry IO shield. Supply voltage is 24V. 
 * (TR) MedIOEx endüstriyel Raspberry IO genişleme kartıdır. Giriş beslemesi 24V'dur. 
 *
 * !EN
 * Requirements:
 * bcm2835.h must be in /usr/lib
 * for further information pe2a.com/docs
 *
 * pe2a_DI_getVal(pinNumber) returns 1 or 0. If voltage of pin less than 3V, it returns 0.
 * You can use J2 or J8 connector as 24VDC source. 
 * The latest test program can be found https://github.com/pe2a/MedIOEx
 * The latest bcm2835 library can be installed: 
 * http://www.airspayce.com/mikem/bcm2835/
 *
 * !TR
 * Gereksinimler:
 * bcm2835.h kütüphanesinin yüklenmesi
 * Ayrıntılı bilgilendirme pe2a.com/docs 
 * Eger pin gerilimi 3V az ise pe2a_DI_getVal(pinNumber) fonksiyonu 0 değerini,
 * 3V'dan fazla ise 1 degerini dondurecektir. 
 * Sahadaki konak eger besleme gerilimi ihtiyaci olursa J2 veya J8 konnektorlerinden 24V beslemenizi alabilirsiniz.  
 * Son guncel programi https://github.com/pe2a/MedIOEx adresinden indirebilirsiniz. 
 * bcm2835 son versionu aşağıdaki adreste bulunabilir: 
 * http://www.airspayce.com/mikem/bcm2835/
 * 
 * compile:
 * gcc -o Di_test Di_test.c pmedex.c -lbcm2835 -std=gnu11
 * 
 * Run:
 * ./Di_test
 *
 * Copyright (C) 2016 Polly Electronics & Automation
 * If you have any troubles on MedIoEx, please do no not hesiate to contact support@pe2a.com
 * */

#include <stdio.h>
#include "pmedex.h"
#include <bcm2835.h>

int main(){
	

    pe2a_DO_DI_init(); //DO and DI pins intialize
	uint8_t arr_diGPIO[16];
	
	
	for(;;){
			
	arr_diGPIO[0] = pe2a_DI_getVal(pe2a_GPIO_J14_16);
	arr_diGPIO[1] = pe2a_DI_getVal(pe2a_GPIO_J14_15);
	arr_diGPIO[2] = pe2a_DI_getVal(pe2a_GPIO_J14_14);
	arr_diGPIO[3] = pe2a_DI_getVal(pe2a_GPIO_J14_13);
	
	arr_diGPIO[4] = pe2a_DI_getVal(pe2a_GPIO_J15_12);
	arr_diGPIO[5] = pe2a_DI_getVal(pe2a_GPIO_J15_11);
	arr_diGPIO[6] = pe2a_DI_getVal(pe2a_GPIO_J15_10);
	arr_diGPIO[7] = pe2a_DI_getVal(pe2a_GPIO_J15_9);
	


	printf("pe2a_GPIO_J14_16 status : %d \n",arr_diGPIO[0]);
	printf("pe2a_GPIO_J14_15 status : %d \n",arr_diGPIO[1]);
	printf("pe2a_GPIO_J14_14 status : %d \n",arr_diGPIO[2]);
	printf("pe2a_GPIO_J14_13 status : %d \n",arr_diGPIO[3]);
	
	printf("\n\n");
	
	printf("pe2a_GPIO_J15_12 status : %d \n",arr_diGPIO[4]);
	printf("pe2a_GPIO_J15_11 status : %d \n",arr_diGPIO[5]);
	printf("pe2a_GPIO_J15_10 status : %d \n",arr_diGPIO[6]);
	printf("pe2a_GPIO_J15_9 status : %d \n",arr_diGPIO[7]);

	
	printf("\n\n");
	
	delay(100); //100ms

	}

 	pe2a_bcm2835_close();  //All SPI port will be closed.
 	
 	return 0;
}

