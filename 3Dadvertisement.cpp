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
								- object transformation via LEFT-RIGHT-DOWN-UP keys
							Josiah McGurty -- 50%
								- basic setup of windows
								- render 3D text
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

//rm 3Da.o; clear; g++ 3Dadvertisement.cpp -lGL -lglut -o 3Da.o; ./3Da.o

//#include <iostream>
#include <GL/glut.h>				// include GLUT library
//#include <math.h>
//#include <string>

//using namespace std;
//***********************************************************************************

int selection; bool wireframe = false;

//Define a set of vertices for each letter in 'LightsOut'
GLfloat letterVertices[][3] = {
{-150, 150, -10}, {-160, 145, 0}, {-150, 140, 10}, {-140, 145, 0}, //begin L [0]-[11]
{-150, 0, -10}, {-160, -5, 0}, {-150, -10, 10}, {-140, -5, 0},
{150, 0, -10}, {160, -5, 0}, {150, -10, 10}, {140, -5, 0},
{-120, 25, -10}, {-130, 20, 0}, {-120, 15, 10}, {-110, 20, 0}, //begin i [12]-[27]
{-120, 75, -10}, {-130, 70, 0}, {-120, 65, 10}, {-110, 70, 0},
{-120, 90, -10}, {-130, 85, 0}, {-120, 80, 10}, {-110, 85, 0},
{-120, 100, -10}, {-130, 95, 0}, {-120, 90, 10}, {-110, 95, 0},
{-90, 100, -10}, {-100, 95, 0}, {-90, 90, 10}, {-80, 95, 0}, //begin g [28]-[51]
{-90, 60, -10}, {-100, 55, 0}, {-90, 50, 10}, {-80, 55, 0},
{-50, 60, -10}, {-60, 55, 0}, {-50, 50, 10}, {-40, 55, 0},
{-50, 100, -10}, {-60, 95, 0}, {-50, 90, 10}, {-40, 95, 0},
{-50, 25, -10}, {-60, 20, 0}, {-50, 15, 10}, {-40, 20, 0},
{-90, 25, -10}, {-100, 20, 0}, {-90, 15, 10}, {-80, 20, 0},
{-20, 140, -10}, {-30, 135, 0}, {-20, 130, 10}, {-10, 135, 0}, //begin h [52]-[71]
{-20, 25, -10}, {-30, 20, 0}, {-20, 15, 10}, {-10, 20, 0},
{-20, 80, -10}, {-30, 75, 0}, {-20, 70, 10}, {-10, 75, 0},
{20, 80, -10}, {10, 75, 0}, {20, 70, 10}, {30, 75, 0},
{20, 25, -10}, {10, 20, 0}, {20, 15, 10}, {30, 20, 0},
{50, 140, -10}, {40, 135, 0}, {50, 130, 10}, {60, 135, 0}, //begin t [72]-[91]
{50, 80, -10}, {40, 75, 0}, {50, 70, 10}, {60, 75, 0},
{70, 80, -10}, {60, 75, 0}, {70, 70, 10}, {80, 75, 0},
{50, 25, -10}, {40, 20, 0}, {50, 15, 10}, {60, 20, 0},
{80, 25, -10}, {70, 20, 0}, {80, 15, 10}, {90, 20, 0},
{110, 25, -10}, {100, 20, 0}, {110, 15, 10}, {120, 20, 0}, //begin s [92]-[115]
{150, 25, -10}, {140, 20, 0}, {150, 15, 10}, {160, 20, 0},
{150, 55, -10}, {140, 50, 0}, {150, 45, 10}, {160, 50, 0},
{110, 55, -10}, {100, 50, 0}, {110, 45, 10}, {120, 50, 0},
{110, 85, -10}, {100, 80, 0}, {110, 75, 10}, {120, 80, 0},
{140, 85, -10}, {130, 80, 0}, {140, 75, 10}, {150, 80, 0},
{150, -20, -10}, {160, -25, 0}, {150, -30, 10}, {140, -25, 0}, //begin T [116]-[131]
{-150, -20, -10}, {-160, -25, 0}, {-150, -30, 10}, {-140, -25, 0},
{95, -20, -10}, {85, -25, 0}, {95, -30, 10}, {105, -25, 0},
{95, -170, -10}, {85, -175, 0}, {95, -180, 10}, {105, -175, 0},
{-120, -45, -10}, {-130, -50, 0}, {-120, -55, 10}, {-110, -50, 0}, //begin o [132]-[147]
{-120, -140, -10}, {-130, -145, 0}, {-120, -150, 10}, {-110, -145, 0},
{-50, -140, -10}, {-60, -145, 0}, {-50, -150, 10}, {-40, -145, 0},
{-50, -45, -10}, {-60, -50, 0}, {-50, -55, 10}, {-40, -50, 0},
{-20, -140, -10}, {-30, -145, 0}, {-20, -150, 10}, {-10, -145, 0}, //begin u [148]-[163]
{-20, -45, -10}, {-30, -50, 0}, {-20, -55, 10}, {-10, -50, 0},
{65, -45, -10}, {55, -50, 0}, {65, -55, 10}, {75, -50, 0},
{65, -140, -10}, {55, -145, 0}, {65, -150, 10}, {75, -145, 0},
};

GLfloat pipeColors[][3] = { {0.8, 0.2, 0.1}, {0.1, 0.8, 0.2}, {0.1, 0.2, 0.8} };

/*==============================================
Function drawLetters()

This function serves as the template for actually placing
vertices into a 3D space.

=================================================*/
void drawLetters(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glVertex3fv(letterVertices[a]);
	glVertex3fv(letterVertices[b]);
	glVertex3fv(letterVertices[c]);
	glVertex3fv(letterVertices[d]);
	glEnd();
}

/*==============================================
Function drawLightsOut()

This function uses drawLetters() to draw the vertices given
to form 3D letters.

=================================================*/
void drawLightsOut()
{
	glPolygonMode(GL_BACK, GL_LINE);
	if (wireframe == false)
	{
	  glPolygonMode(GL_FRONT, GL_FILL);
	}
	else
	{
	  glPolygonMode(GL_FRONT, GL_LINE);
	}
  glColor3fv(pipeColors[0]); //red
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
  drawLetters(52, 53, 54, 55); // draw the 'h'
  drawLetters(56, 59, 58, 57);
  drawLetters(54, 53, 57, 58);
  drawLetters(55, 54, 58, 59);
  drawLetters(52, 55, 59, 56);
  drawLetters(53, 52, 56, 57);
  drawLetters(60, 61, 65, 64);
  drawLetters(61, 62, 66, 65);
  drawLetters(62, 63, 67, 66);
  drawLetters(63, 60, 64, 65);
  drawLetters(66, 65, 69, 70);
  drawLetters(67, 66, 70, 71);
  drawLetters(64, 67, 71, 68);
  drawLetters(65, 64, 68, 69);
  drawLetters(64, 65, 66, 67);
  drawLetters(68, 71, 70, 69);
  drawLetters(72, 73, 74, 75); // draw the 't'
  drawLetters(74, 73, 85, 86);
  drawLetters(75, 74, 86, 87);
  drawLetters(72, 75, 87, 84);
  drawLetters(73, 72, 84, 85);
  drawLetters(76, 77, 81, 80);
  drawLetters(77, 78, 82, 81);
  drawLetters(78, 79, 83, 82);
  drawLetters(79, 76, 80, 83);
  drawLetters(80, 81, 82, 83);
  drawLetters(84, 85, 89, 88);
  drawLetters(85, 86, 90, 89);
  drawLetters(87, 84, 88, 91);
  drawLetters(86, 87, 91, 90);
  drawLetters(88, 89, 90, 91);
  drawLetters(88, 89, 90, 91);
  drawLetters(84, 87, 86, 85);
  drawLetters(92, 93, 97, 96); // draw the 's'
  drawLetters(93, 94, 98, 97);
  drawLetters(95, 92, 96, 99);
  drawLetters(94, 95, 99, 98);
  drawLetters(95, 94, 93, 92);
  drawLetters(98, 99, 103, 102);
  drawLetters(97, 98, 102, 101);
  drawLetters(96, 97, 101, 100);
  drawLetters(99, 96, 100, 103);
  drawLetters(100, 101, 102, 103);
  drawLetters(101, 100, 104, 105);
  drawLetters(102, 101, 105, 106);
  drawLetters(107, 103, 102, 106);
  drawLetters(107, 106, 105, 104);
  drawLetters(104, 100, 103, 107);
  drawLetters(106, 107, 111, 110);
  drawLetters(105, 106, 110, 109);
  drawLetters(109, 108, 104, 105);
  drawLetters(108, 111, 107, 104);
  drawLetters(108, 109, 113, 112);
  drawLetters(109, 110, 114, 113);
  drawLetters(111, 108, 112, 115);
  drawLetters(110, 111, 115, 114);
  drawLetters(112, 113, 114, 115);
  glColor3fv(pipeColors[2]); //blue
  drawLetters(116, 117, 118, 119); // draw the 'T'
  drawLetters(120, 123, 119, 116);
  drawLetters(123, 122, 118, 119);
  drawLetters(116, 119, 118, 117);
  drawLetters(120, 121, 122, 123);
  drawLetters(124, 125, 126, 127);
  drawLetters(128, 129, 130, 131);
  drawLetters(120, 116, 119, 123);
  drawLetters(123, 119, 118, 122);
  drawLetters(127, 126, 130, 131);
  drawLetters(126, 125, 129, 130);
  drawLetters(124, 127, 131, 128);
  drawLetters(125, 124, 128, 129);
  drawLetters(131, 130, 129, 128);
  drawLetters(123, 122, 121, 120);
  drawLetters(132, 133, 134, 135); // draw the 'o'
  drawLetters(135, 134, 138, 139);
  drawLetters(134, 133, 137, 138);
  drawLetters(133, 132, 136, 137);
  drawLetters(132, 135, 139, 136);
  drawLetters(136, 137, 138, 139);
  drawLetters(136, 139, 143, 140);
  drawLetters(139, 138, 142, 143);
  drawLetters(137, 136, 140, 141);
  drawLetters(138, 137, 141, 142);
  drawLetters(140, 141, 142, 143);
  drawLetters(142, 143, 147, 146);
  drawLetters(141, 142, 146, 145);
  drawLetters(145, 144, 140, 141);
  drawLetters(144, 147, 143, 140);
  drawLetters(141, 140, 143, 142);
  drawLetters(144, 145, 146, 147);
  drawLetters(147, 144, 132, 135);
  drawLetters(146, 147, 135, 134);
  drawLetters(133, 132, 144, 145);
  drawLetters(134, 133, 145, 146);
  drawLetters(148, 149, 150, 151); // draw the 'u'
  drawLetters(154, 153, 149, 150);
  drawLetters(155, 154, 150, 151);
  drawLetters(153, 152, 148, 149);
  drawLetters(152, 155, 151, 148);
  drawLetters(152, 153, 154, 155);
  drawLetters(149, 150, 162, 161);
  drawLetters(148, 149, 161, 160);
  drawLetters(151, 150, 149, 148);
  drawLetters(151, 148, 160, 163);
  drawLetters(150, 151, 163, 162);
  drawLetters(156, 157, 158, 159);
  drawLetters(161, 162, 158, 157);
  drawLetters(162, 163, 159, 158);
  drawLetters(156, 159, 163, 160);
  drawLetters(157, 156, 160, 161);
  drawLetters(160, 161, 162, 163);
}

/*===============================================================================================*/
void myInit()
{
	glClearColor(0.15, 0.15, 0.15, 0); // specify a background color: white

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glFrustum(-200.0, 200.0, -200.0, 200.0, -200.0, 200.0);
	glOrtho(-200.0, 200.0, -200.0, 200.0, -200.0, 200.0);
}

/*===============================================================================================*/
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // draw the background

	drawLightsOut();

	glFlush(); // flush out the buffer contents
}

/*============================================
Function update()
This function is the end point for the right-click menu,
where the object rendered can be rotated a set amount.
===================================================*/
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

/*===============================================================================================*/
void FirstMenu(int x)
{
	if (x == 7) {
		wireframe = false;
		myInit();
		myDisplayCallback();
	}
	if (x == 8) {
		exit(0);
	}
	if (x == 1) {
		if (wireframe == false)
			wireframe = true;
		else
			wireframe = false;
		update();
	}
}

/*===============================================================================================*/
void runXMenu(int x) {
	if (x == 1) {
		selection = 1;
	}
	if (x == 2) {
		selection = 2;
	}
	update();
}

/*===============================================================================================*/
void runYMenu(int x) {
	if (x == 1) {
		selection = 3;
	}
	if (x == 2) {
		selection = 4;
	}
	update();
}

/*===============================================================================================*/
void runZMenu(int x) {
	if (x == 1) {
		selection = 5;
	}
	if (x == 2) {
		selection = 6;
	}
	update();
}

/*==========================================
Function myKeyboardFunc()
This function allows for the use of set keyboard buttons to transform the object
rendered around certain axis, depending on which button was pressed.
=====================================================*/
void mykeyboardFunc(int key, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	switch (key) {
		case GLUT_KEY_LEFT: glRotatef(5.0, 1.0, 0.0, 0.0); break;
		case GLUT_KEY_RIGHT: glRotatef(-5.0, 1.0, 0.0, 0.0); break;
		case GLUT_KEY_UP: glRotatef(5.0, 0.0, 1.0, 0.0); break;
		case GLUT_KEY_DOWN: glRotatef(-5.0, 0.0, 1.0, 0.0); break;
		case GLUT_KEY_PAGE_UP: glRotatef(5.0, 0.0, 0.0, 1.0); break;
		case GLUT_KEY_PAGE_DOWN: glRotatef(-5.0, 0.0, 0.0, 1.0); break;
		case GLUT_KEY_END: wireframe = false; myInit(); myDisplayCallback(); break;
	}
	drawLightsOut();
	glFlush();
}

/*===============================================================================================*/
int main(int argc, char ** argv)
{
	glutInit(& argc, argv); // optional in some environments
	glutInitWindowSize(400, 400); // specify a window size
	glutInitWindowPosition(100, 0); // specify a window position
	glutCreateWindow("3D Advertisement"); // create a titled window
	myInit(); // setting up

	glutDisplayFunc(myDisplayCallback); // register a callback

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
	glutAddMenuEntry("Wireframe/Solid Fill Text", 1);
	glutAddSubMenu("Rotate around X axis", XMenu);
	glutAddSubMenu("Rotate around Y axis", YMenu);
	glutAddSubMenu("Rotate around Z axis", ZMenu);
	glutAddMenuEntry("Reset", 7);
	glutAddMenuEntry("Exit", 8);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop(); // get into an infinite loop

	return 0;
}
