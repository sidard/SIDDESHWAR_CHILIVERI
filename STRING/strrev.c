#include<stdio.h>



void strRev(char *srcdata)
{
    int i,j;
    for(i=0;srcdata[i];i++);
    for(j=0,i=i-1;i>j;i--,j++)
    {
        char temp = srcdata[j];
         srcdata[j] = srcdata[i];
         srcdata[i] = temp;
    }
}

int main()
{
    char src[11] = "Siddeshwar";
    printf("%ld %ld ",sizeof(src)/sizeof(char), strlen(src));
    int i;
    strRev(src);
    printf("%s ",src);
}
