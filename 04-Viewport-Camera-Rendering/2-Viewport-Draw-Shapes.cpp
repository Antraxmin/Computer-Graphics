#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float angle = 0.0f;
int width;
int height;

void idleProcess() {
    angle += 0.0001;
    if (angle > 360.0)
        angle = 0.0f;
    glutPostRedisplay();
}

void draw_box(float R, float G, float B) {
    glRotatef(angle, 0, 0, 1);
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    glVertex3f(-0.75, -0.75, 0.0);
    glVertex3f(0.75, -0.75, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(-0.75, 0.75, 0.0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, height / 2, width / 2, height / 2);
    draw_box(1.0f, 1.0f, 1.0f);

    glViewport(width / 2, height / 2, width / 2, height / 2);
    draw_box(1.0f, 0.0f, 0.0f);

    glViewport(0, 0, width / 2, height / 2);
    draw_box(0.0f, 1.0f, 0.0f);

    glViewport(width / 2, 0, width / 2, height / 2);
    draw_box(0.0f, 0.0f, 1.0f);

    glutSwapBuffers();
}

void reshape(int new_w, int new_h) {
    width = new_w;
    height = new_h;

    float WidthFactor = (float)new_w / 250.0;
    float HeightFactor = (float)new_h / 250.0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-5.0 * WidthFactor, 5.0 * WidthFactor, -5.0 * HeightFactor, 5.0 * HeightFactor);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}