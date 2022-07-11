/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler*/
/*2) EVEN AND ODD NUMBER USING CONDITIONAL OPERATOR*/

#include<stdio.h>

int main()
{
   int a;
   printf("Enter the number to check even or odd\n");
   scanf("%d",&a);
 
   (a%2==0)?printf("Even number"): printf("Odd number");

}
