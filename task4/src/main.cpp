#include <stdio.h>
#include <stdlib.h> 
#include <visa.h>
#include <unistd.h>
#include <function.h>
#include <windows.h>

int main()
{
	float x;

	functionGenerator fg;

	fg.identify();
	Sleep(2000);

	fg.turnon();
	Sleep(2000);
	fg.voltageUnit();
	Sleep(2000);

	fg.phases();
	Sleep(2000);

	fg.generateSin();


}