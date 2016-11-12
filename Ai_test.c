/* author : yanikgo@itu.edu.tr
 * ANALOG INPUT TEST PROGRAMI
 * !@ J13 @! konnektorune disaridan olcum istenilen gerilim kaynagi baglanialbilir. Toprak kablosu unutulmamalidir. 
 * GELEN REFERERANS DEGERI 0V ise 0, 10V ise program 4095 degerini uretecektir. 
 * SW2 ile kartin girisindeki gerilim olculebilir. !@ 24V ile beslenmesine karsin diyotlardan dolayi yaklasik 
 * 1.5V gerilim dusumu de hesaba katilmalidir. @!
 * 
 * compile:
 * gcc -std=gnu11 -o Ai_test Ai_test.c pmedex.c -lbcm2835
 * 
 * Run:
 * ./Ai_test
 * */
 
#include <stdio.h>
#include "pmedex.h"
#include <bcm2835.h>

int main(){
	
	pe2a_AI_init();

	
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
	

 	pe2a_bcm2835_close();
 	
 	return 0;
}
