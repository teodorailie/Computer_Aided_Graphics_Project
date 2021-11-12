

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

#include <stdio.h>
#include <GL/glut.h>

static GLfloat spin = 0.0;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	if (spin < 250)
		glTranslatef(spin, spin, 0.0);
	else if (spin < 500)
		glTranslatef(spin, 250, 0.0);
	else
		glTranslatef(500, 250, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glRectf(0.0, -10.0, 0.0, 10.0);
	glColor3f(2.0, 3.0, 0.0);
	glRectf(0.0, 0.0, 20.0, 20.0);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0, 500.0, 0.0);
	if (spin < 250)
		glTranslatef(spin, -spin, 0.0);
	else if (spin < 500)
		glTranslatef(spin, -250, 0.0);
	else
		glTranslatef(-500, -250, 0.0);
	glColor3f(3.0, 2.0, 1.0);
	glRectf(0.0, 0.0, 20.0, 20.0);
	glPopMatrix();

	glPushMatrix();
	if (spin < 250)
		glTranslatef(-spin, spin, 0.0);
	else if (spin < 500)
		glTranslatef(spin, -250, 0.0);
	else
		glTranslatef(-500, -550, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1000.0, 20.0, 0.0);
	glVertex3f(980.0, 20.0, 0.0);
	glVertex3f(980.0, 0.0, 0.0);                //green square
	glVertex3f(1000.0, 0.0, 0.0);
	glEnd();
	
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(800.0, 350.0, 0.0);                    //big middle square
	glVertex3f(500.0, 350.0, 0.0);
	glVertex3f(500.0, 100.0, 0.0);             
	glVertex3f(800.0, 100.0, 0.0);
	glEnd();

	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void spinDisplay(void)
{
	spin = spin + 0.3;
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1000.0, 500.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void reshape2(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(1000.0, 0.0, 500.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay);
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(NULL);
		break;
	default:
		break;
	}
}

/*
* Initializarea modului de afisare dublu-buffer
* Inregistrarea functiilor callback pentru tratarea
* evenimentelor generate de mouse
*/
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutReshapeFunc(reshape2);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
