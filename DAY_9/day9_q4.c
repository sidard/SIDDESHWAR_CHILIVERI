/*9.Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
 Assume that we have a car with 8 seats, and we are monitoring 8 seat belt status
in a variable “G_Msg_switchstatus_Byte[]” as shown in pic1. Each switch status is combination of 2 bits as shown in pic2.
Write status of switches into variable “G_Msg_switchstatus_Byte[]” as below.
SWITCH1, SWITCH7 status is “faulty type 1 in switch”, SWITCH2, SWITCH5 status is ”switch unbuckle”, SWITCH3, SWITCH6 status is “switch buckle”, SWITCH4, SWITCH0 status is “faulty type 2 in switch” without disturbing the other bits.

Switch status value :
00 Fault type 1 in switch
01 switch is buckle
10 switch is unbuckle
11 Fault type 2 in switch*/


/*Algorithm:
1)G_Msg_switchstatus_Byte[] as 3 elements with default value 0x00
2)Create a menu to ask which type of switch status user wants to see
3)Based on given input print the switch status */

#include<stdio.h>
typedef char byte;
void printSWStatus(byte);

int main()
   {
    byte i,num,G_Msg_switchstatus_Byte[3] ={0x00,0x00,0x00};
	
    printf("Enter the below number to check status of switches:\n");
    printf("0.Faulty type 1 in switch:\n");
    printf("1.switch buckle:\n");
    printf("2.switch unbuckle:\n");
    printf("3.Faulty type 2 in switch:\n");
    puts("---------------------------------");
    scanf("%hhd",&num);
    switch(num)
	{
	  case 0: puts("Faulty type 1 in switch"); 
		  G_Msg_switchstatus_Byte[0]|=(1<<0);//SWITCH_1 0th bit
		  G_Msg_switchstatus_Byte[0]|=(1<<1);//SWITCH_1 1st bit
          G_Msg_switchstatus_Byte[2]|=(1<<4);//SWITCH_7 4th bit 
		  G_Msg_switchstatus_Byte[2]|=(1<<5);//SWITCH_7 5th bit
		  printSWStatus(G_Msg_switchstatus_Byte[0]);//print of SWITCH_1 status
          printSWStatus(G_Msg_switchstatus_Byte[2]);//print of SWITCH_7 status
		  break;
	
	  case 1: puts("Switch buckle");
		  G_Msg_switchstatus_Byte[1]|=(1<<5);// SWITCH_3 5th bit
  		  G_Msg_switchstatus_Byte[1]|=(1<<4);// SWITCH_3 4th bit
          G_Msg_switchstatus_Byte[2]|=(1<<7);// SWITCH_6 7th bit
		  G_Msg_switchstatus_Byte[2]|=(1<<6);// SWITCH_6 6th bit
		  printSWStatus(G_Msg_switchstatus_Byte[1]);//print of SWITCH_3 status
          printSWStatus(G_Msg_switchstatus_Byte[2]);//print of SWITCH_6 status
		  break;

          case 2: puts("Switch Unbuckle");
		  G_Msg_switchstatus_Byte[1]|=(1<<7);//SWITCH_2 7th bit
 		  G_Msg_switchstatus_Byte[1]|=(1<<6);//SWITCH_2 6th bit
          G_Msg_switchstatus_Byte[1]|=(1<<0);//SWITCH_5 0th bit
		  G_Msg_switchstatus_Byte[1]|=(1<<1);//SWITCH_5 1st bit     
		  printSWStatus(G_Msg_switchstatus_Byte[1]);//print of SWITCH_2 and SWITCH_5 status
		  break;

          

	  case 3: puts("Faulty type 2 in switch");
		  G_Msg_switchstatus_Byte[0]|=(1<<2);// SWITCH_0 2nd bit
  		  G_Msg_switchstatus_Byte[0]|=(1<<3);// SWITCH_0 3rd bit
          G_Msg_switchstatus_Byte[1]|=(1<<2);// SWITCH_4 2nd bit
		  G_Msg_switchstatus_Byte[1]|=(1<<3);// SWITCH_4 3rd bit
		  printSWStatus(G_Msg_switchstatus_Byte[0]);//print of SWITCH_0 status
          printSWStatus(G_Msg_switchstatus_Byte[1]);//print of SWITCH_4 status
		  break;        
	}
}

void printSWStatus(byte data)
{
   char i;
   for(i=7;i>=0;i--)
		printf("%d ",(data>>i)&1);
	puts("");
}


