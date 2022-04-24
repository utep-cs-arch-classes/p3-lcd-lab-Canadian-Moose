#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "switches.h"
#include "stateMachines.h"

int main() {
    configureClocks();
    lcd_init();
    switch_init();
    //buzzer_init();
    
    //clear screen of previous loads 
    clearScreen(background_color);

    //initialize the screen
    init_shapes();
    
    //begin the timer 
    enableWDTInterrupts();

    /* forever check for the state */
    while(1){
	// check for which state to call 
	if(state == 1){
	  you_win();
	}else if(state == 2){
	  game_over();
	}else{
	  //play_game();
		  /* This will listen for the switches to move the frog */
  // Switch 1 : LEFT 
  if (switch1_down){
    // color in old frog
    eraseFrog();
    // move frog left 
    frogColStart-=10;
    // redraw frog 
    frog(frogColor);
  }

  // Switch 2 : UP
  if (switch2_down){
    // color in old frog
    eraseFrog();
    // move frog left 
    frogRowStart-=32;
    // redraw frog 
    frog(frogColor);
  }

  // Switch 3 : DOWN
  if (switch3_down){
    // color in old frog
    eraseFrog();
    // move frog left 
    frogRowStart+=32;
    // redraw frog 
    frog(frogColor);
  }

  // Switch 4 : RIGHT
  if (switch4_down){
    // color in old frog
    eraseFrog();
    // move frog left 
    frogColStart+=10;
    // redraw frog 
    frog(frogColor);
  }
	}
      or_sr(0x18);          // CPU off, GIE on
    }

}
