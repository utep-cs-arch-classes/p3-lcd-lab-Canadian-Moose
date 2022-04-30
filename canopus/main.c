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
    buzzer_init();
    
    //clear screen of previous loads 
    clearScreen(background_color);

    //initialize the screen
    init_shapes();
    
    //begin the timer 
    enableWDTInterrupts();

    // forever 
    while (1){
        switch_interrupt_handler();
        chooseState();
        // CPU off, GIE on
        or_sr(0x18);
    }

}
