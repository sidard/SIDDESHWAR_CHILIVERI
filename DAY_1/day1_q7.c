/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Problem Statement 7:
/*Find whether a given 10-digit number is palindrome or not. 
(HINT: Any number is said to be a palindrome if the original number and the reverse of the original number are the same.)

*/

// Method 1: If given number is only 10 - digit 
 #include <stdio.h>

int main()
{
   int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,rev,n=1222222221,original=n;
   printf("Given 10-digit number is : %d\n",n);

  d10=n%10; n=n/10;
  d9=n%10; n=n/10;
  d8=n%10; n=n/10;
  d7=n%10; n=n/10;
  d6=n%10; n=n/10;
  d5=n%10; n=n/10;
  d4=n%10; n=n/10;
  d3=n%10; n=n/10;
  d2=n%10; n=n/10;
  d1=n%10; n=n/10;
 
  rev = d10*1000000000 + d9*100000000 + d8*10000000 + d7*1000000 + d6*100000 + d5*10000 + d4*1000 + d3*100 + d2*10 + d1;
  
  printf("Reverse number:%d\n", rev);
  

 (rev==original)? printf("Palindrome\n") : printf("Not palindrome");
 
  return 0;
}
/*

//Method 2 : If given number is any number
#include <stdio.h>
int main() {
  int n, reversed = 0, remainder, original;
    printf("Enter an integer: ");
    scanf("%d", &n);
    original = n;

    // reversed integer is stored in reversed variable
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    // palindrome if orignal and reversed are equal
    if (original == reversed)
        printf("%d is a palindrome.", original);
    else
        printf("%d is not a palindrome.", original);

    return 0;
}

*/
