#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float smooth(float* data,int readdatasize,int filtersize,float* finalresults)

{
	//int filterSize=5; // size of filter

	int filtRight=(filtersize-1)/2;
	int filtLeft=-filtRight;
	
	for (int n=filtRight+1;n<500+filtLeft;n++) //for loop moving through original data set
	{
		float x=0; //resetting sum of data for each loop
		for (int m = filtLeft;filtLeft<=m && filtRight>=m;m++) //moving filter along original data set and calucalting the sum of sets the size of inputted filter size
		{
			x=x+data[m+filtRight]; //calculating sum

		}
		finalresults[n-3]=x/filtersize; //inputting averaged value into output set 
	}

	FILE * fp=fopen("clean_sin.dat", "w");
	
	for (int i = 0; i < 500; i++)
		{
			fprintf(fp,"%f\n",finalresults[i]);

		}
	fclose(fp);

}