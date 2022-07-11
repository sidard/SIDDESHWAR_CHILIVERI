/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler*/
/*1) SWAPPING OF TWO NUMBERS USING THIRD VARIABLE*/

#include <stdio.h>

int main()
{
   int a,b,temp;
   printf("Enter two numbers:\n");
   scanf("%d%d",&a,&b);

   temp = a;
   a = b;
   b = temp;
   
   printf("Swapped numbers : %d %d",a,b);
}
