/* Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
3. b) Find out the value of T0PS2, T0PS1, T0PS0 bits in T0CON register if the value of the register is 0xF3.

/******************************************************************************
Algorithm:
1. Set the bits of 7 and 0 of T0CON Registers.
*******************************************************************************/
	
#include<stdio.h>


int main()
{
    char i,T0CON_Regbits  = 0xF3;//Initializing 0xF3 data in T0CON_Register
    
    printf("Given data binary bits:\n");
//Set bit:0, 1, 2
for (i=7;i>=0;i--) 
    {
        printf("%d ",(T0CON_Regbits>>i)&1);
    }
    puts("");

    printf("T0PS0:%d, ",(T0CON_Regbits>>0)&1);
    printf("T0PS1:%d, ",(T0CON_Regbits>>1)&1);
    printf("T0PS2:%d, ",(T0CON_Regbits>>2)&1);
}
