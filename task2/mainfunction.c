#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <smooth.h>
#include <readdata.h>

#define data_size 1000
#define filtersize 5

int main(void)
{

	float data[data_size];

	FILE * fp = fopen("files.dat", "r");
	int readdatasize = readdata(data,  data_size, fp);
	printf("%f\n", readdatasize);

	float finalresults[readdatasize];
	smooth(data, readdatasize,filtersize , finalresults);
	
}