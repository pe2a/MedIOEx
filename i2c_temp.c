/*
 
   Ortam sicaklik bilgileri bu program yardimiyla okunabilir. 

   Compile with gcc -o i2c_lm75bd i2c_lm75bd.c
   Run with ./i2c_lm75bd 
   
 
*/

#define ADDR_SELECT 0x0

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <bcm2835.h>

int main(){

    int lm75file;
    int addr = 0x48 | ADDR_SELECT;	/* address of sensor */
    signed char buf[2];
    int n;
    float temp;

    if ((lm75file = open("/dev/i2c-1", O_RDWR)) < 0) { //eger daha onceki surum ise degisitirilmesi gerekiyor -o ile
        printf("open error!\n");	/* open device file */
        exit(1);
    }

    if (ioctl(lm75file, I2C_SLAVE_FORCE, addr) < 0) {
        printf("address error!\n");	/* set I2C device address */
        exit(1);
    }

    buf[0] = 0;				/* write register=0 */
    n=write(lm75file,buf,1);		/* to make sure we read temp */
    if (n != 1) {
        printf("write error! %d\n",n);
        exit(1);
    }

	
    n=read(lm75file, buf, 2);		/* read 2 temperature bytes */
    if (n != 2) {
        printf("read error! %d\n",n);
        exit(1);
    } else {		/* combine the 11 bits from the two bytes */
	n = buf[0] << 3 | ((buf[1] >> 5) & 0x07);
	temp = (float)n / 8;		/* 11 bits to temperature */
/*      printf("read: 0x%X 0x%X %d %4.2f\n", buf[0], buf[1], n, temp); */
        printf("Ortam Sicakligi %4.2f\n", temp);	/* print temp in 2 decimals */
        
    }

		
	
    close(lm75file);
    return 0;
}

