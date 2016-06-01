// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#pragma once
#include "Globals.h"
#include "cSprite.h"
#include "cAnimation.h"
#include "cAnimControl.h"

class cPlayer
{
private:
	cAnimControl *animControl;
	std::vector<cSprite*> *playerSheet;
	float x, y;
	int width, height;
	bool keys[255];
public:
	cPlayer(std::vector<cSprite*> *playerSheet, float x, float y, int width, int height)
		:playerSheet(playerSheet), x(x), y(y), width(width), height(height) {}
	cPlayer();
	~cPlayer();

	virtual void Render();
	virtual void Init();
	virtual void Update(float tpf = 0.0333);
	virtual void ReadKeyboard(unsigned char key, int x, int y, bool press);
	virtual void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press);
	virtual void ReadMouse(int button, int state, int x, int y);

	int Height() const { return height; }
	void Height(int val) { height = val; }
	int Width() const { return width; }
	void Width(int val) { width = val; }
	float X() const { return x; }
	void X(float val) { x = val; }
	float Y() { return y; }
	void Y(float val) { y = val; }
};

