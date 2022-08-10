#include "types.h"

void main(void) {
    /*Transmit Parameters*/
    char TransmitBuffer=Transfer_Buffer_0;
    char MsgID=Instrument_Cluster_Msg_ID;
    char Tx_Instrument_Cluster_DataBytes[8];
    char Rx_Cruise_Control_Warning_Lamp;
    char Rx_Occupant_Classification_Warning_Lamp;
    char ReadfromEEPROM[16];
    
    TRISA=0x00;//Set LED_0,LED_1,LED_2,LED_3
    TRISC=0X00;
    TRISB = 0X0B ;//SW_1, SW_2, TX & RX
    RBPU=0;
    Sys_Init();
    Can_Init();
    CANCON_Set_Mode(0);//Set Configuration Mode  the CANCON Register 
    Set_Mask();
    Set_Filter();
    Set_BaudRate();
    CANCON_Set_Mode(4);//Set Normal Mode
    
    while(1)
    {       
        /*Receiver Message ID Comparison*/
        for(int i=0;i<16;i++)
        {
            
            ReadfromEEPROM[i] = readEEPROM(i);   //Last Updated Status from Cruise Control and Occupant Classification
            __delay_ms(500);
        }
        
        Rx_Cruise_Control_Warning_Lamp = (ReadfromEEPROM[7]>>3);
       
        if(Rx_Cruise_Control_Warning_Lamp==3)
        {
            RA1 = 1;//LED_3 - Hardware Failure Lamp
            __delay_ms(2000);
            RA1 = 0;//LED_3 - Hardware Failure Lamp
            __delay_ms(2000);
        }
      
        
        Tx_Instrument_Cluster_DataBytes[1] = (SWStatus[1]<<1) | SWStatus[0];/*Tx Instrument Cluster Msg ID 0x88 Byte 1*/
        Tx_Instrument_Cluster_DataBytes[3] =  ReadfromEEPROM[8];/*Occupant Classification //Byte_0 bit:1 and bit:0*/
        Tx_Instrument_Cluster_DataBytes[5] = (TripSwitchFunc()<<2);     
        Tx_Buffer(TransmitBuffer,MsgID,Tx_Instrument_Cluster_DataBytes);
        __delay_ms(5000);
        
        RC0=0;//Setting Default LED_1 to OFF
        RC1=0;//Setting Default LED_2 to OFF
        GIE=1;
    }//while
}


