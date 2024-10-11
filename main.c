#include "lib/Constants.h"
#include "src/menu.c"
#include "src/hello_world.c"
#include "src/geometry.c"



void mouse(int button, int state, int x, int y) {
    printf("button %d state %d x %d y %d\n",button,state,x, y);
   
}
void keyboard(unsigned char key, int x, int y) {
    printf("key %c %d", key, key);
    
    if(option != 1 && (int)key== 27) option = 1;
    if(key == '1') option = 2;
    if(key == '2') option = 3;
    if(key == '3') option = 4;
    if(key == 'q') option = -1;

    glutPostRedisplay();
}


void config_framerate() {
    int x,y;
    //only draw 20 frames/second
    if(T.fr1-T.fr2>=(1000/FRAMERATE)) { 
        T.fr2=T.fr1;   
        glutSwapBuffers(); 
       // glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);             //prevent window scaling
    }

    T.fr1=glutGet(GLUT_ELAPSED_TIME);          //1000 Milliseconds per second
    glutPostRedisplay();
    GLenum errorCode = glGetError();
    if (errorCode != GL_NO_ERROR) {
        printf("OpenGL error: %d\n", errorCode);
    }
    
}

void display() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    config_framerate();

    switch(option) {
        case 1:
            renderMenu();
            break;
        case 2:
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
    glutCreateWindow("Menu Example");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;

}