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

//rm p3D.o; clear; g++ proj3Dobject.cpp -lGL -lglut -lGLU -o p3D.o; ./p3D.o

#include <GL/glut.h>

using namespace std;

int selection = 0;

//Define a set of vertices for each letter in 'LightsOut'

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

GLfloat pipeVertices[][3] = {{60, 55, 40}, {60, -50, 40}, {65, 90, -70},
{65, 0, -70}, {-70, 70, 20}, {-70, -20, 20}};

GLfloat pipeColors[][3] = {{0.8, 0.2, 0.1}, {0.1, 0.8, 0.2}, {0.1, 0.2, 0.8}};

void drawLetters(int a, int b, int c, int d)
{
  glBegin(GL_POLYGON);
    glVertex3fv(letterVertices[a]);
    glVertex3fv(letterVertices[b]);
    glVertex3fv(letterVertices[c]);
    glVertex3fv(letterVertices[d]);
  glEnd();
}

void drawPolygon(int a, int b, int c, int d)
{
  glBegin(GL_POLYGON);
    glVertex3fv(pipeVertices[a]);
    glVertex3fv(pipeVertices[b]);
    glVertex3fv(pipeVertices[c]);
    glVertex3fv(pipeVertices[d]);
  glEnd();
}

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

void drawPipeSection()
{
  glPolygonMode(GL_BACK, GL_LINE);
  glPolygonMode(GL_FRONT, GL_FILL);
  glColor3fv(pipeColors[0]);
  drawPolygon(0, 1, 3, 2);
  glColor3fv(pipeColors[1]);
  drawPolygon(5, 4, 2, 3);
  glColor3fv(pipeColors[2]);
  drawPolygon(5, 1, 0, 4);
}

void drawAxes()
{
  glColor3f(1, 1, 1); // change drawing color to white
  glBegin(GL_POINTS);	// use points to form X-/Y-/Z-axes180
    for (int x = -150; x <= 150; x++) glVertex3i(x, 0, 0); // draw X-axis
    for (int y = -150; y <= 150; y++) glVertex3i(0, y, 0); // draw Y-axis
    for (int z = -150; z <= 150; z++) glVertex3i(0, 0, z); // draw Z-axis
  glEnd();
  glRasterPos3i(140, -20, 10); // Axes labels
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'X');
  glRasterPos3i(-20, 140, 10);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'Y');
  glRasterPos3i(-10, -10, 140);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'Z');
}

void drawBitmap()
{
  GLubyte mrScratchy[] =
  {
    0x01,0x80,0x00,0x00, 0x01,0xe0,0x00,0x00, 0x01,0xff,0xc0,0x00,
    0x00,0x1f,0xc0,0x00, 0x70,0x00,0x80,0x00, 0xf8,0x00,0x80,0x00,
    0x3f,0x00,0x80,0x00, 0x03,0xc0,0x80,0x00, 0x00,0xc0,0x80,0x00,
    0x00,0xc1,0x80,0x00, 0x00,0xc1,0x80,0x00, 0x00,0xc3,0x00,0x00,
    0x00,0xc3,0x00,0x00, 0x00,0x86,0x00,0x00, 0x00,0x86,0x00,0x00,
    0x00,0x8e,0x00,0x00, 0x00,0x8c,0x00,0x00, 0x01,0x8c,0x00,0x00,
    0x01,0x9c,0x00,0x00, 0x01,0x9c,0x00,0x00, 0x01,0x9c,0x00,0x00,
    0x01,0xdc,0x00,0x00, 0x01,0xdc,0x00,0x00, 0x01,0xfc,0x00,0x00,
    0x01,0xfe,0x00,0x00, 0x01,0xfe,0x70,0x00, 0x01,0xfe,0xc0,0x00,
    0x03,0xff,0x80,0x00, 0x03,0xff,0x00,0x00, 0x03,0xff,0x80,0x00,
    0x03,0xfd,0xfe,0x00, 0x07,0xf8,0x03,0x00, 0x03,0xf8,0x03,0x00,
    0x03,0xf8,0x06,0x00, 0x03,0xf8,0x0c,0x00, 0x03,0xf8,0x18,0x00,
    0x03,0xfc,0x30,0x00, 0x01,0xfc,0xe0,0x00, 0x01,0xff,0xe0,0x00,
    0x01,0xff,0xc0,0x00, 0x01,0xff,0x80,0x00, 0x03,0xff,0x00,0x00,
    0x07,0xfe,0x00,0x00, 0x0f,0x80,0x00,0x00, 0x0f,0x38,0x00,0x00,
    0x1e,0x3e,0x00,0x00, 0x3c,0x3f,0x00,0x00, 0x38,0x3f,0x80,0x00,
    0x70,0x7f,0xc0,0x00, 0x63,0xff,0xe0,0x00, 0x60,0x3f,0xf0,0x00,
    0xe0,0x3f,0xf0,0x00, 0xe0,0x1f,0xf0,0x00, 0xe0,0x0f,0xf0,0x00,
    0xf8,0x0f,0xf0,0x00, 0x1f,0xf7,0xf0,0x00, 0x00,0x73,0xf0,0x00,
    0x00,0x10,0xe0,0x00, 0x00,0x0d,0x00,0x00, 0x00,0x0f,0x00,0x00,
    0x00,0x00,0x01,0x00, 0x00,0x00,0x01,0xc0, 0x00,0x00,0x00,0x20,
    0x00,0x00,0x00,0x20, 0x00,0x00,0x00,0xe0, 0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00
  };
  glColor3f(0.8, 0.8, 0.2); // change drawing color to yellow
  glRasterPos3i(40, 40, 0);
  glBitmap(28, 68, 0.0, 0.0, 0.0, 0.0, mrScratchy);
}

void myInit()
{
  glClearColor(0.15, 0.15, 0.15, 0); // specify a background clor: dark gray
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // z-buffer for depth
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glFrustum(-200.0, 200.0, -200.0, 200.0, -200.0, 200.0);
  glOrtho(-200.0, 200.0, -200.0, 200.0, -200.0, 200.0);
}

void displayCallback()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// draw the background
  drawLightsOut();
  //drawPipeSection();
  //drawBitmap();
  drawAxes();
  glFlush(); // flush out the buffer contents
}

void updateDisplay()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// draw the background
  switch (selection)
  {
    case 1: glRotatef(45.0, 1.0, 0.0, 0.0); break; // +45 deg, X-axis
    case 2: glRotatef(-45.0, 1.0, 0.0, 0.0); break; // -45 deg, X-axis
    case 3: glRotatef(45.0, 0.0, 1.0, 0.0); break; // +45 deg, Y-axis
    case 4: glRotatef(-45.0, 0.0, 1.0, 0.0); break; // -45 deg, Y-axis
    case 5: glRotatef(45.0, 0.0, 0.0, 1.0); break; // +45 deg, Z-axis
    case 6: glRotatef(-45.0, 0.0, 0.0, 1.0); break; // -45 deg, Z-axis
  }
  drawLightsOut();
  //drawAxes();
  glFlush(); // flush out the buffer contents
}

void runXAxisMenu(int value)
{
  if (value == 1) {selection = 1; updateDisplay();}
  if (value == 2) {selection = 2; updateDisplay();}
}

void runYAxisMenu(int value)
{
  if (value == 3) {selection = 3; updateDisplay();}
  if (value == 4) {selection = 4; updateDisplay();}
}

void runZAxisMenu(int value)
{
  if (value == 5) {selection = 5; updateDisplay();}
  if (value == 6) {selection = 6; updateDisplay();}
}

void runRightClickMenu(int value)
{
  if (value == 7) {myInit(); displayCallback();} // reset
  if (value == 8) {exit(0);}
}

int main(int argc, char ** argv)
{
  glutInit(& argc, argv); // optional in some environments
  glutInitWindowSize(400, 400); // specify a window size
  glutInitWindowPosition(100, 0); // specify a window position
  glutCreateWindow("LightsOut"); // create a titled window
  myInit(); // setting up
  glutDisplayFunc(displayCallback); // register a callback
  int xAxisMenu = glutCreateMenu(runXAxisMenu); // Setup the right-click menu
    glutAddMenuEntry("+ 45 degrees", 1);
    glutAddMenuEntry("- 45 degrees", 2);
  int yAxisMenu = glutCreateMenu(runYAxisMenu);
    glutAddMenuEntry("+ 45 degrees", 3);
    glutAddMenuEntry("- 45 degrees", 4);
  int zAxisMenu = glutCreateMenu(runZAxisMenu);
    glutAddMenuEntry("+ 45 degrees", 5);
    glutAddMenuEntry("- 45 degrees", 6);
  int rightClickMenu = glutCreateMenu(runRightClickMenu);
    glutAddSubMenu("Rotate 3D pipe section & axes about X-axis", xAxisMenu);
    glutAddSubMenu("Rotate 3D pipe section & axes about Y-axis", yAxisMenu);
    glutAddSubMenu("Rotate 3D pipe section & axes about Z-axis", zAxisMenu);
    glutAddMenuEntry("Reset", 7);
    glutAddMenuEntry("Exit", 8);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutMainLoop(); // get into an infinite loop
  return 0;
}
