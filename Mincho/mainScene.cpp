#include "stdafx.h"
#include "mainScene.h"


mainScene::mainScene()
{
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
	if (ZeroInputMgr->AnyKeyDown())
		if (!p1->isInputDone())
			p1->CheckInput();
		else if (!p2->isInputDone())
			p2->CheckInput();
}