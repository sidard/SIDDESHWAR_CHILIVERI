/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Write a function to store "G_Str_SteeringAngle_sint" to "G_Msg_SteeringInformation_Byte" as shown below.
signed int G_Str_SteeringAngle_sint = -60;
unsigned char G_Msg_SteeringInformation_Byte[3u];
*/

#include <stdio.h>
typedef signed int s_int;
typedef unsigned char byte;
void StoreData(s_int);
int main()
{
  s_int G_Str_SteeringAngle =-60;// 2's complement value will be 0XFFC4
  puts("Binary data stored in G_Str_SteeringAngle:");
  for(int i =31;i>=0;i--)
        printf("%d ",(G_Str_SteeringAngle>>i)&1);
  StoreData(G_Str_SteeringAngle);
  
    
}


void StoreData(s_int G_Str_SteeringAngle)
{
    byte G_Msg_SteeringInformation[3] = {0,0,0};
    int i,j;
    G_Msg_SteeringInformation[0] =  (G_Str_SteeringAngle>>10)&0x03; //Steering Angle bit 11 to bit 10 
    G_Msg_SteeringInformation[1] =  (G_Str_SteeringAngle>>2)&0xFF; //Steering Angle bit 9 to bit 2
    G_Msg_SteeringInformation[2] =  (G_Str_SteeringAngle<<6)&0xC0; //Steering Angle bit 1 to bit 0
    
    for(i=0;i<3;i++)
	{
	    printf("\nG_Msg_SteeringInformation[%d]:\n",i);
		for(j=7;j>=0;j--)
			printf("%d ",(G_Msg_SteeringInformation[i]>>j)&1);
	    
	}
}


