// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#pragma once
#include "Globals.h"

class cScene
{
protected:

public:
	cScene();
	~cScene();
	/**
	method that will be called first and only once when 
	*/
	virtual void Init() = 0;

	/**
	method that will be called each frame, use this to update the scene/game logic
	*/
	virtual void Update(float tpf = 0.0333) = 0;

	/**
	method that will be called each frame after update been 
	*/
	virtual void Render() = 0;
	
	/**
	Read normal keyboard input such as [a...z], this method been called from cGame
	*/
	virtual void ReadKeyboard(unsigned char key, int x, int y, bool press) = 0;

	/**
	Read special keyboard input such as ctrl, this method been called from cGame
	*/
	virtual void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press) = 0;

	/**
	Read mouse input, this method been called from cGame
	*/
	virtual void ReadMouse(int button, int state, int x, int y) = 0;

	/**
	Render String Example
	*/
	void renderBitmapString(
		float x,
		float y,
		float z,
		void *font,
		const char *string,
		float r,
		float g,
		float b) {

		glColor3f(r, g, b);
		const char *c;
		glRasterPos3f(x, y, z);
		for (c = string; *c != '\0'; c++) {
			glutBitmapCharacter(font, *c);
		}
		glColor3f(1.0f, 1.0f, 1.0f);

	}
};

