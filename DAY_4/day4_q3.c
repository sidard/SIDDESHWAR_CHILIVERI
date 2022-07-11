/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler*/
/*1)BIGGEST OF TWO NUMBERS USING CONDITIONAL OPERATOR*/

#include <stdio.h>

int main()
{
   int a,b ;
   printf("Enter the two numbers:\n");
   scanf("%d%d",&a,&b);

   (a>b)?printf("1st number is bigger:%d",a):printf("2nd number is bigger:%d",b);
}
