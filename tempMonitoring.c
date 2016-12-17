/* TempMonitoring.c
 * Compile gcc -o TempMonitoring TempMonitoring.c -lbcm2835 pmedex.c -std=gnu11
 * Basic Temperature Datalogger
 * Copyright (C) 2016 Polly Electronics & Automation
 * If you have any troubles on MedIoEx, please do no not hesiate to contact support@pe2a.com
 * */
 
#include <stdio.h>
#include <bcm2835.h>
#include <time.h>
#include <stdlib.h>
#include "pmedex.h" /* you must have it in compile directory */

#define timePeriod 1000 //second

int main(){

	
	double tempVal;
	int counter = timePeriod;
	FILE *fptr;
	fptr = fopen("tempMonitoring.txt","w");
	
	char myDate[80];

	time_t now = time(NULL);
	struct tm *t = localtime(&now);
			
	strftime(myDate,sizeof(myDate)-1,"%d %m %Y %H:%M:%S",t);
	printf("Current Date : %s \n",myDate);

	
	if(fptr ==NULL){
		fprintf(stderr,"Error file handling");
		exit(1);
	}
	
	pe2a_getTemperature_init(); 
	
	tempVal = pe2a_getTemperature(1); //first tempValue
	printf("Current tempVal : %.2f \n",tempVal);
	
	printf("\n\n");


	while(counter){

	now = time(NULL);
	struct tm *t = localtime(&now);
	tempVal = pe2a_getTemperature(1);
		
	strftime(myDate,sizeof(myDate)-1,"%d %m %Y %H:%M:%S",t);
	printf("Current Date : %s , Current Temp : %.2f\n",myDate,tempVal);
	
	fprintf(fptr,"%-40s %.2f\n",myDate,tempVal);
	
	counter--;
	
	delay(1000);
	printf("\n\n");
	


	}
	
	fclose(fptr);

 	pe2a_bcm2835_close(); //All SPI port will be closed. 
 	
 	return 0;
}
