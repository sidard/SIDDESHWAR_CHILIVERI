/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Convert decimal number 204 to hex value, binary value and print the same

*/

#include<stdio.h>

int main()
{
  int data = 204,i;
  printf("Given data in Integer format: %d\n", data);
  printf("Given data in Hex format: %x\n", data);
  printf("Given data in Binary format: \n");

  for(i=31;i>=0;i--)
  {
     printf("%d ", (data>>i)&1);
  }
}
