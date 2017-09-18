#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int nosiysin (void)
{	
	
	float val;
	FILE* fp;
	fp = fopen("files.dat", "w");
		for (int i = 0; i < 500; i++)
		{
			float k=0.2*((float)rand()/(float)RAND_MAX)-0.1;
			val=sin(2*i*M_PI/500)+k;
			fprintf(fp,"%f\n",val);
		}
		fclose(fp);
}
