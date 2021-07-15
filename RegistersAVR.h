#ifndef RegistersAVR_H
#define RegistersAVR_H

#ifndef ARDUINO_H
	#define ARDUINO_H
	#include "Arduino.h"
#endif

class RegistersAVR
{
	public:

	RegistersAVR();
	virtual ~RegistersAVR();
	static void setOn(int reg, int port);
	static void setOff(int reg, int port);
	static void setOutput(int reg, int port);
};

#endif 