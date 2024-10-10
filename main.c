#include <stdio.h>
#include <string.h>
#include <GL/glut.h>

#define WIDTH 400
#define HEIGHT 400
#define X_POS  640
#define Y_POS 360
#define NUM_OPTS 4

void hello_world() {
    printf("entrou aqui no hello");
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0, 0.0, 0.0); // Red color
    glRasterPos2i(10, 20);
    const char* str = "Hello, World!";
    while (*str) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *str);
        str++;
    }

    glFlush();
}

void renderMenu() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

    Menu *m = malloc(sizeof(Menu));
    m->title = "OpenGL Fundamentals";

    // Render menu title
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-0.5, 0.8); // x, y - sinal como plano cartesiano, maximo 1
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,m->title);

    m->opts = (Opt[NUM_OPTS]) {
        { .name="teste", .min_y=-0.4, .max_y=0.3 },
        { .name="teste2", .min_y=-0.4, .max_y=0.1 },
        { .name="teste3", .min_y=-0.4, .max_y=-0.1 },
        { .name="teste4", .min_y=-0.4, .max_y=-0.3 },
    };

    // Render menu options
    glColor3f(0.5, 0.5, 0.5);
    for(uint i=0; i <4; i++) {
        glRasterPos2f(m->opts[i].min_y, m->opts[i].max_y);
        glutBitmapString(GLUT_BITMAP_HELVETICA_12,m->opts[i].name );
    }

    

    glFlush();
}

void mouse(int button, int state, int x, int y) {
    printf("button %d state %d x %d y %d\n",button,state,x, y);
    if(y < 152 && y > 125) {
        printf("entrou no if");
        hello_world();
    }
   
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(X_POS, Y_POS);

    glutCreateWindow("Menu Example");
    glutDisplayFunc(renderMenu);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;

}