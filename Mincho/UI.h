#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "Def.h"
class UI :
	public ZeroIScene
{
public:
	ZeroSprite *character[3];
	ZeroSprite *player1;
	ZeroSprite *player2;
	ZeroSprite *player1Heart[3];
	ZeroSprite *player2Heart[3];
	ZeroSprite *CircleP1[2][2];
	ZeroSprite *CircleP2[2][2];
	ZeroSprite *Tile[15][15];
	bool P1isDone[2];
	bool P2isDone[2];
	bool player1HeartRender[3];
	bool player2HeartRender[3];
	int player1Index;
	int player2Index;
	UI();
	~UI();
	void Render();
	void Update(float eTime);
};

