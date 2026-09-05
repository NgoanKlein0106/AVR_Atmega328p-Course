// void setup() {
//   // put your setup code here, to run once:

// }

// void loop() {
//   // put your main code here, to run repeatedly:

// }
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(INT0_vect){
  PIND = (1<<PIND4);
}

void set_8bit( unsigned char data){
  PORTD &= 0b00001111;
  PORTB &= 0b11110000;
  PORTD |= (data<<4);
  PORTB |= (data>>4);
}

int main() {
  //Config
  // DDRD &= ~(1 << PORTD2);  //set PD2 là input
  // PORTD |= (1 << PORTD2);  //internal input
  // PORTD &= ~((1 << PORTD4) | (1 << PORTD5));
  // DDRD |= ((1 << PORTD4) | (1 << PORTD5));

  // EICRA = 0B00000001;
  // EIMSK = 0B00000001;

  // SREG = 0B10000000;

  // while (1) {  //BAT TAT DEN PD4 CHU KI 1S
  //   PORTD |= (1 << PORTD5);
  //   _delay_ms(500);
  //   PORTD &= ~(1 << PORTD5);
  //   _delay_ms(500);
  // }
  // if (!(PIND & (1 << PORTD2))) {
  //   //0b0000 0000
  //   //0b0000 0100
  //   //0b0000 0000
  //   // True False
  //   // 0: False
  //   // != 0: True
  //   PORTD |= (1 << PORTD4);
  // } else {
  //   PORTD &= ~(1 << PORTD4);
  // }

  PORTD &= 0b00001111;
  PORTB &= 0b11110000;
  DDRD |= (0B11110000);
  DDRB |= (0B00001111);

while(1){
  set_8bit(0B11110000);
  _delay_ms(500);
  set_8bit(0B00001111);
  _delay_ms(500);
  set_8bit(0B11001100);
  _delay_ms(500);
  set_8bit(0B11000011);
  _delay_ms(500);
}
  return 0;
}