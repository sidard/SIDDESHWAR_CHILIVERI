/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Write a program to convert Celsius form of temperature into Fahrenheit and vice versa. 
Example: (30°C x 1.8) + 32 = 86°F
*/

#include<stdio.h>


int main()
{
  float DegC, DegF;
  printf("Enter the temp in DegC:\n");
  scanf("%f", &DegC);
  DegF = (DegC * 1.8) + 32;
  printf("Temp in DegF: %f\n",DegF);
}

