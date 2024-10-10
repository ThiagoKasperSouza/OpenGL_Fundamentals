#include <GL/glut.h>
#include <math.h>

void drawSphere(GLfloat radius, GLint slices, GLint stacks) {

    GLfloat theta, phi;
    GLint i, j;

    for (i = 0; i < stacks; i++) {
        theta = i * M_PI / stacks;
        glBegin(GL_QUAD_STRIP);

        for (j = 0; j <= slices; j++) {
            phi = j * 2 * M_PI / slices;
            glVertex3f(radius * sin(theta) * cos(phi), radius * sin(theta) * sin(phi), radius * cos(theta));
            glVertex3f(radius * sin((theta + M_PI / stacks)) * cos(phi), radius * sin((theta + M_PI / stacks)) * sin(phi), radius * cos((theta + M_PI / stacks)));
        }
        glEnd();
    }
}
void geometry() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up the sphere's properties
    GLfloat radius = 1.0;
    GLint slices = 9999;
    GLint stacks = 8;

    // Draw the sphere
    drawSphere(radius, slices, stacks);

    glFlush();
}
