#pragma once
#include <conio.h>
#include <time.h>
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include "ZeroSceneManager.h"
#include "endScene.h"
#include "Player.h"
#include "UI.h"
#include "Def.h"
#include <utility>

class mainScene :
	public ZeroIScene
{
public:
	mainScene();
	~mainScene();
	void Render();
	void Update(float eTime);
	void Result();
	void Result1(Player *pl);
	void Result2(Player *pl);
	float delayTime;
	int peek;
	bool delayOn;
	bool firstIsfirst;
	bool attackSignal;
	ZeroSprite *Background;
	ZeroSprite *redZone;
	Player *p1;
	Player *p2;
	UI *ui;
};

