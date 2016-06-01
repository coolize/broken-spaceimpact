// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#pragma once
#include "Globals.h"
#include "cSprite.h"
#include "cAnimation.h"
#include "cAnimControl.h"

class cEnemy
{
private:
	cAnimControl *animControl;
	std::vector<cSprite*> *enemySheet;
	float x, y;
	int width, height;
	bool keys[255];
public:
	cEnemy(std::vector<cSprite*> *enemySheet, float x, float y, int width, int height)
		:enemySheet(enemySheet), x(x), y(y), width(width), height(height) {}
	cEnemy();
	~cEnemy();

	virtual void Render();
	virtual void Init();
	virtual void Update(float tpf = 0.0333);


	int Height() const { return height; }
	void Height(int val) { height = val; }
	int Width() const { return width; }
	void Width(int val) { width = val; }
	float X() const { return x; }
	void X(float val) { x = val; }
	float Y() { return y; }
	void Y(float val) { y = val; }
};

