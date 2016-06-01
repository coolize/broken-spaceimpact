// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#include "cMenuScene.h"
#include "cLevel1Scene.h"
#include "cGame.h"
#include "cSound.h"

cMenuScene::cMenuScene()
{

}

cMenuScene::~cMenuScene()

{

}

void cMenuScene::Init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	visible_area.top = GAME_HEIGHT;
	visible_area.bottom = 0;
	visible_area.left = 0;
	visible_area.right = GAME_WIDTH;
	glOrtho(visible_area.left, visible_area.right, visible_area.bottom, visible_area.top, 3, -101);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	cSound::getInstance().Play(SOUND_AMBIENT1);
}

void cMenuScene::Update(float tpf /*= 0.0333*/)
{
	cSound::getInstance().Update();
}


void cMenuScene::Render()
{
	menu.loadImage("Assets/bgMenu.png", 0);
	menu.renderBackgroud(0);
	renderBitmapString(149, 440, 0, GLUT_BITMAP_HELVETICA_18, "DDemonstar", 1, 1, 1);
	renderBitmapString(95, 120, 0, GLUT_BITMAP_HELVETICA_18, "Press Enter to Start Game", 1, 1, 1);
	renderBitmapString(67, 100, 0, GLUT_BITMAP_HELVETICA_10, "How To Play : Press [W/A/S/D] Key to Move, and [ESC] to", 1, 1, 1);
	renderBitmapString(153, 80, 0, GLUT_BITMAP_HELVETICA_10, "Back to Main Menu", 1, 1, 1);
	renderBitmapString(4, 5, 0, GLUT_BITMAP_HELVETICA_12, "High Score : 200", 1, 1, 1);
	renderBitmapString(314, 5, 0, GLUT_BITMAP_HELVETICA_12, "Sound(M) : On", 1, 1, 1);
}

void cMenuScene::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	printf("Normal key: %d\n", key);
	if (press)
	{
		keys[key] = true;
	}
	else
	{
		keys[key] = false;
	}

	if (key == 13) {
		cGame::getInstance().UpdateScene(new cLevel1Scene());
	}

	if (key == 'm') {
		cSound::getInstance().StopAll();
	}
}

void cMenuScene::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
	printf("Special key: %d", key);
	if (press)
	{
		keys[key] = true;
	}
	else
	{
		keys[key] = false;
	}
	if (key == 13) {
		cGame::getInstance().UpdateScene(new cLevel1Scene()); //press Enter di keyboard == 13
		cSound::getInstance().Play(SOUND_AMBIENT1);
	}
}


void cMenuScene::ReadMouse(int button, int state, int x, int y)
{
}
