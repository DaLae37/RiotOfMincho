#include "stdafx.h"
#include "endScene.h"


endScene::endScene(int what)
{
}


endScene::~endScene()
{
}

void endScene::Update(float eTime) {
	ZeroIScene::Update(eTime);
	ZeroSceneMgr->ChangeScene(new menuScene);
}

void endScene::Render() {
	ZeroIScene::Render();
}