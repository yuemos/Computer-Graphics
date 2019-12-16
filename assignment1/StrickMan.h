#pragma once

#include <Windows.h>
#include <GL/gl.h>  
#include <GL/glu.h>  
#include <GL/glut.h> 
#include <vector>
#include <string>
#include <random>
#include <sstream>
#include <fstream>
#include <cstdio>  
#include <iostream>

class Ternary {
public:
	float x, y, z;
	Ternary(float a, float b, float c) {
		x = a;
		y = b;
		z = c;
	}
};

class People {
public:
	float angleoflarma,//���۸첲��ת���ٶ�
		angleoflarmb, //��С�۸첲��ת���ٶ�
		angleofrarma, //�Ҵ�۸첲��ת���ٶ�
		angleofrarmb, //��С�۸첲��ת���ٶ�
		angleofllegb, //����ȸ첲��ת���ٶ�
		angleofrlegb, //��С�ȸ첲��ת���ٶ�
		angleofllega, //�Ҵ��ȸ첲��ת���ٶ�
		angleofrlega = 0;//��С�ȸ첲��ת���ٶ�
	float la, ra, ll, rl = 0;
	float a = 0.2,
		b = 0.1,
		angle = 0;
	const float angle1 = 0.2;
	const float angle2 = 0.1;
	void initAngle();
	void InitGL(int Width, int Height);
	void DrawBody();
	void DrawShoulder();
	void DrawHip();
	void DrawArmA();
	void DrawArmB();
	void DrawLegA();
	void DrawLegB();
	void DrawHead();
	void DrawNeck();
};