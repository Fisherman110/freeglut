#include <GL/glut.h>
//#include<cmath>

void init();
void display();
//void setPixel(int xcoord,int ycoord);
void midpoint(int x,int y,int r);
void plotcircle(int x0,int y0,int x1,int y1);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(300, 300);
	glutCreateWindow("Circle");
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

//void setPixel()(GLint xcoord,GLint ycoord)
//{
//	glBegin(GL_POINTS);
//	glVertex2i(xcoord,ycoord);
//	glEnd();
//}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 0);
	//glutWireTeapot(3);
	int x=100,y=100,r=30;
	midpoint(x,y,r);
	glFlush();
} 

void midpoint(int x,int y,int r)
{	
	//int xa,ya,xb,yb;
	//xa=xa,ya=ya,xb=xb,yb=yb;
	glColor3f(1.0,0.0,0.0);
	glPointSize(2.0f);

	int xb,yb;
	int p=1-r;
	xb=0,yb=r;
	plotcircle(x,y,xb,yb);
	while(xb<yb){
		xb++;
		if(p<0)
			p+=2*xb+1;
		else{
			yb--;
			p+=2*(xb-yb)+1;
		}
		plotcircle(x,y,xb,yb);
	}
}	

void plotcircle(int x0,int y0,int x1,int y1)
{
	//setPixel(x0+x1,y0+y1);	
	glBegin(GL_POINTS);
	glVertex2i(x0+x1,y0+y1);
	glVertex2i(x0-x1,y0+y1);
	glVertex2i(x0+x1,y0-y1);
	glVertex2i(x0-x1,y0-y1);
	glVertex2i(x0+y1,y0+x1);
	glVertex2i(x0-y1,y0+x1);
	glVertex2i(x0+y1,y0-x1);
	glVertex2i(x0-y1,y0-x1);
	glEnd();
	//setPixel(x0-x1,y0+y1);
	//setPixel(x0+x1,y0-y1);
	//setPixel(x0-x1,y0-y1);
	//setPixel(x0+y1,y0+x1);
	//setPixel(x0-y1,y0+x1);
	//setPixel(x0+y1,y0-x1);
	//setPixel(x0-y1,y0-x1);
}
