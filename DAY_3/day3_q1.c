/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Write a program to achieve below statements.

a.Collect 15 elements (8 integers, 7 float) as i/p from user. 

b.Calculate and Print the sum, average and mean of integers

c.Calculate and Print the sum, average of all float values

d.Divide sum in statement ‘b’ with statement ‘c’ sum and print the value.

e.Divide average in statement ‘b’ with statement ‘c’ average and print the value.

f.Convert all 7 float values to integers and print them.*/


#include<stdio.h>

/*Collection of 15 Elements*/

#include<stdio.h>


int main()
{
   int i,IntData[8],sumInt=0;
   float fltData[7],sumFlt=0;
   
   printf("Enter the 8 Integers one by one:\n");
   for(i=0;i<8;i++)
   	scanf("%d",&IntData[i]);
   printf("Enter the 7 float values one by one:\n");
   for(i=0;i<7;i++)
   	scanf("%f",&fltData[i]);

   for(i=0;i<8;i++)
	{
           sumInt= sumInt + IntData[i];
	}
  for(i=0;i<7;i++)
	{
           sumFlt= sumFlt + fltData[i];
	}

   printf("Sum of 8 Integers is : %d\n", sumInt);
   printf("Average of 8 integeres is: %d\n",sumInt/8);
   printf("Sum of 7 float data is : %f\n", sumFlt);
   printf("Average of 7 float data is: %f\n",sumFlt/7);
   printf("Sum of 8 integer data divide by sum of 7 float data: %f\n",(float)sumInt/sumFlt);
   printf("Average of 8 integer data divide by sum of 7 float data: %f\n",((float)sumInt/8)/(sumFlt/7));
   //printf("Conversion of :%d",(int)3.98);
   printf("Conversion of all 7 float values to integers : ");
   for(i=0;i<7;i++)
   	printf("%d ",(int)fltData[i]);
}
