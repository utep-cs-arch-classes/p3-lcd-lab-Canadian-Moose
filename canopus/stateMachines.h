#ifndef _STATE_MACHINES_H_
#define _STATE_MACHINES_H_

#include <lcdutils.h>

int state;
int lives; 
int newGamePlus;
int countdownBool;
int countdown;

void chooseState(void);
void play_game(void);
void you_win(void);
void game_over(void);

#endif
