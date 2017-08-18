#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "mainScene.h"
#include "ZeroSceneManager.h"
#include "ZeroInputManager.h"
class menuScene : public ZeroIScene
{
public:
	menuScene();
	~menuScene();
	void Update(float eTime);
	void Render();
	bool onStartButtonClick;
	bool onEndButtonClick;
	ZeroSprite *background;
	ZeroSprite *startGame[2];
	ZeroSprite *endGame[2];
};

