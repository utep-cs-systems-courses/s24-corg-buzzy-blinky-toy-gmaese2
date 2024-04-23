#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "LED.h"

void buzzer_init()
{
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void song()
{
  float a = 2200;
  float mC = 650.41;
  float d = 1460.83;
  float mD = 730.42;
  float e = 1640.81;
  float mF = 870.31;
  float g = 1960;
  float mG = 980;

  float note[30] = {mF,0,a,mC,0,0,a,0,mF,d,d,d,0,0,0,0,mF,a,mC,0,a,0,mF,e,0,mD,d};
  for(int i = 0; i<30; i++){
    buzzer_set_period(note[i]);
    __delay_cycles(2500000);
  }
  buzzer_set_period(0);
}


void play_song()
{
  for(int i = 0; i<30;i++){
    if(i%2 == 0){
      buzzer_set_period(2000);
      toggle_on();
    }
    else{
      buzzer_set_period(1000);
      toggle_off();
    }
    __delay_cycles(2500000);
  }
  buzzer_set_period(0);
}
