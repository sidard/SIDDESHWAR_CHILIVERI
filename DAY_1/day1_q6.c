/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Problem Statement 6:
Students with roll numbers 1-9 are seated in ascending order in an examination hall. 
There has been a slight mistake in their seating arrangement where two consecutive roll numbers have been swapped.
Choose these two consecutive numbers as per your choice and swap them back in their right places according to ascending order.
*/

#include<stdio.h>

int main()
{
   int r1=1,r2=2,r3=3,r4=4,r5=5,r6=7,r7=6,r8=8,r9=9;
   printf("Roll numbers 1-9 are: %d, %d, %d, %d, %d, %d, %d, %d, %d\n",r1,r2,r3,r4,r5,r6,r7,r8,r9);
   
   r6^=r7^=r6^=r7;
   printf("Roll numbers 1-9 in ascending order: %d, %d, %d, %d, %d, %d, %d, %d, %d",r1,r2,r3,r4,r5,r6,r7,r8,r9);
   
}
