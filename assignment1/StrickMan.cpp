#include "StrickMan.h"
#include <iostream>

using namespace std;

void People::InitGL(int Width, int Height) {



	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//gluPerspective(45.0f, (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
}

void People::initAngle() {
	angleoflarma = 0;//左大臂胳膊旋转角速度
	angleoflarmb = 0; //左小臂胳膊旋转角速度
	angleofrarma = 0; //右大臂胳膊旋转角速度
	angleofrarmb = 0; //右小臂胳膊旋转角速度
	angleofllegb = 0; //左大腿胳膊旋转角速度
	angleofrlegb = 0; //左小腿胳膊旋转角速度
	angleofllega = 0; //右大腿胳膊旋转角速度
	angleofrlega = 0;//右小腿胳膊旋转角速度
	la = 0;
	ra = 0;
	ll = 0;
	rl = 0;
}

void People::DrawBody() {
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	//forward           
	glVertex3f(-0.5f, 1.0f, 0.25f);
	glVertex3f(0.5f, 1.0f, 0.25f);
	glVertex3f(0.5f, -1.0f, 0.25f);
	glVertex3f(-0.5f, -1.0f, 0.25f);
	//left  
	glVertex3f(0.5f, 1.0f, 0.25f);
	glVertex3f(0.5f, 1.0f, -0.25f);
	glVertex3f(0.5f, -1.0f, -0.25f);
	glVertex3f(0.5f, -1.0f, 0.25f);
	//back  
	glVertex3f(0.5f, 1.0f, -0.25f);
	glVertex3f(-0.5f, 1.0f, -0.25f);
	glVertex3f(-0.5f, -1.0f, -0.25f);
	glVertex3f(0.5f, -1.0f, -0.25f);
	//right  
	glVertex3f(-0.5f, 1.0f, 0.25f);
	glVertex3f(-0.5f, 1.0f, -0.25f);
	glVertex3f(-0.5f, -1.0f, -0.25f);
	glVertex3f(-0.5f, -1.0f, 0.25f);
	//top  
	glVertex3f(0.5f, 1.0f, 0.25f);
	glVertex3f(0.5f, 1.0f, -0.25f);
	glVertex3f(-0.5f, 1.0f, -0.25f);
	glVertex3f(-0.5f, 1.0f, 0.25f);
	//bottom  
	glVertex3f(0.5f, -1.0f, 0.25f);
	glVertex3f(0.5f, -1.0f, -0.25f);
	glVertex3f(-0.5f, -1.0f, -0.25f);
	glVertex3f(-0.5f, -1.0f, 0.25f);
	glEnd();
}
void People::DrawShoulder() {
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	//forward           
	glVertex3f(-1.0f, 0.2f, 0.25f);
	glVertex3f(1.0f, 0.2f, 0.25f);
	glVertex3f(1.0f, -0.2f, 0.25f);
	glVertex3f(-1.0f, -0.2f, 0.25f);
	//left  
	glVertex3f(1.0f, 0.2f, 0.25f);
	glVertex3f(1.0f, 0.2f, -0.25f);
	glVertex3f(1.0f, -0.2f, -0.25f);
	glVertex3f(1.0f, -0.2f, 0.25f);
	//back  
	glVertex3f(1.0f, 0.2f, -0.25f);
	glVertex3f(-1.0f, 0.2f, -0.25f);
	glVertex3f(-1.0f, -0.2f, -0.25f);
	glVertex3f(1.0f, -0.2f, -0.25f);
	//right  
	glVertex3f(-1.0f, 0.2f, 0.25f);
	glVertex3f(-1.0f, 0.2f, -0.25f);
	glVertex3f(-1.0f, -0.2f, -0.25f);
	glVertex3f(-1.0f, -0.2f, 0.25f);
	//top  
	glVertex3f(1.0f, 0.2f, 0.25f);
	glVertex3f(1.0f, 0.2f, -0.25f);
	glVertex3f(-1.0f, 0.2f, -0.25f);
	glVertex3f(-1.0f, 0.2f, 0.25f);
	//bottom  
	glVertex3f(1.0f, -0.2f, 0.25f);
	glVertex3f(1.0f, -0.2f, -0.25f);
	glVertex3f(-1.0f, -0.2f, -0.25f);
	glVertex3f(-1.0f, -0.2f, 0.25f);
	glEnd();
}
void People::DrawHip() {
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	//forward             
	glVertex3f(-0.7f, 0.2f, 0.25f);
	glVertex3f(0.7f, 0.2f, 0.25f);
	glVertex3f(0.7f, -0.2f, 0.25f);
	glVertex3f(-0.7f, -0.2f, 0.25f);
	//left  
	glVertex3f(0.7f, 0.2f, 0.25f);
	glVertex3f(0.7f, 0.2f, -0.25f);
	glVertex3f(0.7f, -0.2f, -0.25f);
	glVertex3f(0.7f, -0.2f, 0.25f);
	//back  
	glVertex3f(0.7f, 0.2f, -0.25f);
	glVertex3f(-0.7f, 0.2f, -0.25f);
	glVertex3f(-0.7f, -0.2f, -0.25f);
	glVertex3f(0.7f, -0.2f, -0.25f);
	//right  
	glVertex3f(-0.7f, 0.2f, 0.25f);
	glVertex3f(-0.7f, 0.2f, -0.25f);
	glVertex3f(-0.7f, -0.2f, -0.25f);
	glVertex3f(-0.7f, -0.2f, 0.25f);
	//top  
	glVertex3f(0.7f, 0.2f, 0.25f);
	glVertex3f(0.7f, 0.2f, -0.25f);
	glVertex3f(-0.7f, 0.2f, -0.25f);
	glVertex3f(-0.7f, 0.2f, 0.25f);
	//bottom  
	glVertex3f(0.7f, -0.2f, 0.25f);
	glVertex3f(0.7f, -0.2f, -0.25f);
	glVertex3f(-0.7f, -0.2f, -0.25f);
	glVertex3f(-0.7f, -0.2f, 0.25f);
	glEnd();
}
void People::DrawArmA() {
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);

	//forward           
	glVertex3f(-0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, -1.0f, 0.25f);
	glVertex3f(-0.2f, -1.0f, 0.25f);
	//left  
	glVertex3f(0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, 0.2f, -0.25f);
	glVertex3f(0.2f, -1.0f, -0.25f);
	glVertex3f(0.2f, -1.0f, 0.25f);
	//back  
	glVertex3f(0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, -1.0f, -0.25f);
	glVertex3f(0.2f, -1.0f, -0.25f);
	//right  
	glVertex3f(-0.2f, 0.2f, 0.25f);
	glVertex3f(-0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, -1.0f, -0.25f);
	glVertex3f(-0.2f, -1.0f, 0.25f);
	//top  
	glVertex3f(0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, 0.2f, 0.25f);
	//bottom  
	glVertex3f(0.2f, -0.2f, 0.25f);
	glVertex3f(0.2f, -0.2f, -0.25f);
	glVertex3f(-0.2f, -0.2f, -0.25f);
	glVertex3f(-0.2f, -0.2f, 0.25f);

	glEnd();
}
void People::DrawArmB() {
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);

	//forward           
	glVertex3f(-0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, -1.0f, 0.25f);
	glVertex3f(-0.2f, -1.0f, 0.25f);
	//left  
	glVertex3f(0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, 0.2f, -0.25f);
	glVertex3f(0.2f, -1.0f, -0.25f);
	glVertex3f(0.2f, -1.0f, 0.25f);
	//back  
	glVertex3f(0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, -1.0f, -0.25f);
	glVertex3f(0.2f, -1.0f, -0.25f);
	//right  
	glVertex3f(-0.2f, 0.2f, 0.25f);
	glVertex3f(-0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, -1.0f, -0.25f);
	glVertex3f(-0.2f, -1.0f, 0.25f);
	//top  
	glVertex3f(0.2f, 0.2f, 0.25f);
	glVertex3f(0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, 0.2f, -0.25f);
	glVertex3f(-0.2f, 0.2f, 0.25f);
	//bottom  
	glVertex3f(-0.2f, -1.0f, 0.25f);
	glVertex3f(0.2f, -1.0f, 0.25f);
	glVertex3f(0.2f, -1.0f, -0.25f);
	glVertex3f(-0.2f, -1.0f, -0.25f);
	glEnd();
}
void People::DrawLegB() {
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);

	//forward           
	glVertex3f(-0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, -1.25f, 0.255f);
	glVertex3f(-0.3f, -1.25f, 0.255f);
	//left  
	glVertex3f(0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, 0.25f, -0.255f);
	glVertex3f(0.3f, -1.25f, -0.255f);
	glVertex3f(0.3f, -1.25f, 0.255f);
	//back  
	glVertex3f(0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, -0.255f);
	glVertex3f(0.3f, -1.25f, -0.255f);
	//right  
	glVertex3f(-0.3f, 0.25f, 0.255f);
	glVertex3f(-0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, 0.255f);
	//top  
	glVertex3f(0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, 0.25f, 0.255f);
	//bottom  
	glVertex3f(0.3f, -1.25f, 0.255f);
	glVertex3f(0.3f, -1.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, 0.255f);

	glEnd();
}
void People::DrawLegA() {
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);

	//forward           
	glVertex3f(-0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, -1.25f, 0.255f);
	glVertex3f(-0.3f, -1.25f, 0.255f);
	//left  
	glVertex3f(0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, 0.25f, -0.255f);
	glVertex3f(0.3f, -1.25f, -0.255f);
	glVertex3f(0.3f, -1.25f, 0.255f);
	//back  
	glVertex3f(0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, -0.255f);
	glVertex3f(0.3f, -1.25f, -0.255f);
	//right  
	glVertex3f(-0.3f, 0.25f, 0.255f);
	glVertex3f(-0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, 0.255f);
	//top  
	glVertex3f(0.3f, 0.25f, 0.255f);
	glVertex3f(0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, 0.25f, -0.255f);
	glVertex3f(-0.3f, 0.25f, 0.255f);
	//bottom  
	glVertex3f(0.3f, -1.25f, 0.255f);
	glVertex3f(0.3f, -1.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, -0.255f);
	glVertex3f(-0.3f, -1.25f, 0.255f);

	glEnd();
}
void People::DrawHead() {
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);

	//forward           
	glVertex3f(-0.6f, 0.6f, 0.35f);
	glVertex3f(0.6f, 0.6f, 0.35f);
	glVertex3f(0.6f, -0.6f, 0.35f);
	glVertex3f(-0.6f, -0.6f, 0.35f);
	//left  
	glVertex3f(0.6f, 0.6f, 0.35f);
	glVertex3f(0.6f, 0.6f, -0.35f);
	glVertex3f(0.6f, -0.6f, -0.35f);
	glVertex3f(0.6f, -0.6f, 0.35f);
	//back  
	glVertex3f(0.6f, 0.6f, -0.35f);
	glVertex3f(-0.6f, 0.6f, -0.35f);
	glVertex3f(-0.6f, -0.6f, -0.35f);
	glVertex3f(0.6f, -0.6f, -0.35f);
	//right  
	glVertex3f(-0.6f, 0.6f, 0.35f);
	glVertex3f(-0.6f, 0.6f, -0.35f);
	glVertex3f(-0.6f, -0.6f, -0.35f);
	glVertex3f(-0.6f, -0.6f, 0.35f);
	//top  
	glVertex3f(0.6f, 0.6f, 0.35f);
	glVertex3f(0.6f, 0.6f, -0.35f);
	glVertex3f(-0.6f, 0.6f, -0.35f);
	glVertex3f(-0.6f, 0.6f, 0.35f);
	//bottom  
	glVertex3f(0.6f, -0.6f, 0.35f);
	glVertex3f(0.6f, -0.6f, -0.35f);
	glVertex3f(-0.6f, -0.6f, -0.35f);
	glVertex3f(-0.6f, -0.6f, 0.35f);
	glEnd();
}
void People::DrawNeck() {
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	//forward           
	glVertex3f(-0.2f, 0.1f, 0.25f);
	glVertex3f(0.2f, 0.1f, 0.25f);
	glVertex3f(0.2f, -0.1f, 0.25f);
	glVertex3f(-0.2f, -0.1f, 0.25f);
	//left  
	glVertex3f(0.2f, 0.1f, 0.25f);
	glVertex3f(0.2f, 0.1f, -0.25f);
	glVertex3f(0.2f, -0.1f, -0.25f);
	glVertex3f(0.2f, -0.1f, 0.25f);
	//back  
	glVertex3f(0.2f, 0.1f, -0.25f);
	glVertex3f(-0.2f, 0.1f, -0.25f);
	glVertex3f(-0.2f, -0.1f, -0.25f);
	glVertex3f(0.2f, -0.1f, -0.25f);
	//right  
	glVertex3f(-0.2f, 0.1f, 0.25f);
	glVertex3f(-0.2f, 0.1f, -0.25f);
	glVertex3f(-0.2f, -0.1f, -0.25f);
	glVertex3f(-0.2f, -0.1f, 0.25f);
	//top  
	glVertex3f(0.2f, 0.1f, 0.25f);
	glVertex3f(0.2f, 0.1f, -0.25f);
	glVertex3f(-0.2f, 0.1f, -0.25f);
	glVertex3f(-0.2f, 0.1f, 0.25f);
	//bottom  
	glVertex3f(0.2f, -0.1f, 0.25f);
	glVertex3f(0.2f, -0.1f, -0.25f);
	glVertex3f(-0.2f, -0.1f, -0.25f);
	glVertex3f(-0.2f, -0.1f, 0.25f);

	glEnd();
}


