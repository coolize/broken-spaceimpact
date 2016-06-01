#pragma once
#include "cPlayer.h"
#include "Globals.h"
#include "cSprite.h"
#include "cAnimation.h"
#include "cAnimControl.h"

class cPelor : public cPlayer
{
private:
	cAnimControl *animControl;
	std::vector<cSprite*> *bulletSheet;
	float x, y,xinv,yinv;
	int width, height;
	bool keys[255];
public:
	cPelor(std::vector<cSprite*> *bulletSheet, float x, float y, int width, int height)
		:bulletSheet(bulletSheet), x(x), y(y), width(width), height(height) {}
	cPelor();
	~cPelor();

	virtual void Render() override;
	virtual void Init() override;
	virtual void Update(float tpf = 0.0333) override;
	virtual void ReadKeyboard(unsigned char key, int x, int y, bool press) override;
	virtual void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press) override;
	virtual void ReadMouse(int button, int state, int x, int y) override;
	void sety(int y);
	void setx(int x);

	int Height() const { return height; }
	void Height(int val) { height = val; }
	int Width() const { return width; }
	void Width(int val) { width = val; }
	float X() const { return x; }
	void X(float val) { x = val; }
	float Y() const { return y; }
	void Y(float val) { y = val; }
};

