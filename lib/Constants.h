#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include "Components.h"

#define FRAMERATE 20
#define RESOLUTION 1  //0=160x120 1=360x240 4=640x480
#define PIXEL_SCALE 4/RESOLUTION 
#define WIDTH 160
#define HEIGHT 120
#define NUM_OPTS 4
#define WINDOW_TITLE "OpenGL Fundamentals"
#define WINDOW_WIDTH WIDTH*PIXEL_SCALE
#define WINDOW_HEIGHT HEIGHT*PIXEL_SCALE

typedef struct 
{
 int fr1,fr2;           //frame 1 frame 2, to create constant frame rate
}time; time T;

/* Theme Colors  - RGB */
Color title_color = {.r=1.0, .g=1.0, .b=1.0};
Color opts_color = {.r=0.5, .g=0.5, .b=0.5};
/* Theme Colors */
#endif