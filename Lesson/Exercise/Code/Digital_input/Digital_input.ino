#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL


int main() {
  DDRB = 0b00000001;//Config pin 8 on Arduino board(PB0) and pin 9 (PB1) as output and input saperately
  PORTB |= (1 << PORTB1);// Enable internal pull-up resistor

  //Main loop
  while (1) {
    if (PINB & (1<<PINB1)){
      PORTB |= (1 << PORTB0);
    }else{
      PORTB &= ~(1 << PORTB0);
    }
  }
  return 0;
}