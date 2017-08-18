#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include <utility>
#include "Def.h"

class Player :
	public ZeroIScene
{
public:
	Player(int playerNum);
	~Player();
	ZeroSprite *player[2];
	int playerNum;
	int qeek;
	int hp;
	bool playerDo[2];
	bool isInputDone();
	pair<int, int> pos;
	pair<int, int> tmpPos;
	pair<int, int> spawnPos;
	int inputStackX[2];
	int inputStackY[2];
	STATUE statue[2];
	void Render();
	void Update(float eTime);
	void CheckInput();
	bool Check(int x, int y);
};

