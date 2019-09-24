# MEDIOEX 
MEDIOEX-V2 is basically Raspberry Pi shield and it is suitable Raspberry 2/3/4 and also Zero. Even if Raspberry has been a popular worldwide hobby in the last decades, we have transformed it into an engine which could be utilized in industrial environments thanks to our rich experience in the heavy industry. This document contains application samples regarding the commissionning of the card. Detailed information on MEDIOEX is shared in this document. The student and engineers may utilize in industrial environments thanks to such information on Raspberry Pi shared in this Document. 

MEDIOEX contains the following features:

![Image of MedIOEx-V2](http://pe2a.com/MedIOEx/TR/images/pe2a_info.jpg)

* 16ch isolated Digital Input

* 16ch Digital Output ( 4 ch 250V relay, 12 ch 24VDC transistor output)

* 4ch 12bit Analog Input 

* Real time clock

* Rs232 **OR** RS485 via D-SUB

* Internal temperature sensor LM75bd

* External I2C terminal output 

![Image of MedIOEx-V2](http://pe2a.com/images/medioex_1.jpg)
*MEDIOEX-V2*

![Image of MedIOEx-V2](http://pe2a.com/images/medioex_2.jpg)
*MEDIOEX-V2*

**MEDIOEX-V2** should powered with an external power supply of 24VDC. You can start MEDIOEX through a connection between MEDIOEX and J11 connecteur, as shown in the below picture or directly with a PC adapteur with a 24VDC.

PE2A provides the consumers with MEDIOEX cards together with open sources software. The consumer may make modifications on the code of the open source software. You can have access to detailed information via the below link as to the code functions. 

C: https://github.com/pe2a/MedIOEx

Python: https://github.com/bayraktarulku/medioex_test_suite

C#: https://github.com/huseyint/MedIOExNET

Node js: https://www.npmjs.com/package/node-red-contrib-medioex

MEDIOEX provides physical Digital-Analog Input based SPI. You can even use serial port RS232 and RS485. The consumer may first install "bcm2835.h" library if they aim to code in C programming language.

    
```console
   	      pi@raspberrypi:~ $ sudo su
              root@raspberrypi:/home/pi# mkdir medIOEx-Example
              root@raspberrypi:/home/pi# cd medIOEx-Example
              root@raspberrypi:/home/pi/MedIOEx_Example/MedIOEx# git clone git://github.com/pe2a/MedIOEx.git
              root@raspberrypi:/home/pi/MedIOEx_Example/MedIOEx# cd MedIOEx
              root@raspberrypi:/home/pi/MedIOEx_Example/MedIOEx# tar zxvf bcm2835-1.50.tar.gz
              root@raspberrypi:/home/pi/MedIOEx_Example/MedIOEx# cd bcm2835-1.50
              root@raspberrypi:/home/pi/MedIOEx_Example/MedIOEx/bcm2835-1.50# ./configure
              root@raspberrypi:/home/pi/MedIOEx_Example/MedIOEx/bcm2835-1.50# make
              root@raspberrypi:/home/pi/MedIOEx_Example/MedIOEx/bcm2835-1.50# make check
              root@raspberrypi:/home/pi/MedIOEx_Example/MedIOEx/bcm2835-1.50# make install
              root@raspberrypi:/home/pi/MedIOEx_Example/MedIOEx# cd ..
```

For Digital Output Test:

		root@raspberrypi:/home/pi/MedIOEx_Example/MedIOEx# gcc -o Do_test Do_test.c -lbcm2835 pmedex.c -std=gnu11

To run Digital Output Pins:
   						
		root@raspberrypi:/home/pi/MedIOEx_Example/MedIOEx# ./Do_test 
		
Initial Setup Video: https://vimeo.com/197692012

Digital Output Video: https://vimeo.com/196781378 
