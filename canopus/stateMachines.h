#ifndef _STATE_MACHINES_H_
#define _STATE_MACHINES_H_

#include <lcdutils.h>

static int state;
static int lives; 
short redrawScreen;

void play_game(void);
void you_win(void);
void game_over(void);

#endif
