
/* Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
 * 1. Write a program to convert a data stream from Little Endian to Big Endian
 *  (you can take any 8 bit value or use 0b110101110)?
Author : Siddeshwar Chiliveri
  */


/*Algorithm :
 1) Take an 8 bit data bit stream of 0x32
 2) Get first lower nibble
 3) Get  upper nibble
 4) Do the right shift of lower nibble by 4 times
 5) Do the left shift of upper nibble by 4 times
 6) Now do concatenate of right and left shifted nibbles
 7) Check the result*/


#include<stdio.h>

int main()
{
   unsigned char byteData = 0x35;
   printf("The Little Endian byteData  : %x\n",byteData);
   byteData = ((byteData & 0X0F)<<4) | ((byteData & 0XF0)>>4) ;
   printf("The Big Endian byteData  : %x",byteData);

}

