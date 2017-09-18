#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int readdata(float* data, int data_size, FILE* fp)

{
	//FILE * fp = fopen("files.dat", "r");

	//float original[sz_data];
	int count = 0;

	char line[32];
	
	while (fgets(line, sizeof line, fp)!= NULL && count < data_size)
	{
		data[count]= atof(line);
		count++;
	}
	
	//fclose(fp);

	return count;
}
