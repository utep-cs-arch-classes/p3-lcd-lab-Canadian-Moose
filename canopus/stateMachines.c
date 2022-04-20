#include <stdbool.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "draw_shapes.h"

// State0 is the default game state
void play_game(void){
  /* This will call draw_shapes.c 
     which will move the vehicles */
  draw_moving_shapes();
  /* This will call the listener for the frog */

  
}


// State1 is the win screen with text
void you_win(void){
  // change the background color
  clearScreen(COLOR_GREEN);
  // add the YOU WIN text to the screen
  drawString5x7(5, 5, "You Win!!", COLOR_PURPLE, COLOR_GREEN);
  // add the 'press any button to continue'
  drawString5x7(5, 97, "Play again?", COLOR_RED, COLOR_GREEN);
  drawString5x7(5, 129, "Press any button to continue...", COLOR_RED, COLOR_GREEN);
  // call listener to continue 
  
}


// State2 is the game over screen with text
void game_over(void){
  // clear the screen
  clearScreen(COLOR_BLACK);
  // add the game over text
  drawString5x7(5, 5, "GAME OVER", COLOR_RED, COLOR_BLACK);
  // add press any button to continue text
  drawString5x7(5, 97, "Play again?", COLOR_WHITE, COLOR_BLACK);
  drawString5x7(5, 129, "Press any button to continue...", COLOR_WHITE, COLOR_BLACK);
  // call listener to reset the lives to 3
  
}
