/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
2.A message ID is required to send data via CAN communication between ECU’s. Accept a random 2-digit message ID from the user to send data. Keep in mind that the given ECU only accepts binary form of the message ID. Write a program to convert the 2-digit ID to binary form.*/


#include<stdio.h>

int main()
{
  int i,data;
  printf("Enter the 2 digit number:\n");
  scanf("%2d",&data);
  
  for(i=31;i>=0;i--)
  {
	printf("%d",(data>>i)&1);	
  }

  
}
