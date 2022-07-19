/*
 ============================================================================

 Author      : Siddeshwar Chiliveri
 Version     : 1.0
 Copyright   : Your copyright notice
 IDE : Eclipse C/C++ Workspace Environment
 Compiler : GCC
 Algorithm:
(1) There are 3 pressure sensor:
-> Pressure sensor right (PR)
-> Pressure sensor left (PL)
-> Pressure sensor center (PC)
(2) Take the input from the user to enter the number of samples.
(3) Take the input from the user to enter the data sample for each sensor
(4) Print the data sample on output console for each sensor
(5) Create the function which must discard the noise data if it is <0x05 or >0xF5 and return the valid array.
(6) Based on valid array create one more function which must remove the malfunction data Continuously 5 samples
 are having more threshold than 0x55.
(7) If Malfunction data is found then deploy the air bag
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(void)
{
	int *PRSensor = NULL;//Create the dynamic memory allocation by initializing the NULL pointer
	int *PLSensor = NULL;//Create the dynamic memory allocation by initializing the NULL pointer
	int *PCSensor = NULL;//Create the dynamic memory allocation by initializing the NULL pointer
	int Samples=0;
  
	/*Enter the number of samples required for each sensor (minimum 50 required)*/
	printf("\nPlease  enter the minimum 50 samples:\n");
	fflush(stdout);
	scanf("%d",&Samples);


	/*Allocate the size for each sensor*/
	PRSensor = calloc(Samples,sizeof(int));
	PLSensor = calloc(Samples,sizeof(int));
	PCSensor = calloc(Samples,sizeof(int));

	/*Please enter the sensor data for each sensors*/
	printf("Enter the %d samples PR sensor data:\n",Samples);
	fflush(stdout);
	for(int i=0;i<Samples;i++)
	{
		
	  scanf("%x",&PRSensor[i]);
	}
	printf("Enter the %d samples PL sensor data:\n",Samples);
	fflush(stdout);
	for(int i=0;i<Samples;i++)
	{
		scanf("%x",&PLSensor[i]);
	}
	printf("Enter the %d samples PC sensor data:\n",Samples);
	fflush(stdout);
	for(int i=0;i<Samples;i++)
	{
		scanf("%x",&PCSensor[i]);
	}

	/*Print the sensor data for each sensor on display*/
	printf("PR sensor data\n");
	fflush(stdout);
	for(int i=0;i<Samples;i++)
	{
		printf("%x,", PRSensor[i]);fflush(stdout);
	}
	printf("\nPL sensor data\n");
	fflush(stdout);
	for(int i=0;i<Samples;i++)
	{
		printf("%x,", PLSensor[i]);fflush(stdout);
	}
	printf("\nPC  sensor data\n");
	fflush(stdout);
	for(int i=0;i<Samples;i++)
	{
		printf("%x,", PCSensor[i]);fflush(stdout);
	}
	puts("");


	puts("\nFinal Data Array without noise:");fflush(stdout);
	int (*ptr)[No_of_Sensors] = F_P_Data_Fun(PRSensor,PLSensor,PCSensor,Samples);

	int finaArr[FinalDataSize*No_of_Sensors] = {0};

	for(int i=0;i<FinalDataSize;i++)
	     for(int j=0;j<No_of_Sensors;j++)
	    {
	        finaArr[i* No_of_Sensors +j] = ptr[i][j];
	        printf("%x,",finaArr[i* No_of_Sensors +j]);
	    }

	if(AirBagDeployment(finaArr,FinalDataSize*No_of_Sensors))
	{
	    printf("\nDeploy Air Bag");
	}
	else
	{
	    printf("\nDo not deploy air bag");
	}

}


