
#ifndef __FUNCTION_H
#define __FUNCTION_H

#include <visa.h>

class functionGenerator
{
	ViStatus status;
	ViSession viDG1022;
	ViSession defaultRM;
	ViFindList fList;
	ViUInt32 numInst;
	ViChar desc[VI_FIND_BUFLEN];
	ViChar resultBuffer[256];
	ViUInt32 resultCount;
	char commandstring[256];
	float voltage;
	float freq;
	float phase;
    float dcoffset;
    ViChar type[4];

public:
	 functionGenerator();
	
	void identify();

    void setFreq(double);

    void setOffset(double);

    void setPhase(double);

    void setVoltage(double);

	void turnon();
    void turnoff();

    void generateSin(const ViChar*);

	void voltageUnit();

};
#endif
