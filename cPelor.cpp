#include "cPelor.h"
#include "cGame.h"
#include "cPlayer.h"

cPelor::cPelor()
{
}


cPelor::~cPelor()
{
}

void cPelor::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, bulletSheet->at(animControl->Index())->Texture());
	glBegin(GL_QUADS);
	glTexCoord2f(bulletSheet->at(animControl->Index())->X0(), bulletSheet->at(animControl->Index())->Y1());	glVertex3i(x, y, 50);
	glTexCoord2f(bulletSheet->at(animControl->Index())->X1(), bulletSheet->at(animControl->Index())->Y1());	glVertex3i(x + Width(), y, 50);
	glTexCoord2f(bulletSheet->at(animControl->Index())->X1(), bulletSheet->at(animControl->Index())->Y0());	glVertex3i(x + Width(), y + Height(), 50);
	glTexCoord2f(bulletSheet->at(animControl->Index())->X0(), bulletSheet->at(animControl->Index())->Y0());	glVertex3i(x, y + Height(), 50);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void cPelor::Init()
{
	animControl = new cAnimControl();
	animControl->AddAnim("NoLoop", "bullet_forward", 0, 0, 0.2f);
}

void cPelor::Update(float tpf)
{
	animControl->UpdateAnim(tpf);
	if (keys[32]) {
		if (
			animControl->ActiveName() != "bullet_forward")
			animControl->SetActiveAnim("bullet_forward");
		}

	if (y < GAME_HEIGHT && y>0) {
		y += 15 * unitpersec;
	}
	//TODO: sepertinya ngebug disini , pelurunya tetep maju biarpun tembus viewport , kalo didiemin lama dia abort() langsung crash

}

void cPelor::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	if (press)
	{
		keys[key] = true;
	}
	else
	{
		keys[key] = false;
	}
}

void cPelor::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
	if (press)
	{
		keys[key] = true;
	}
	else
	{
		keys[key] = false;
	}
}

void cPelor::ReadMouse(int button, int state, int x, int y)
{

}

void cPelor::sety(int y)
{
	this->y = y;
}

void cPelor::setx(int x)
{
	this->x = x;
}
