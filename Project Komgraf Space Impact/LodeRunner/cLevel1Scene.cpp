// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#include "cLevel1Scene.h"
#include "cAssetManager.h"
#include "cGame.h"
#include "cMenuScene.h"
#include "cSound.h"
#pragma warning(disable:4996)

cLevel1Scene::cLevel1Scene()
{

}

cLevel1Scene::~cLevel1Scene()
{
}

void cLevel1Scene::Init()
{
	player = new cPlayer(cAssetManager::getInstance().player, (GAME_WIDTH/2)-(TILE_SIZE/2), 30, TILE_SIZE, TILE_SIZE);
	pelor0 = new cPelor(cAssetManager::getInstance().pelor, (GAME_WIDTH / 2) - (TILE_SIZE / 2), 30, TILE_SIZE, TILE_SIZE);
	pelor1 = new cPelor(cAssetManager::getInstance().pelor, (GAME_WIDTH / 2) - (TILE_SIZE / 2), 30, TILE_SIZE, TILE_SIZE);
	enemy = new cEnemy(cAssetManager::getInstance().enemy, (GAME_WIDTH / 2) - (TILE_SIZE / 2), 30, TILE_SIZE, TILE_SIZE);
	cSound::getInstance().Play(SOUND_AMBIENT2);
	player->Init();
	pelor0->Init();
	pelor1->Init();
	enemy->Init();
}

void cLevel1Scene::Render()
{
	lv1.loadImage("Assets/bg.png", 0);
	lv1.renderBackgroud(0);
	player->Render();
	pelor0->Render();
	pelor1->Render();
	enemy->Render();
	renderBitmapString(165, 5, 9, GLUT_BITMAP_HELVETICA_18, "Wave : 1", 1, 1, 1);
	renderBitmapString(260, 5, 9, GLUT_BITMAP_HELVETICA_18, "Lv : 1", 1, 1, 1);
	renderBitmapString(330, 5, 9, GLUT_BITMAP_HELVETICA_18, "HP : 15", 1, 1, 1);
}



void cLevel1Scene::Update(float tpf /*= 0.0333*/)
{
	cSound::getInstance().Update();
	pelor0->Update();
	pelor1->Update();
	player->Update();
	enemy->Update();
}
int flag = 1;
void cLevel1Scene::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	player->ReadKeyboard(key, x, y, press);
	pelor0->ReadKeyboard(key, x, y, press);
	pelor1->ReadKeyboard(key, x, y, press);

	if (keys[32]) {
		flag++;
		//TODO : BIKIN 2 DETIK DELAY TIAP PELOR
		if (flag%2==0) {
			pelor0->sety(player->Y());
			pelor0->setx(player->X());
			puts("0");
		}
		else {
			pelor1->sety(player->Y());
			pelor1->setx(player->X());
			puts("1");
		}
	}
	if (press)
	{
		keys[key] = true;
	}
	else
	{
		keys[key] = false;
	}
	if (key == 27) {
		cGame::getInstance().UpdateScene(new cMenuScene());
	}
}

void cLevel1Scene::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
	player->ReadSpecialKeyboard(key, x, y, press);
	pelor0->ReadSpecialKeyboard(key, x, y, press);
	pelor1->ReadSpecialKeyboard(key, x, y, press);
	if (press)
	{
		keys[key] = true;
	}
	else
	{
		keys[key] = false;
	}
}

void cLevel1Scene::ReadMouse(int button, int state, int x, int y)
{
	player->ReadMouse(button, state, x, y);

}

