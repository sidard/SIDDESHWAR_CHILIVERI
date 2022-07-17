/******************************************************************************
Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Algorithm:
1. Read Sensor data samples captured at every 10 msec from acceleration uptil count of samples reached to 20
2. Check Noise Condition : Sensor data read is smaller than 0x05 & greater than 0xF0
3. If Noise condition is false then insert the data in Sensor_noNoice_Value Array.
4. Display No Noise Sensor Data elements of Sensor_noNoice_Value Array.
5. If Noise condition is false then check Malfunction condition
6. If Malfunction data condition is true then print time stamp of current sensor data.
7. If Malfunction data condition is false then insert the data in Sensor_Final_Value Array.
8. Display Valid (Exclude of Noise and Malfunction) Sensor Data elements of Sensor_noNoice_Value Array.
 *******************************************************************************/
#include<stdio.h>
#include <stdlib.h>

#define Noise_lowRange  0x05 // Set Noise Range1 : less than 0x05
#define Noise_highRange  0xF0 // Set Noise Range2 : greater than 0xF0
#define ContinuousDataSample 3 //Set the Condinuous Data Sample



/*Function to Display the Array elements*/
void Disp(int (*arr)[2], int size)
{
	for(int i = 0;i<size;i++)
	{
		printf("%d msec: 0x%x | ",arr[i][0], arr[i][1]);fflush(stdout);
	}
}
/*Function to Check the sensor data is noise or not*/
int CheckNoise(int data)
{
	if((data<Noise_lowRange) || (data>Noise_highRange))
		return 1;
	else
		return 0;
}
int CheckMalfun(int data1, int data2)
{
	if(data1 == data2)
		return 1;
	else
		return 0;
}
int main()
{
	/*Acceleration Sensor Data*/
	int Sensor_Values[20][2] = {{0,0x00},{10,0x00},{20,0x00},{30,0x00},{40,0x00},{50,0xEF},
								{60,0x06},{70,0x84},{80,0xF8},{90,0x39},{100,0x39},{110,0x39},{120,0xF6},
								{130,0x57},{140,0x43},{150,0x42},{160,0x69},{170,0x75},{180,0x16},{190,0x19}};

	/*No Noise Array declaration and initialize to 0*/
	int Sensor_noNoice_Value[20][2]={0};
	int Sensor_Final_Value[20][2]={0};
	int size = sizeof(Sensor_Values)/sizeof(Sensor_Values[0]);// to find the size of array
	int NoNoiseCnt=0, flag=1;
	int NoMalCnt=0;

	puts("20 Sample Data:\n");
	Disp(Sensor_Values,size);

	puts("\n---------------------------------------------------------------------------------------");
	puts("\nNo-Noise Data:");
	for(int i=0;i<size;i++)
	{
		if(!CheckNoise(Sensor_Values[i][1]))
		{
			Sensor_noNoice_Value[NoNoiseCnt][0] = Sensor_Values[i][0];//Assign the no noise time stamp
			Sensor_noNoice_Value[NoNoiseCnt][1] = Sensor_Values[i][1];//Assign the no noise data
			NoNoiseCnt++;//Increment the index of Sensor_noNoice_Value array to add no noise data
		}
	}
	Disp(Sensor_noNoice_Value,NoNoiseCnt);

	puts("\n---------------------------------------------------------------------------------------");
	puts("\nMalfunction Data timestamp:");
	for(int i=0;i<size;i++)
		{
		if(!CheckNoise(Sensor_Values[i][1])) //Check no noise condition to discard first noise data
		{
			if(flag<ContinuousDataSample)
			{
				if(CheckMalfun(Sensor_Values[i][1],Sensor_Values[i+1][1]))//Check Malfunc Data
				{
					if(flag==1)
					{
						printf("%d msec to ", Sensor_Values[i][0]);fflush(stdout);//Disp Start time of Malfun Data
					}
					flag++;
				}
				else
				{
					/*Assign valid data to Sensor_Final_Value Array*/
					Sensor_Final_Value[NoMalCnt][0] = Sensor_Values[i][0];//Assign the no malfunction data time stamp
					Sensor_Final_Value[NoMalCnt][1] = Sensor_Values[i][1];//Assign the no malfunction data
					NoMalCnt++;//Increment the index of Sensor_Final_Value array to add no noise data
				}
			}
			else
			{
				printf("%d msec  ", Sensor_Values[i][0]);fflush(stdout);//Disp End time of Malfun Data
				flag = 1;//reset the flag
			}
		}//if Noise condition

		}//for loop
	puts("\n---------------------------------------------------------------------------------------");
	puts("\nSensor Final Data exclude of noise and malfun data:");
	Disp(Sensor_Final_Value,NoMalCnt);
}
