#include "cTower.h"



cTower::cTower()
{
	x = GAME_WIDTH / 2;
	y = GAME_HEIGHT / 2;
}


cTower::~cTower()
{
}

void cTower::Init()
{
}

void cTower::Update(float tpf)
{
}

void cTower::Render()
{
	glLoadIdentity();
	//rotate ub arbitrary point (titik yang bukan titik 0)
	glTranslated(x, y, 3);
	glRotated(angle, 0, 0, 1);
	glTranslated(-x, -y, 3);
	glColor3f(.5f, .5f, .5f); //.5f = 0.5f
	glBegin(GL_QUADS);
	glVertex3f(x - 10, y - 5, 3); // kiri bawah
	glVertex3f(x + 10, y - 5, 3); // kanan bawah
	glVertex3f(x + 10, y + 5, 3); // kanan atas
	glVertex3f(x - 10, y + 5, 3); // kiri atas
	glEnd();
}

void cTower::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
}

void cTower::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
}

void cTower::ReadMouse(int button, int state, int x, int y)
{
}

void cTower::ReadPassiveMotion(int x, int y)
{
	y = GAME_HEIGHT - y;
	float dx = x - this->x;
	float dy = y - this->y;
	try {
		float tan = dy / dx;
		angle = atan(tan); //return radian
		//redian to degree
		angle = angle * 180.0f / (22.0f / 7.0f);
	}
	catch (int e) {};
}
