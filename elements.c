#include <GL/glut.h>
//#include<cmath>
#include<stdio.h>
#include<math.h>
#define PI 3.1415926f

void init();
void display();
void ddaline(int xa,int ya,int xb,int yb);
void circle(int ,int ,int ,float );

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1060, 590);
	glutCreateWindow("Line");
	//init(); 
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}


void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
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
	int x=100,y=100;
	float R=10.0f;

	circle(x,y,3600,R);
	ddaline(xa,ya,xb,yb);
	glFlush();
} 

void circle(int x,int y,int n,float R)
{
	glClear(GL_COLOR_BUFFER_BIT);    
	glClearColor(1,1,1,0);
	glColor4f(0,0,1,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<n;i++)
	{
		glVertex2f(x+R*cos(2*PI*i/n),y+R*sin(2*PI*i/n));   //定义顶点
	}
	glEnd();
	glFlush();
}

void ddaline(int xa,int ya,int xb,int yb)
{	
	//int xa,ya,xb,yb;
	//xa=xa,ya=ya,xb=xb,yb=yb;
	glColor3f(1.0,0.0,0.0);
	glPointSize(4.0f);
	
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

