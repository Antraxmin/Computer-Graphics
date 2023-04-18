#include <GL/glut.h>
#include <stdlib.h>

void display() {
    glColor3f(1.0, 1.0, 1.0);   // setting white color

    // set coordinate for rectangle
    // glBegin ~ glEnd = input vertex value
    glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(0.25, 0.75, 0.0);
    glEnd();

    glFlush();    // draw sqaure on screen
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);   // setting bgColor black
    glClear(GL_COLOR_BUFFER_BIT);       // clear color buffer
    glMatrixMode(GL_PROJECTION);        // setting projection matrix mode
    glLoadIdentity();           // initialize to unit matrix

    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);     // setting orthogonal projection
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);   // initialize glut lib 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // setting display mode

    glutInitWindowSize(250, 250);   // 250 x 250 size window
    glutInitWindowPosition(100, 100);   // setting window coord = (100, 100)

    glutCreateWindow("1-1. Draw Square");   // create new window
    init();    

    glutDisplayFunc(display);    //   regist display callback func
    glutMainLoop();   // start event processing engine
    return 0;
}