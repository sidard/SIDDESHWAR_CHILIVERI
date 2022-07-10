/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Problem Statement 8:
//Consider a character input and find its ASCII value.*/

#include<stdio.h>

int main()
{
  char c;
  printf("Enter the character: ");
  scanf("%c",&c);
  (c> 0 && c<=127) ?printf("Character is %c and ASCII Value is :%d",c,c): printf("Character is not found in ASCII Table");
}
