/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler*/
/*4) GIVEN NUMBER IS POWER OF 2 OR NOT*/
#include <stdio.h>

int main()
{
    int data;
    printf("Enter the data:\n");
    scanf("%d",&data);

    (data&(data-1))==0 ? printf("Power of 2") : printf("Not power of 2");

    return 0;
}
