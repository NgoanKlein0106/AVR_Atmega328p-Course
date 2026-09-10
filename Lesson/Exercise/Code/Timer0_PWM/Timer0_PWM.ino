// void setup() {
//   // put your setup code here, to run once:

// }

// void loop() {
//   // put your main code here, to run repeatedly:

// }


//Basic code
// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include <avr/interrupt.h>
// #include <stdint.h>

// volatile uint32_t my_millis = 0;
// uint32_t time = 0;
// ISR(TIMER0_COMPA_vect) {
//   my_millis++;
// }

// int main(void) {
//   //Config
//   //Timer 0 config
//   TCCR0A |= (1 << WGM01);
//   TCCR0B |= (1 << CS01) | (1 << CS00);
//   OCR0A = 249;
//   TIMSK0 |= (1 << OCIE0A);

//   //Output config
//   PORTB &= ~0X01;
//   DDRB |= 0X01;



//   //Interrupt enable
//   sei();

//   //main loop
//   while (1) {
//     if(my_millis - time >= 500){
//       PINB = 1;
//       time = my_millis;
//     }

//   }
// }



//Safe code
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>

volatile uint32_t my_millis = 0;
uint32_t time = 0;
ISR(TIMER0_COMPA_vect) {
  my_millis++;
}

uint32_t read_time(void){
  cli();
  uint32_t mil;
  mil = my_millis;
  sei();
  return mil;
}

int main(void) {
  //Config
  //Timer 0 config
  TCCR0A |= (1 << WGM01);
  TCCR0B |= (1 << CS01) | (1 << CS00);
  OCR0A = 249;
  TIMSK0 |= (1 << OCIE0A);

  //Output config
  PORTB &= ~0X01;
  DDRB |= 0X01;



  // //Interrupt enable
  // sei();

  //init variable
  uint32_t ms;
  //main loop
  while (1) {
    ms = read_time();

    if(ms - time >= 500){
      PINB = 1;
      time = ms;
    }

  }
}

