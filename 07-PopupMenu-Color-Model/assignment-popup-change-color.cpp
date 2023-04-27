#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

float sun_R = 1.0;
float sun_G = 0.0;
float sum_B = 0.0;

float moon_R = 1.0;
float moon_G = 1.0;
float moon_B = 1.0;

int year = 0;
int day = 0;

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glPushMatrix();
	glColor3f(sun_R, sun_G, sum_B);
	glutSolidSphere(1.0, 20, 16);

	glColor3f(moon_R, moon_G, moon_B);
	glRotatef(year, 0.0, 1.0, 0.0);
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef(day, 0.0, 1.0, 0.0);
	glutSolidSphere(0.2, 10, 8);
	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int new_w, int new_h) {
	glViewport(0, 0, new_w, new_h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)new_w / (GLfloat)new_h, 1.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 7.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0);

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'd':
		day = (day + 10) % 360;
		break;
	case 'D':
		day = (day - 10) % 360;
		break;
	case 'y':
		year = (year - 10) % 360;
		break;
	case 'Y':
		year = (year - 10) % 360;
		break;
	default:
		break;
	}
	glutPostRedisplay();
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
	case 4:
		printf("색상을 빨간색으로 변경합니다. \n");
		sun_R = 1.0; sun_G = 0.0; sum_B = 0.0;
		glutPostRedisplay();
		break;
	case 5:
		printf("색상을 초록색으로 변경합니다. \n");
		sun_R = 0.0; sun_G = 1.0; sum_B = 0.0;
		glutPostRedisplay();
		break;
	case 6:
		printf("색상을 파란색으로 변경합니다. \n");
		moon_R = 0.0; moon_G = 0.0; moon_B = 1.0;
		glutPostRedisplay();
		break;
	case 7:
		printf("색상을 하얀색으로 변경합니다. \n");
		moon_R = 1.0; moon_G = 1.0; moon_B = 1.0;
		glutPostRedisplay();
		break;
	case 8:
		printf("색상을 노란색으로 변경합니다. \n");
		sun_R = 1.0; sun_G = 1.0; sum_B = 0.0;
		glutPostRedisplay();
		break;
	case 99:
		printf("OpenGL 프로그램을 종료합니다\n");
		exit(0);
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("과제 : Pop-up 메뉴로 태양, 달 색상 변경하기");

	init();

	int submenu = glutCreateMenu(popupMenu);
	glutAddMenuEntry("Red", 4);
	glutAddMenuEntry("Yellow", 8);

	int moon_submenu = glutCreateMenu(popupMenu);
	glutAddMenuEntry("white", 7);
	glutAddMenuEntry("Blue", 6);

	glutCreateMenu(popupMenu);
	glutAddSubMenu("Sun", submenu);
	glutAddSubMenu("Moon", moon_submenu);
	glutAddMenuEntry("Exit", 99);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
