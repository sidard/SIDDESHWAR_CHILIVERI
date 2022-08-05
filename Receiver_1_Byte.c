// PIC18F458 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
#pragma config OSCS = OFF       // Oscillator System Clock Switch Enable bit (Oscillator system clock switch option is disabled (main oscillator is source))

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bit (Brown-out Reset disabled)
#pragma config BORV = 25        // Brown-out Reset Voltage bits (VBOR set to 2.5V)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 128      // Watchdog Timer Postscale Select bits (1:128)

// CONFIG4L
#pragma config STVR = OFF       // Stack Full/Underflow Reset Enable bit (Stack Full/Underflow will not cause Reset)
#pragma config LVP = OFF        // Low-Voltage ICSP Enable bit (Low-Voltage ICSP disabled)

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000200-001FFFh) not code protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot Block (000000-0001FFh) not code protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000200-001FFFh) not write protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0001FFh) not write protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000200-001FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from Table Reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0001FFh) not protected from Table Reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>
#define _XTAL_FREQ  2000000
#define ConfigurationMode_0x80 0x80
#define ListenOnlyMode_0x60  0x60
#define LoopbackMode_0x40 0x40
#define DisableMode_0x20 0x20
#define NormalMode_0x00 0x00
#define CANCON_TransmitBuffer_0 0x08
#define CANCON_TransmitBuffer_1 0x06
#define CANCON_TransmitBuffer_2 0x04
#define TransmitAtHighPriority 0x0B
#define LED_1 RA0
#define LED_2 RA1

enum Tx_Buffer{Transfer_Buffer_0, Transfer_Buffer_1, Transfer_Buffer_2};  
enum Rx_Buffer{Receiver_Buffer_0, Receiver_Buffer_1, Receiver_Buffer_2};  


char Rx_data_bytes_11[11]={0};
char Tx_Message_data_0[]= {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};
    
int Sys_Init()
{
    GIE=1;//Global Interrupt Enable
    PEIE=1;//Peripheral Interrupt Enable
    
}
int CANSTAT_Get_Mode(void)
{
    if((CANSTAT == NormalMode_0x00))
    {
        return 1;
    }
    else if((CANSTAT == DisableMode_0x20))
    {
        return 1;
    }
    else if ((CANSTAT == LoopbackMode_0x40))
    {
        return 1;
    }
    else if ((CANSTAT == ListenOnlyMode_0x60))
    {
        return 1;
    }
    else if ((CANSTAT == ConfigurationMode_0x80))
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
    //  TRISA=0X00;                             //Trisa bits are set to high for LED as an Output
    TRISBbits.RB2=0;                        //Rb2 bit is set for output
    TRISBbits.RB3=1;                        //Rb3 bit is set for input
    //PIE3=0x02;                              //PIE3 register is set to enable Receiver Buffer 1
    //IPR3=0X02;                              //IPR3 register is set to enable 
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

//int Write_fun(short int Transfer_buffer, short int Message_id, long long int *data)
int Tx_Buffer(char Transfer_buffer)
{ 
       //char Tx_Message_data2[]= {0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8};
     // char Tx_Message_data3[]= {0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80};
    switch(Transfer_buffer)
    {
        //selecting Transfer buffer and  setting to Normal Mode
        //if(Transfer_buffer == 0)//100 = Transmit Buffer 0
        case 0:
            CANCON = CANCON_TransmitBuffer_0;
            TXB0SIDH=0x0C;
            TXB0SIDL=0x80;
            TXB0DLC = 0x08;
          
            //Assigning the 0th byte of data  to  byte of the TXB0D1
            TXB0D0 = Tx_Message_data_0[0];
            //Assigning the 1st byte of data  to  byte of the TXB0D2
            TXB0D1 = Tx_Message_data_0[1];
            //Assigning the 2nd byte of data  to  byte of the TXB0D3
            TXB0D2 = Tx_Message_data_0[2];
            //Assigning the 3rd byte of data  to  byte of the TXB0D4
            TXB0D3 = Tx_Message_data_0[3];
            //Assigning the 4th byte of data  to  byte of the TXB0D5
            TXB0D4 = Tx_Message_data_0[4];
            //Assigning the 5th byte of data  to  byte of the TXB0D6
            TXB0D5 = Tx_Message_data_0[5];
            //Assigning the 6th byte of data  to  byte of the TXB0D7
            TXB0D6 = Tx_Message_data_0[6];
            //Assigning the 7th byte of data  to  byte of the TXB0D8
            TXB0D7 = Tx_Message_data_0[7];
            //enable the TXBnCON  such that the transmitter buffer and assign the highest priority to the chosen buffer.
            TXB0CON = TransmitAtHighPriority;
            break;
            
            // else if(Transfer_buffer == 1)//011 = Transmit Buffer 1
       /* case 1:
            CANCON = CANCON_TransmitBuffer_1;
            //assign the Message ID High byte to TXBnSIDH (High Byte Register).
            //Assign the Message ID Low byte to TXBnSIDL (Low Byte Register).
            TXB1SIDL = (0x07 & Message_id) << 5;//for LSB 3 bits
            TXB1SIDH = (0x7F8 & Message_id) >> 3;//for MSB 8 bits
            /*Set the length of the messages to 8 bytes in the TXBnDLC
             1000 = Data Length = 8 bytes
             0 = Transmitted message will have TXRTR bit cleared
            TXB1DLC = 0x08;
            char *msg_data = data;
            //Assigning the 0th byte of data  to  byte of the TXB1D1
            TXB1D0 = *msg_data;
            msg_data++;
            //Assigning the 1st byte of data  to  byte of the TXB1D2
            TXB1D1 = *msg_data;
            msg_data++;
            //Assigning the 2nd byte of data  to  byte of the TXB1D3
            TXB1D2 = *msg_data;
            msg_data++;
            //Assigning the 3rd byte of data  to  byte of the TXB1D4
            TXB1D3 = *msg_data;
            msg_data++;
            //Assigning the 4th byte of data  to  byte of the TXB1D5
            TXB1D4 = *msg_data;
            msg_data++;
            //Assigning the 5th byte of data  to  byte of the TXB1D6
            TXB1D5 = *msg_data;
            msg_data++;
            //Assigning the 6th byte of data  to  byte of the TXB1D7
            TXB1D6 = *msg_data;
            msg_data++;
            //Assigning the 7th byte of data  to  byte of the TXB1D8
            TXB1D7 = *msg_data;
            msg_data++;
            //enable the TXBnCON  such that the transmitter buffer and assign the highest priority to the chosen buffer.
            TXB1CON = TransmitAtHighPriority;
            break;*/
            /*
            // else if(Transfer_buffer == 2)//010 = Transmit Buffer 2
        case 2:
            CANCON = CANCON_TransmitBuffer_2;            
            TXB2SIDL = (0x07 & Message_id) << 5;//for LSB 3 bits
            TXB2SIDH = (0x7F8 & Message_id) >> 3;//for MSB 8 bits
                   
            //Set the length of the messages to 8 bytes in the TXBnDLC
            //1000 = Data Length = 8 bytes
            //0 = Transmitted message will have TXRTR bit cleared
            TXB2DLC = 0x08;
            
            
            char *msg_data = data;
            //Assigning the 0th byte of data  to  byte of the TXB2D1
            TXB2D0 = *msg_data;
            msg_data++;
            //Assigning the 1st byte of data  to  byte of the TXB2D2
            TXB2D1 = *msg_data;
            msg_data++;
            //Assigning the 2nd byte of data  to  byte of the TXB2D3
            TXB2D2 = *msg_data;
            msg_data++;
            //Assigning the 3rd byte of data  to  byte of the TXB2D4
            TXB2D3 = *msg_data;
            msg_data++;
            //Assigning the 4th byte of data  to  byte of the TXB2D5
            TXB2D4 = *msg_data;
            msg_data++;
            //Assigning the 5th byte of data  to  byte of the TXB2D6
            TXB2D5 = *msg_data;
            msg_data++;
            //Assigning the 6th byte of data  to  byte of the TXB2D7
            TXB2D6 = *msg_data;
            msg_data++;
            //Assigning the 7th byte of data  to  byte of the TXB2D1
            TXB2D7 = *msg_data;
            msg_data++;
            
            //enable the TXBnCON  such that the transmitter buffer and assign the highest priority to the chosen buffer.
            TXB2CON = TransmitAtHighPriority;*/
        default://No code line statement
            ;
    }//switch ends  
    CANCON=NormalMode_0x00;
}

void CAN_Read_fun()
{
    CANCON=0x0C;//Select Normal Mode and Select Receive Buffer_0.   
    Rx_data_bytes_11[0] =  RXB0D0;//data_byte_0
    Rx_data_bytes_11[1] =  RXB0D1;//data_byte_1
    Rx_data_bytes_11[2] =  RXB0D2;//data_byte_2
    Rx_data_bytes_11[3] =  RXB0D3;//data_byte_3
    Rx_data_bytes_11[4] =  RXB0D4;//data_byte_4
    Rx_data_bytes_11[5] =  RXB0D5;//data_byte_5
    Rx_data_bytes_11[6] =  RXB0D6;//data_byte_6
    Rx_data_bytes_11[7] =  RXB0D7;//data_byte_7 
    Rx_data_bytes_11[8] =  RXB0SIDL;//LowByte_3bits
    Rx_data_bytes_11[9] =  RXB0SIDH ;//HigherByte_8bits
    Rx_data_bytes_11[10] =  RXB0DLC;//DLC 
    
    RXB0CONbits.RXB0FUL = 0;
    CANCON=NormalMode_0x00;//Resetting the Receiver Buffer_0 000 and set mode to Normal Mode  to get next data
}
__interrupt () ISR1()
{
    CANCON=NormalMode_0x00;
    if(RXB0IF)
    {
        RXB0IF=0;//Clear The Interrupt enable flag
        CAN_Read_fun();//CAN Rx is called
        /*LED Blink for Notification of Interrupt LED 1*/
        LED_1 = 1;
        __delay_ms(1000);
        LED_1 = 0;
    }
}

void main(void) {
    
    TRISA=0x00;//Set LED_1 & LED_2 as an Output
    Sys_Init();
    Can_Init();
    CANCON_Set_Mode(0);//Set Configuration Mode  the CANCON Register 
    Set_Mask();
    Set_Filter();
    Set_BaudRate();
    CANCON_Set_Mode(4);//Set Normal Mode
    
    while(1)
    {  
        Tx_Buffer(Transfer_Buffer_0);
        __delay_ms(5000);        
        for(char i=0;i<8;i++)
        {  
            if(Rx_data_bytes_11[i] == Tx_Message_data_0[i])//Set 88 is first byte D1 in Bus Analyser Software
            {             
                LED_2 = 1;//Notification of Interrupt LED 2
                __delay_ms(5000);
                LED_2 = 0;
                Rx_data_bytes_11[i]=0;//Clearing the Received Global Data
            }
        }
    }//while
}
