// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#ifndef PCH_H
#define PCH_H

#define EPSILON 0.000001
#define WIDTH 400
#define HEIGTH 500

	void CreateVolume(int *Data, int* Dim);//生成体数据
	void CreateCube(int x, int y, int z, int side, int density, int *Data, int *Dim);//生成正方体数据
	void CreateSphere(int x, int y, int z, int radius, int density, int *Data, int *Dim);//生成球体数据
	void Classify(float* CData, int *Data, int *Dim);//数据分类
	void RotationMatrix(float *R, float *eye, float *center, float *up);//求取图像空间到物体空间变换的旋转矩阵
	void Composite(float *rgba, int x0, int y0, float *CData, int *Dim, float *R, float *T);//合成像素颜色值
	bool Intersection(float *startpos, float *pos, float *dir, int *Dim);//求光线与包围盒交点坐标
	void TrInterpolation(float *rgba, float *pos, float *CData, int *Dim);//三线性插值
	bool CheckinBox(float *point, int *Dim);//判断点是否在包围盒内
	void MatrixmulVec(float *c, float *a, float *b);//矩阵向量乘积
	void CrossProd(float *c, float *a, float *b);//向量叉乘	
	void Normalize(float *norm, float *a);//向量归一化

#endif //PCH_H
