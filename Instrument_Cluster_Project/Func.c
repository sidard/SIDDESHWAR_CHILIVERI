
#include "types.h"

uint8_t TripSwitchFunc(void) {
    SWStatus[0]=RB0;
    SWStatus[1]=RB1;  
    if(RB0==0 && RB1==0)
        {/* Action*/
            RA0 = 1;//LED_4
            __delay_ms(1000);
            SWStatus[0]=0;
            SWStatus[1]=0;      
            return 1;
        }
    else if(RB0==1 && RB1==1)
        {/*No Action*/
            RA0=0;
            RA1=0;
            __delay_ms(1000);         
            return 0;
        }
    else
        {/*Hardware Failure*/
            RA0=0;//LED_4
            RA1=1;//LED_3
        }
    return 0;
}
void Sys_Init()
{
    GIE=1;//Global Interrupt Enable
    PEIE=1;//Peripheral Interrupt Enable
    
}
void CANCON_Set_Mode(int mode)
{
    
    switch(mode)
    {
        case 0:
            CANCON = ConfigurationMode_0x80;// CANCON Register set to configure mode
            break;
        case 1:
            CANCON = ListenOnlyMode_0x60; // CANCON Register set to listen mode
            break;
        case 2:
            CANCON = LoopbackMode_0x40;// CANCON Register set to loop back mode
        case 3:
            CANCON = DisableMode_0x20;// CANCON Register set to disable mode
        case 4:
            CANCON = NormalMode_0x00;// CANCON Register set to normal mode
    }
} 
void Can_Init(){
    
    TRISBbits.RB2=0;                        //Rb2 bit is set for output
    TRISBbits.RB3=1;                        //Rb3 bit is set for input
    PIE3bits.RXB0IE = 1;           /*Enable receiver buffer 0 interrupt*/
    IPR3bits.RXB0IP = 1;           /*Enable receiver buffer 0 as high priority*/   
}
void Set_BaudRate()  // baud rate function
{
    BRGCON1=0xC1;  //BRGCON1 register set to be 0xc1 for 250kbps.
    BRGCON2=0xAE;   //BRGCON2 register set to be 0xAE for 250kbps.
    BRGCON3=0x45;   //BRGCON3 register set to be 0x45 for 250kbps.
}
void Set_Filter()    //acceptance filter function
{
    RXF0SIDH=0x00;  // RXF0SIDH register set to 0x00.
    RXF0SIDL=0x00;  // RXF0SIDL register set to 0x00.  
}
void Set_Mask()     //acceptance mack function
{
    RXM0SIDH=0x00;  //RXM0SIDH register set to 0x00;
    RXM0SIDL=0x00;  //RXM0SIDL register set to 0x00;
    
}

void Tx_Buffer(uint8_t  Transfer_buffer, uint8_t Message_id, uint8_t DataBytes[])
{ 
    switch(Transfer_buffer)
    {
        case 0:
            CANCON = CANCON_TransmitBuffer_0;
            TXB0SIDH=(0x7F8 & Message_id) >> 3;//for MSB 8 bits
            TXB0SIDL=(0x07 & Message_id) << 5;//for LSB 3 bits;;
            TXB0DLC = 0x08;
            TXB0D0 = 0x00;
            TXB0D1 = DataBytes[1];//Warning Lamp Status
            TXB0D2 = 0x00;
            TXB0D3 = DataBytes[3];//Occupant Classification Status
            TXB0D4 = 0x00;
            TXB0D5 = DataBytes[5];//Trip Switch Status 
            TXB0D6 = 0x00;
            TXB0D7 = 0x00;
            //enable the TXBnCON  such that the transmitter buffer and assign the highest priority to the chosen buffer.
            TXB0CON = TransmitAtHighPriority;
            break;
            
        case 1:
            CANCON = CANCON_TransmitBuffer_1;
            TXB1SIDL = 0x00 ;
            TXB1SIDH = 0x00;
            TXB1DLC = 0x08;
            TXB1D0 = DataBytes[0];
            TXB1D1 = DataBytes[1];
            TXB1D2 = DataBytes[2];
            TXB1D3 = DataBytes[3];
            TXB1D4 = DataBytes[4];
            TXB1D5 = DataBytes[5];
            TXB1D6 = DataBytes[6];
            TXB1D7 = DataBytes[7];
            //enable the TXBnCON  such that the transmitter buffer and assign the highest priority to the chosen buffer.
            TXB1CON = TransmitAtHighPriority;
            break;
            
            // else if(Transfer_buffer == 2)//010 = Transmit Buffer 2
        case 2:
            CANCON = CANCON_TransmitBuffer_2;            
            TXB2SIDL = 0x00;//for LSB 3 bits
            TXB2SIDH = 0x01;//for MSB 8 bits
            TXB2DLC = 0x08;
            TXB2D0 = DataBytes[0];
            TXB2D1 = DataBytes[1];
            TXB2D2 = DataBytes[2];
            TXB2D3 = DataBytes[3];
            TXB2D4 = DataBytes[4];
            TXB2D5 = DataBytes[5];
            TXB2D6 = DataBytes[6];
            TXB2D7 = DataBytes[7];
            
            //enable the TXBnCON  such that the transmitter buffer and assign the highest priority to the chosen buffer.
            TXB2CON = TransmitAtHighPriority;
        default://No code line statement
            ;
    }//switch ends  
    CANCON=NormalMode_0x00;
}
void CAN_Read_fun()
{
    CANCON=0x0C;//Select Normal Mode and Select Receive Buffer_0.   
    Rx_data_11bytes_Buffer_0[0] =  RXB0D0;//data_byte_0
    Rx_data_11bytes_Buffer_0[1] =  RXB0D1;//data_byte_1
    Rx_data_11bytes_Buffer_0[2] =  RXB0D2;//data_byte_2
    Rx_data_11bytes_Buffer_0[3] =  RXB0D3;//data_byte_3
    Rx_data_11bytes_Buffer_0[4] =  RXB0D4;//data_byte_4
    Rx_data_11bytes_Buffer_0[5] =  RXB0D5;//data_byte_5
    Rx_data_11bytes_Buffer_0[6] =  RXB0D6;//data_byte_6
    Rx_data_11bytes_Buffer_0[7] =  RXB0D7;//data_byte_7 
    Rx_data_11bytes_Buffer_0[8] =  RXB0SIDL;//LowByte_3bits
    Rx_data_11bytes_Buffer_0[9] =  RXB0SIDH ;//HigherByte_8bits
    Rx_data_11bytes_Buffer_0[10] =  RXB0DLC;//DLC   
    
    /*Concatenate the RXB0SIDH + RXB0SIDL to Get 11_bits_data*/
    Rx_Data_MsgID_11bits = Rx_data_11bytes_Buffer_0[9]<<3 | Rx_data_11bytes_Buffer_0[8]>>5;
    if(Rx_Data_MsgID_11bits == Cruise_Control_Msg_ID)/*Cruise Control*/
    {
        // LED Debugging Purpose  
        RC0= 1;//LED_1
        __delay_ms(1000);
        for(uint8_t address =0;address<8;address++)
        {
        writeEEPROM(address, Rx_data_11bytes_Buffer_0[address]); //writing data to first memory location and then goes upto last location
        __delay_ms(20);
        }
    } 
    if(Rx_Data_MsgID_11bits == Occupant_Classification_Msg_ID)/*Occupant Classification*/
    {  
        // LED Debugging Purpose        
        RC1=  1;//LED_2 
        __delay_ms(1000);
        for(uint8_t address =8;address<16;address++)
        {
            writeEEPROM(address, Rx_data_11bytes_Buffer_0[address]); //writing data to first memory location and then goes upto last location
            __delay_ms(20);
        }
    }
        
    RXB0CONbits.RXB0FUL = 0;
    CANCON=NormalMode_0x00;//Resetting the Receiver Buffer_0 000 and set mode to Normal Mode  to get next data.
}

__interrupt () ISR1()
{
    CANCON=NormalMode_0x00;
    if(RXB0IF)
    {
        RXB0IF=0;//Clear The Interrupt enable flag
        CAN_Read_fun();//CAN Rx is called
    }
    
}
