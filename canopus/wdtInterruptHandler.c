#include <msp430.h>
#include <stdbool.h>
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachines.h"
#include "draw_shapes.h"
#include "buzzer.h"

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  const  int second_limit = 250;
  static int second_count = 0;
  
  second_count++;

  if (second_count >= second_limit) {
    // This will check for the win condition 
    if(frogRowStart <= 32){
      // prep screen for win state
      clearScreen(COLOR_GREEN);
      // change state
      state = 1;
    }else if(lives == 0){
      // this will be nested once I add collisions
      // TODO
      // prep screen for lose state 
      clearScreen(COLOR_BLACK);
      state = 2;
    }else{
      // default play game state 
      state = 0;
      draw_moving_shapes(newGamePlus);
    }

    buzzer_set_period(0);

    //reset the second counter 
    second_count = 0;
  
    // call state machine to choose the state 
    chooseState();
  }
  
} 

