#include "stdafx.h"
#include "Player.h"

Player::Player(int playerNum)
{
	this->playerNum = playerNum;
	qeek = 0;
	player = new ZeroSprite("Resource/Player/Player.png");
	for (int i = 0; i < 2; i++) {
		inputStackX[i] = 0;
		inputStackY[i] = 0;
		playerDo[i] = false;
		statue[i] = STATUE::NONE;
	}
	if (playerNum == 1) {
		player->SetPos(280, 240);
	}
	else if (playerNum == 2) {
		player->SetPos(900, 240);
	}
}

Player::~Player()
{
}

void Player::Render() {
	ZeroIScene::Render();
	player->Render();
}

void Player::Update(float eTime) {
	ZeroIScene::Update(eTime);
}

void Player::CheckInput() {
	if (playerNum == 1) {
		if (qeek <= 1) {
			//player1 move
			if (ZeroInputMgr->GetKey('W') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('w') == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = 1;
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey('A') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('a') == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = -1;
				inputStackY[qeek] = 0;
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey('S') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('s') == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = -1;
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey('D') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('d') == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 1;
				inputStackY[qeek] = 0;
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			//player1 attack
			else if (ZeroInputMgr->GetKey('T') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('t') == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = 1;
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey('F') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('f') == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = -1;
				inputStackY[qeek] = 0;
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey('G') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('g') == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = -1;
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey('H') == INPUTMGR_KEYDOWN || ZeroInputMgr->GetKey('h') == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 1;
				inputStackY[qeek] = 0;
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
			if (ZeroInputMgr->GetKey(VK_UP) == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = 1;
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey(VK_LEFT) == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = -1;
				inputStackY[qeek] = 0;
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey(VK_DOWN) == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = -1;
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey(VK_RIGHT) == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 1;
				inputStackY[qeek] = 0;
				statue[qeek] = STATUE::MOVE;
				playerDo[qeek++] = true;
			}
			//player2 attack
			else if (ZeroInputMgr->GetKey(VK_HOME) == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = 1;
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey(VK_DELETE) == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = -1;
				inputStackY[qeek] = 0;
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey(VK_END) == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 0;
				inputStackY[qeek] = -1;
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			else if (ZeroInputMgr->GetKey(SB_PAGEDOWN) == INPUTMGR_KEYDOWN) {
				inputStackX[qeek] = 1;
				inputStackY[qeek] = 0;
				statue[qeek] = STATUE::ATACK;
				playerDo[qeek++] = true;
			}
			//player2 Hold
			else if (ZeroInputMgr->GetKey(VK_RCONTROL) == INPUTMGR_KEYDOWN) {
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

void Player::Result() {
	for (int i = 0; i < 2; i++) {
		if (statue[i] == STATUE::ATACK) {

		}
		else if (statue[i] == STATUE::MOVE) {

		}
	}
}