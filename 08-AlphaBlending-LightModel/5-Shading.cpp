#include <GL/glut.h>
#include <stdlib.h>

void init(void) {
	// Material Property
	GLfloat mat_ambient[] = { 0.329412, 0.223529, 0.027451 };
	GLfloat mat_diffuse[] = { 0.780392, 0.568627, 0.113725 };
	GLfloat mat_specular[] = { 0.992157, 0.941176, 0.807843 };
	GLfloat mat_shininess[] = { 0.21794872 * 128 };

	// Lighting Property
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


	glLightfv(GL_LIGHT0, GL_POSITION, light_position);		// 조명 위치 설정
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);		// 조명의 Ambient 설정
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);		// 조명의 Diffuse 설정
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);		// 조명의 Specular 설정

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSolidTeapot(1.0);
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		glOrtho(-2.0, -2.0, -2.0 * (GLfloat)h / (GLfloat)w, 2.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else 
		glOrtho(-2.0 * (GLfloat)w / (GLfloat)h, 2.0 * (GLfloat)w/ (GLfloat)h, -2.0, 2.0, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// 메뉴를 선택했을 때 수행되는 함수
void main_menu_select(int value) {
	switch (value) {
	case 1:
		glShadeModel(GL_FLAT);
		glutPostRedisplay();
		break;
	case 2:
		glShadeModel(GL_SMOOTH);
		glutPostRedisplay();
		break;

	case 666:
		exit(0);
		break;
	}
}



int main(int argc, char** argv) 
{
	glutInit(&argc, argv);		
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);		
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);	
	glutCreateWindow("8-5. Shading Example");		
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	// Pop-up 메뉴를 생성하고 세부메뉴의 이름과 메뉴의 번호를 할당
	glutCreateMenu(main_menu_select);
	glutAddMenuEntry("Flat Shading", 1);
	glutAddMenuEntry("Smooth Shading", 2);

	// 마우스의 오른쪽 버튼을 누르면 메뉴가 생성됨
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();		
	return 0;
}
