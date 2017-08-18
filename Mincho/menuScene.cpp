#include "stdafx.h"
#include "menuScene.h"


menuScene::menuScene()
{
	background = new ZeroSprite("Resource/Background/mainBackground.png");
	endGame[0] = new ZeroSprite("Resource/Background/endGame.png");
	endGame[1] = new ZeroSprite("Resource/Background/onendGame.png");
	startGame[0] = new ZeroSprite("Resource/Background/startGame.png");
	startGame[1] = new ZeroSprite("Resource/Background/onstartGame.png");
	for (int i = 0; i < 2; i++) {
		endGame[i]->SetPos(600, 300);
		startGame[i]->SetPos(600,100);
	}
	onStartButtonClick = false;
	onEndButtonClick = false;
}


menuScene::~menuScene()
{
}

void menuScene::Update(float eTime) {
	ZeroIScene::Update(eTime);
	if (onEndButtonClick) {
		if (!endGame[1]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			onEndButtonClick = false;
	}
	if (onStartButtonClick) {
		if (!startGame[1]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			onStartButtonClick = false;
	}
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN) {
		if (endGame[0]->IsOverlapped(ZeroInputMgr->GetClientPoint())) {
			onEndButtonClick = true;
		}
		if (startGame[0]->IsOverlapped(ZeroInputMgr->GetClientPoint())) {
			onStartButtonClick = true;
		}
	}
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP) {
		if (endGame[1]->IsOverlapped(ZeroInputMgr->GetClientPoint())) {
			exit(0);
		}
		if (startGame[1]->IsOverlapped(ZeroInputMgr->GetClientPoint())) {
			ZeroSceneMgr->ChangeScene(new mainScene);
		}
	}
}

void menuScene::Render() {
	ZeroIScene::Render();
	background->Render();
	if (!onEndButtonClick)
		endGame[0]->Render();
	else
		endGame[1]->Render();
	if (!onStartButtonClick)
		startGame[0]->Render();
	else
		startGame[1]->Render();
}