/* author : yanikgo@itu.edu.tr
 * DIGITAL INPUT TEST PROGRAMI
 * J4,J15,J16,J17 nolu pinleri Digital Input olarak kullanabilirsiniz. 
 * Pinlere eger <3V gelirse 0, yukarisinde bir gerilim gelirse yazilimda 1 degerini elde etmemiz gerekiyor.  
 * Guc kaynaginin eksisi ile karta gelen eksi uc kısa devre ise digital input'da eksi kablosunu takmaya gerek yoktur. 
 * 
 * compile:
 * gcc -std=gnu11 -o Di_test Di_test.c pmedex.c -lbcm2835
 * 
 * Run:
 * ./Di_test
 * */


#include <stdio.h>
#include "pmedex.h"
#include <bcm2835.h>

int main(){
	

    pe2a_DO_DI_init(); //DO ve DI pinlerin gpio ayarlari bu fonksiyon ile yapiliyor
	uint8_t arr_diGPIO[16];
	
	
	for(;;){
		
	//pe2a_DI_getVal() fonksiyonu geri donus degeri 1 veya 0 dondurecektir
	//istenilen pinler yorum satirindan kaldirilarak kullanilabilir
	
	arr_diGPIO[0] = pe2a_DI_getVal(pe2a_GPIO_J14_J1);
	arr_diGPIO[1] = pe2a_DI_getVal(pe2a_GPIO_J14_J2);
	arr_diGPIO[2] = pe2a_DI_getVal(pe2a_GPIO_J14_J3);
	arr_diGPIO[3] = pe2a_DI_getVal(pe2a_GPIO_J14_J4);
	
	//arr_diGPIO[4] = pe2a_DI_getVal(pe2a_GPIO_J15_J1);
	//arr_diGPIO[5] = pe2a_DI_getVal(pe2a_GPIO_J15_J2);
	//arr_diGPIO[6] = pe2a_DI_getVal(pe2a_GPIO_J15_J3);
	//arr_diGPIO[7] = pe2a_DI_getVal(pe2a_GPIO_J15_J4);
	
	//arr_diGPIO[8]  = pe2a_DI_getVal(pe2a_GPIO_J16_J1);
	//arr_diGPIO[9]  = pe2a_DI_getVal(pe2a_GPIO_J16_J2);
	//arr_diGPIO[10] = pe2a_DI_getVal(pe2a_GPIO_J16_J3);
	//arr_diGPIO[11] = pe2a_DI_getVal(pe2a_GPIO_J16_J4);
	
	//arr_diGPIO[12] = pe2a_DI_getVal(pe2a_GPIO_J17_J1);
	//arr_diGPIO[13] = pe2a_DI_getVal(pe2a_GPIO_J17_J2);
	//arr_diGPIO[14] = pe2a_DI_getVal(pe2a_GPIO_J17_J3);
	//arr_diGPIO[15] = pe2a_DI_getVal(pe2a_GPIO_J17_J4);
	
	

	printf("pe2a_GPIO_J14_1 konumu : %d \n",arr_diGPIO[0]);
	printf("pe2a_GPIO_J14_2 konumu : %d \n",arr_diGPIO[1]);
	printf("pe2a_GPIO_J14_3 konumu : %d \n",arr_diGPIO[2]);
	printf("pe2a_GPIO_J14_4 konumu : %d \n",arr_diGPIO[3]);
	
	//delay(100);
	//printf("\n");
	
	//printf("pe2a_GPIO_J15_1 konumu : %d \n",arr_diGPIO[4]);
	//printf("pe2a_GPIO_J15_2 konumu : %d \n",arr_diGPIO[5]);
	//printf("pe2a_GPIO_J15_3 konumu : %d \n",arr_diGPIO[6]);
	//printf("pe2a_GPIO_J15_4 konumu : %d \n",arr_diGPIO[7]);
	
	//delay(100);
	//printf("\n");
	
	//printf("pe2a_GPIO_J16_1 konumu : %d \n",arr_diGPIO[8]);
	//printf("pe2a_GPIO_J16_2 konumu : %d \n",arr_diGPIO[9]);
	//printf("pe2a_GPIO_J16_3 konumu : %d \n",arr_diGPIO[10]);
	//printf("pe2a_GPIO_J16_4 konumu : %d \n",arr_diGPIO[11]);
	
	//delay(100);
	//printf("\n");
	
	//printf("pe2a_GPIO_J17_1 konumu : %d \n",arr_diGPIO[12]);
	//printf("pe2a_GPIO_J17_2 konumu : %d \n",arr_diGPIO[13]);
	//printf("pe2a_GPIO_J17_3 konumu : %d \n",arr_diGPIO[14]);
	//printf("pe2a_GPIO_J17_4 konumu : %d \n",arr_diGPIO[15]);
	

	
	printf("\n\n");
	
	delay(1000);

	
	

	}
	

 	pe2a_bcm2835_close();
 	
 	return 0;
}

