/* 
 * 4ch 12 bit ANALOG INPUT Test Program
 * (EN) MedIOEx is completely industrial Raspberry IO shield. Supply voltage is 24V. 
 * (TR) MedIOEx endüstriyel Raspberr IO genişleme kartıdır. Giriş beslemesi 24V'dur. 
 *
 * !EN
 * Requirements:
 * bcm2835.h must be in /usr/lib
 * for further information pe2a.com/docs
 * !@JJ13@! you can connect voltage source to J13 connector. Please do no forget to connect earth cable. 
 * Incoming voltage ref. might be between 0 - 10V. pe2a_AI_getVal() function returns between 0 - 4095.
 * If it is 0 , probably you have 0V and if it is 4095, you might have 10V voltage source. 
 * If you have any voltage source, you can test analog input function as using SW2 'voltage sense' button. 
 * Please consider MedIoEx has bridge diode so it has voltage drop at below 24V. 
 * The latest test program can be found https://github.com/pe2a/MedIOEx
 *
 * The latest bcm2835 library can be installed: 
 * http://www.airspayce.com/mikem/bcm2835/
 *
 * !TR
 * Gereksinimler:
 * bcm2835.h kütüphanesinin yüklenmesi
 * Ayrıntılı bilgilendirme pe2a.com/docs 
 * !@ J13 @! konnektorune disaridan olcum istenilen gerilim kaynagi baglanabilir. Toprak kablosu unutulmamalidir. 
 * GELEN REFERERANS DEGERI 0V ise 0; 10V ise pe2a_AI_getVal() fonksiyonu 4095 degerini uretecektir. 
 * SW2 ile kartin girisindeki gerilim olculebilir.  24V ile beslenmesine karsin diyotlardan dolayi yaklasik 
 * 1.5V gerilim dusumu de hesaba katilmalidir. 
 * 
 * Son guncel programi https://github.com/pe2a/MedIOEx adresinden indirebilirsiniz. 
 *
 * compile:
 * gcc -std=gnu11 -o Ai_test Ai_test.c pmedex.c -lbcm2835
 *
 * bcm2835 son versionu aşağıdaki adreste bulunabilir 
 * http://www.airspayce.com/mikem/bcm2835/
 * 
 * Run:
 * ./Ai_test
 *
 * Copyright (C) 2016 Polly Electronics & Automation
 * If you have any troubles on MedIoEx, please do no not hesiate to contact support@pe2a.com
 * */
 
#include <stdio.h>
#include "pmedex.h" /* you must have it in compile directory */
#include <bcm2835.h>

int main(){
	
	pe2a_AI_init(); //initialize Analog input

	
	for(;;){

	
	printf("\n\n");
	
	printf("ch0__J13_1 : %d \n",pe2a_AI_getVal(pe2a_GPIO_J13_1));//24v sense,use SW2
	delay(100);
	printf("ch0__J13_2 : %d \n",pe2a_AI_getVal(pe2a_GPIO_J13_2));
	delay(100);
	printf("ch0__J13_3 : %d \n",pe2a_AI_getVal(pe2a_GPIO_J13_3));
	delay(100);
	printf("ch0__J13_4 : %d \n",pe2a_AI_getVal(pe2a_GPIO_J13_4));
	
	delay(1000);
	printf("\n\n");
	


	}
	

 	pe2a_bcm2835_close(); //All SPI port will be closed. 
 	
 	return 0;
}
