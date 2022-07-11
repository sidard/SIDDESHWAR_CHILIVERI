/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler*/


/*3) POSITIVE OR NEGATIVE NUMBER USING CONDITIONAL OPERATOR*/


#include<stdio.h>

int main()
{
   int a,bit;
   printf("Enter the number to check positive or negative number\n");
   scanf("%d",&a);
   
   bit = sizeof(int)*8 -1 ;
 
   ((a>>bit)&1)?printf("Negative number"): printf("Positive number");

}
