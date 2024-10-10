#include "lib/Constants.h"
#include "src/menu.c"
#include "src/hello_world.c"
#include "src/geometry.c"



void mouse(int button, int state, int x, int y) {
    printf("button %d state %d x %d y %d\n",button,state,x, y);
    if(button == 0 && state == 0 && option ==1) {
        if(y < 170 && y > 120) option = 2;
        if(y < 200 && y > 170) option = 3;
        if(y < 240 && y > 200) option = 4;
        if(y > 240) option = -1;
    }
   
    glutPostRedisplay();
   
}
void keyboard(unsigned char key, int x, int y) {
    
    if(option != 1 && (int)key== 27) option = 1;
    glutPostRedisplay();
}

void display() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLenum errorCode = glGetError();

    if (errorCode != GL_NO_ERROR) {

        printf("OpenGL error: %d\n", errorCode);

    }
    
    switch(option) {
        case 1:
            renderMenu();
            break;
        case 2:
            printf("entra no case\n");
            hello_world();
            break;
        case 3:
            geometry();
            break;
        default:
            exit(0);
            break;
    }
   
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(X_POS, Y_POS);

    glutCreateWindow("Menu Example");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;

}