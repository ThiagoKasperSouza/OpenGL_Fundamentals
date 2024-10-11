#ifndef _COMPONENTS_H_
#define _COMPONENTS_H_
#include <GL/glut.h>
#include <math.h>



int option =1;
double g,b = 1.0;
double r = 0.0;
 // cada vertice eh a coord de um ponto
void drawAxis() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    // eixo x - vermelho
    glColor3f(1.0,0.0,0.0);
    glVertex2i(-1,0);
    glVertex2i(1,0);

    // eixo y - verde
    glColor3f(0.0,1.0,0.0);
    glVertex2i(0,-1);
    glVertex2i(0,1);

    glEnd();
}

typedef struct {
    double r;
    double g;
    double b;
} Color;
typedef struct {
    char* name;
    double min_y;
    double max_y;
} Opt;
typedef struct {
    char* title;
    Opt* opts;
} Menu;
#endif