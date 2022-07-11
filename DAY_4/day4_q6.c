/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler*/
/*1)HOW TO SET A BIT*/
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
   printf("Enter the bit number to set: ");   
   scanf("%d",&bit); 
  printf("\n");
 
  data = data | (1<<bit); // Set the bit
    for(i=31;i>=0;i--)
  {
	printf("%d ",((data>>i)&1));
  }
     
   
}
