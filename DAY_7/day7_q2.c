/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
2. Write a code to swap even bits with odd bits in unsigned long variable(uint64).
Example: bit 0 with bit 1; bit 2 with bit 3; bit 4 with bit 5

Algorithm:
1. If the current bit and next bit is unequal then do complement
2. If the current bit and next bit is equal then don't do complement
*/

#include <stdio.h>
int main()
{
     unsigned long int data = 9007464240589635583;
     unsigned long int data1, data2;
     data1=data&0x00000000ffffffff;
     data2=data&0xffffffff00000000;
     data2 = data2>>32;
    int i;
    
    puts("Given data binary format:");
    
    for(i=63;i>=0;i--)
    {
       printf("%d ",(data>>i)&1);
    }
    puts("");
   
   
    for(i=31;i>=0;i--)
      {
       if(((data1>>i)&1) != ((data1>>(i-1))&1))
        {
           data1 = (1<<i)^data1;
           data1 = (1<<i-1)^data1;
        }
        i--;
      }
      for(i=31;i>=0;i--)
      {
       if(((data2>>i)&1) != ((data2>>(i-1))&1))
        {
           data2 = (1<<i)^data2;
           data2 = (1<<i-1)^data2;
        }
        i--;
      }
      data = data2<<32 | data1;
    puts("\nAfter swapping adjacent bits:");
     for(i=63;i>=0;i--)
       printf("%d ",(data>>i)&1);
    return 0;
}
