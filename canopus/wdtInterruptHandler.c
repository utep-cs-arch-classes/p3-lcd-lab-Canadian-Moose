#include <msp430.h>
#include <stdbool.h>
#include "libTimer.h"
#include "stateMachines.h"

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

  second_count++;

  if (second_count >= second_limit) {
    //this will check for collisions
    //TODO
    // This will check for the win condition 
    if(frogRowStart <= 32){
      // if the frog is in the end zone, true 
      endZone = true;
    }

    /* This will call the correct state 
    if (endZone == true){
      // Win state if in end zone 
      //you_win();
    }else if (lives == 0){
      // You lose state if 0 lives 
      game_over();
    }else{
      // game state 
      play_game();
    } */
    
    play_game();

    //reset the second counter 
    second_count = 0;
  }
} 

