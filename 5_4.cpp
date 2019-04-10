
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void MyDisplay() {                      //디스플레이 콜백함수
    glClear(GL_COLOR_BUFFER_BIT);       //GL 상태변수 설정
    glViewport(0, 0, 300, 300);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);                //입력 기본요소 정의
        glVertex3f(-0.5, -0.5, 0.0);
        glVertex3f(0.5, -0.5, 0.0);
        glVertex3f(0.5, 0.5, 0.0);
        glVertex3f(-0.5, 0.5, 0.0);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);               //GLUT 윈도우 함수
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Sample Drawing");

    glClearColor(0.0, 0.0, 0.0, 1.0);   //GL 상태변수 설정
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(MyDisplay);         //GLUT 콜백함수 등록
    glutMainLoop();                     //이벤트 루프 진입
    return 0;
}


/* 5.11
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

GLfloat Delta = 0.0;

void DrawCircle(float cx, float cy, float r)
{
	float x1, y1, x2, y2;
	float angle;
	double radius = r;

	x1 = cx, y1 = cy;
	glColor3f(1.0, 1.0, 0.6);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);

	for (angle = 1.0f; angle < 361.0f; angle += 0.2)
	{
		x2 = x1 + sin(angle)*radius;
		y2 = y1 + cos(angle)*radius;
		glVertex2f(x2, y2);
	}

	glEnd();
}



void MyDisplay() {

	glClear(GL_COLOR_BUFFER_BIT);
	DrawCircle(0 + Delta, 0, 0.2);


	
		//glClear(GL_COLOR_BUFFER_BIT);
		//glBegin(GL_POLYGON);
		//glColor3f(0.0, 0.5, 0.8);
		//glVertex3f(-1.0 + Delta, -0.5, 0.0);
		//glVertex3f(0.0 + Delta, -0.5, 0.0);
		//glVertex3f(0.0 + Delta, 0.5, 0.0);
		//glVertex3f(-1.0 + Delta, 0.5, 0.0);
		//glEnd();
	

	glutSwapBuffers();
}

void MyTimer(int Value) {
	Delta = Delta + 0.001;
	glutPostRedisplay();
	glutTimerFunc(40, MyTimer, 1);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100, 0);
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(1.0, 0.5, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(40, MyTimer, 1);
	glutMainLoop();
	return 0;
}

*/