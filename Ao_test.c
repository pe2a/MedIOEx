/*
 * 4ch 12 bit ANALOG OUTPUT Test Program
 * (EN) MedIOEx is completely industrial Raspberry IO shield. Supply voltage is 24V. 
 * (TR) MedIOEx endüstriyel Raspberry IO genişleme kartıdır. Giriş beslemesi 24V'dur. 
 *
 * !EN
 * Requirements:
 * bcm2835.h must be in /usr/lib
 * for further information pe2a.com/docs
 *
 * !@ J1 @! it can be used as voltage source. Please do no forget to connect earth cable. 
 * Outcoming voltage ref. might be between 0 - 10V. pe2a_AO_writeVal() function produces between 0 - 4095 number.
 * If it is 0 , probably you are producing 0V and if it is 4095, your voltage reference might be 10V. 
 * If you run this program, analog output pin(J1_1, J1_2, J1_3, J1_4) can be increased as 240mA.  
 * You can measure voltage on pins. 
 * The latest test program can be found https://github.com/pe2a/MedIOEx
 *
 * The latest bcm2835 library can be installed: 
 * http://www.airspayce.com/mikem/bcm2835/
 *
 * !TR
 * Gereksinimler:
 * bcm2835.h kütüphanesinin yüklenmesi
 * Ayrıntılı bilgilendirme pe2a.com/docs 
 * !@ J1 @! konnektorune gerilim referansi gondermek istediginiz cihazi baglayabilirsiniz. Toprak kablosu unutulmamalidir. 
 * GONDERILEN REFERERANS DEGERI 0 ise 0V; 4095 ise pe2a_AO_writeVal() fonksiyonu 4095 degerini uretecektir. 
 * pe2a_AO_writeVal(x,y) kullanmak icin x degiskenine pin numarasi ornek pe2a_GPIO_J1_1, y'ye ise gonderilecek gerilimr referansi yazilmalidir,
 * ornek 2048 yazildiginda 5V istenilen pinden gerilim uretilebilecektir.
 * Ornek programda her 1sn'de gerilim referansi 100 yani yaklasik olarak 240mA arttirilacaktir. 
 * Olcum aleti ile cikis referansini kontrol edebilirsiniz. 
 * 
 * Son guncel programi https://github.com/pe2a/MedIOEx adresinden indirebilirsiniz. 
 *
 * bcm2835 son versionu aşağıdaki adreste bulunabilir 
 * http://www.airspayce.com/mikem/bcm2835/
 * 
 * compile:
 * gcc -std=gnu11 -o Ao_test Ao_test.c pmedex.c -lbcm2835
 * 
 * Run:
 * ./Ao_test
 *
 * Copyright (C) 2016 Polly Electronics & Automation
 * If you have any troubles on MedIoEx, please do no not hesiate to contact support@pe2a.com
 * */


#include <stdio.h>
#include <bcm2835.h>
#include "pmedex.h"

int main(){
	

	pe2a_AO_init();	 //initialize Analog output
	int i = 0;
	
	printf("Analog Output test program starting \n");
	printf("\n");
	for(;;){
		
	pe2a_AO_writeVal(pe2a_GPIO_J1_1,i); //every cycle pin voltage will be increased until 10V. 
	pe2a_AO_writeVal(pe2a_GPIO_J1_2,i);
	pe2a_AO_writeVal(pe2a_GPIO_J1_3,i);
	pe2a_AO_writeVal(pe2a_GPIO_J1_4,i);

	i+=100;
	if( i > 4095)
	i = 0;
	
	delay(1000); //1second


	}
	

 	pe2a_bcm2835_close(); //All SPI port will be closed. 
 	
 	return 0;
}
