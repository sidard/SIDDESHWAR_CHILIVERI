/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Find the number of leap years in the interval 1990-2022.*/
#include <stdio.h>
int main() {
   int year,cnt=0;
 
  for(year=1990;year<=2022;year++)
  {
   // leap year if perfectly divisible by 400
   if ((year % 400 == 0) || (year % 4 == 0))  
   {
     // printf("%d is a leap year.\n", year);
      cnt++;
       
   }
  }
  printf("No of leap years:%d",cnt);
 

   return 0;
}
