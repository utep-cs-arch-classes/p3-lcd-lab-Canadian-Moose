#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"

int main() {
    configureClocks();
    lcd_init();
    //buzzer_init();

    init_shapes();

    or_sr(0x18);          // CPU off, GIE on
}
