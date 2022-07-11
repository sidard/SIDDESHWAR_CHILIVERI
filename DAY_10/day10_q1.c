/*10. Write a function to store "G_Eng_EngineTemperature_uchar" and "G_Eng_EngineRpm_uint" into " G_Msg_EngineInformation_Byte[5u]" as shown below.

unsigned char G_Eng_EngineTemperature_uchar = 50u ;


unsigned int G_Eng_EngineRpm_uint = 1000u;


unsigned char G_Msg_EngineInformation_Byte[5u];

*/

#include<stdio.h>
typedef unsigned char u_char;
typedef unsigned int  u_int;

void StoreData(u_char,u_int);

int main()
{
	u_char G_Eng_EngineTemperature = 50 ;
        u_int  G_Eng_EngineRpm = 1000;
	puts("Binary data stored in G_Eng_EngineTemperature:");
  for(int i =7;i>=0;i--)
        printf("%d ",(G_Eng_EngineTemperature>>i)&1);

	puts("\nBinary data stored in G_Eng_EngineRpm:");
   for(int i =31;i>=0;i--)
        printf("%d ",(G_Eng_EngineRpm>>i)&1);

	StoreData(G_Eng_EngineTemperature,G_Eng_EngineRpm);
	
	
}

void StoreData(u_char G_Eng_EngineTemperature ,u_int G_Eng_EngineRpm)
{
  u_char G_Msg_EngineInformation_Byte[5]={0x00,0x00,0x00,0x00,0x00};
    int i,j;
  
	G_Msg_EngineInformation_Byte[0] = (G_Eng_EngineRpm>>9)&0x0F;//G_Eng_EngineRpm 12-9 bits
	G_Msg_EngineInformation_Byte[1] = (G_Eng_EngineRpm>>1)&0xFF;//G_Eng_EngineRpm 8-1 bits
	G_Msg_EngineInformation_Byte[2] =  (G_Eng_EngineRpm &(1<<0))<<7;//G_Eng_EngineRpm 0th bit
	G_Msg_EngineInformation_Byte[3] =  G_Eng_EngineTemperature;//G_Eng_EngineTemperature 7-0 bits
	
   for(i=0;i<5;i++)
	{
	    printf("\nG_Msg_EngineInformation_Byte[%d]:\n",i);
		for(j=7;j>=0;j--)
			printf("%d ",(G_Msg_EngineInformation_Byte[i]>>j)&1);
	    
	}
}
