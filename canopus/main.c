#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "switches.h"
#include "stateMachines.h"

extern int state;
extern int frogColStart;
extern int frogRowStart;
extern int frogColor;

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

    // forever check for the state 
    while(1){
      if(redrawScreen){
	redrawScreen = 0;
	// check for which state to call 
	if(state == 1){
	  you_win();
	}else if(state == 2){
	  game_over();
	}else{
	  play_game();
	}
      }
      or_sr(0x18);          // CPU off, GIE on
    }
}
