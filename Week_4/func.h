#define FinalDataSize 50 //Initialize with maximum data rows of F_D Array
#define Noise_lowRange  0x05 // Set Noise Range1 : less than 0x05
#define Noise_highRange  0xF5 // Set Noise Range2 : greater than 0xF0
#define ContinuousDataSample 5 //Set the Condinuous Data Sample
#define No_of_Sensors 3//Number of Pressure Sensors connected

/*Function to Check the sensor data is noise or not*/
int CheckNoise(int data)
{
	if((data<Noise_lowRange) || (data>Noise_highRange))
		return 0;//noise data
	else
		return 1;//no noise data
}
int CheckMalfun(int data)
{
	if(data > 0x55)
		return 1;
	else
		return 0;
}
int** F_P_Data_Fun(int *PRSensor,int *PLSensor,int *PCSensor,int size)//Create the valid data array without noise using F_P_Data_Fun Function
{
	static int F_P_Data[FinalDataSize][No_of_Sensors]={0,0,0} ;
	int m=0; // m is the index for valid data of PRSensor initialize to index 0
	int n=0; // n is the index for valid data of PLSensor initialize to index 0
	int p=0; // p is the index for valid data of PCSensor initialize to index 0
	int i=0;// i is the index for valid data of F_D_Array


	while(i<FinalDataSize)//Iteration of F_P_Data Array
		{
			for(int j = 0;j<No_of_Sensors;j++)//Iteration of each Pressure sensor
			{
				if( j==0 )//PR_Sensor
				{
					if(m!=0)
						m=p+5;//to jump next 5msec interval after receiving the data from PC_Sensor
					while(m<size)// Check the range of samples
					{
						if(CheckNoise(PRSensor[m]))//Check valid data condition (i.e. No noise data)
						{
							F_P_Data[i][j] = PRSensor[m];
							printf("F_P_Data[%d][%d]: %x\n",i,j,F_P_Data[i][j]);fflush(stdout);//Debug Print
							break;
						}//if
						m+=5;//increment the PR_Sensor Interval to next 5 msec (increment of F_P_Data Array index of column 0)
					}//while loop
				}//if
				if( j==1 )//PL_Sensor
				{
					n = m+5;//to jump next 5msec interval after receiving the data from PR_Sensor
					while(n<size)
					{
						if(CheckNoise(PRSensor[n]))//Check noise data condition
						{
							F_P_Data[i][j] = PLSensor[n];
							printf("F_P_Data[%d][%d]: %x\n",i,j,F_P_Data[i][j]);fflush(stdout);//Debug Print
							break;
						}//if
						n+=5;//increment the PL_Sensor Interval to next 5 msec (increment of F_P_Data Array index of column 1)
					}//while loop
				}//if
				if( j==2 )//PC_Sensor
				{
					p = n+5;//to jump next 5msec interval after receiving the data from PL_Sensor
					while(p<size)
					{
						if(CheckNoise(PRSensor[p]))//Check noise data condition
						{
							F_P_Data[i][j] = PCSensor[p];
							printf("F_P_Data[%d][%d]: %x \n",i,j,F_P_Data[i][j]);fflush(stdout);//Debug Print
							break;
						}//if
						p+=5;//increment the PC_Sensor Interval to next 5 msec (increment of F_P_Data Array index of column 2)
					}//while loop
				}//if
			}
			i++;//increment of F_P_Data Array index of row

		}//while loop

	return &F_P_Data;
}
int AirBagDeployment(int *FinalValidData,int size)
{
	puts("\nIN Air Bag");fflush(stdout);
	int flag=0;

	for(int i=0;i<size;i++)
	{
			if(flag<ContinuousDataSample)//Check 5 times Continuous Data Samples if greater than 0x55
			{
				if(CheckMalfun(FinalValidData[i]))
				{
					flag++;
				}//if CheckMalfun
				else
				{
				 flag=0;
				}
			}//if flag
			if(flag==ContinuousDataSample)
			{
				return 1;
			}//else of if flag
	}
	return 0;
}
