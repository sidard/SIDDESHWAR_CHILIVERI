/*
Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Problem 1 :We'll say a number is special if it is a multiple of 11 or if it is one more than a multiple of 11.
Print “SPECIAL” if the given non-negative number is special. Use the % "mod" operator.
*************************************/
#include <stdio.h>

int main()
{
  int number;
  printf("Enter the non-negative number: ");
  scanf("%d", &number);
  
  number%11 == 0 || number%11 == 1 ? puts("SPECIAL") : puts("Not Special");
}

