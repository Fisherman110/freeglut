#include <GL/glut.h>
//#include<cmath>

void init();
void display();
void ddaline(int xa,int ya,int xb,int yb);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(300, 300);
	glutCreateWindow("Line");
	//init(); 
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}


void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0,150.0);
	//glMatrixMode(GL_MODELVIEW);
	//gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 0);
	//glutWireTeapot(3);
	int xa=20,ya=20,xb=180,yb=360;
	ddaline(xa,ya,xb,yb);
	glFlush();
} 

void ddaline(int xa,int ya,int xb,int yb)
{	
	//int xa,ya,xb,yb;
	//xa=xa,ya=ya,xb=xb,yb=yb;
	glColor3f(1.0,0.0,0.0);
	glPointSize(2.0f);
	
	int base=0;
	if(abs(xa-xb)>=abs(ya-yb))
		base=abs(xa-xb);
	else
		base=abs(ya-yb);
	float dx=(float)(xb-xa)/base;
	float dy=(float)(yb-ya)/base;
	float x=xa;
	float y=ya;

	for(int i=0;i<base;i++)
	{
		glBegin(GL_POINTS);
		glVertex2f((int)x,(int)y);
		glEnd();
		glFlush();
		x+=dx;
		y+=dy;
	}
}

