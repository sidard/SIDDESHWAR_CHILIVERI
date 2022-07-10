/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
A message is encoded in the form of numbers and sent to you. Write a program to decode the message. (HINT: A=1, B=2, … so on)

Input : 1234 ( Encoded format )
Output : ABCD ( Decoded format )

*/

#include<stdio.h>

int main()
{
  int data = 1234;
  int tmp;
  printf("%d\n",data);

  while(data)
  {
    tmp = data;
    tmp = tmp%10;
    printf("%c ",65+tmp-1);
    data/=10;
  }
}
