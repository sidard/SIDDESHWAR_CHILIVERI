#include "types.h"
//#define LED_1 RC0
//#define LED_2 RC1


char RetEEData;


unsigned char readEEPROM(unsigned char address)
{
    EEADR = address; //Address to be read
    EECON1bits.EEPGD = 0; //Selecting EEPROM Data Memory
    EECON1bits.RD = 1; //Initialise read cycle
    while(EECON1bits.RD);
    RetEEData = EEDATA;
    return RetEEData; //Returning data
}
void writeEEPROM(unsigned char Address, unsigned char data)
{
    EEADR = Address; //Address to write
    EEDATA = data; //Data to write
    
    EECON1bits.EEPGD = 0; //Selecting EEPROM Data Memory
    EECON1bits.CFGS = 0; //Access program Flash or data EEPROM memory
    EECON1bits.WREN = 1; //Enable writing of EEPROM
    GIE = 0;//Disable Interrupts
    EECON2=0x55; //Required sequence for write to internal EEPROM
    EECON2=0xAA; //Required sequence for write to internal EEPROM
    EECON1bits.WR = 1; //Initialize write cycle
    GIE=1;
    while(PIR2bits.EEIF == 0);
    EECON1bits.WREN = 0; //To disable write
    PIR2bits.EEIF = 0; //Clearing EEIF bit
}


 
