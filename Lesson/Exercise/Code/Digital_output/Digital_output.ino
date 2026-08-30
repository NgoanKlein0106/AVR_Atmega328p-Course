#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
//Macro
#define set_bit(reg, pin)   (reg |= (1<< pin))
#define clear_bit(reg, pin) (reg &= ~(1<<pin))
int main(){
  //Initialize
  DDRB = 0X01;
  PORTB = 0X00;

  //Main loop - This will affect other pins
  // while(1){
  //   PORTB = (1<<0);//On bit by bit
  //   // PORTB = 0XFF; //On full port
  //   _delay_ms(500);
  //   PORTB = !(1<<0);//Off bit by bit
  //   // PORTB = 0X00; //Off full port
  //   _delay_ms(500);
  // }
  //Main loop - This wont affect other pins
  //  while(1){
  //   PORTB |= (1 << PORTB0);
  //   _delay_ms(500);
  //   PORTB &= ~(1 << PORTB0);
  //   _delay_ms(500);
  // }
  //Main loop - Using macro
  while(1){
    // PORTB |= (1 << PORTB0);
    set_bit(PORTB, 0);
    _delay_ms(500);
    // PORTB &= ~(1 << PORTB0);
    clear_bit(PORTB, 0);
    _delay_ms(500);
  }

  return 0;
}
