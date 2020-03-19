import RPi.GPIO as GPIO
import spidev
import time
from enum import Enum,auto
from Pi_MCP23S17 import MCP23S17
"""
It works with Raspbian OS,
Hardware should be: 
-Raspberry Pi 2
-Raspberry Pi 3B
-Raspberry Pi 3B+
-Raspberry Pi Zero W
-Raspberry Pi 3 A+

MedIOEx-V2 is must.
SPI must be ENABLE via Raspi-Config. 
Pi_MCP23S17.py file must be at the same directory. 
"""
__author__ = "pe2a"
__license__ = "GPL"


#GLOBAL VARIABLES DIGITAL INPUT

DI_GPIO_J17_1 = 16
DI_GPIO_J17_2 = 20
DI_GPIO_J17_3 = 21
DI_GPIO_J17_4 = 26

DI_GPIO_J16_5 = 19
DI_GPIO_J16_6 = 13
DI_GPIO_J16_7 = 6 
DI_GPIO_J16_8 = 5

DI_GPIO_J15_9 = 22 
DI_GPIO_J15_10 = 12 
DI_GPIO_J15_11 = 27 
DI_GPIO_J15_12 = 17 

DI_GPIO_J14_13 = 4
DI_GPIO_J14_14 = 23 
DI_GPIO_J14_15 = 24 
DI_GPIO_J14_16 = 18 


#ANALOG INPUT VAL
AI_J13_1 = 4
AI_J13_2 = 5
AI_J13_3 = 6
AI_J13_4 = 7



GPIO_AI_CS3 = 25  #analog input SPI chip select
GPIO_DO_CS1 = 7

#converts digital number to voltage
def rpi_dig_vol_converter(val):
    return val*33.0/4095.0

def __myGPIOInit__():

    #init function
    GPIO.setmode(GPIO.BCM) #bcm library
    #for digital inputs
    
    #DIGITAL INPUT
    GPIO.setup(DI_GPIO_J17_1,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    GPIO.setup(DI_GPIO_J17_2,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    GPIO.setup(DI_GPIO_J17_3,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    GPIO.setup(DI_GPIO_J17_4,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    
    GPIO.setup(DI_GPIO_J16_5,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    GPIO.setup(DI_GPIO_J16_6,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    GPIO.setup(DI_GPIO_J16_7,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    GPIO.setup(DI_GPIO_J16_8,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    
    GPIO.setup(DI_GPIO_J15_9,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    GPIO.setup(DI_GPIO_J15_10,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    GPIO.setup(DI_GPIO_J15_11,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    GPIO.setup(DI_GPIO_J15_12,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    
    GPIO.setup(DI_GPIO_J14_13,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    GPIO.setup(DI_GPIO_J14_14,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    GPIO.setup(DI_GPIO_J14_15,GPIO.IN,pull_up_down=GPIO.PUD_UP)
    GPIO.setup(DI_GPIO_J14_16,GPIO.IN,pull_up_down=GPIO.PUD_UP)

    #analog input chip select
    GPIO.setup(GPIO_AI_CS3,GPIO.OUT)
    
    #digital output chip select
      
    GPIO.setup(GPIO_DO_CS1,GPIO.OUT)


 
    GPIO.setwarnings(False)
    
__myGPIOInit__()


#ANALOG INPUT START
#MiniIOEx has 12 bit ADC and the inputs work between 0-33V 
#mcp3208 ADC

def rpi_readAI(ch):

    spi = spidev.SpiDev()
    spi.open(0, 0)
    spi.max_speed_hz = 7629

    #burada digital output SPI CS kapatilacak kesinlikle

    GPIO.output(GPIO_DO_CS1,GPIO.HIGH) #DIGITAL OUTPUT DE-ACTIVE
    GPIO.output(GPIO_AI_CS3, GPIO.LOW)  # AI_Pin  is Active


   
    if 7 <= ch <= 0:
        raise Exception('MCP3208 channel must be 0-7: ' + str(ch))

    cmd = 128  # 1000 0000
    cmd += 64  # 1100 0000
    cmd += ((ch & 0x07) << 3)
    ret = spi.xfer2([cmd, 0x0, 0x0])

    # get the 12b out of the return
    val = (ret[0] & 0x01) << 11  # only B11 is here
    val |= ret[1] << 3           # B10:B3
    val |= ret[2] >> 5           # MSB has B2:B0 ... need to move down to LSB
    GPIO.output(GPIO_AI_CS3, GPIO.HIGH)  # AI_Pin  is DeActive

    return (val & 0x0FFF)  # ensure we are only sending 12b

#Digital Input Query
def getDIVal(ch):

    if GPIO.input(ch):
        return False
    else:
        return True
    


try:
    mcp1 = MCP23S17(ce=1)
    mcp1.open()

    for x in range(0, 16):
        mcp1.setDirection(x, mcp1.DIR_OUTPUT)

    print ("Starting blinky on all pins (CTRL+C to quit)")
    while (True):
        for x in range(0, 16):
            mcp1.digitalWrite(x, MCP23S17.LEVEL_HIGH)
        time.sleep(1)

        for x in range(0, 16):
            mcp1.digitalWrite(x, MCP23S17.LEVEL_LOW)
        time.sleep(1)
        print(rpi_readAI(AI_J13_1))
        

finally:
    mcp1.close()

    

 



