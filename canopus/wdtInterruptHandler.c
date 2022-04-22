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
  const  int second_limit = 250;
  static int second_count = 0;
  static int lives = 3;
  static bool endZone = false;
  extern int frogRowStart;
  extern int state; 

  second_count++;

  if (second_count >= second_limit) {
    //this will check for collisions
    //TODO
    // This will check for the win condition 
    if(frogRowStart <= 32){
      // if the frog is in the end zone, true 
      endZone = true;
    }

    /* This will call the correct state */
    if (endZone == true){
      // Win state if in end zone 
      state = 1;
    }else if (lives == 0){
      // You lose state if 0 lives 
      state = 2;
    }else{
      // game state
      state = 0;
      draw_moving_shapes();
    }

    //reset the second counter 
    second_count = 0;
    redrawScreen = 1;
  }
} 

