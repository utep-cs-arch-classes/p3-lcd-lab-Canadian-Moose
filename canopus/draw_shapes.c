#include <msp430.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "stateMachines.h"
#include "buzzer.h"

/* global vars for the shape positions */
//hearts 
int heartColor = COLOR_RED;
//frog
int frogColor = COLOR_DARK_GREEN;
int frogColStart = 58;
int frogRowStart = 132;
//lane 1
int truckColor1 = COLOR_PURPLE;
int lane1colStart = 56;
int lane1rowStart = 102;
//lane 3
int truckColor3 = COLOR_ORANGE;
int lane3colStart1 = 10;
int lane3rowStart = 37;
//lane 2
int carColor2 = COLOR_BLUE;
int lane2colStart1 = 10;
int lane2colStart2 = 58;
int lane2rowStart = 76;

u_int background_color = COLOR_GRAY;

/* global constant variables for wheel sizes/ color */
const int wheelh1 = 5;
const int wheelw1 = 3;
const int wheelh2 = 3;
const int wheelw2 = 5;
const int wheelColor = COLOR_BLACK;

/* initialize the lanes and non-moving-shapes */ 
void init_shapes(void){
  clearScreen(background_color);
  safeZones();
  roads();
  heart1(heartColor);
  heart2(heartColor);
  heart3(heartColor);
  
  frogColStart = 58;
  frogRowStart = 132;
  frog(frogColor);
}

void safeZones(void){
  int startCol = 0;
  int startRow = 128;
  int endCol = 0;
  int endRow = 0;
  int height = 32;
  int width = 128;
  int color = COLOR_PALE_GREEN;

  fillRectangle(startCol, startRow, width, height, color);
  fillRectangle(endCol, endRow, width, height, color);
}

void roads(void){
  int divider1row = 95;
  int divider2row = 63;
  int dividerCol = 0;
  int dividerHeight = 2;
  int width = 128;
  int colorDivider = COLOR_YELLOW;

  fillRectangle(dividerCol, divider2row, width, dividerHeight, colorDivider);
  fillRectangle(dividerCol, divider1row, width, dividerHeight, colorDivider);
}

void heart1(int colorHeart){
  int rowStart = 2;
  int colStart = 107;

  fillRectangle(colStart, rowStart, 2, 2, colorHeart);
  fillRectangle(colStart+3, rowStart, 2, 2, colorHeart);
  fillRectangle(colStart+1, rowStart+1, 3, 2, colorHeart);
  fillRectangle(colStart+2, rowStart+3, 1, 1, colorHeart);
}

void heart2(int colorHeart){
  int rowStart = 2;
  int colStart = 114;

  fillRectangle(colStart, rowStart, 2, 2, colorHeart);
  fillRectangle(colStart+3, rowStart, 2, 2, colorHeart);
  fillRectangle(colStart+1, rowStart+1, 3, 2, colorHeart);
  fillRectangle(colStart+2, rowStart+3, 1, 1, colorHeart);
}

void heart3(int colorHeart){
  int rowStart = 2;
  int colStart = 121;

  fillRectangle(colStart, rowStart, 2, 2, colorHeart);
  fillRectangle(colStart+3, rowStart, 2, 2, colorHeart);
  fillRectangle(colStart+1, rowStart+1, 3, 2, colorHeart);
  fillRectangle(colStart+2, rowStart+3, 1, 1, colorHeart);
}

void frog(int colorFrog){
  int headWidth = 4;
  int headHeight = 2;
  int bodyWidth = 6;
  int bodyHeight = 8;
  int tailWidth = 4;  //height = 1
  int legHeight = 4;

  //body
  fillRectangle(frogColStart+4, frogRowStart, headWidth, headHeight, colorFrog);
  fillRectangle(frogColStart+3, frogRowStart+2, bodyWidth, bodyHeight, colorFrog);
  fillRectangle(frogColStart+4, frogRowStart+10, headWidth, headHeight, colorFrog);
  //legs
  fillRectangle(frogColStart+1, frogRowStart, 1, legHeight, colorFrog);
  fillRectangle(frogColStart+10, frogRowStart, 1, legHeight, colorFrog);
  fillRectangle(frogColStart+1, frogRowStart+8, 1, legHeight, colorFrog);
  fillRectangle(frogColStart+10, frogRowStart+8, 1, legHeight, colorFrog);
  //other leg pixels
  drawPixel(frogColStart+2, frogRowStart+3, colorFrog);
  drawPixel(frogColStart+9, frogRowStart+3, colorFrog);
  drawPixel(frogColStart+2, frogRowStart+8, colorFrog);
  drawPixel(frogColStart+2, frogRowStart+9, colorFrog);
  drawPixel(frogColStart+9, frogRowStart+8, colorFrog);
  drawPixel(frogColStart+9, frogRowStart+9, colorFrog);
  drawPixel(frogColStart+2, frogRowStart+7, colorFrog);
  drawPixel(frogColStart+9, frogRowStart+7, colorFrog);
  //peets
  drawPixel(frogColStart, frogRowStart+11, colorFrog);
  drawPixel(frogColStart+11, frogRowStart+11, colorFrog);
}

void eraseFrog(void){
  //depending on zone, color in old frog
  if (frogRowStart < 32 || frogRowStart > 129){
    frog(COLOR_PALE_GREEN);
  }else{
    frog(background_color);
  }
}

void lane1(int colorTruck, int colorWheel){
  int backHeight = 18;
  int backWidth = 30;
  int cabHeight = 11;
  int cabWidth = 9;
  int connectorHeight = 4; //width 1

  //truck
  fillRectangle(lane1colStart, lane1rowStart, backWidth, backHeight, colorTruck);
  fillRectangle(lane1colStart+31, lane1rowStart+7, cabWidth, cabHeight, colorTruck);
  fillRectangle(lane1colStart+30, lane1rowStart+14, 1, connectorHeight, colorTruck);
  //wheel 1
  fillRectangle(lane1colStart+3, lane1rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane1colStart+2, lane1rowStart+17, wheelw2, wheelh2, colorWheel);
  //wheel 2
  fillRectangle(lane1colStart+10, lane1rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane1colStart+9, lane1rowStart+17, wheelw2, wheelh2, colorWheel);
  //wheel 3
  fillRectangle(lane1colStart+17, lane1rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane1colStart+16, lane1rowStart+17, wheelw2, wheelh2, colorWheel);
  //wheel 4
  fillRectangle(lane1colStart+24, lane1rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane1colStart+23, lane1rowStart+17, wheelw2, wheelh2, colorWheel);
  //wheel 5
  fillRectangle(lane1colStart+34, lane1rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane1colStart+33, lane1rowStart+17, wheelw2, wheelh2, colorWheel);
}

void lane3(int colorTruck, int colorWheel){
  int backHeight = 18;
  int backWidth = 30;
  int cabHeight = 11;
  int cabWidth = 9;
  int connectorHeight = 4; //width 1

  //truck 1
  fillRectangle(lane3colStart1+10, lane3rowStart, backWidth, backHeight, colorTruck);
  fillRectangle(lane3colStart1, lane3rowStart+7, cabWidth, cabHeight, colorTruck);
  fillRectangle(lane3colStart1+9, lane3rowStart+14, 1, connectorHeight, colorTruck);
  //wheel 1
  fillRectangle(lane3colStart1+3, lane3rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane3colStart1+2, lane3rowStart+17, wheelw2, wheelh2, colorWheel);
  //wheel 2
  fillRectangle(lane3colStart1+13, lane3rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane3colStart1+12, lane3rowStart+17, wheelw2, wheelh2, colorWheel);
  //wheel 3
  fillRectangle(lane3colStart1+20, lane3rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane3colStart1+19, lane3rowStart+17, wheelw2, wheelh2, colorWheel);
  //wheel 4
  fillRectangle(lane3colStart1+27, lane3rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane3colStart1+26, lane3rowStart+17, wheelw2, wheelh2, colorWheel);
  //wheel 5
  fillRectangle(lane3colStart1+34, lane3rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane3colStart1+33, lane3rowStart+17, wheelw2, wheelh2, colorWheel);
}

void lane2(int colorCar, int colorWheel){
  int topHeight = 5;
  int topWidth = 16;
  int botHeight = 5;
  int botWidth = 26;

  //car 1
  fillRectangle(lane2colStart1+5, lane2rowStart, topWidth, topHeight, colorCar);
  fillRectangle(lane2colStart1, lane2rowStart+5, botWidth, botHeight, colorCar);
  //wheel 1
  fillRectangle(lane2colStart1+5, lane2rowStart+8, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane2colStart1+4, lane2rowStart+9, wheelw2, wheelh2, colorWheel);
  // wheel 2
  fillRectangle(lane2colStart1+18, lane2rowStart+8, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane2colStart1+17, lane2rowStart+9, wheelw2, wheelh2, colorWheel);

  //car 2
  fillRectangle(lane2colStart2+5, lane2rowStart, topWidth, topHeight, colorCar);
  fillRectangle(lane2colStart2, lane2rowStart+5, botWidth, botHeight, colorCar);
  //wheel 1
  fillRectangle(lane2colStart2+5, lane2rowStart+8, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane2colStart2+4, lane2rowStart+9, wheelw2, wheelh2, colorWheel);
  // wheel 2
  fillRectangle(lane2colStart2+18, lane2rowStart+8, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane2colStart2+17, lane2rowStart+9, wheelw2, wheelh2, colorWheel);
}

void draw_moving_shapes(int scaler){
  lane3(background_color, background_color);
  lane2(background_color, background_color);
  lane1(background_color, background_color);

  //Move Lane 3	
  if (lane3colStart1 <= 0){
    lane3colStart1 = 88;
  }else{
    lane3colStart1-=(15*scaler);
  }
  
  //Move Lane 2
  if (lane2colStart1 >= 88){
    lane2colStart1 = 0;
  }else{
    lane2colStart1+=(7*scaler);
  }
  if (lane2colStart2 >= 88){
    lane2colStart2 = 0;
  }else{
    lane2colStart2+=(7*scaler);
  }
  
  //Move Lane 1
  if (lane1colStart >= 88){
    lane1colStart = 0;
  }else{
    lane1colStart+=(3*scaler);
  }

  lane3(truckColor3, wheelColor);
  lane2(carColor2, wheelColor);
  lane1(truckColor1, wheelColor);
}

void drawWinScreen(void){
  // add the YOU WIN text to the screen
  drawString5x7(5, 32, "You Win!!", COLOR_PURPLE, COLOR_GREEN);
  // arcade style countdown til reset
  char counter[1];
  drawString5x7(32, 64, itoa(countdown,counter,10), COLOR_RED, COLOR_GREEN); 
  // add the 'press any button to continue'
  drawString5x7(5, 97, "Play again?", COLOR_RED, COLOR_GREEN);
  drawString5x7(5, 129, "Press any button to", COLOR_RED, COLOR_GREEN);
  drawString5x7(5, 139, " continue...", COLOR_RED, COLOR_GREEN);
  if (countdown % 2 == 0){
    buzzer_set_period(2000);
  }else{
    buzzer_set_period(0);
  }
}

void drawGameOver(void){
  // add the game over text
  drawString5x7(5, 5, "GAME OVER", COLOR_RED, COLOR_BLACK);
  // arcade style countdown til reset
  char counter[1];
  drawString5x7(32, 64, itoa(countdown,counter,10), COLOR_RED, COLOR_GREEN);
  // add press any button to continue text
  drawString5x7(5, 97, "Play again?", COLOR_WHITE, COLOR_BLACK);
  drawString5x7(5, 129, "Press any button to", COLOR_WHITE, COLOR_BLACK);
  drawString5x7(5, 139, " continue...", COLOR_WHITE, COLOR_BLACK);
}
