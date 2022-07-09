/*
Author: Siddeshwar Chiliveri
Programming Language: C
Software Used to Test: Online GDB Debugger
Problem 2: 
Consider a character input from a user and print if it is a vowel or consonant. 

Algorithm :
1. Take a letter from user 
2. Check the condition is vovel or consonant
3. If condition is true then print "VOWEL" else "CONSONANT"
4. End
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


