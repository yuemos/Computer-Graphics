// Ray_Casting.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <GL/glut.h>
float Image[WIDTH*HEIGTH * 4];

//显示函数
void Mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(WIDTH, HEIGTH, GL_RGBA, GL_FLOAT, Image);//使用OpenGL的绘图函数
	glFlush();
}

int main(int argc, char **argv)
{
	int Dim[3] = { 200,200,200 };//体数据大小
	int *Data = (int *)malloc(sizeof(int)*Dim[0] * Dim[1] * Dim[2]);
	float *CData = (float*)malloc(sizeof(float)*Dim[0] * Dim[1] * Dim[2] * 4);
	float R[9];//旋转矩阵
	float T[3] = { 0,0,450 };//平移向量（要根据R调整，以保证获得体数据全貌）
	float eye[3] = { 0.5,0.5,1 };//视点位置
	float center[3] = { 0,0,0 };//物体参考点位置
	float up[3] = { 0,1,0 };//相机朝上的方向
	RotationMatrix(R, eye, center, up);//获得旋转矩阵
	CreateVolume(Data, Dim);//生成原始体数据
	Classify(CData, Data, Dim);//对体数据分类
	float *LinePS = Image;
	for (int j = 0; j < HEIGTH; j++)//逐个合成像素值
	{
		for (int i = 0; i < WIDTH; i++)
		{
			Composite(LinePS, i, j, CData, Dim, R, T);
			LinePS += 4;
		}
	}
	free(Data);
	free(CData);
	//使用OpenGL显示此二维图像
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Ray-Casting");
	glClearColor(1, 1, 1, 1);//背景设为白色
	glutDisplayFunc(Mydisplay);//显示图像
	glutMainLoop();
}

