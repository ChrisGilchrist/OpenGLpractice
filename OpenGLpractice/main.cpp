#include <GL/glut.h>
#include <iostream> 
using namespace std;

void render(void);
void reshape(int, int);
void timer(int);

void keyboard(unsigned char c, int x, int y);

void mouse(int button, int state, int x, int y);

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Simple GLUT Application");

	glutDisplayFunc(render);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	init();

	glutMainLoop();
}

// Angle of rotation for the cube
float angle = 0.0;


// Handles the keyboard press events
void keyboard(unsigned char c, int x, int y) {

	switch (c) {
	// 'escape' has been pressed by user
	case 27:
		cout << "Escape was clicked" << '\n';
		exit(0);
		break;

	// 'w' has been clicked by user
	case 119:
		cout << "w was clicked" << '\n';
		break;

	// 'a' has been clicked by user
	case 97:
		cout << "a was clicked" << '\n';
		break;

	// 's' has been clicked by user
	case 115:
		cout << "s was clicked" << '\n';
		break;

	// 'd' has been clicked by user
	case 100:
		cout << "d was clicked" << '\n';
		break;
	}
}

// Handles the mouse movement / click events
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_RIGHT_BUTTON) {
		exit(0);
	}
}

// Renders objects into the window created on startup
void render(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -8.0);
	glRotatef(angle, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);

	glBegin(GL_QUADS);

	// Front
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);

	// Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, 1.0, -1.0);

	// Right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(1.0, 1.0, -1.0);

	// Left
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);

	// Top
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);

	// Bottom
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);

	glEnd();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 2.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int) {

	glutPostRedisplay();
	glutTimerFunc(1000/60, timer, 0);

	angle += 0.8 * 4;
	// Stop the angle going past 360 - resets it back to 0
	if (angle > 360.0) {
		angle = angle - 360.0;
	}
}
