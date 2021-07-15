#define LED 13
#define TEMPO 100

#include "RegistersAVR.h"

void setup() {
  //pinMode(LED, OUTPUT);
  RegistersAVR::setOutput(0x04,PORTB7);
}

/*
void setOn(int reg, int port)
{
  //_SFR_IO8(0XOFFSET) from: https://stackoverflow.com/questions/63564964/how-do-avr-i-o-macro-definitions-work-to-allow-access-to-registers
  //OFFSET dados pelo datasheet
  _SFR_IO8(reg) |= (1<<port);  //altrando PORTB
}

void setOff(int reg, int port)
{
  _SFR_IO8(reg) &= (1<<port)^0xFF;  //altrando PORTB
}*/

// the loop function runs over and over again forever
void loop() {

  RegistersAVR::setOn(0x05, PORTB7); // utilizano função para alterar PORTB
  delay(TEMPO);
  RegistersAVR::setOff(0x05, PORTB7);
  delay(TEMPO);                       
}
