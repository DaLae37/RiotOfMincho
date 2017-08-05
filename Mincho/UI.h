#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
class UI :
	public ZeroIScene
{
public:
	ZeroSprite *character[3];
	ZeroSprite *player1;
	ZeroSprite *player2;
	ZeroSprite *player1Heart[3];
	ZeroSprite *player2Heart[3];
	int player1Index;
	int player2Index;
	UI();
	~UI();
	void Render();
	void Update(float eTime);
};

