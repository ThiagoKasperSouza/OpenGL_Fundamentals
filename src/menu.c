#include <GL/glut.h>



void renderMenu() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    
    Menu *m = malloc(sizeof(Menu));


    // Renderiza titulo
    m->title = "OpenGL Fundamentals - Menu";
    glColor3f(title_color.r, title_color.g, title_color.b);
    glRasterPos2f(-0.6, 0.8); // x, y - sinal como plano cartesiano, maximo 1
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,m->title);

    // Renderiza menu options
    m->opts = (Opt[NUM_OPTS]) {
        { .name="1 - Hello World", .min_y=-0.4, .max_y=0.3 },
        { .name="2 - Geometry", .min_y=-0.4, .max_y=0.1 },
        { .name="3 - Animation", .min_y=-0.4, .max_y=-0.1 },
        { .name="q - Quit window.", .min_y=-0.4, .max_y=-0.3 },
    };

    glColor3f(opts_color.r, opts_color.g, opts_color.b);
    for(uint i=0; i <NUM_OPTS; i++) {
        glRasterPos2f(m->opts[i].min_y, m->opts[i].max_y);
        glutBitmapString(GLUT_BITMAP_HELVETICA_12,m->opts[i].name );
    }

    glFlush();


}
