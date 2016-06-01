// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#pragma once
#include "Globals.h"
#include "cScene.h"
#include "cPlayer.h"
#include "cRect.h"
#include "cGame.h"
#include "cPelor.h"
#include "cEnemy.h"
#define TOTAL_TILE_Y 18
#define TOTAL_TILE_X 1000
#define TILE_SIZE 32
#define TEXTURE_TILE_SIZE 32


class cLevel1Scene:public cScene
{
public:
	cLevel1Scene();
	~cLevel1Scene();
	cPelor *pelor0;
	cPelor *pelor1;
	cPlayer *player;
	cEnemy *enemy;
	cGame lv1;
	virtual void Render();

	virtual void Init();

	virtual void Update(float tpf = 0.0333);

	virtual void ReadKeyboard(unsigned char key, int x, int y, bool press);

	virtual void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press);

	virtual void ReadMouse(int button, int state, int x, int y);


private:
	bool keys[255];
};


