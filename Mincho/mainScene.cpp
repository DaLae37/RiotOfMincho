#include "stdafx.h"
#include "mainScene.h"
#include <stdio.h>

mainScene::mainScene() :
	firstIsfirst(true)
{
	srand(time(NULL));
	Background = new ZeroSprite("Resource/Background/Background.png");
	p1 = new Player(1);
	p2 = new Player(2);
	ui = new UI();
}


mainScene::~mainScene()
{
}

void mainScene::Render() {
	ZeroIScene::Render();
	Background->Render();
	p1->Render();
	p2->Render();
	ui->Render();
}

void mainScene::Update(float eTime) {
	ZeroIScene::Update(eTime);
	for (int i = 0; i < 2; i++) {
		ui->P1isDone[i] = p1->playerDo[i];
		ui->P2isDone[i] = p2->playerDo[i];
	}
	if (!p1->isInputDone() || !p2->isInputDone()) {
		if (ZeroInputMgr->AnyKeyDown()) {
			p1->CheckInput();
			p2->CheckInput();
		}
	}
	else {
		Result();
	}
}

void mainScene::Result() {
	p1->qeek = 0;
	p2->qeek = 0;
	if (firstIsfirst) {
		Result1(p1);
		Result1(p2);
		Result2(p1);
		Result2(p2);
	}
	else {
		Result1(p2);
		Result1(p1);
		Result2(p2);
		Result2(p1);
	}
	for (int i = 0; i < 2; i++) {
		p1->playerDo[i] = false;
		p2->playerDo[i] = false;
	}
	firstIsfirst = !firstIsfirst;
}

void mainScene::Result1(Player *pl) {
	if (pl->statue[0] == STATUE::MOVE) {
		pl->player->AddPos(pl->inputStackX[0] * MAP_SIZE, pl->inputStackY[0] * MAP_SIZE);
	}
	else if (pl->statue[0] == STATUE::ATACK) {
		if (pl->playerNum == 1) {
			if (p1->pos.first == p2->pos.first + p1->inputStackX[0] && p1->pos.second == p2->pos.second + p1->inputStackY[0]) {
				ui->player2HeartRender[p2->hp--] = false;
				printf("p1Attack\n");
			}
		}
		else {
			if (p2->pos.first == p1->pos.first + p2->inputStackX[0] && p2->pos.second == p1->pos.second + p2->inputStackY[0]) {
				ui->player1HeartRender[p1->hp--] = false;
				printf("p2Attack\n");
			}
		}
		printf("p1 : %d %d p2 : %d %d\n", p1->pos.first, p1->pos.second, p2->pos.first, p2->pos.second);
	}
}

void mainScene::Result2(Player *pl) {
	if (pl->statue[1] == STATUE::MOVE) {
		pl->player->AddPos(pl->inputStackX[1] * MAP_SIZE, pl->inputStackY[1] * MAP_SIZE);
	}
	else if (pl->statue[1] == STATUE::ATACK) {
		if (pl->playerNum == 1) {
			if (p1->pos.first == p2->pos.first + p1->inputStackX[1] && p1->pos.second == p2->pos.second + p1->inputStackY[1]) {
				ui->player2HeartRender[p2->hp--] = false;
				printf("p2Attack\n");
			}
		}
		else {
			if (p2->pos.first == p1->pos.first + p2->inputStackX[1] && p2->pos.second == p1->pos.second + p2->inputStackY[1]) {
				ui->player1HeartRender[p1->hp--] = false;
				printf("p1Attack\n");
			}
		}
	}
}