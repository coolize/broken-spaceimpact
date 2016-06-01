// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#include "cPlayer.h"
#include "cGame.h"



cPlayer::cPlayer()
{
}


cPlayer::~cPlayer()
{
}

void cPlayer::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, playerSheet->at(animControl->Index())->Texture());
	glBegin(GL_QUADS);

	glTexCoord2f(playerSheet->at(animControl->Index())->X0(), playerSheet->at(animControl->Index())->Y1());	glVertex3i(x, y, 49);
	glTexCoord2f(playerSheet->at(animControl->Index())->X1(), playerSheet->at(animControl->Index())->Y1());	glVertex3i(x + Width(), y, 49);
	glTexCoord2f(playerSheet->at(animControl->Index())->X1(), playerSheet->at(animControl->Index())->Y0());	glVertex3i(x + Width(), y + Height(), 49);
	glTexCoord2f(playerSheet->at(animControl->Index())->X0(), playerSheet->at(animControl->Index())->Y0());	glVertex3i(x, y + Height(), 49);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void cPlayer::Init()
{
	animControl = new cAnimControl();
	animControl->AddAnim("NoLoop", "walk_forward", 9, 16, 0.2f);
	animControl->AddAnim("NoLoopBackward", "walk_backward", 7, 0, 0.2f);
	animControl->AddAnim("NoLoop", "idle", 8, 8, 0.2f);
}

void cPlayer::Update(float tpf /*= 0.0333*/)
{
	animControl->UpdateAnim(tpf);

	if (keys['D'] || keys['d'])
	{
		if (animControl->ActiveName() != "walk_forward")
			animControl->SetActiveAnim("walk_forward");
	}
	else if (keys['A'] || keys['a'])
	{
		if (animControl->ActiveName() != "walk_backward")
			animControl->SetActiveAnim("walk_backward");
	}
	else
	{
		if (animControl->ActiveName() != "idle")
			animControl->SetActiveAnim("idle");
	}

	if (keys['W'] || keys['w']) {
		if (y <= GAME_HEIGHT-32) {
			y += 10 * unitpersec;
		}
	}
	else if (keys['A'] || keys['a']) {
		if (x > 8) {
			x -= 10 * unitpersec;
		}
	}
	else if (keys['S'] || keys['s']) {
		if (y > 8) {
			y -= 10 * unitpersec;
		}
	}
	else if (keys['D'] || keys['d']) {
		if (x <= GAME_WIDTH-40){
			x += 10 * unitpersec;
		}
	}
}

void cPlayer::ReadKeyboard(unsigned char key, int x, int y, bool press)
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

void cPlayer::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
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

void cPlayer::ReadMouse(int button, int state, int x, int y)
{

}
