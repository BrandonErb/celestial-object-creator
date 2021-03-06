#include "OpenGLDraw.h"
using namespace std;

vector<Coords> coords;

OpenGLDraw::OpenGLDraw(vector<Coords> pCoords, float size)
{
	//coords = pCoords;
	Coords converted;//Coordinates converted to percentages to be drawn
	for (int i = 0; i < pCoords.size(); i++)
	{
		if (pCoords[i].x != 0.0f)//Prevents division by zero
		{
			converted.x = pCoords[i].x / size; 
		}
		if (pCoords[i].y != 0.0f)//Prevents division by zero
		{
			converted.y = pCoords[i].y / size;
		}
		if (pCoords[i].z != 0.0f)//Prevents division by zero
		{
			converted.z = pCoords[i].z / size;
		}
		coords.push_back(converted);
	}
} 

OpenGLDraw::OpenGLDraw()
{
}

OpenGLDraw::~OpenGLDraw()
{
}


/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer (background)

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0.0, 1.0, 0.0, 1.0); //For 2D Testing
	gluLookAt(1.0f, 1.0f, 1.0f, 0.5, 0.5, 0.5, 0.0, 1.0f, 0.0); //Camera Position
	glScalef(1.25, 1.25, 1.25); //Zoom Camera
	 
	//Draw Sphere
	glColor3f(0.6f, 1.0f, 0.7f);
	for (int i = 0; i < coords.size(); i++ )
	{
		glPushMatrix();
		glTranslatef(coords[i].x, coords[i].y, coords[i].z);
		glutSolidSphere(0.005, 10, 10);
		glPopMatrix();
	}

	//Scale lines
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(0.5);
	glBegin(GL_LINES);
	glVertex3f(0.25f, 0.5f, 0.5f);
	glVertex3f(0.75f, 0.5f, 0.5f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.5f, 0.25f, 0.5f);
	glVertex3f(0.5f, 0.75f, 0.5f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.5f, 0.5f, 0.25f);
	glVertex3f(0.5f, 0.5f, 0.75f);
	glEnd();

	glFlush();  // Render now
}


void OpenGLDraw::OpenWindow(int argc, char ** argv)
{
	glutInit(&argc, argv);                 // Initialize GLUT
	//glutInitDisplayMode(GLUT_DOUBLE); //Sets double buffering 
	glutInitWindowSize(600, 600);   // Set the window size
	glutCreateWindow("Celestial Space"); // Create a window with the given title
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return;
}
