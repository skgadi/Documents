/*
 * File:   main.c
 * Author: gadis
 *
 * Created on October 3, 2016, 2:00 PM
 */


/*
EEPROM Examples from internet
 * 
 * __EEPROM_DATA(0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88);
 * 
 * 
 * 
#include  
int main ()
{
    volatile unsigned char value = 0x09;
    unsigned char address = 0xE5;
    eeprom_write(address, value);     // Writing value 0x9 to EEPROM address 0xE5        
    value = eeprom_read (address);    // Reading the value from address 0xE5
}
 * 
 * 
 * 
 * 
#include  
int main ()
{
    volatile unsigned char value = 0x09;
    unsigned char address = 0xE5;
    EEPROM_WRITE(address, value);    // Writing value 0x9 to EEPROM address 0xE5 using the macro
    value = EEPROM_READ(address);    // Reading the value from address 0xE5 using the macro
}

 * 
 * 
 * 
 * 

 *  * // Primary Data Type with eeprom qualifier 
eeprom unsigned char inputData[3]={0xa,0xb,0xc};

// Secondary Data Type with eeprom qualifier 
eeprom struct EESTR {
    unsigned char Version[];
    unsigned char VersionString[];
    unsigned char VersionDate[];
} myStruct = { {0x00, 0x01, 0x02} , {"hello"}, {"18/10/13"} };

 * 
 * 
 * /**/
#include "main.h"


eeprom char EE_C_D =0x15;eeprom char EE_C[3][3] = {{1, 81, 127},{0, 39, 15},{0, 117, 47},};eeprom char EE_STATE_BREAKS[3] = {8,15,25,};eeprom char EE_STATES[30][5]= {{10,0x08,0x09,0x02,0x00},{3,0x0C,0x09,0x00,0x00},{10,0x01,0x09,0x00,0x20},{3,0x01,0x0D,0x00,0x00},{10,0x09,0x08,0x10,0x00},{3,0x09,0x0A,0x00,0x00},{10,0x09,0x01,0x00,0x00},{3,0x09,0x11,0x00,0x00},{10,0x08,0x09,0x02,0x00},{3,0x0C,0x09,0x00,0x00},{10,0x01,0x09,0x00,0x20},{3,0x01,0x0D,0x00,0x00},{10,0x09,0x08,0x10,0x00},{3,0x09,0x0A,0x00,0x00},{10,0x09,0x01,0x00,0x00},{3,0x09,0x11,0x00,0x00},{10,0x08,0x09,0x02,0x00},{3,0x0C,0x09,0x00,0x00},{10,0x01,0x09,0x00,0x20},{3,0x01,0x0D,0x00,0x00},{10,0x09,0x08,0x10,0x00},{3,0x09,0x0A,0x00,0x00},{10,0x09,0x01,0x00,0x00},{3,0x09,0x11,0x00,0x00},{10,0x09,0x08,0x10,0x00},{3,0x09,0x0A,0x00,0x00},{10,0x09,0x01,0x00,0x00},{3,0x09,0x11,0x00,0x00},{10,0x09,0x01,0x00,0x00},{3,0x09,0x11,0x00,0x00},};eeprom char EE_AUDIO[4]= {0x82,0x02,0x02,0x28,};



void main(void) {
    return;
}