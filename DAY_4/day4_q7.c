/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
2)HOW TO CLEAR A BIT*/


#include <stdio.h>

int main()
{
   int i,data,bit;
   printf("Enter the data: ");
   scanf("%d",&data);
   puts("Equivalent binary is: ");
   for(i=31;i>=0;i--)
  {
	printf("%d ",((data>>i)&1));
  }
   printf("\n");
   printf("Enter the bit number to clear: ");   
   scanf("%d",&bit);
   
  
  printf("\n");
 
  data = data & ~(1<<bit); // CLEAR A BIT
    for(i=31;i>=0;i--)
  {
	printf("%d ",((data>>i)&1));
  }
     
   
}
