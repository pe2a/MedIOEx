/* author : yanikgo@itu.edu.tr
 * ANALOG OUTPUT TEST PROGRAMI
 * !@ J1 @! KONNEKTORUNE 0-10V ARASI GERILIM REF. GONDERILEBILIR
 * EGER i = 0 ise 0V, 4095 ise 10V GER. REF. GONDERILECEKTIR. 
 * Her cycle'da yaklasik 0.24V (240mA) gerilim referansi arttirilacaktir. 
 * 
 * compile:
 * gcc -std=gnu11 -o Ao_test Ao_test.c pmedex.c -lbcm2835
 * 
 * Run:
 * ./Ao_test
 * */
 
 
#include <stdio.h>
#include <bcm2835.h>
#include "pmedex.h"

int main(){
	

	pe2a_AO_init();	
	int i = 0;
	
	printf("Analog Output tum kanallara yazma islemi baslatiliyor \n");
	printf("\n");
	for(;;){
		
	pe2a_AO_writeVal(0,i);
	pe2a_AO_writeVal(1,i);
	pe2a_AO_writeVal(2,i);
	pe2a_AO_writeVal(3,i);

	i+=100;
	if( i > 4095)
	i = 0;
	
	delay(1000);


	}
	

 	pe2a_bcm2835_close();
 	
 	return 0;
}
