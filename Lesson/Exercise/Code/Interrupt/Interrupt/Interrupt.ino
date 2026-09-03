// void setup() {
//   // put your setup code here, to run once:
//   pinMode(1, INPUT_PULLUP);
//   pinMode(8, OUTPUT);
//   pinMode(9, OUTPUT);

//   attachInterrupt(0, toggle, FALLING);

// }

// void toggle(){
//   digitalWrite(8, !digitalRead(8));
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   digitalWrite(9, !digitalRead(9));
//   delay(500);
// }
// //1310 bytes



#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL

#define set_bit(reg, bit_num) (reg |= (1 << bit_num))
#define clear_bit(reg, bit_num) (reg &= ~(1<< bit_num))

ISR(INT0_vect){
  PINB = (1<<PORTB1);
}

int main(void) {
  //Config output
  DDRB |= ((1<<PORTB0) | (1<<PORTB1));
  DDRD |= 0X00;
  PORTB &= ~(0X03);
  PORTD |= 0X0C;
  //Config interrupt
  EICRA |= ((1<<ISC01) | (1<<ISC00)); //Detect RISING edge
  EIMSK |= (1<<INT0); //Allow ISR on INT0
  
  SREG |= (0X80); //ENABLE GLOBAL INTERRUPT

  while (1) {
    set_bit(PORTB, PORTB0);
    _delay_ms(500);
    clear_bit(PORTB, PORTB0);
    _delay_ms(500);
  }
  return 0;
}