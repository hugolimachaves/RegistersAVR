#include <RegistersAVR.h> 

RegistersAVR::RegistersAVR()
{

}

RegistersAVR::~RegistersAVR()
{

}

static void RegistersAVR::setOn(int reg, int port)
{
	_SFR_IO8(reg) |= (1<<port);  //altrando PORTB	
}

static void RegistersAVR::setOff(int reg, int port)
{
	_SFR_IO8(reg) &= (1<<port)^0xFF;  //altrando PORTB
}

static void RegistersAVR::setOutput(int reg, int port)
{
	_SFR_IO8(reg) |= (1<<port);  //setando como output
}