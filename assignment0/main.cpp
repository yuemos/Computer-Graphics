#include "openGL_work0.h"
using namespace std;
//模型路径
string filePath = "teapot.obj";

//相机
Ternary<float> camera;

ObjLoader objModel = ObjLoader(filePath);

//初始化
void init() {
	camera.x = -20;
	camera.y = 30;
	camera.z = 20;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("ObjLoader");

	//材质反光性设置
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };  //镜面反射参数
	GLfloat mat_shininess[] = { 50.0 };               //高光指数
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };   //灯位置(1,1,1), 最后1-开关
	GLfloat Light_Model_Ambient[] = { 0.2, 0.2, 0.2, 1.0 }; //环境光参数

	glClearColor(0.0, 0.0, 0.0, 0.0);  //背景色
	glShadeModel(GL_SMOOTH);           //多变性填充模式

									   //材质属性
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	//灯光设置
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);   //散射光属性
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);  //镜面反射光
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Light_Model_Ambient);  //环境光参数

	glEnable(GL_LIGHTING);   //开关:使用光
	glEnable(GL_LIGHT0);     //打开0#灯
	glEnable(GL_DEPTH_TEST); //打开深度测试
}

void Draw() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//开始绘制
	for (int i = 0; i < objModel.obj_surface.size(); i++) {
		glBegin(GL_TRIANGLES);

		Ternary<float> normal = objModel.obj_normal[objModel.obj_surface[i].normal.x - 1];
		glNormal3f(normal.x, normal.y, normal.z);
		Ternary<float> texture = objModel.obj_texture[objModel.obj_surface[i].texture.x - 1];
		glTexCoord3f(texture.x, texture.y, texture.z);
		Ternary<float> vertex = objModel.obj_vertexe[objModel.obj_surface[i].vertex.x - 1];
		glVertex3f(vertex.x, vertex.y, vertex.z);

		normal = objModel.obj_normal[objModel.obj_surface[i].normal.y - 1];
		glNormal3f(normal.x, normal.y, normal.z);
		texture = objModel.obj_texture[objModel.obj_surface[i].texture.y - 1];
		glTexCoord3f(texture.x, texture.y, texture.z);
		vertex = objModel.obj_vertexe[objModel.obj_surface[i].vertex.y - 1];
		glVertex3f(vertex.x, vertex.y, vertex.z);

		normal = objModel.obj_normal[objModel.obj_surface[i].normal.z - 1];
		glNormal3f(normal.x, normal.y, normal.z);
		texture = objModel.obj_texture[objModel.obj_surface[i].texture.z - 1];
		glTexCoord3f(texture.x, texture.y, texture.z);
		vertex = objModel.obj_vertexe[objModel.obj_surface[i].vertex.z - 1];
		glVertex3f(vertex.x, vertex.y, vertex.z);

		glEnd();
	}
	glFlush();
}

void reshape(int w, int h)
{
	float size = 80;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-size, size, -size * (GLfloat)h / (GLfloat)w, size*(GLfloat)h / (GLfloat)w, -size, size);
	else
		glOrtho(-size * (GLfloat)w / (GLfloat)h, size*(GLfloat)w / (GLfloat)h, -size, size, -size, size);

	//设置模型参数--几何体参数
	gluLookAt(camera.x, camera.y, camera.z, 0, 20, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

float past_x, past_y;
int get_pos = 0;




default_random_engine e;
uniform_real_distribution<double> u(0, 1);
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

		glColor3f(u(e), u(e), u(e));
		Draw();
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		get_pos = 1;
		past_x = x;
		past_y = y;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		get_pos = 0;
	}

}
void mouse_move(int x, int y)
{
	float speed = 0.3;
	if (get_pos == 1)
	{
		glRotatef(speed*(x - past_x), 0, 1, 0);
		glRotatef(speed*(y - past_y), 1, 0, 0);
		Draw();
		past_x = x;
		past_y = y;
	}
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	init();	
	glEnable(GL_COLOR_MATERIAL);
	glutDisplayFunc(&Draw);
	glutReshapeFunc(&reshape);
	glutMouseFunc(&mouse);
	glutMotionFunc(&mouse_move);
	glutMainLoop();
	return 0;
}