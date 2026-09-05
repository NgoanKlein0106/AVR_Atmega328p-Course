// void setup() {
//   // put your setup code here, to run once:
//   pinMode(8, OUTPUT);
//   pinMode(9, OUTPUT);

// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   digitalWrite(8, !digitalRead(8));
//   digitalWrite(9, !digitalRead(9));
//   delay(500);
// }
//1052 bytes

//delay() -> timer 0;



#include <avr/io.h>
#include <util/delay.h>   //_delay_ms(500) -> for(i=0; i< 500; i++)
#define F_CPU 16000000UL  //DEFUT 1Mhz

#define set_bit(reg, bit_num) (reg |= (1 << bit_num))
#define clear_bit(reg, bit_num) (reg &= ~(1 << bit_num))

int main(void) {
  //Config
  // DDRB |= ((1<<DDB1)|(1<<DDB0)); // set d8, d9 output
  set_bit(DDRB, DDB1);
  set_bit(DDRB, DDB0);

  // PORTB &= ~((1<<PORTB0)|(1<<PORTB1));
  clear_bit(PORTB, PORTB0);
  clear_bit(PORTB, PORTB1);


  while (1) {
    // PORTB |= ((1<<PORTB0)|(1<<PORTB1));
    set_bit(PORTB, PORTB0);
    set_bit(PORTB, PORTB1);
    _delay_ms(500);
    // PORTB &= ~((1<<PORTB0)|(1<<PORTB1));
    clear_bit(PORTB, PORTB0);
    clear_bit(PORTB, PORTB1);
    _delay_ms(500);
  }


  return 0;
}
//180BYTES
