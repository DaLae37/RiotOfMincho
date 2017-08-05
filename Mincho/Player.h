#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
enum class STATUE {
	MOVE,
	ATACK,
	NONE,
};
class Player :
	public ZeroIScene
{
public:
	Player(int playerNum);
	~Player();
	ZeroSprite *player;
	int playerNum;
	int qeek;
	bool playerDo[2];
	bool isInputDone();
	int inputStackX[2];
	int inputStackY[2];
	STATUE statue[2];
	void Render();
	void Update(float eTime);
	void CheckInput();
	void Result();
};

