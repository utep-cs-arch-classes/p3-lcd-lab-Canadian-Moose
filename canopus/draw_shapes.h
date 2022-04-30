#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_

#include <lcdutils.h>

//hearts 
int heartColor;
//frog
int frogColor;
int frogColStart;
int frogRowStart;
//lane 1
int truckColor1;
int lane1colStart;
int lane1rowStart;
//lane 3
int truckColor3;
int lane3colStart1;
int lane3rowStart;
//lane 2
int carColor2;
int lane2colStart1;
int lane2colStart2;
int lane2rowStart;

const int wheelh1;
const int wheelw1;
const int wheelh2;
const int wheelw2;
const int wheelColor;

extern u_int background_color;
int newGamePlus;

/* initializes shape positions */
void init_shapes(void);

// safe zones
void safeZones(void);
//roads
void roads(void);
//hearts
void heart1(int colorHeart);
void heart2(int colorHeart);
void heart3(int colorHeart);
//frog
void frog(int colorFrog);
void eraseFrog(void);
// vehicles
void lane1(int colorTruck, int colorWheel);
void lane2(int colorCar, int colorWheel);
void lane3(int colorTruck, int colorWheel);

/* handles erasing and updating all the shapes */
void draw_moving_shapes(int scaler);

#endif // _DRAW_SHAPES_H_
