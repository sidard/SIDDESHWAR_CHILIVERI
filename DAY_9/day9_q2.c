/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
 Find out the value of UA, BF, SMP bits in SSPSTAT register if the value of the register is 0x55 */

//bit to find 7, 1, 0
#include<stdio.h>

int main()
{
    char i, SSPSTAT_RegBits =  0x55;//Initialize the data in SSPSTAT_Register
    
    puts("Given Binary data:");
    for(i=7;i>=0;i--)
        printf("%d ",(SSPSTAT_RegBits>>i)&1);
        
        
        
        
    printf("\nBF:%d, ",(SSPSTAT_RegBits>>0)&1);
    printf("UA:%d, ",(SSPSTAT_RegBits>>1)&1);
    printf("SMP:%d, ",(SSPSTAT_RegBits>>7)&1);
    
    
}

