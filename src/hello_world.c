#include <GL/glut.h>

void hello_world() {
    printf("ta aqui");
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.6,0.5);
    glColor3f(0,1,0); // green

    glutBitmapString(GLUT_BITMAP_HELVETICA_18, "Hello, World!");
    glFlush();
}