
/*
    Usa angulo em rad, que é PI/180
    Então pra 360, tem que fazer um loop pra cada fatia,
    criando assim uma literal varredura do angulo
    hip é o raio, X e Y É oq vai ser usado
    cos = adj(X)/hip -> adj(X) = cos . hip
    sen = op(Y)/hip -> op(Y) = sen . hip

*/
void drawCircle(double radius) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,WINDOW_WIDTH,0,WINDOW_HEIGHT); // origem 0,0
    glBegin(GL_POLYGON);
    float theta;

    for(uint i=0;i<360; i++) {
        theta = i * M_PI /180;
        // PRA CALCULAR A FATIA, É COS(THETA) EM X E SEN(THETA) EM Y
        double x = cos(theta)*radius;
        double y = sin(theta)*radius;
        glColor3f(0.5,0.5,1);
       // printf("angulo gerado - X %.2f, Y %.2f\n", x,y);
        glVertex2f(80+WINDOW_WIDTH/2+x,80+WINDOW_HEIGHT/2+y);
     
    }
    glEnd();
}
void geometry() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawAxis();

    // Draw circle
   drawCircle(WINDOW_WIDTH/8);

    glFlush();
}
