/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
7. I). Set the register SSPSTAT value such a way that bit CKE, P and S bit are cleared (0), without disturbing the other bits.
Algorithm:
1. Initialize the SSPSTAT Register with some data such as 0xFF
2. Now clear the bits CKE, P and S bit of SSPSTAT Register*/


#include<stdio.h>


//reset bits  6, 4, 3 

int main()
{
    char i, SSPSTAT_RegBits =  0xFF;
    
    puts("Given Binary data:");
    for(i=7;i>=0;i--)
        printf("%d ",(SSPSTAT_RegBits>>i)&1);
    
    
    SSPSTAT_RegBits &= ~(1 << 6);

    SSPSTAT_RegBits &= ~(1 << 4);  
    
    SSPSTAT_RegBits &= ~(1 << 3);
    
    puts("\nAfter clearing bits  CKE, P and S bit Binary data:");
        for(i=7;i>=0;i--)
        printf("%d ",(SSPSTAT_RegBits>>i)&1);
}



