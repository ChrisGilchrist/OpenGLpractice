#include <GL/glut.h>

void render(void);

void keyboard(unsigned char c, int x, int y);

void mouse(int button, int state, int x, int y);

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Simple GLUT Application");

	glutDisplayFunc(render);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	glutMainLoop();
}

// Handles the keyboard press events
void keyboard(unsigned char c, int x, int y) {
	if (c == 27) {
		exit(0);
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

	// Creates a standard traingle (red, blue, green in each corner)
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex2f(-0.5, -0.5);
	glColor3f(0, 1, 0);
	glVertex2f(0.5, -0.5);
	glColor3f(0, 0, 1);
	glVertex2f(0.0, 0.5);
	glEnd();

	glutSwapBuffers();
}
