MEDIOEX is basically Raspberry shield. Even if Raspberry has been a popular worldwide hobby in the last decades, we have transformed it into an engine which could be utilized in industrial environments thanks to our rich experience in the heavy industry. This document contains application samples regarding the commissionning of the card. Detailed information on MEDIOEX is shared in this document. The student and engineers may utilize in industrial environments thanks to such information on Raspberry shared in this Document. 
MEDIOEX contains the following features:

-><b>16ch isolated Digital Input</b>

-><b>16ch Digital Output ( 4 ch 250V relay, 12 ch 24VDC transistor output)</b>

-><b>4ch 12bit Analog Input </b> 

-><b>4ch 12bit Analog Output</b>  

-><b>Real time clock</b> 

-><b>1ch Rs232</b> 

-><b>1ch Rs485</b> 

-><b>>Including temperature sensor LM75bd</b> 

-><b>i2c terminal output </b> 

The below features should be added to the abovementioned features:

->64-bit quad-core ARMV8 processor.

->1.2GHz 1GB RAM.

->WiFi - BCM43143.

->Bluetooth 4.1 (Bluetooth Low Energy - BLE)

->4chUSB 2.

->4ch Stereo and Composite video output

Several tests have been performed on MEDIOX and raspberry so that the former and the latter could be utilized in industrial environments. You may perform the following test on MEDIOEX and RASPBERRY.

#1 remote control IO from cloud,

#2 Serial bus reading ex. energy analyzer etc.

Even if the above scenario might seem very easy to occur, the realization of this scenario with PLC and Industrial PC is very costly. You will have the chance to minimize the costs of the engines thanks to the utilization of Medioex and Raspberry. Consequently, you will be able to focus on software without having to deal with the hardware issues. 

MEDIOEX should powered with an external power supply of 24VDC. You can start Medioex through a connection between Medioex and J11 connecteur, as shown in the below picture or directly with a PC adapteur with a 24VDC.
PE2A provides the consumers with MEDIOEX cards together with open sources software. The consumer may make modifications on the code of the open source software. You can have access to detailed information via the below link as to the code functions. 

C: https://github.com/pe2a/MedIOEx

Python: https://github.com/bayraktarulku/medioex_test_suite

C#: https://github.com/huseyint/MedIOExNET

Node js: https://www.npmjs.com/package/node-red-contrib-medioex

Mediox provides physical Digital-Analog Input/output with SPI communcation based circuits. You can even use serial port RS232 and RS485. The consumer may first install "bcm2835.h" library.

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

For Digital Output Test:

		root@raspberrypi:/home/pi/MedIOEx_Example/MedIOEx# gcc -o Do_test Do_test.c -lbcm2835 pmedex.c -std=gnu11

To run Digital Output Pins:
   						
		root@raspberrypi:/home/pi/MedIOEx_Example/MedIOEx# ./Do_test 
		
Initial Setup Video: https://vimeo.com/197692012

Digital Output Video: https://vimeo.com/196781378 

