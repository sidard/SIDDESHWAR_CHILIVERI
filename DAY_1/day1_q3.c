/*
Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Problem 3: 
The entire area of a circular garden is to be covered with grass by a Gardener. 
The radius of the garden is given by the user input. 
Calculate the area that has to be covered. 


*************************************/
#include <stdio.h>
#include <math.h>
int main()
{
  float area, radius;
  printf("Enter the radius : ");
  scanf("%f", &radius);
  
  area = 3.14159*radius*radius;
  
  printf("\n Area :%f",area);
  
  
}

