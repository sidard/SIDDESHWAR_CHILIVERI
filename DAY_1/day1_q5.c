/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Problem statement 5:
5 balls are numbered with random 1-digit number each. Assign these numbers using user input.
Print whether each ball is assigned odd or even number.


*/

#include <stdio.h>

int main()
{
  int b1,b2,b3,b4,b5;
  printf("Assign the 1 digit number to ball-1: \n");
  scanf("%1d",&b1); // %1d means only 1 digit will be input from user, more than 1 digit will be ignored
  (b1%2==0) ? puts("Even Number") : puts("Odd Number");
  printf("Assign the 1 digit number to ball-2: \n");
  scanf("%1d",&b2);
  (b2%2==0) ? puts("Even Number") : puts("Odd Number");
  printf("Assign the 1 digit number to ball-3: \n");
  scanf("%1d",&b3);
  (b3%2==0) ? puts("Even Number") : puts("Odd Number");
  printf("Assign the 1 digit number to ball-4: \n");
  scanf("%1d",&b4);
  (b4%2==0) ? puts("Even Number") : puts("Odd Number");
  printf("Assign the 1 digit number to ball-5: \n");
  scanf("%1d",&b5);
  (b5%2==0) ? puts("Even Number") : puts("Odd Number");
  
  
}
