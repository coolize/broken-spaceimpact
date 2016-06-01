// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#include "cEnemy.h"
#include "cGame.h"



cEnemy::cEnemy()
{
}


cEnemy::~cEnemy()
{
}

void cEnemy::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, enemySheet->at(animControl->Index())->Texture());
	glBegin(GL_QUADS);
	glTexCoord2f(enemySheet->at(animControl->Index())->X0(), enemySheet->at(animControl->Index())->Y1());	glVertex3i(x, y, 49);
	glTexCoord2f(enemySheet->at(animControl->Index())->X1(), enemySheet->at(animControl->Index())->Y1());	glVertex3i(x + Width(), y, 49);
	glTexCoord2f(enemySheet->at(animControl->Index())->X1(), enemySheet->at(animControl->Index())->Y0());	glVertex3i(x + Width(), y + Height(), 49);
	glTexCoord2f(enemySheet->at(animControl->Index())->X0(), enemySheet->at(animControl->Index())->Y0());	glVertex3i(x, y + Height(), 49);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void cEnemy::Init()
{
	animControl = new cAnimControl();
	animControl->AddAnim("NoLoop", "idle", 23, 23, 0.2f);
}

void cEnemy::Update(float tpf /*= 0.0333*/)
{
	animControl->UpdateAnim(tpf);
	if (animControl->ActiveName() != "idle")
		animControl->SetActiveAnim("idle");
}

