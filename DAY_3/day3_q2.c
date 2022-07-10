/*2.Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Write a program to calculate the sum of the first and the second last digit of a 5-digit number entered from the keyboard.*/


#include<stdio.h>

int main()
{
   int temp,data,count,sum=0;
   enter:printf("Enter the 5 digit number\n");
   scanf("%d",&data);
   
   //Check the given integer is 5 - digit or not
   if((data%100000)!= data)
	{
		goto enter; // if found more than 5-digit than jump to enter the number again
	}
	
	
	sum = data%10 + data/10000;
	
	printf("Sum:%d\n" ,sum);
}


