#include <msp430.h>
#include <stdbool.h>
#include "libTimer.h"
#include "stateMachines.h"
#include "draw_shapes.h"

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  const  int second_limit = 100;
  static int second_count = 0;
  
  second_count++;

  if (second_count >= second_limit) {
    //this will check for collisions
    //TODO
    // This will check for the win condition 
    if(frogRowStart <= 32){
      // if the frog is in the end zone, true 
      state = 1;
    }else if(lives == 0){
      // this will be nested once I add collisions 
      state = 2;
    }else{
      state = 0;
      draw_moving_shapes();
    }
    
    switch(state){
    case 0: 
      play_game();
      break;
    case 1:
      you_win();
      break;
    case 2:
      game_over();
      break;
    default:
      play_game();
    } 

    //reset the second counter 
    second_count = 0;
    redrawScreen = 1;
  }
} 

