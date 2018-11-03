/*
 * ATtiny timer with TM1637 display
 * Tauno Erik
 * 18.02.2018
 * 
 */
 
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "tm1637.c" 


int main(void)
{
  
  uint8_t    i = 0; // Display 1 num right to left
  uint8_t   ii = 0; // Display 2 num right to left
  uint8_t  iii = 0; // Display 3 num right to left
  uint8_t iiii = 0; // Display 4 num right to left

  PORTB |= (1 << PB4); // enable start/stop button

  TM1637_init(); 

  while (1)
  {
    
  int BUTTON = PINB;
  
  if(!(BUTTON&0b00010000)){
    /*When Button is ON */
      
    // Display 1 num right to left
    TM1637_display_digit(TM1637_SET_ADR_03H,i % 0b00001010);
      
    // Display 2 num right to left
    if(i > 9 && ii==0){
      ii = i-9;
      TM1637_display_digit(TM1637_SET_ADR_02H, ii % 0b00001010);
      i = 0;
    }else if(i > 9 && ii > 0){
      ii++;
      TM1637_display_digit(TM1637_SET_ADR_02H, ii % 0b00001010);
      i = 0;
    }
      
    // Display 3 num right to left
    if(ii > 9 && iii==0){
      iii = ii-9;
      TM1637_display_digit(TM1637_SET_ADR_01H, iii % 0b00001010);
      ii = 0;
    }else if(ii > 9 && iii > 0){
      iii++;
      TM1637_display_digit(TM1637_SET_ADR_01H, iii % 0b00001010);
      ii = 0;
    }
      
    // Display 1 num right to left
    if(iii > 9 && iiii==0){
      iiii = iii-9;
      TM1637_display_digit(TM1637_SET_ADR_00H, iiii % 0b00001010);
      ii = 0;
    }else if(iii > 9 && iiii > 0){    
      TM1637_display_digit(TM1637_SET_ADR_00H, iiii % 0b00001010);
      iiii++;
      iii = 0;
    }

    _delay_ms(90);//
    i++;
    
  }else{
  /*When Button is OFF */ 
  }
    
  
  }//while loop end
}//main end

