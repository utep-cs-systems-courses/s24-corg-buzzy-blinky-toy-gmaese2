#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_int()
{
  P1DIR |= LEDS;
  switch_state_changed = 1;
}
void led_update()
{
  if (switch_state_changed){
    char ledFlags = 0;
    ledFlags |= switch_state_down ? LED_GREEN : 0;
    ledFlags |= switch_state_down ? 0 : LED_RED;
    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  switch_state_changed = 0;
}

void toggle_on(){
  P1OUT = LED_RED;
  __delay_cycles(500000);
  P1OUT = LED_GREEN;
  __delay_cycled(500000);
}

void toggle_off(){
  P1OUT = !(LED_GREEN);
  __delay_cycles(500000);
  P1OUT = !LED_RED;
  __delay_cycles(500000);
}

void led_dim(){
  for(int i = 0; i < 1000; i++){
    P1OUT = LED_RED;
    __delay_cycles(10000);
    P1OUT = LED_GREEN;
    __delay_cycles(10000);
    P1OUT = !LED_RED;
    __delay_cycles(10000);
    P1OUT = !LED_GREEN;
    __delay_cycles(10000);
  }
}

void led_siren(){
  for(int i = 0; i<20; i++){
    P1OUT = LED_GREEN;
    __delay_cycles(500000);
    P1OUT = !LED_RED;
    __delay_cycles(2500000);
    P1OUT = !LED_GREEN;
    __delay_cycles(500000);
    P1OUT = LED_RED;
    __delay_cycles(2500000);
  }
}
