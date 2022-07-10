/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Problem Statement 9:
/*Implement basic logic gates using C (AND, OR, NOT). Consider the inputs: 0,0

   			0,1

  			1,0

   			1,1. 

*/


#include<stdio.h>

int main()
{
    int data1, data2;
    printf("Enter the data1 and data2:");
    scanf("%d%d",&data1,&data2);
    printf("AND Gate : %d\n", data1&&data2);
    printf("OR Gate : %d\n", data1||data2);
    printf("NOT Gate : %d\n", !(data1!=0));
   
}
