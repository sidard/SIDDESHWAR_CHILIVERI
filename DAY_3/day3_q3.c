/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Write a program to reverse a 3-digit number which is entered from keyboard. */


#include<stdio.h>

int main()
{
   int data,rev;
   enter:printf("Enter the 3 digit number\n");
   scanf("%d",&data);
   
   //Check the given integer is 5 - digit or not
   if((data%1000)!= data)
	{
		goto enter; // if found more than 5-digit than jump to enter the number again
	}
	
	int d1, d2, d3;
	d1 = data%10; data/=10;
	d2 = data%10; data/=10;
	d3 = data%10;
	
	rev = d1*100 + d2*10 + d3;
	
	
	printf("Rev:%d\n" ,rev);
}


