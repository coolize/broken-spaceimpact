// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#pragma warning(disable:4996)
#include "Globals.h"
#include "cGame.h"
#include "cMenuScene.h"

GLuint img_id[2];

cGame::cGame(void)
{
}

cGame::~cGame(void)
{
}

bool cGame::Init()
{
	//Graphics initialization
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	visible_area.left = 0;
	visible_area.right = GAME_WIDTH;
	visible_area.bottom = 0;
	visible_area.top = GAME_HEIGHT;

	glOrtho(visible_area.left, visible_area.right, visible_area.bottom, visible_area.top, 3, -101);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_ALPHA_TEST);
	glEnable(GL_DEPTH_TEST);

	//Texture initialization
	if (!cAssetManager::getInstance().Load())printf("Some images may missing");

	//Stage initialization
	active_scene = new cMenuScene();
	
	return true;
}

bool cGame::Loop()
{
	
	int t1, t2;
	t1 = glutGet(GLUT_ELAPSED_TIME);

	if (bIsFirst) {//only call once for init on active_scene
		bIsFirst = false;
		active_scene->Init();
	}
	Update();
	Render();

	if (bSceneValid == false) {
		RealUpdateScene();
	}

	do {
		t2 = glutGet(GLUT_ELAPSED_TIME);
	} while (t2 - t1 < 1000 / 30);   //30 fps = 1000/30

	return true;
}

//Input
void cGame::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	active_scene->ReadKeyboard(key, x, y, press);//call ReadKeyboard on active scene to receive input on scene
}

void cGame::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
	active_scene->ReadSpecialKeyboard(key, x, y, press);//call Read SpecialKeyboard on active scene to receive special key
}

void cGame::ReadMouse(int button, int state, int x, int y)
{
	active_scene->ReadMouse(button, state, x, y);
}

bool cGame::Update(float tpf/*=0.0333*/)
{
	active_scene->Update(tpf);
	return true;
}


void cGame::Reshape(int w, int h) {
	glViewport(0, 0, w, h);
}

//Output
void cGame::Render()
{
	int tex_w, tex_h;
	int tex_w2, tex_h2;
	bool run = true;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	active_scene->Render();

	//glEnable(GL_BLEND);			   // Turn Blending On
	////glDisable(GL_DEPTH_TEST);    // Turn Depth Testing Off
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glDisable(GL_BLEND);          // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glAlphaFunc(GL_GREATER, 0.05f);

	
	glutSwapBuffers();
}



void cGame::renderBackgroud(int BGID) {
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, img_id[BGID]);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 1); glVertex3i(0, 0, 100);
	glTexCoord2f(1, 1); glVertex3i(GAME_WIDTH, 0, 100);
	glTexCoord2f(1, 0); glVertex3i(GAME_WIDTH, GAME_HEIGHT, 100);
	glTexCoord2f(0, 0); glVertex3i(0, GAME_HEIGHT, 100);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

bool cGame::loadTexture(char *filepath, int identifier) {
	int img_width, img_height = 0;
	corona::Image *img = corona::OpenImage(filepath);

	if (img) {
		img = ConvertImage(img, corona::PF_R8G8B8A8);

		img_width = img->getWidth();
		img_height = img->getHeight();

		glGenTextures(1, &img_id[identifier]);
		glBindTexture(GL_TEXTURE_2D, img_id[identifier]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img_width, img_height, 0, GL_RGBA, GL_UNSIGNED_BYTE
			, img->getPixels());
	}
	return true;
}

void cGame::loadImage(char *filepath, int BGID)
{
		if (!cGame::loadTexture(filepath, BGID)) {
			printf("Error Load Background Image");
		}
}

void cGame::UpdateScene(cScene *scene)
{
	bSceneValid = false;
	next_scene = &(*scene);
}

void cGame::RealUpdateScene()
{
	bSceneValid = true;
	bIsFirst = true;
	active_scene = &(*next_scene);
}
