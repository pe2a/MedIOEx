/* Do_test.c
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
 * thanks to pe2a_DO_setHigh(pinNumber) function to HIGH J3, J4, J5, J6 connector. 
 * and you can also use pe2a_DO_setLow(pinNumber) to LOW J3, J4, J5, J6 connector. 
 * When they are HIGH, you can see LED as green blinking. 
 * We are providing also buzzer on MedIOEx, if you set pe2a_DO_setHigh(pe2a_GPIO_J3_1) and 
 * SW2 buzzer button, you can hear the sound. 
 * The latest test program can be found https://github.com/pe2a/MedIOEx
 * The latest bcm2835 library can be installed: 
 * http://www.airspayce.com/mikem/bcm2835/
 *
 * !TR
 * Gereksinimler:
 * bcm2835.h kütüphanesinin yüklenmesi
 * Ayrıntılı bilgilendirme pe2a.com/docs 
 * pe2a_DO_setHigh(pinNumber) kullanarak J3,J4,J5,J6 konnektöründen istediğiniz pini
 * HIGH yapabilirsiniz. J4..J6 konnektörleri 24VDC, 80mA çıkış verebilir. Bu değerlerle 
 * herhangi bir röle veya kontaktörü çektirebilirsiniz.
 * pe2a_DO_setlow(pinNumber) fonksiyonu ile çekili olan kontağı LOW pozisyonuna getirebilirsiniz. 
 * Devre üzerinde buzzer mevcuttur. pe2a_DO_setHigh(pe2a_GPIO_J3_1) fonksiyonu ve SW2 butonunu 
 * aktif hale getirerek 'buzzer' sesini duyabilirsiniz. Çalışmalarınızda alarm olarak kullanılabilir. 
 * Son guncel programi https://github.com/pe2a/MedIOEx adresinden indirebilirsiniz. 
 * bcm2835 son versionu aşağıdaki adreste bulunabilir: 
 * http://www.airspayce.com/mikem/bcm2835/
 * 
 * compile:
 *  gcc -o Do_test Do_test.c pmedex.c -lbcm2835 -std=gnu11
 * 
 * Run:
 * ./Do_test
 * 
 * update 15.12.16
 * 
 * Copyright (C) 2016 Polly Electronics & Automation
 * If you have any troubles on MedIoEx, please do no not hesiate to contact support@pe2a.com
 * */


#include <stdio.h>
#include "pmedex.h"
#include <bcm2835.h>

int main(){
	

    pe2a_DO_DI_init(); //DO and DI pins intialize

	
	for(;;){

	//All DO_GPIO set HIGH position
	
	pe2a_DO_setHigh(pe2a_GPIO_J3_1); 
	pe2a_DO_setHigh(pe2a_GPIO_J3_2);
	pe2a_DO_setHigh(pe2a_GPIO_J3_3);
	pe2a_DO_setHigh(pe2a_GPIO_J3_4);
	
	pe2a_DO_setHigh(pe2a_GPIO_J4_1); //sw2 for buzzer 
	pe2a_DO_setHigh(pe2a_GPIO_J4_2);
	pe2a_DO_setHigh(pe2a_GPIO_J4_3);
	pe2a_DO_setHigh(pe2a_GPIO_J4_4);

	pe2a_DO_setHigh(pe2a_GPIO_J5_5); 
	pe2a_DO_setHigh(pe2a_GPIO_J5_6);
	pe2a_DO_setHigh(pe2a_GPIO_J5_7);
	pe2a_DO_setHigh(pe2a_GPIO_J5_8);
	
	pe2a_DO_setHigh(pe2a_GPIO_J6_9); 
	pe2a_DO_setHigh(pe2a_GPIO_J6_10);
	pe2a_DO_setHigh(pe2a_GPIO_J6_11);
	pe2a_DO_setHigh(pe2a_GPIO_J6_12);
	
	
	delay(1000); //1000ms
	
	//All DO_GPIO set LOW position

		
	pe2a_DO_setLow(pe2a_GPIO_J3_1);
	pe2a_DO_setLow(pe2a_GPIO_J3_2);
	pe2a_DO_setLow(pe2a_GPIO_J3_3);
	pe2a_DO_setLow(pe2a_GPIO_J3_4);
	
	pe2a_DO_setLow(pe2a_GPIO_J4_1); 
	pe2a_DO_setLow(pe2a_GPIO_J4_2);
	pe2a_DO_setLow(pe2a_GPIO_J4_3);
	pe2a_DO_setLow(pe2a_GPIO_J4_4);
	
	pe2a_DO_setLow(pe2a_GPIO_J5_5);
	pe2a_DO_setLow(pe2a_GPIO_J5_6);
	pe2a_DO_setLow(pe2a_GPIO_J5_7);
	pe2a_DO_setLow(pe2a_GPIO_J5_8);
	
	pe2a_DO_setLow(pe2a_GPIO_J6_9);
	pe2a_DO_setLow(pe2a_GPIO_J6_10);
	pe2a_DO_setLow(pe2a_GPIO_J6_11);
	pe2a_DO_setLow(pe2a_GPIO_J6_12);
	

	delay(1000); //1000ms

	}
	

 	pe2a_bcm2835_close();  //All SPI port will be closed.
 	
 	return 0;
}

