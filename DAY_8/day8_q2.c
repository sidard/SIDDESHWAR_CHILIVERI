/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
5.Write a program in C to sort an array using Pointer. The sample output must be as below
Author : Siddeshwar Chiliveri


/******************************************************************************
Algorithm:
1. Get the number of elements from user
2. Get the input of elements from user
3. Sort the elements one by one and print sorted elements on output
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,N,temp,*data;
    
    printf("Enter the number of elements to add:\n");
    scanf("%d",&N);//get the number of elements from user
    
    data = (int*)calloc(N, sizeof(int));//creating dynamic array
    
    printf("Enter the integer type data elements one by one:\n");
    
     for(i=0;i<N;i++)
     {
        scanf("%d",(data+i));
     }
  
    puts("");
    for(i=0;i<N;i++)
    {
     for(j=i+1;j<N;j++)
     {
      if(*(data+i) > *(data+j))
        {
         temp = *(data+i);
        *(data+i) = *(data+j);
        *(data+j) = temp;
        }
     }
    }
    for(i=0;i<N;i++)
    {
      printf("%d ",*(data+i));
    }
    
    free(data);//free the dynamic array 
    data=NULL;//put NULL to avoid dangling pointer
    
}
