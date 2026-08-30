#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

//Macro
#define set_bit(reg, pin)   (reg |= (1<< pin))
#define clear_bit(reg, pin) (reg &= ~(1<<pin))

int main() {
  DDRB = 0b00000001;//Config pin 8 on Arduino board(PB0) and orther pins(including PB1 or pin 9) as output and input saperately
  PORTB |= (1 << PORTB1);// Enable internal pull-up resistor

  //Main loop
  while (1) {
    if (PINB & (1<<PINB1)){ //Check the signal in pin 9(PB1)
      set_bit(PORTB, PORTB0); //Turn on the LED
    }else{
      clear_bit(PORTB, PORTB0);//Turn off the LED
    }
  }
  return 0;
}