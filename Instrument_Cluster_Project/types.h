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

#define Cruise_Control_Msg_ID 0x75
#define Occupant_Classification_Msg_ID 0x99
#define Instrument_Cluster_Msg_ID 0x88

#define LED_1 RC0
#define LED_2 RC1

enum Tx_Buffer{Transfer_Buffer_0, Transfer_Buffer_1, Transfer_Buffer_2};  
enum Rx_Buffer{Receiver_Buffer_0, Receiver_Buffer_1};  

enum bytes{byte_0,byte_1,byte_2,byte_3,byte_4,byte_5,byte_6,byte_7};

uint8_t Rx_data_11bytes_Buffer_0[11]={0};
uint8_t Rx_data_11bytes_Buffer_1[11]={0};

void writeEEPROM( uint8_t address,  uint8_t data);
uint8_t readEEPROM( uint8_t address);
uint8_t SWStatus[2];//TripResetSwitchStatus Array
/* SW2 SW1 Status
 *  0  0    Trip is Reset (No Hardware Failure)
 *  0  1    Hardware Failure  
 *  1  0    Hardware Failure
 *  1  1    No Action (No Hardware Failure)
 */
uint8_t arr_read[8];
uint16_t Rx_Data_MsgID_11bits;
uint8_t RetEEData;

uint8_t TripSwitchFunc(void);
void Sys_Init(void);
void CANCON_Set_Mode(int mode);
void Can_Init(void);
void Set_BaudRate(void);
void Set_Filter(void);
void Set_Mask(void);
void Tx_Buffer(uint8_t ,uint8_t,uint8_t*);
void CAN_Read_fun(void);
