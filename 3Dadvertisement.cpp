/*==================================================================================================
 PROGRAMMER:				Zackh Tucker // Josiah McGurty
 COURSE:					CSC 525/625
 MODIFIED BY:				Zackh Tucker <tucker117> // Josiah McGurty <mcgurty1337>
 ELECTRONIC FILE LOCATIONS:	\\trace\Class\CSC-525-625\001\tucker117\projects\project3\
							\\trace\Class\CSC-525-625\001\McGurty1337\projects\project3\
 CONTRIBUTION BREAKDOWN:	Zackh Tucker -- 50%
								- basic setup of windows
								- render the background
								- render the frame 
								- add camera movement via W-S-A-D keys
							Josiah McGurty -- 50%
								- basic setup of windows
								- render 3D objects
								- cosmetic work on 3D objects
 LAST MODIFIED DATE:		12.12.2018
 DESCRIPTION:				Lab Project 3, working with 3D objects in openGL to create an advertisement.
 NOTE:
 FILES:						3dadvertisement.cpp, (labProject.sln, ...)
 IDE/COMPILER:				MicroSoft Visual Studio 2017
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on projProject.sln	to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/

#include <iostream>
#include <GL/glut.h>				// include GLUT library
#include <math.h>
#include <string>

using namespace std;
//***********************************************************************************

GLfloat vertices[][3] = { {60, 55, 40}, {60, -50, 40}, {65, 90, -70}, {65, 0, -70}, {-70, 70, 20}, {-70, -20, 20} };

GLfloat colors[][3] = { {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0} };

int selection;

int xangle = 0;
int yangle = 0;

void drawAxis()
{
	char y;
	y = 'Y';
	glRasterPos3f(-3, 155, 0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, int(y));

	char x;
	x = 'X';
	glRasterPos3f(155, -3, 0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, int(x));

	char z;
	z = 'Z';
	glRasterPos3f(0, 0, 0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, int(z));

	glPointSize(1);		// change point size back to 1

	glBegin(GL_POINTS);	// use points to form X-/Y-axes
	glColor3f(0, 0, 0);			 // change drawing color to black
	for (int x = -150; x <= 150; x++) // draw X-axis
		glVertex3i(x, 0, 0);
	for (int y = -150; y <= 150; y++) // draw Y-axis
		glVertex3i(0, y, 0);
	for (int z = -150; z <= 150; z++) {
		glVertex3i(0, 0, z);
	}
	glEnd();

}

void drawPolygon(int a, int b, int c, int d) {

	glPolygonMode(GL_BACK, GL_LINE);
	glPolygonMode(GL_FRONT, GL_FILL);
	glBegin(GL_POLYGON);
	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);
	glVertex3fv(vertices[d]);
	glEnd();
}

void drawPipe() {
	glColor3fv(colors[1]);
	drawPolygon(0, 1, 3, 2);

	glColor3fv(colors[2]);
	drawPolygon(5, 4, 2, 3);

	glColor3fv(colors[3]);
	drawPolygon(5, 1, 0, 4);
}


//***********************************************************************************
void myInit()
{
	glClearColor(0.8, 0.8, 0.8, 0);			// specify a background color: white 

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glFrustum(-200.0, 200.0, -200.0, 200.0, -200.0, 200.0);
	glOrtho(-200.0, 200.0, -200.0, 200.0, -200.0, 200.0);
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// draw the background

	drawAxis();
	drawPipe();

	glFlush(); // flush out the buffer contents
}

void update() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	switch (selection) {
	case 1: glRotatef(45.0, 1.0, 0.0, 0.0); break; //45 degrees around x axis
	case 2: glRotatef(-45.0, 1.0, 0.0, 0.0); break;
	case 3: glRotatef(45.0, 0.0, 1.0, 0.0); break;
	case 4: glRotatef(-45.0, 0.0, 1.0, 0.0); break;
	case 5: glRotatef(45.0, 0.0, 0.0, 1.0); break;
	case 6: glRotatef(-45.0, 0.0, 0.0, 1.0); break;
	}
	drawPipe();
	drawAxis();
	glFlush();
}

void FirstMenu(int x)
{
	if (x == 7) {
		myInit();
		myDisplayCallback();
	}
	if (x == 8) {
		exit(0);
	}
}

void runXMenu(int x) {
	if (x == 1) {
		selection = 1;
	}
	if (x == 2) {
		selection = 2;
	}
	update();
}

void runYMenu(int x) {
	if (x == 1) {
		selection = 3;
	}
	if (x == 2) {
		selection = 4;
	}
	update();
}

void runZMenu(int x) {
	if (x == 1) {
		selection = 5;
	}
	if (x == 2) {
		selection = 6;
	}
	update();
}

void mykeyboardFunc(int key, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	switch (key) {
	case GLUT_KEY_LEFT: cout << "LEFT\n";  xangle += 1; cout << xangle; glRotatef(xangle, 1.0, 0.0, 0.0); xangle = 0; break;
	case GLUT_KEY_RIGHT: cout << "RIGHT\n"; xangle -= 1; cout << xangle; glRotatef(xangle, 1.0, 0.0, 0.0); xangle = 0; break;
	case GLUT_KEY_UP: cout << "UP\n"; yangle += 1; cout << yangle; glRotatef(yangle, 0.0, 1.0, 0.0); yangle = 0; break;
	case GLUT_KEY_DOWN: cout << "Down\n"; yangle -= 1; cout << yangle; glRotatef(yangle, 0.0, 1.0, 0.0); yangle = 0; break;
	case GLUT_KEY_END: myInit(); myDisplayCallback(); break; 
	}
	drawPipe();
	drawAxis();
	glFlush();
}


//***********************************************************************************
int main(int argc, char ** argv)
{//glutInit(& argc, argv);                  // optional in our environment

	glutInitWindowSize(400, 400);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("3D Advertisement");	// create a titled window
	myInit();									// setting up

	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutSpecialFunc(mykeyboardFunc);

	int XMenu = glutCreateMenu(runXMenu);
	glutAddMenuEntry("+45", 1);
	glutAddMenuEntry("-45", 2);

	int YMenu = glutCreateMenu(runYMenu);
	glutAddMenuEntry("+45", 1);
	glutAddMenuEntry("-45", 2);

	int ZMenu = glutCreateMenu(runZMenu);
	glutAddMenuEntry("+45", 1);
	glutAddMenuEntry("-45", 2);

	int mainMenu = glutCreateMenu(FirstMenu);
	glutAddMenuEntry("Help", 1);
	glutAddSubMenu("Rotate around X axis", XMenu);
	glutAddSubMenu("Rotate around Y axis", YMenu);
	glutAddSubMenu("Rotate around Z axis", ZMenu);
	glutAddMenuEntry("Reset", 7);
	glutAddMenuEntry("Exit", 8);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();							// get into an infinite loop

	return 0;
}
