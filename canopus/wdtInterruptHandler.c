#include <msp430.h>
#include <stdbool.h>
#include "libTimer.h"
#include "draw_shapes.h"
#include "stateMachines.h"

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  const  u_int second_limit = 250;
  static u_int second_count = 0;
  static int lives = 3;
  static bool endZone = false; 

  second_count++;

  if (second_count >= second_limit) {
    //this will check for collisions or win
    //TODO
    if(frogRowStart >= 32){
      endZone = true;
    }

    // This will call the correct state 
    if (endZone == true){
      state1();
    }else if (lives == 0){
      state2();
    }else{
      state0();
    }

    //reset the second counter 
    second_count = 0;
  }
} 

