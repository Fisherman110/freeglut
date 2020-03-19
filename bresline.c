#include <GL/glut.h>
//#include<cmath>

void init();
void display();
void bresline(int xa,int ya,int xb,int yb);

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
	bresline(xa,ya,xb,yb);
	glFlush();
} 

void bresline(int xa,int ya,int xb,int yb)
{	
	//int xa,ya,xb,yb;
	//xa=xa,ya=ya,xb=xb,yb=yb;
	glColor3f(1.0,0.0,0.0);
	glPointSize(2.0f);
	//glBegin(GL_POINTS);
	//glVertex2f((int)x,(int)y);
	//glEnd();
	//glFlush();
	int dx,dy;
	int x,y;
	int p,const1,const2;
	int inc,tmp;
	dx=xb-xa;
	dy=yb-ya;
	if(dx*dy>=0)
		inc=1;
	else
		inc=-1;
	if(abs(dx)>abs(dy)){
		if(dx<0){
			tmp=xa;
			xa=xb;
			xb=tmp;
			tmp=ya;
			ya=yb;
			yb=tmp;
			dx=-dx;
			dy=-dy;
		}
		p=2*dy-dx;
		const1=2*dy;
		const2=2*(dy-dx);
		x=xa;
		y=ya;
		while(x<xb){
			glBegin(GL_POINTS);
			glVertex2f((int)x,(int)y);
			glEnd();
			glFlush();
			x++;
			if(p<0)
				p+=const1;
			else{y+=inc;p+=const2;}
		}
	}
	else{
		if(dy<0){
			tmp=xa;
			xa=xb;
			xb=tmp;
			tmp=ya;
			ya=yb;
			yb=tmp;
			dx=-dx;
			dy=-dy;
		}
	p=2*dx-dy;
	const1=2*dx;
	const2=2*(dx-dy);
	x=xa;
	y=ya;
	while(y<yb){
		glBegin(GL_POINTS);
		glVertex2f((int)x,(int)y);
		glEnd();
		glFlush();
		y++;
		if(p<0)
			p+=const1;
		else{
			x+=inc;
			p+=const2;
		}
	}
	}
}	
	

