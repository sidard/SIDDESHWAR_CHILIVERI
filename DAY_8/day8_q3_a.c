/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler

3.a) Set the register T0CON value such a way that bit TMR0ON and PSA bit are set(1), 
without disturbing the other bits.




/******************************************************************************
Algorithm:
1. Set the bits of 7 and 0 of T0CON Registers.
*******************************************************************************/
	
#include<stdio.h>


int main()
{
    char i,T0CON_Regbits  = 0x03;//Initializing some data in T0CON_Register
    
    printf("Given data in T0CON_Reg binary bits");
//Set bit:7 and 3
 for (i=7;i>=0;i--) 
    {
        printf("%d ",(T0CON_Regbits>>i)&1);
    }
    puts("");

    T0CON_Regbits = T0CON_Regbits|(1<<7);// Set bit register 7
    
    T0CON_Regbits = T0CON_Regbits|(1<<3);// Set bit register 3
    printf("Set bits of 7 and 3:\n");
    for (i=7;i>=0;i--) 
    {
        printf("%d ",(T0CON_Regbits>>i)&1);
    }
    
}
