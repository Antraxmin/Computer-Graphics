#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.0, 0.0, 0.0);
	glFlush();
}

void popupMenu(int value) {
	switch (value) {
	case 1:
		glutSetWindowTitle("첫 번째 메뉴");
		printf("첫 번째 메뉴를 선택하였습니다. \n");
		break;
	case 2:
		glutSetWindowTitle("두 번째 메뉴");
		printf("두 번째 메뉴를 선택하였습니다. \n");
		break;
	case 3:
		glutSetWindowTitle("세 번째 메뉴");
		printf("세 번째 메뉴를 선택하였습니다. \n");
		break;
	case 99:
		printf("OpenGL 프로그램을 종료합니다\n");
		exit(0);
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("7-1. Pop-up Menu");

	glutCreateMenu(popupMenu);
	glutAddMenuEntry("First", 1);
	glutAddMenuEntry("Second", 2);
	glutAddMenuEntry("Third", 3);
	glutAddMenuEntry("Exit", 99);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
