#include <GL/glut.h>
#include <math.h>

void drawAnimatedSphere(GLfloat radius, GLint slices, GLint stacks) {

    GLUquadric* quadric = gluNewQuadric();

    drawSphere(radius, slices, stacks);

    gluDeleteQuadric(quadric);

}

GLfloat spherePosX = 0.0f;
GLfloat spherePosY = 0.0f;
GLfloat spherePosZ = 0.0f;
GLfloat sphereVelX = 0.1f;
GLfloat sphereVelY = 0.2f;
GLfloat sphereVelZ = 0.3f;
GLfloat sphereRotX = 0.0f;
GLfloat sphereRotY = 0.0f;
GLfloat sphereRotZ = 0.0f;
GLfloat sphereRotSpeed = 1.0f;

void updateSphere() {
    spherePosX += sphereVelX;
    spherePosY += sphereVelY;
    spherePosZ += sphereVelZ;
    sphereRotX += sphereRotSpeed;
    sphereRotY += sphereRotSpeed;
    sphereRotZ += sphereRotSpeed;
}

void animation() {
    glColor3f(0.0, 0.0, 0.5);

  glBegin(GL_POLYGON);
    glVertex2d(-0.5+dx, 0.5);
    glVertex2d(-0.5+dx, -0.5);
    glVertex2d(0.5+dx, -0.5);
    glVertex2d(0.5+dx, 0.5);
  glEnd();
}