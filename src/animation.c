
void animation(GLfloat xRotated, GLfloat yRotated, GLfloat zRotated) {
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

   

    glTranslatef(0.0,0.0,-5.0);
    glColor3f(0.5,0.5,1);

    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(xRotated,1.0,0.0,1.0);

    glScalef(1.0,1.0,1.0);
    glutWireSphere(1,20,20);
    glFlush();
}

