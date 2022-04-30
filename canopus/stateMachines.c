#include <msp430.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachines.h"
#include "switches.h"
#include "draw_shapes.h"
#include "buzzer.h"

int state;
int lives = 3; 
int countdown = 11;
int newGamePlus = 1;
int countdownBool = 0;

void chooseState(void){
  switch(state){
    case 0: 
      play_game();
      break;
    case 1:
      switch_interrupt_handler();
      you_win();
      break;
    case 2:
      switch_interrupt_handler();
      game_over();
      break;
    default:
      play_game();
    }
}

void newGame(void){
  lives = 3;
  countdown = 11;
  init_shapes();
  switch1_down = 0;
  state = 0;
}

// State0 is the default game state
void play_game(void){
  /* This will listen for the switches to move the frog */
  // Switch 1 : LEFT 
  if (switch1_down){
    // make a beep
    buzzer_set_period(1000);
    // color in old frog
    eraseFrog();
    // move frog left 
    frogColStart-=10;
    // redraw frog 
    frog(frogColor);
    // turn switch back to off 
    switch1_down = 0;
  }

  // Switch 2 : UP
  if (switch2_down){
    // make a beep
    buzzer_set_period(1000);
    // color in old frog
    eraseFrog();
    // move frog left 
    frogRowStart-=32;
    // redraw frog 
    frog(frogColor);
    // turn switch back to off 
    switch2_down = 0; 
  }

  // Switch 3 : DOWN
  if (switch3_down){
    // make a beep
    buzzer_set_period(1000);
    // color in old frog
    eraseFrog();
    // move frog left 
    frogRowStart+=32;
    // redraw frog 
    frog(frogColor);
    // turn switch back to off 
    switch3_down = 0;
  }

  // Switch 4 : RIGHT
  if (switch4_down){
    // make a beep
    buzzer_set_period(1000);
    // color in old frog
    eraseFrog();
    // move frog left 
    frogColStart+=10;
    // redraw frog 
    frog(frogColor);
    // turn switch back to off 
    switch4_down = 0;
  }
  
}


// State1 is the win screen with text
void you_win(void){
  // add the YOU WIN text to the screen
  drawString5x7(5, 32, "You Win!!", COLOR_PURPLE, COLOR_GREEN);
  // arcade style countdown til reset
  char counter[1];
  drawString5x7(32, 64, itoa(countdown,counter,10), COLOR_RED, COLOR_GREEN); 
  // add the 'press any button to continue'
  drawString5x7(5, 97, "Play again?", COLOR_RED, COLOR_GREEN);
  drawString5x7(5, 129, "Press any button to", COLOR_RED, COLOR_GREEN);
  drawString5x7(5, 139, " continue...", COLOR_RED, COLOR_GREEN);
  // listen to continue 
  if (switch1_down || switch2_down || switch3_down || switch4_down || countdown <= 0){
    newGamePlus++;
    newGame();
  }
  // increment counter
  if (countdownBool){
    countdown--;
    countdownBool = 0;
  }
}


// State2 is the game over screen with text
void game_over(void){
  // death buzzer
  buzzer_set_period(10000);
  // add the game over text
  drawString5x7(5, 5, "GAME OVER", COLOR_RED, COLOR_BLACK);
  // arcade style countdown til reset
  char counter[1];
  drawString5x7(32, 64, itoa(countdown,counter,10), COLOR_RED, COLOR_GREEN);
  // add press any button to continue text
  drawString5x7(5, 97, "Play again?", COLOR_WHITE, COLOR_BLACK);
  drawString5x7(5, 129, "Press any button to", COLOR_WHITE, COLOR_BLACK);
  drawString5x7(5, 139, " continue...", COLOR_WHITE, COLOR_BLACK);
  // call listener to reset the lives to 3
  if (switch1_down || switch2_down || switch3_down || switch4_down || countdown <= 0){
    buzzer_set_period(0);
    newGame();
  }
  // increment counter 
  if (countdownBool){
    countdown--;
    countdownBool = 0;
  }
}
