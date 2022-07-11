/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
13.Write a program to do binary search in a sorted array. 
Program should take input of sorted values and search value. 

 The basic steps to perform Binary Search are:
Algorithm:
1. Get the size of an array from user
2. Get the elements from user one by one
3. Sort the array first 
4. Get the searching number from user
5. Begin with the mid element of the whole array as a search key.
6. If the value of the search key is equal to the mid element then print the index of element.
7. Or if the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
8. Otherwise, narrow it to the upper half.
9. Repeatedly check  until the value is found or the interval is empty.
*/
#include <stdio.h>
#include <stdlib.h>
void main()
{
    int *array=NULL,ArrSize=0;
    int i, j, num, temp, search;
    int L, M, H; 
   
    printf("Enter the size of elements: ");
    scanf("%d",&ArrSize);
    
    array = calloc(ArrSize,sizeof(int));
    printf("Add the elements:\n");
    for (i = 0; i < ArrSize; i++)
    {
        scanf("%d", &array[i]);
    }
    
    for (i = 0; i < ArrSize; i++)
    {
        for (j = 0; j < (ArrSize - i - 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("Sorted array is...\n");
    for (i = 0; i < ArrSize; i++)
   {
        printf("%d, ", array[i]);
    }
    printf("\nElement to search \n");
    scanf("%d", &search);
    /*  Binary searching begins */
    L = 0;
    H = ArrSize-1;
    do
    {
        M = (L + H) / 2;
        if (search < array[M])
            H = M - 1; 
        else if (search > array[M])
            L = M + 1; 
    }while(search != array[M] && L <= H);
    
    if (search == array[M])
    {
        printf("Position of Index:%d\n",M);
    }
    else
    {
        printf("not found \n");
    }
}
