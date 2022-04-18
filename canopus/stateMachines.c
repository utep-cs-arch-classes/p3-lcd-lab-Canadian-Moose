#include "stateMachines.h"
#include "led.h"

// State0 (button pushed) calls custom function
// will count to 100 then call the function 
void fastCounter(void)
{
  static int count = 0;
  static int blinkCount = 0;

  count++;
  // every 2/5ths of a second 
  if (count >= 100) {
    // call custom function (C or Assembly)
    blinkPattern(blinkCount);
    // increment blink counter 
    blinkCount++;
    // tell led.c the led changed
    led_changed = 1;
    led_update();
    // reset counter to 0
    count = 0;
  }
  // reset blinkCount to 0 if it reaches 25 (end of pattern)
  if (blinkCount > 25){
    blinkCount = 0;
  }
}

// State1 (button not pushed) executes code once per second
// The light will turn on/off every second 
void secondCounter (void)
{
  // number of ticks per second 
  const  int secondLimit = 250;
  static int secondCount = 0;

  // measure a second
  secondCount ++;
  // once each second 
  if (secondCount >= secondLimit) {
    // flip the green led 
    green_on = 1 - green_on;
    // update led.c 
    led_changed = 1;
    led_update();
    // reset second counter 
    secondCount = 0;
  }
}
