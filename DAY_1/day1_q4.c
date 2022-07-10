/*
Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Problem 4:
Take a 6-digit number as input from the user and reverse the number. 
Make sure that the number does not include a ‘0’ in any of its digits.
*******************************************************************************/
/*Method 1 : In this method we are reversing exact 6 digit number */
#include <stdio.h>

int main()
{
   int d1,d2,d3,d4,d5,d6,rev,n=641312;
   printf("Given number:%d\n", n);
  d6=n%10; n=n/10;
  d5=n%10; n=n/10;
  d4=n%10; n=n/10;
  d3=n%10; n=n/10;
  d2=n%10; n=n/10;
  d1=n%10; n=n/10;
  rev = d6*100000 + d5*10000 + d4*1000 + d3*100 + d2*10 + d1;
  printf("Reverse number:%6d", rev);
    return 0;
}*/

/*Method 2 : In this method we are reversing any number
from user using while loop*/
#include <stdio.h>
int main() {
  int n, reversed = 0, remainder;
    printf("Enter an integer: ");
    scanf("%d", &n);

    // reversed integer is stored in reversed variable
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
printf("Reverse number:%d", reversed);
    return 0;
}
