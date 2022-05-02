#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

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
