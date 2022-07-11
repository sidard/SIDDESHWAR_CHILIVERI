/*Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler

2) SWAPPING OF TWO NUMBERS WITHOUT USING THIRD VARIABLE*/

#include <stdio.h>

int main()
{
   int a,b;
   printf("Enter two numbers:\n");
   scanf("%d%d",&a,&b);

   a = a^b;
   b = b^a;
   a = a^b;
   printf("Swapped numbers : %d %d",a,b);
}
