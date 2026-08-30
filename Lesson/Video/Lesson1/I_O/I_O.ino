// void setup() {
//   // put your setup code here, to run once:
//   pinMode(8, OUTPUT);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   digitalWrite(8, HIGH);
//   delay(500);
//   digitalWrite(8, LOW);
//   delay(500);
// }


#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

#define set_bit(reg, bit_num) (reg |= (1<<bit_num))
#define clear_bit(reg, bit_num) (reg &= ~(1<<bit_num))

int main(void){
//Init
  set_bit(DDRB, PORTB0);
  set_bit(DDRB, PORTB1);
  
  PORTB= 0b00000000;

//Main loop
  while(1){
    set_bit(PORTB, PORTB0);
    _delay_ms(500);
    set_bit(PORTB, PORTB1);
    _delay_ms(500);
    clear_bit(PORTB, PORTB1);
    _delay_ms(500);
    clear_bit(PORTB, PORTB0);
    _delay_ms(500);

  }
  return 0;
}

// #include <avr/io.h>
// #include <util/delay.h>
// #define F_CPU 16000000UL
// int main(void) {
//   //init
//   DDRB = 0b00000001;//d8 output
//   DDRB = 0b00000010;//d9 output, d8 thành input
//   PORTB = 0b00000000;
//   //main loop
//   while (1) {
//     PORTB = 0b00000001;
//     _delay_ms(500);
//     PORTB = 0b00000010;
//     _delay_ms(500);
//     PORTB = 0b00000000;
//     _delay_ms(500);
//     PORTB = 0b00000000;
//     _delay_ms(500);
//   }
//   return 0;
// }