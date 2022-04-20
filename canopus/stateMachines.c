#include <stdbool.h>
#include "stateMachines.h"
#include "led.h"

// State0 is the default game state 
void state0(void){
  /* This will call draw_shapes.c 
     which will move the vehicles */
  draw_moving_shapes();
  /* This will call the listener for the frog */


  
}


// State1 is the win screen with text 
void state1(void){
  // change the background color
  clearScreen(COLOR_GREEN);
  // add the YOU WIN text to the screen

  // add the 'press any button to continue'

  // call listener for the reset win boolean


  
}


// State2 is the game over screen with text
void state2(void){
  // clear the screen

  // add the game over text

  // add press any button to continue text

  // call listener to reset the lives to 3


  
}
