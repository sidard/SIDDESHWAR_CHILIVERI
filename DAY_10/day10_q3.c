/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Write a program to Implement ”Selection Sort” using Recursion for given elements (Number elements will vary, so make it as configurable item)

How Selection sort works is explained below.
*/
#include <stdio.h>
#include <stdlib.h>
void sorting(int *arr, int i, int n)
{
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] < arr[min]) {
            min = j;  //store the minimum element index  
        }
    }
 
    //Swap the elements
    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
 
    if (i + 1 < n) //compare until index == array_size
    {
        sorting(arr, i + 1, n);
    }
}
 

 
int main()
{
    int *arr=NULL, size = 0, i;
    printf("Enter the size of Array:\n");
    scanf("%d",&size);
    arr = calloc(size, sizeof(int));
    for(i=0;i<size;i++)
    {
        printf("Enter the element for arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    printf("Before Sorting:\n");
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    sorting(arr, 0, size);
    printf("\nAfter Sorting:\n");
      for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    return 0;
}
