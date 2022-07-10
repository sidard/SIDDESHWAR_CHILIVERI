/*
Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Problem 2: 
Consider a character input from a user and print if it is a vowel or consonant. 
*************************************/
#include <stdio.h>

int main()
{
  char letter;
  printf("Enter the letter : ");
  scanf("%c", &letter);
  
  ((letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'u')
  || (letter == 'A') || (letter == 'E') || (letter == 'I') || (letter == 'U')) ?
  puts("vowel") : puts("consonant");
  
}


