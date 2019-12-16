#include "StrickMan.h"
#include <string>
People people;

Ternary camera(0, 0, 40);
std::string str = "current fps = ";

void DisPlay() {
	//清除了深度缓冲区
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//要显示的字符  
	std::string str = "You can change direction by pressing wasd";
	int n = str.length();
	//设置要在屏幕上显示字符的起始位置  
	glRasterPos2i(-10, 10);
	//逐个显示字符串中的每个字符  
	for (int i = 0; i < n; i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str[0+i]);

	glLoadIdentity();
	gluLookAt(camera.x, camera.y, camera.z, 0, 0, 0, 0, 1, 0);

	//本次绘图最基础的开始坐标原点
	glTranslatef(0.0f, 0.0f, 0.0f);//平移矩阵(x,y,z)
	glRotatef(people.angle, 0, 1, 0);//旋转矩阵
	glPushMatrix();//保存当前模型的视图矩阵


	glTranslatef(0.0f, 0.0f, 0.0f);
	//glTranslatef(25.0, 0.0, 0.0);
	glRotatef(-90, 0, 1, 0);
	glPushMatrix();
	glTranslatef(0.0f, 1.2f, 0.0f);
	glPushMatrix();
	glTranslatef(0.8, 0.0, 0.0);
	glTranslatef(0.0, -0.4, 0.0);
	glRotatef(people.angleoflarmb, 1, 0, 0);
	glPushMatrix();
	glTranslatef(0.0, -0.8, 0.0);
	glTranslatef(0.0, -0.3, 0.0);
	glRotatef(people.angleoflarma, 1, 0, 0);
	people.DrawArmA();
	glPopMatrix();
	people.DrawArmB();
	glPopMatrix();
	//画出右臂
	glPushMatrix();
	glTranslatef(-0.8, 0.0, 0.0);
	glTranslatef(0.0, -0.4, 0.0);
	glRotatef(people.angleofrarmb, 1, 0, 0);
	glPushMatrix();
	glTranslatef(0.0, -0.8, 0.0);
	glTranslatef(0.0, -0.3, 0.0);
	glRotatef(people.angleofrarma, 1, 0, 0);
	people.DrawArmA();
	glPopMatrix();
	people.DrawArmB();
	glPopMatrix();

	//return shoulder  
	glPushMatrix();
	glTranslatef(0.0, 0.3, 0.0);
	glPushMatrix();
	glTranslatef(0.0, 0.7, 0.0);
	people.DrawHead();
	glPopMatrix();
	people.DrawNeck();
	glPopMatrix();
	people.DrawShoulder();
	glPopMatrix();
	//return body  
	glPushMatrix();
	glTranslatef(0.0f, -1.2f, 0.0f);
	glPushMatrix();
	glTranslatef(0.4, 0.0, 0.0);
	glTranslatef(0.0, -0.4, 0.0);
	glRotatef(people.angleofllegb, 1, 0, 0);
	glPushMatrix();
	glTranslatef(0.0, -1.5, 0.0);
	glRotatef(people.angleofllega, 1, 0, 0);
	people.DrawLegA();
	glPopMatrix();
	people.DrawLegB();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4, 0.0, 0.0);
	glTranslatef(0.0, -0.4, 0.0);
	glRotatef(people.angleofrlegb, 1, 0, 0);
	glPushMatrix();
	glTranslatef(0.0, -1.5, 0.0);
	glRotatef(people.angleofrlega, 1, 0, 0);
	people.DrawLegA();
	glPopMatrix();
	people.DrawLegB();
	glPopMatrix();
	people.DrawHip();
	glPopMatrix();
	people.DrawBody();
	glPopMatrix();
	glPopMatrix();

	people.angleoflarma += people.la;
	people.angleofrarma += people.ra;
	people.angleoflarmb += people.a;
	people.angleofrarmb -= people.a;

	people.angleofllega += people.ll;
	people.angleofrlega += people.rl;
	people.angleofllegb -= people.b;
	people.angleofrlegb += people.b;

	/*if (trans <= -50)
		trans = 0;*/
	if (50 > people.angleoflarmb && people.angleoflarmb > 0 && people.a > 0) {
		people.a = people.angle1;
		people.b = people.angle2;
		people.la = -people.angle1 * 0.75;
		people.ra = -people.angle1;
		people.ll = 0.75*people.angle2;
		people.rl = people.angle2 * 1.5;
	}
	if (people.angleoflarmb >= 50 && people.a > 0) {
		people.a = -people.angle1;
		people.b = -people.angle2;
	}
	if (people.angleoflarmb > 0 && people.a < 0) {
		people.a = -people.angle1;
		people.b = -people.angle2;
		people.la = people.angle1 * 0.75;
		people.ra = people.angle1;
		people.ll = -people.angle2 * 0.75;
		people.rl = -people.angle2 * 1.5;
	}
	if (-50 < people.angleoflarmb && people.angleoflarmb <= 0 && people.a < 0) {
		people.a = -people.angle1;
		people.b = -people.angle2;
		people.la = -people.angle1;
		people.ra = -people.angle1 * 0.75;
		people.ll = people.angle2 * 1.5;
		people.rl = people.angle2 * 0.75;
	}
	if (people.angleoflarmb <= -50 && people.a < 0) {
		people.a = people.angle1;
		people.b = people.angle2;
	}
	if (people.angleoflarmb < 0 && people.a>0) {
		people.a = people.angle1;
		people.b = people.angle2;
		people.la = people.angle1;
		people.ra = people.angle1 * 0.75;
		people.ll = -people.angle2 * 1.5;
		people.rl = -people.angle2 * 0.75;
	}

	glutSwapBuffers();
}


void ReSizeGLScene(int Width, int Height)
{
	float size = 80;
	if (Height == 0)
		Height = 1;
	glViewport(0, 0, (GLsizei)Width, (GLsizei)Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//if (Width <= Height)
	//	glOrtho(-size, size, -size * (GLfloat)Height / (GLfloat)Width, size*(GLfloat)Height / (GLfloat)Width, -size, size);
	//else
	//	glOrtho(-size * (GLfloat)Width / (GLfloat)Height, size*(GLfloat)Width / (GLfloat)Height, -size, size, -size, size);

	gluPerspective(45.0f, (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);
	//glMatrixMode(GL_MODELVIEW);
	//设置模型参数--几何体参数
	glMatrixMode(GL_MODELVIEW);
}
 
void keyPressed(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
		people.angle = 270;
		break;
	case 'a':
		people.angle = 0;
		break;
	case 's':
		people.angle = 90;
		break;
	case 'd':
		people.angle = 180;
		break;
	default:
		break;
	}
	people.initAngle();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);	
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
	glutInitWindowSize(1080, 768);
	glutInitWindowPosition(100,100);
	int window = glutCreateWindow("Stick man");
	glutDisplayFunc(&DisPlay);/* Register the function to do all our OpenGL drawing. */
	glutIdleFunc(&DisPlay);/* Even if there are no events, redraw our gl scene. */
	glutReshapeFunc(&ReSizeGLScene);/* Register the function called when our window is resized. */
	glutKeyboardFunc(&keyPressed);
	people.InitGL(640, 480);
	glutMainLoop();
	return 0;
}