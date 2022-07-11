/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Write program to accept hex value as i/p and right shift bit value also as i/p and print the value after doing the hex right shift

Enter the DataInp = CC;
Enter UsrBit = 1;
Display DataInp updated after right shift = CE;
*/


#include<stdio.h>

int main()
{
  int DataInp, UsrBit;
  printf("Enter the data in hex format:\n");
  scanf("%x",&DataInp);
  printf("Enter the bit:\n");
  scanf("%x",&UsrBit);
  DataInp>>=UsrBit; 
  printf("Data after right shift: %x", DataInp);  
  
 
}
