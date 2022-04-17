#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_

#include <lcdutils.h>

/*
typedef struct rect_st {
  int rect_row;
  int rect_col;
  int old_rect_row;
  int old_rect_col;
  u_char height;
  u_char width;
} rectangle;

typedef struct cir_st {
  int cir_x;
  int cir_y;
  int old_cir_x;
  int old_cir_y;
  int r;
} circle;
*/
extern u_int background_color;

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
// vehicles
void lane1(int colorTruck, int colorWheel);
void lane2(int colorCar, int colorWheel);
void lane3(int colorTruck, int colorWheel);

/* handles erasing and updating all the shapes */
void draw_moving_shapes(void);

#endif // _DRAW_SHAPES_H_
