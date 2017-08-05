#pragma once
#include <conio.h>
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include "Player.h"
#include "UI.h"
class mainScene :
	public ZeroIScene
{
public:
	mainScene();
	~mainScene();
	void Render();
	void Update(float eTime);
	ZeroSprite *Background;
	Player *p1;
	Player *p2;
	UI *ui;
};

