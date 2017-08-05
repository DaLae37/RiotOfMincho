#include "stdafx.h"
#include "UI.h"

UI::UI()
{
	player1Index = 0;
	player2Index = 1;
	player1 = new ZeroSprite("Resource/UI/player1.png");
	player1->SetPos(0, 20);
	PushScene(player1);
	player2 = new ZeroSprite("Resource/UI/player2.png");
	player2->SetPos(1000, 20);
	PushScene(player2);
	for (int i = 0; i < 3; i++) {
		player1Heart[i] = new ZeroSprite("Resource/UI/Heart.png");
		player1Heart[i]->SetPos(i * 95, 115);
		player2Heart[i] = new ZeroSprite("Resource/UI/Heart.png");
		player2Heart[i]->SetPos(1000 + i * 95, 115);
		character[i] = new ZeroSprite("Resource/UI/Character%d.png", i+1);
	}
}

UI::~UI()
{
}

void UI::Render() {
	ZeroIScene::Render();
	player1->Render();
	player2->Render();
	for (int i = 0; i < 3; i++) {
		if (player1Index == i) {
			character[player1Index]->SetPos(5,210);
			character[player1Index]->Render();
		}
		else if (player2Index == i) {
			character[player2Index]->SetPos(1005,210);
			character[player2Index]->Render();
		}
		player1Heart[i]->Render();
		player2Heart[i]->Render();
	}
}

void UI::Update(float eTime) {
	ZeroIScene::Update(eTime);
}