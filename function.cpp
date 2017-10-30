
#include <stdio.h>
#include <stdlib.h> 
#include <visa.h>
#include <unistd.h>
#include <function.h>
#include <windows.h>

functionGenerator::functionGenerator()
{
  	voltage = 5.00;
	freq = 20000;
	phase = 0;
	dcoffset= 0;
    sprintf(type,"SIN ");

};

void functionGenerator::generateSin(const ViChar* type)
{
    sprintf(commandstring,"APPL:%s , %f, %f, %f",type, freq, voltage, dcoffset);
	status = viWrite(viDG1022,(unsigned char*)commandstring,sizeof commandstring,VI_NULL);
  	Sleep(2000);
};

void functionGenerator::setFreq(double f)
{
    freq=f;
};

void functionGenerator::setOffset(double o)
{
    dcoffset=o;
};

void functionGenerator::setVoltage(double v)
{
    voltage=v;
}

void functionGenerator::turnon()
{
    status = viWrite(viDG1022,(unsigned char*)"OUTP ON",8,VI_NULL);
  	Sleep(2000);
};

void functionGenerator::turnoff()
{
    status = viWrite(viDG1022,(unsigned char*)"OUTP OFF",9,VI_NULL);
    Sleep(2000);
};

void functionGenerator::voltageUnit()
{
	status = viWrite(viDG1022,(unsigned char*)"VOLT:UNIT VPP",14,VI_NULL);
	Sleep(2000);
};

void functionGenerator::setPhase(double phase)
{
	sprintf(commandstring,"PHAS %f",phase);

  	status = viWrite(viDG1022,(unsigned char*)commandstring,sizeof commandstring,VI_NULL);
	Sleep(2000);
};

void functionGenerator::identify()
{
    status=viOpenDefaultRM(&defaultRM);

    status = viFindRsrc(defaultRM,"USB0::0x0400::0x09C4::DG1D182403418::INSTR",&fList, &numInst, desc);

    status = viOpen(defaultRM,desc,VI_NULL,VI_NULL,&viDG1022);
    Sleep(2000);
    status = viWrite(viDG1022,(unsigned char*)"*IDN?\n",6,VI_NULL);
    Sleep(2000);

    status = viRead(viDG1022, (unsigned char*)resultBuffer, 256, &resultCount);
    Sleep(2000);

};
