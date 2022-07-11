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
1. Read elements from Sensor_values array one by one.
2. Check the Sensor_data is less than 0x05 and greater than 0xF0, if found true then print time stamp, else move to next element.
3. If above step gives false then create an Sensor_noNoise_Vlaue Array and add the no noise elements in it.
4. Print the Sensor_noNoise_Vlaue Array 
*******************************************************************************/
#include<stdio.h>
#include <stdlib.h>
int main()
{
    short int Sensor_Values[20][2] = {{0,0x00},{10,0x00},{20,0x0F},{30, 0xFF}, {40, 0xFF},
    						{50,0x05}, {60, 0xAA}, {70, 0x55}, {80, 0xFE},
                        {90, 0x00}, {100, 0x00}, {110, 0x00}, {120, 0xFF}, {130, 0xFF}, {140, 0xFF}, {150, 0xFF},
                        {160,0x11}, {170, 0x33}, {180, 0x99}, {190, 0xE9}};

    //Initializing the array elements with 0 to avoid garbage value
    short int (*Sensor_noNoise_Vlaue)[2] = {0};
    int cnt=0;// Number of noise values count


    printf("Sensor Values are:\n");
    for(int i=0;i<20;i++, printf("\n"))
            printf("%hd , %x",Sensor_Values[i][0], Sensor_Values[i][1]);

   //Output 1 : Print the time stamp where data is coming as noise.

    printf("Time stamp where data is coming as noise:\n");
    for(int i=0;i<20;i++)
    {
            if((Sensor_Values[i][1] < 0x05) || (Sensor_Values[i][1] > 0xF0 ))
            {
            	printf("%d msec, ", Sensor_Values[i][0]);
            	cnt++;// Number of noise values count
            }

    }
    printf("\n");

    //Output 2 : Delete the noise data and write valid sensor values to new 2-dimension array
   // “Sensor_noNoice_Vlaue[Timestamp_Value][ Sensor_Data]” and print them – timestamp and values.

    //No Noise = Sensor_Values - cnt
    //No Noise = 20 - cnt

    Sensor_noNoise_Vlaue = calloc(20-cnt,sizeof(Sensor_Values[0])); //Creating the array to store valid sensor values
    printf("Valid sensor values w.r.to time with NO noise:\n");
    for(int i=0;i<20;i++)
        {
    			if((Sensor_Values[i][1] >= 0x05) && (Sensor_Values[i][1] < 0xF0 ))
                {
                	Sensor_noNoise_Vlaue[i][0] = Sensor_Values[i][0];
                	Sensor_noNoise_Vlaue[i][1] = Sensor_Values[i][1];
                	printf(" %d msec , %x | ",Sensor_noNoise_Vlaue[i][0], Sensor_noNoise_Vlaue[i][1]);
                }
    	}

    return 0;
}
