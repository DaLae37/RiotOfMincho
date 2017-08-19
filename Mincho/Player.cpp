#include "stdafx.h"
#include "Player.h"
#include <iostream>
Player::Player(int playerNum)
{
	this->playerNum = playerNum;
	qeek = 0;
	hp = 3;
	for (int i = 0; i < 4; i++) {
		player[i] = new ZeroSprite("Resource/Player/%d.png", i);
	}
	for (int i = 0; i < 2; i++) {
		inputStackX[i] = 0;
		inputStackY[i] = 0;
		playerDo[i] = false;
		statue[i] = STATUE::NONE;
	}
	spawnPos.first = rand() % 5;
	spawnPos.second = rand() % 5;
	if (playerNum == 1) {
		mode = 3;
		player[mode]->SetPos(280 + spawnPos.first * MAP_SIZE, 240 + spawnPos.second * MAP_SIZE);
		pos.first = 0 + spawnPos.first;
		pos.second = 5 + spawnPos.second;
	}
	else if (playerNum == 2) {
		mode = 2;
		player[mode]->SetPos(952 - spawnPos.first * MAP_SIZE, 240 + spawnPos.second * MAP_SIZE);
		pos.first = 14 - spawnPos.first;
		pos.second = 5 + spawnPos.second;
	}
	tmpPos.first = pos.first;
	tmpPos.second = pos.second;
	printf("%d %d\n", tmpPos.first, tmpPos.second);
}

Player::~Player()
{
}

void Player::Render() {
	ZeroIScene::Render();
	player[mode]->Render();
}

void Player::Update(float eTime) {
	ZeroIScene::Update(eTime);
}

void Player::CheckInput() {
	if (playerNum == 1) {
		if (qeek <= 1) {
			//player1 move
			if ((ZeroInputMgr->GetKey('W') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('w') == INPUTMGR_KEYDOWN) && Check(0,-1)) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = -1;
				tmpPos.second -= 1;
				printf("p1 pos = %d %d\n", tmpPos.first, tmpPos.second);
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			else if ((ZeroInputMgr->GetKey('A') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('a') == INPUTMGR_KEYDOWN) && Check(-1, 0)) {
				inputStackX[qeek] = -1;
				inputStackY[qeek] = 0;
				tmpPos.first -= 1;
				printf("p1 pos = %d %d\n", tmpPos.first, tmpPos.second);
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			else if ((ZeroInputMgr->GetKey('S') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('s') == INPUTMGR_KEYDOWN) && Check(0, 1)) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = 1;
				tmpPos.second += 1;
				printf("p1 pos = %d %d\n", tmpPos.first, tmpPos.second);
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			else if ((ZeroInputMgr->GetKey('D') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('d') == INPUTMGR_KEYDOWN) && Check(1, 0)) {
				inputStackX[qeek] = 1;
				inputStackY[qeek] = 0;
				tmpPos.first += 1;
				printf("p1 pos = %d %d\n", tmpPos.first, tmpPos.second);
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			//player1 attack
			else if (ZeroInputMgr->GetKey('T') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('t') == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = -1;
				printf("%d : player1InputAttack\n", qeek);
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey('F') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('f') == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = -1;
				inputStackY[qeek] = 0;
				printf("%d : player1InputAttack\n", qeek);
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey('G') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('g') == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = 1;
				printf("%d : player1InputAttack\n", qeek);
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey('H') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('h') == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 1;
				inputStackY[qeek] = 0;
				printf("%d : player1InputAttack\n", qeek);
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			//player1 Hold
			else if (ZeroInputMgr->GetKey('C') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('c') == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = 0;
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
		}
	}
	else {
		if (qeek <= 1) {
			//player2 move
			if (ZeroInputMgr->GetKey(VK_UP) == INPUTMGR_KEYDOWN && Check(0, -1)) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = -1;
				tmpPos.second -= 1;
				printf("p2 pos = %d %d\n", tmpPos.first, tmpPos.second);
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey(VK_LEFT) == INPUTMGR_KEYDOWN && Check(-1, 0)) {
				inputStackX[qeek] = -1;
				inputStackY[qeek] = 0;
				tmpPos.first -= 1;
				printf("p2 pos = %d %d\n", tmpPos.first, tmpPos.second);
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey(VK_DOWN) == INPUTMGR_KEYDOWN && Check(0, 1)) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = 1;
				tmpPos.second += 1;
				printf("p2 pos = %d %d\n", tmpPos.first, tmpPos.second);
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey(VK_RIGHT) == INPUTMGR_KEYDOWN && Check(1, 0)) {
				inputStackX[qeek] = 1;
				inputStackY[qeek] = 0;
				tmpPos.first += 1;
				printf("p2 pos = %d %d\n", tmpPos.first, tmpPos.second);
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			//player2 attack
			else if (ZeroInputMgr->GetKey(VK_HOME) == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = -1;
				printf("%d : player2InputAttack\n", qeek);
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey(VK_DELETE) == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = -1;
				inputStackY[qeek] = 0;
				printf("%d : player2InputAttack\n", qeek);
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey(VK_END) == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = 1;
				printf("%d : player2InputAttack\n", qeek);
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey(VK_NEXT) == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 1;
				inputStackY[qeek] = 0;
				printf("%d : player2InputAttack\n", qeek);
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			//player2 Hold
			else if (ZeroInputMgr->GetKey(VK_CONTROL) == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = 0;
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
		}
	}
}

bool Player::isInputDone() {
	return playerDo[0] && playerDo[1];
}

bool Player::Check(int x, int y) {
	if ((new Def)->map[x + tmpPos.first][y + tmpPos.second] && x + tmpPos.first <=14 && x + tmpPos.first >= 0 && y + tmpPos.second <= 14 && y + tmpPos.second >= 0) {
		printf("¤¡¤º");
		return true;
	}
	else {
		printf("¤¤¤¤");
		return false;
	}
}