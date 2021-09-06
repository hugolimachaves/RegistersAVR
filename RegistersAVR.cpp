#include <RegistersAVR.h> 

RegistersAVR::RegistersAVR()
{

}

RegistersAVR::~RegistersAVR()
{

}

/**
 * # Coloca em estado logico alto uma porta definida anteriormente como saida.
 * - Primeiro argumento é o endereço absoluto do registrador de PORT no formato PORTX . Temos defines para cada um deles no formato _PORTX
 * - Segundo argumento é a macro default do AVR para as portas no formato PORTXN, onde X é o grupo e N é o numero da porta dentro desse grupo.
*/
static void RegistersAVR::setOn(uint16_t regAbsolteAddress, uint8_t registerBit)
{
	//(*(volatile uint16_t *)( regAbsolteAddress )) |= (1<<registerBit);  
	(*(volatile uint16_t *)( regAbsolteAddress )) = (*(volatile uint16_t *)( regAbsolteAddress )) |  (1<<registerBit);
}


/**
 * # Coloca em estado logico baixo uma porta definida anteriormente como saida.
 * - Primeiro argumento é o endereço absoluto do registrador de PORT no formato PORTX . Temos defines para cada um deles no formato _PORTX
 * - Segundo argumento é a macro default do AVR para as portas no formato PORTXN, onde X é o grupo e N é o numero da porta dentro desse grupo.
*/
static void RegistersAVR::setOff(uint16_t regAbsolteAddress, uint8_t registerBit)
{
	//(*(volatile uint16_t *)( regAbsolteAddress )) &= (1<<registerBit)^0xFF;  
	(*(volatile uint16_t *)( regAbsolteAddress )) = (*(volatile uint16_t *)( regAbsolteAddress )) &  (1<<registerBit)^0xFF;  
}

/**
 * # Define uma porta como entrada ou saida
 * - Primeiro argumento é o endereço absoluto do registrador de direção DDR no formato DDRX . Temos defines para cada um deles no formato _DDRX
 * - Segundo argumento é a macro default do AVR para as portas no formato DDRXN, onde X é o grupo e N é o numero da porta dentro desse grupo.
 * - Terceiro argumento é a direçao da porta definida pelas seguinte macros locais _OUTPUT e _INPUT.
 * @attention As macros locais são sempre seguidas de _ (underscore) no formato _MACRO
*/
static void RegistersAVR::setIO(uint16_t regAbsolteAddress, uint8_t registerBit, uint8_t direction)
{
	if (direction == _INPUT) 
	{
		(*(volatile uint16_t *)( regAbsolteAddress)) = (*(volatile uint16_t *)( regAbsolteAddress)) & (1 << registerBit)^0xFF;

	} 
	else if (direction == _OUTPUT) 
	{
		(*(volatile uint16_t *)( regAbsolteAddress)) = (*(volatile uint16_t *)( regAbsolteAddress)) | (1 << registerBit);  //setando como input
	}
}

/**
 * # Verifica estado de uma porta digital. 
 * - Primeiro argumento é o endereço absoluto do registrador PIN. Temos defines para cada um deles no formato _PINX
 * - Segundo argumento é a macro default do AVR para as portas no formato PINXN.
 * @attention Deve-se definir anteriormente a porta como entrada
*/
static bool RegistersAVR::getInput(uint16_t regAbsolteAddress, uint8_t registerBit) 
{
	return (regAbsolteAddress & 1<<registerBit)>>registerBit;
}