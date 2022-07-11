/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Write program to check given i/p by user is alphabet or not alphabet using conditional operator

*/


#include <stdio.h>

int main()
{
   char data;
   printf("Enter the data\n");
   scanf("%c", &data);
   
   ((data>='A' && data<='Z') || (data>='a' && data<='b'))?printf("An Alphabet\n"):printf("Not an Alphabet");
}
