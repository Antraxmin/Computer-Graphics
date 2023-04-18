#include <GL/glut.h>
#include <stdlib.h>

GLfloat Red = 0.0f;
GLfloat Green = 0.0f;
GLfloat Blue = 0.0f;

GLint index = 0;
GLfloat Delta = 0.0f;
GLfloat angle = 0.0f;
unsigned char PALETTE[9][3] = {
    {255, 255, 255},    //WHITE
    {0, 255, 255},        //CYAN
    {255, 0, 255},        //PURPLE
    {192, 192, 192},    //LIGHT GRAY
    {128, 128, 128},    //DARK GRAY
    {128, 0, 0},        //DARK RED
    {0, 128, 0},        //DARK GREEN
    {0, 0, 128},        //DARK BLUE
    {0, 0, 0}            //BLACK
};

void timerProcess(int value) {
    if (Delta < 2.0f) {
        Delta = Delta + 0.01f;
        if (++index >= 8) {
            index = 0;
            glClear(GL_COLOR_BUFFER_BIT);
        }
    }
    else {
        Delta = 0.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(200, timerProcess, 1);
}

void idleProcess() {
    angle += 0.0001;
    if (angle > 360.0)
        angle = 0.0f;

    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glRotatef(angle, 0, 0, 1);

    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);
    glVertex3f(-0.75, -0.75, 0.0);
    glVertex3f(0.75, -0.75, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(-0.75, 0.75, 0.0);
    glEnd();

    glFlush();
    glutSwapBuffers();
}
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void reshape(int new_w, int new_h) {
    glViewport(0, 0, new_w, new_h);
    float WidthFactor = (float)new_w / 250.0;
    float HeightFactor = (float)new_h / 250.0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("2-5. Idle Callback");
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idleProcess);
    glutMainLoop();

    return 0;
}
