/*
Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
(1) Consider the phone number of a person as user input and find the sum of its */

#include<stdio.h>

int main()
{
  int res=0,data,temp;
  printf("Enter the data:\n");
  scanf("%d",&data);

  while(data)
  {
     res = res + data%10;
     data/=10;
  }
  printf("Result of sum of digits entered:%d\n",res);
} 


