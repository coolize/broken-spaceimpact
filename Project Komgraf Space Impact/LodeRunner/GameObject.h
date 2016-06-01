#pragma once
class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Init() = 0;
	virtual void Update(float tpf = 0.0333) = 0;
	virtual void Render() = 0;

	virtual void ReadKeyboard(unsigned char key, int x, int y, bool press) = 0;
	virtual void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press) = 0;
	virtual void ReadMouse(int button, int state, int x, int y) = 0;
	virtual void ReadPassiveMotion(int x, int y) = 0;


};

