#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void display() {
    glColor3f(1.0, 1.0, 1.0);

    glShadeModel(GL_SMOOTH);

    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex3f(-0.75, -0.75, 0.0);
    glColor3f(0, 1, 0);
    glVertex3f(0.75, -0.75, 0.0);
    glColor3f(0, 0, 1);
    glVertex3f(0.75, 0.75, 0.0);
    glColor3f(1, 1, 1);
    glVertex3f(-0.75, 0.75, 0.0);
    glEnd();

    glFlush();
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

    gluOrtho2D(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor);    // ¿©µµøÏ √¢ ≈©±‚∏¶ ∫Ø∞Ê«ÿµµ ≈©±‚∞° ∫Ø«œ¡ˆ æ ∞‘ «ÿ¡‹
}

void keyboardProcess(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        printf("숫자 1 키를 입력하였습니다. \n");
        break;
    case '2':
        printf("숫자 2 키를 입력하였습니다. \n");
        break;
    case '5':
        printf("숫자 5 키를 입력하였습니다. \n");
        break;
    case 'Q':
        printf("문자 Q 키를 입력하였습니다. \n");
        break;
    }
}

void mouseProcess(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        printf("왼쪽 마우스 버튼을 클릭하였습니다. \n");
    }
    else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
        printf("가운데 마우스 버튼을 클릭하였습니다.\n");
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        printf("오른쪽 마우스 버튼을 클릭하였습니다.\n");
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        printf("왼쪽 마우스 버튼을 똈습니다. \n");
    }
    else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) {
        printf("가운데 마우스 버튼을 똈습니다.\n");
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        printf("오른쪽 마우스 버튼을 똈습니다. \n");
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("02 Reshape Callback");
    init();

    glutKeyboardFunc(keyboardProcess);
    glutMouseFunc(mouseProcess);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}