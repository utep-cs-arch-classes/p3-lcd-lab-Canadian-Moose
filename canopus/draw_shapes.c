#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"

/* global vars for the shape positions */
//frog
int frogColStart = 58;
int frogRowStart = 132;
//lane 1
int lane1colStart = 56;
int lane1rowStart = 102;
//lane 3
int lane3colStart1 = 6;
int lane3colStart2 = 83;
int lane3rowStart = 37;
//lane 2
int lane2colStart1 = 17;
int lane2colStart2 = 86;
int lane2rowStart = 76;

u_int background_color = COLOR_BLUE;

/* global constant variables for wheel sizes/ color */
const int wheelh1 = 5;
const int wheelw1 = 3;
const int wheelh2 = 3;
const int wheelw2 = 5;
const int colorWheel = COLOR_BLACK;

void init_shapes(void){
  safeZones();
  roads();
  heart1();
  heart2();
  heart3();
  frog();
  lane3();
  lane2();
  lane1();
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
  int laneCol = 0;
  int lane1row = 97;
  int lane2row = 65;
  int lane3row = 32;
  int divider1row = 95;
  int divider2row = 63;
  int dividerCol = 0;
  int dividerHeight = 2;
  int height = 32;
  int width = 128;
  int colorRoad = COLOR_GRAY;
  int colorDivider = COLOR_YELLOW;

  fillRectangle(laneCol, lane3row, width, height, colorRoad);
  fillRectangle(laneCol, lane2row, width, height, colorRoad);
  fillRectangle(laneCol, lane1row, width, height, colorRoad);
  fillRectangle(dividerCol, divider2row, width, dividerHeight, colorDivider);
  fillRectangle(dividerCol, divider1row, width, dividerHeight, colorDivider);
}

void heart1(void){
  int rowStart = 2;
  int colStart = 107;
  int color = COLOR_RED;

  fillRectangle(colStart, rowStart, 2, 2, color);
  fillRectangle(colStart+3, rowStart, 2, 2, color);
  fillRectangle(colStart+1, rowStart+1, 3, 2, color);
  fillRectangle(colStart+2, rowStart+3, 1, 1, color);
}

void heart2(void){
  int rowStart = 2;
  int colStart = 114;
  int color = COLOR_RED;

  fillRectangle(colStart, rowStart, 2, 2, color);
  fillRectangle(colStart+3, rowStart, 2, 2, color);
  fillRectangle(colStart+1, rowStart+1, 3, 2, color);
  fillRectangle(colStart+2, rowStart+3, 1, 1, color);
}

void heart3(void){
  int rowStart = 2;
  int colStart = 121;
  int color = COLOR_RED;

  fillRectangle(colStart, rowStart, 2, 2, color);
  fillRectangle(colStart+3, rowStart, 2, 2, color);
  fillRectangle(colStart+1, rowStart+1, 3, 2, color);
  fillRectangle(colStart+2, rowStart+3, 1, 1, color);
}

void frog(void){
  int headWidth = 4;
  int headHeight = 2;
  int bodyWidth = 6;
  int bodyHeight = 8;
  int tailWidth = 4;  //height = 1
  int legHeight = 4;
  int color = COLOR_DARK_GREEN;

  //body
  fillRectangle(frogColStart+4, frogRowStart, headWidth, headHeight, color);
  fillRectangle(frogColStart+3, frogRowStart+2, bodyWidth, bodyHeight, color);
  fillRectangle(frogColStart+4, frogRowStart+10, headWidth, headHeight, color);
  //legs
  fillRectangle(frogColStart+1, frogRowStart, 1, legHeight, color);
  fillRectangle(frogColStart+10, frogRowStart, 1, legHeight, color);
  fillRectangle(frogColStart+1, frogRowStart+8, 1, legHeight, color);
  fillRectangle(frogColStart+10, frogRowStart+8, 1, legHeight, color);
  //other leg pixels
  drawPixel(frogColStart+2, frogRowStart+3, color);
  drawPixel(frogColStart+9, frogRowStart+3, color);
  drawPixel(frogColStart+2, frogRowStart+8, color);
  drawPixel(frogColStart+2, frogRowStart+9, color);
  drawPixel(frogColStart+9, frogRowStart+8, color);
  drawPixel(frogColStart+9, frogRowStart+9, color);
  drawPixel(frogColStart+2, frogRowStart+7, color);
  drawPixel(frogColStart+9, frogRowStart+7, color);
  //peets
  drawPixel(frogColStart, frogRowStart+11, color);
  drawPixel(frogColStart+11, frogRowStart+11, color);
}

void lane1(void){
  int backHeight = 18;
  int backWidth = 30;
  int cabHeight = 11;
  int cabWidth = 9;
  int connectorHeight = 4; //width 1
  int colorTruck = COLOR_PURPLE;

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

void lane3(void){
  int backHeight = 18;
  int backWidth = 30;
  int cabHeight = 11;
  int cabWidth = 9;
  int connectorHeight = 4; //width 1
  int colorTruck = COLOR_ORANGE;

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

  //truck 2
  fillRectangle(lane3colStart2+10, lane3rowStart, backWidth, backHeight, colorTruck);
  fillRectangle(lane3colStart2, lane3rowStart+7, cabWidth, cabHeight, colorTruck);
  fillRectangle(lane3colStart2+9, lane3rowStart+14, 1, connectorHeight, colorTruck);
  //wheel 1
  fillRectangle(lane3colStart2+3, lane3rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane3colStart2+2, lane3rowStart+17, wheelw2, wheelh2, colorWheel);
  //wheel 2
  fillRectangle(lane3colStart2+13, lane3rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane3colStart2+12, lane3rowStart+17, wheelw2, wheelh2, colorWheel);
  //wheel 3
  fillRectangle(lane3colStart2+20, lane3rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane3colStart2+19, lane3rowStart+17, wheelw2, wheelh2, colorWheel);
  //wheel 4
  fillRectangle(lane3colStart2+27, lane3rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane3colStart2+26, lane3rowStart+17, wheelw2, wheelh2, colorWheel);
  //wheel 5
  fillRectangle(lane3colStart2+34, lane3rowStart+16, wheelw1, wheelh1, colorWheel);
  fillRectangle(lane3colStart2+33, lane3rowStart+17, wheelw2, wheelh2, colorWheel);
}

void lane2(void){
  int topHeight = 5;
  int topWidth = 16;
  int botHeight = 5;
  int botWidth = 26;
  int colorCar = COLOR_BLUE;

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
