/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Right shift the value 0xFE by 3 bits and print the value

*/

#include <stdio.h>

int main()
{
  int data = 0xFE;
  printf("Given data : %x\n", data);
  data>>=3;
  printf("After Right shift by 3 times : %x\n", data);
  
}
