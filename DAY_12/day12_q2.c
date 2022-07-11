/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
 Find empty strings in an array of strings (Array of strings will be given as input to program)
and print the position of array where empty string is present. 
And replace the empty string array element as “CYIENT”
*/


#include <stdio.h>
#include <string.h>

int main()
{
    char str[3][10]={0};
    int i;
    
    printf("Enter the string:\n");
    for(i=0;i<3;i++)
    {
      
       gets(str[i]); // Please use the Enter Key from Keyboard of PC to enter the next string
    }

    for(i=0;i<3;i++)
    {
       for(int j=0;j<strlen(str[i]);)
        {
            if(str[i][j] == ' ')
                {
                  j++;
                }
                
            else
                break; //break inner loop
            
            if(j+1 == strlen(str[i]))
            {
                    printf("Position:%d\n",i);
                    strcpy(str[i],"CYIENT");
            }
        }
            
    }
    
   for(i=0;i<3;i++)
    {
       printf("%s, ",str[i]);
    }
    
    
}
