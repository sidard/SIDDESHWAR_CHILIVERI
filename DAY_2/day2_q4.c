/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Kishore bought ‘n’ number of lottery tickets. His lucky number is 3 so he wants to separate all the tickets that have the number 3 in them. Find how many such lucky tickets are found in the ‘n’ number of tickets purchased by Kishore.*/

#include<stdio.h>

int main()
{
   int k,tmp,i,count=0, tickt[]={1,2,333,433,3,13,2,10};
   int ArrSize = sizeof(tickt)/sizeof(int);
   
   for(i=0;i<ArrSize ;i++)
     printf("%d,",tickt[i]); //print the ticket numbers

   for(i=0;i<ArrSize ;i++)
     {
       tmp = tickt[i]; //scan each ticket by storing each element in 'tmp' variable
       while(tmp) 
       {
         k = tmp;
         k = k%10;
         if(k==3) // check if any ticket has lucky number 3
            {
              count++; //increment the count and break the while loop for next tickt 
              break;
	    }
         tmp= tmp/10;
       }
  
     }
printf("\nThe number of tickets are:%d",count); 
}
