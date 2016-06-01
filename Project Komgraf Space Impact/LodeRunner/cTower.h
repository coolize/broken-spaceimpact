#pragma once
#include "GameObject.h"
#include "Globals.h"
#include "cGame.h"

class cTower : public GameObject
{
protected:
	float x, y, angle;	
public:
	cTower();
	~cTower();

	virtual void Init() override;
	virtual void Update(float tpf = 0.0333) override;
	virtual void Render() override;

	virtual void ReadKeyboard(unsigned char key, int x, int y, bool press) override;
	virtual void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press) override;
	virtual void ReadMouse(int button, int state, int x, int y) override;
	virtual void ReadPassiveMotion(int x, int y) override;
	
};

