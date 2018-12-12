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
								- add camera movement via LEFT-RIGHT-DOWN-UP keys
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

int selection;

GLfloat letterVertices[][3] = {
{-150, 150, -10}, {-160, 145, 0}, {-150, 140, 10}, {-140, 145, 0}, //begin L
{-150, 0, -10}, {-160, -5, 0}, {-150, -10, 10}, {-140, -5, 0},
{150, 0, -10}, {160, -5, 0}, {150, -10, 10}, {140, -5, 0},

{-120, 25, -10}, {-130, 20, 0}, {-120, 15, 10}, {-110, 20, 0}, //begin i
{-120, 75, -10}, {-130, 70, 0}, {-120, 65, 10}, {-110, 70, 0},
{-120, 90, -10}, {-130, 85, 0}, {-120, 80, 10}, {-110, 85, 0},
{-120, 100, -10}, {-130, 95, 0}, {-120, 90, 10}, {-110, 95, 0},

{-90, 100, -10}, {-100, 95, 0}, {-90, 90, 10}, {-80, 95, 0}, //begin g
{-90, 60, -10}, {-100, 55, 0}, {-90, 50, 10}, {-80, 55, 0},
{-50, 60, -10}, {-60, 55, 0}, {-50, 50, 10}, {-40, 55, 0},
{-50, 100, -10}, {-60, 95, 0}, {-50, 90, 10}, {-40, 95, 0},
{-50, 25, -10}, {-60, 20, 0}, {-50, 15, 10}, {-40, 20, 0},
{-90, 25, -10}, {-100, 20, 0}, {-90, 15, 10}, {-80, 20, 0},
};

GLfloat pipeColors[][3] = { {0.8, 0.2, 0.1}, {0.1, 0.8, 0.2}, {0.1, 0.2, 0.8} };

//***********************************************************************************
void drawLetters(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glVertex3fv(letterVertices[a]);
	glVertex3fv(letterVertices[b]);
	glVertex3fv(letterVertices[c]);
	glVertex3fv(letterVertices[d]);
	glEnd();
}

//***********************************************************************************
void drawLightsOut()
{
	glPolygonMode(GL_BACK, GL_LINE);
	glPolygonMode(GL_FRONT, GL_FILL);

	glColor3fv(pipeColors[0]);
	drawLetters(0, 1, 2, 3); // Draw the 'L'
	drawLetters(3, 2, 6, 7);
	drawLetters(2, 1, 5, 6);
	drawLetters(1, 0, 4, 5);
	drawLetters(0, 3, 7, 4);
	drawLetters(4, 7, 6, 5);
	drawLetters(8, 4, 5, 9);
	drawLetters(9, 5, 6, 10);
	drawLetters(10, 6, 7, 11);
	drawLetters(11, 7, 4, 8);
	drawLetters(8, 9, 10, 11);

	drawLetters(15, 14, 13, 12); // draw the 'i'
	drawLetters(16, 17, 18, 19);
	drawLetters(18, 17, 13, 14);
	drawLetters(19, 18, 14, 15);
	drawLetters(16, 19, 15, 12);
	drawLetters(17, 16, 12, 13);
	drawLetters(20, 23, 22, 21); // dot the 'i'
	drawLetters(24, 25, 26, 27);
	drawLetters(27, 26, 22, 23);
	drawLetters(26, 25, 21, 22);
	drawLetters(25, 24, 20, 21);
	drawLetters(24, 27, 23, 20);

	drawLetters(28, 29, 41, 40); // draw the 'g'
	drawLetters(29, 30, 42, 41);
	drawLetters(30, 31, 43, 42);
	drawLetters(31, 28, 40, 43);
	drawLetters(30, 29, 33, 34);
	drawLetters(31, 30, 34, 35);
	drawLetters(28, 31, 35, 32);
	drawLetters(29, 28, 32, 33);
	drawLetters(32, 33, 37, 36);
	drawLetters(33, 34, 38, 37);
	drawLetters(34, 35, 39, 38);
	drawLetters(35, 32, 36, 39);
	drawLetters(42, 41, 45, 46);
	drawLetters(43, 42, 46, 47);
	drawLetters(40, 43, 47, 44);
	drawLetters(41, 40, 44, 45);
	drawLetters(45, 44, 48, 49);
	drawLetters(46, 45, 49, 50);
	drawLetters(44, 47, 51, 48);
	drawLetters(47, 46, 50, 51);
	drawLetters(40, 41, 42, 43);
	drawLetters(35, 34, 33, 32);
	drawLetters(51, 50, 49, 48);

	glColor3fv(pipeColors[1]);
	//drawPolygon(5, 4, 2, 3);

	glColor3fv(pipeColors[2]);
	//drawPolygon(5, 1, 0, 4);
}

//***********************************************************************************
void myInit()
{
	glClearColor(0.15, 0.15, 0.15, 0);			// specify a background color: white 

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

	drawLightsOut();

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
	drawLightsOut();
	glFlush();
}

//***********************************************************************************
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

//***********************************************************************************
void runXMenu(int x) {
	if (x == 1) {
		selection = 1;
	}
	if (x == 2) {
		selection = 2;
	}
	update();
}

//***********************************************************************************
void runYMenu(int x) {
	if (x == 1) {
		selection = 3;
	}
	if (x == 2) {
		selection = 4;
	}
	update();
}

//***********************************************************************************
void runZMenu(int x) {
	if (x == 1) {
		selection = 5;
	}
	if (x == 2) {
		selection = 6;
	}
	update();
}

//***********************************************************************************
void mykeyboardFunc(int key, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	switch (key) {
	case GLUT_KEY_LEFT: glRotatef(5.0, 1.0, 0.0, 0.0); break;
	case GLUT_KEY_RIGHT: glRotatef(-5.0, 1.0, 0.0, 0.0); break;
	case GLUT_KEY_UP: glRotatef(5.0, 0.0, 1.0, 0.0); break;
	case GLUT_KEY_DOWN: glRotatef(-5.0, 0.0, 1.0, 0.0); break;
	case GLUT_KEY_PAGE_UP: glRotatef(5.0, 0.0, 0.0, 1.0); break;
	case GLUT_KEY_PAGE_DOWN: glRotatef(-5.0, 0.0, 0.0, 1.0); break;
	case GLUT_KEY_END: myInit(); myDisplayCallback(); break;
	}
	drawLightsOut();
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
