/* Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler

4. Realize a function which has 2 arguments and 1 return value. Argument 1 is Byte value, Argument 2 is bit position. 
Function has to flip the bit position (as per argument 2) in argument 1 byte value and return complete byte value.

Author : Siddeshwar Chiliveri

Algorithm:
/*
1.Get the byte and bit position from user input
2.Create the function which will flip the bit position provided by user.
*/
#include<stdio.h>
typedef char byte;

int FuncFlipBit(byte data, int bit);
int main()
{
	
	int data,i, bit=0;
	printf("Enter the data:");
	scanf("%d",&data);
	for(i=7;i>=0;i--)
		printf("%d ",(data>>i)&1);	
        puts("");
Label:  printf("Enter the bit position between 0 to 7:");
	scanf("%d",&bit);	
	if(bit>7)
		goto Label;
	data = FuncFlipBit(data,bit);
}

int FuncFlipBit(byte data, int bit)
{
	 data = data^(1<<bit);
        for(int i=7;i>=0;i--)
		printf("%d ",(data>>i)&1);	
	return data;
}
