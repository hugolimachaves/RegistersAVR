#ifndef RegistersAVR_H
#define RegistersAVR_H

#ifndef ARDUINO_H
	#define ARDUINO_H
	#include "Arduino.h"
#endif

#if defined(ATMEGA2560)

	#define _PINA 0x20
	#define _PINB 0x23
	#define _PINC 0x26
	#define _PIND 0x29
	#define _PINE 0x2C
	#define _PINF 0x2F
	#define _PING 0x32
	#define _PINH 0x100

	#define _DDRA 0x21
	#define _DDRB 0x24
	#define _DDRC 0x27
	#define _DDRD 0x2A
	#define _DDRE 0x2D
	#define _DDRF 0x30
	#define _DDRG 0x33
	#define _DDRH 0x101

	#define _PORTA 0x22
	#define _PORTB 0x25
	#define _PORTC 0x28
	#define _PORTD 0x2B
	#define _PORTE 0x2E
	#define _PORTF 0x31
	#define _PORTG 0x34
	#define _PORTH 0x102

	#define SYSOFF_DIRECTION 			_INPUT //Lembrar que errei ao colocar um R0 para o terra. Trabalhar como INPUT
	#define POWER_GOOD_DIRECTION 		_INPUT
	#define CHARGING_DIRECTION 			_INPUT
	#define CE_POWER_DIRECTION          _OUTPUT

	#define SYSOFF_DDR_NUMBER 			DDH1
	#define POWER_GOOD_DDR_NUMBER 		DDH7
	#define CHARGING_DDR_NUMBER 		DDH2
	#define CE_POWER_DDR_NUMBER 		DDH0

	#define SYSOFF_DIRECTION_FAMILY 	_DDRH
	#define POWER_GOOD_DIRECTION_FAMILY _DDRH
	#define CHARGING_DIRECTION_FAMILY 	_DDRH
	#define CE_POWER_DIRECTION_FAMILY 	_DDRH

	#define SYSOFF_INPUT_NUMBER 		PINH1
	#define POWER_GOOD_INPUT_NUMBER 	PINH7
	#define CHARGING_INPUT_NUMBER 		PINH2
	#define CE_POWER_OUTPUT_NUMBER 		PORTH0


	#define SYSOFF_INPUT_FAMILY 		_PINH
	#define POWER_GOOD_INPUT_FAMILY 	_PINH
	#define CHARGING_INPUT_FAMILY 		_PINH
	#define CE_POWER_INPUT_FAMILY 		_PORTH


#endif

#define _INPUT 0
#define _OUTPUT 1


class RegistersAVR
{
	public:

	RegistersAVR();
	virtual ~RegistersAVR();
	static void setOn(uint16_t regAbsolteAddress, uint8_t registerBit);
	static void setOff(uint16_t regAbsolteAddress, uint8_t registerBit);
	static void setIO(uint16_t regAbsolteAddress, uint8_t registerBit, uint8_t direction);
	static bool getInput(uint16_t regAbsolteAddress, uint8_t registerBit);
};

#endif 