#include "stdafx.h"
#include "mainScene.h"
#include <stdio.h>

mainScene::mainScene() :
	firstIsfirst(true),
	delayOn(true),
	peek(0),
	attackSignal(false)
{
	srand(time(NULL));
	Background = new ZeroSprite("Resource/Background/Background.png");
	redZone = new ZeroSprite("Resource/Background/redZone.png");
	p1 = new Player(1);
	p2 = new Player(2);
	ui = new UI();
	delayTime = 0.0f;
}


mainScene::~mainScene()
{
}

void mainScene::Render() {
	ZeroIScene::Render();
	Background->Render();
	ui->Render();
	if (attackSignal)
		redZone->Render();
	p1->Render();
	p2->Render();
}

void mainScene::Update(float eTime) {
	ZeroIScene::Update(eTime);
	if (delayOn)
		delayTime += eTime;
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
	else if (delayOn && delayTime >= 1.0f){
		Result();
	}
}

void mainScene::Result() {
	if (firstIsfirst) {
		switch (peek)
		{
		case 0:
			Result1(p1);
			break;
		case 1:
			Result1(p2);
			break;
		case 2:
			Result2(p1);
			break;
		case 3:
			Result2(p2);
			break;
		}
	}
	else {
		switch (peek)
		{
		case 0:
			Result1(p2);
			break;
		case 1:
			Result1(p1);
			break;
		case 2:
			Result1(p2);
			break;
		case 3:
			Result2(p1);
			break;
		}
	}
	if (peek == 4) {
		p1->qeek = 0;
		p2->qeek = 0;
		for (int i = 0; i < 2; i++) {
			p1->playerDo[i] = false;
			p2->playerDo[i] = false;
		}
		firstIsfirst = !firstIsfirst;
		peek = 0;
	}
}

void mainScene::Result1(Player *pl) {
	delayTime = 0.0f;
	delayOn = false;
	attackSignal = false;
	printf("statue : %d\n", pl->statue[0]);
	if (pl->statue[0] == STATUE::MOVE) {
		if (pl->inputStackX[0] == 1) {
			pl->mode = 3;
		}
		else if (pl->inputStackX[0] == -1) {
			pl->mode = 2;
		}
		else if (pl->inputStackY[0] == 1) {
			pl->mode = 1;
		}
		else if (pl->inputStackY[0] == -1) {
			pl->mode = 0;
		}
		pl->player[pl->mode]->AddPos(pl->inputStackX[0] * MAP_SIZE, pl->inputStackY[0] * MAP_SIZE);
		pl->pos.first += pl->inputStackX[0];
		pl->pos.second += pl->inputStackY[0];
	}
	else if (pl->statue[0] == STATUE::ATACK) {
		attackSignal = true;
		redZone->SetPos(pl->player[pl->mode]->Pos().x + pl->inputStackX[0] * MAP_SIZE, pl->player[pl->mode]->Pos().y + pl->inputStackY[0] * MAP_SIZE);
		if (pl->playerNum == 1) {
			if (p2->pos.first == p1->pos.first + p1->inputStackX[0] && p2->pos.second == p1->pos.second + p1->inputStackY[0]) {
				ui->player2HeartRender[--p2->hp] = false;
				if (p2->hp <= 0) {
					ZeroSceneMgr->ChangeScene(new endScene(1));
					return;
				}

				printf("%d", p2->hp);
				printf("p1Attack\n");
			}
		}
		else {
			if (p1->pos.first == p2->pos.first + p2->inputStackX[0] && p1->pos.second == p2->pos.second + p2->inputStackY[0]) {
				ui->player1HeartRender[--p1->hp] = false;
				if (p1->hp <= 0) {
					ZeroSceneMgr->ChangeScene(new endScene(2));
					return;
				}
				printf("%d", p1->hp);
				printf("p2Attack\n");
			}
		}
		printf("p1 : %d %d p2 : %d %d\n", p1->pos.first, p1->pos.second, p2->pos.first, p2->pos.second);
	}
	for (int i = 0; i < 4; i++) {
		if (!(i == p1->mode))
			p1->player[i]->SetPos(p1->player[p1->mode]->Pos());
		if (!(i == p2->mode))
			p2->player[i]->SetPos(p2->player[p2->mode]->Pos());
	}
	delayOn = true;
	peek++;
}

void mainScene::Result2(Player *pl) {
	attackSignal = false;
	delayTime = 0.0f;
	delayOn = false;
	printf("statue : %d\n", pl->statue[1]);
	if (pl->statue[1] == STATUE::MOVE) {
		if (pl->inputStackX[1] == 1) {
			pl->mode = 3;
		}
		else if (pl->inputStackX[1] == -1) {
			pl->mode = 2;
		}
		else if (pl->inputStackY[1] == 1) {
			pl->mode = 1;
		}
		else if (pl->inputStackY[1] == -1) {
			pl->mode = 0;
		}
		pl->player[pl->mode]->AddPos(pl->inputStackX[1] * MAP_SIZE, pl->inputStackY[1] * MAP_SIZE);
		pl->pos.first += pl->inputStackX[1];
		pl->pos.second += pl->inputStackY[1];
	}
	else if (pl->statue[1] == STATUE::ATACK) {
		attackSignal = true;
		redZone->SetPos(pl->player[pl->mode]->Pos().x + pl->inputStackX[1] * MAP_SIZE, pl->player[pl->mode]->Pos().y + pl->inputStackY[1] * MAP_SIZE);
		if (pl->playerNum == 1) {
			if (p2->pos.first == p1->pos.first + p1->inputStackX[1] && p2->pos.second == p1->pos.second + p1->inputStackY[1]) {
				ui->player2HeartRender[--p2->hp] = false;
				if (p2->hp <= 0) {
					ZeroSceneMgr->ChangeScene(new endScene(1));
					return;
				}
				printf("%d", p2->hp);
				printf("p2Attack\n");
			}
		}
		else {
			if (p1->pos.first == p2->pos.first + p2->inputStackX[1] && p1->pos.second == p2->pos.second + p2->inputStackY[1]) {
				ui->player1HeartRender[--p1->hp] = false;
				if (p1->hp <= 0) {
					ZeroSceneMgr->ChangeScene(new endScene(2));
					return;
				}
				printf("%d", p1->hp);
				printf("p1Attack\n");
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (!(i == p1->mode))
			p1->player[i]->SetPos(p1->player[p1->mode]->Pos());
		if (!(i == p2->mode))
			p2->player[i]->SetPos(p2->player[p2->mode]->Pos());
	}
	delayOn = true;
	peek++;
}