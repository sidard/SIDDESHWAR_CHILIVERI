/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
 Write program to set (1) bits CIS, C2OUT, C1OUT in register “CMCON” if bits 
CHS3, CHS2, CHS1 bits are set to 0x06 in register “ADCON0” */


//CMCON Register  - CIS->bit_3   ,  C2OUT->bit_7 ,C1OUT->bit_6
//ADCON0 Register - CHS3->bit_5    , CHS2->bit_4  ,CHS1->bit_3 
#include<stdio.h>


int main()
{
   char ADCON0Regbyte = 0x33;//Initialize data in ACON0Register 
   char CMCONRegbyte  = 0x50;//Initialize data in CMCONRegister 
  
  puts("\nADCON0 Register binary print:");
  for(int i=7;i>=0;i--)
	printf("%d ",(ADCON0Regbyte>>i)&1);	
  puts("\nCMCON Register binary print:");
  for(int i=7;i>=0;i--)
	printf("%d ",(CMCONRegbyte>>i)&1);

  

  if(((ADCON0Regbyte>>3)&0x0f) == 0x06)
	{
	  CMCONRegbyte|=(1<<3);
	  CMCONRegbyte|=(1<<7);
      CMCONRegbyte|=(1<<6); 	
	}

  puts("\nAfter setting the bits CIS, C2OUT, C1OUT in register “CMCON”  ");
 
  for(int i=7;i>=0;i--)
	printf("%d ",(CMCONRegbyte>>i)&1);

}
