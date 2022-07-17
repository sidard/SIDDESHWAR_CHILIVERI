/*Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
Acceleration sensor data is captured in a 2-dimension array as “Sensor_Values[Timestamp_Value][ Sensor_Data]”.

Time stamp interval = 10 ms incremental

Number of data samples = 20 (20 time stamp samples, 20 data samples)

The Sensor_Data is considered as noise if values is < 0x05 and > 0xF0.
Output 1 : Print the time stamp where data is coming as noise.

Output 2 : Delete the noise data and write valid sensor values to new 2-dimension array “Sensor_noNoise_Vlaue[Timestamp_Value][ Sensor_Data]” and
print them – timestamp and values.

Algorithm:
1.Initlialize a count of Samples to 0
2. Read Sensor data samples captured at every 10 msec from acceleration uptil count of samples reached to 20.
3. If Sensor data read is smaller than 0x05 & greater than 0xF0, print the time stamp of current sensor data read.
4. If Sensor data read does not meet above condition then store the time stamp & current sensor data in "Sensor_noNoiceValue" Array
*******************************************************************************/
#include<stdio.h>
#include <stdlib.h>

#define Noise_lowRange  0x05 // Set Noise Range1 : less than 0x05
#define Noise_highRange  0xF0 // Set Noise Range2 : greater than 0xF0



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

	int size = sizeof(Sensor_Values)/sizeof(Sensor_Values[0]);// to find the size of array
	int NoNoiseCnt=0;

	puts("20 Sample Data:\n");
	Disp(Sensor_Values,size);

	puts("\n---------------------------------------------------------------------------------------");

	puts("\nTime stamp where data is coming as noise:\n");
	for(int i=0;i<size;i++)
	{
		if(CheckNoise(Sensor_Values[i][1]))
		{
			printf("%d msec , ", Sensor_Values[i][0]);fflush(stdout);
		}
		else
		{
			Sensor_noNoice_Value[NoNoiseCnt][0] = Sensor_Values[i][0];//Assign the no noise time stamp
			Sensor_noNoice_Value[NoNoiseCnt][1] = Sensor_Values[i][1];//Assign the no noise data
			NoNoiseCnt++;//Increment the index of Sensor_noNoice_Value array to add no noise data
		}
	}
	puts("\n---------------------------------------------------------------------------------------");
	puts("\nNo-Noise Data:");
	Disp(Sensor_noNoice_Value,NoNoiseCnt);

}
