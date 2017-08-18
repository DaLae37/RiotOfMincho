#pragma once
#include "ZeroIScene.h"
#include "ZeroSceneManager.h"
#include "menuScene.h"
class endScene :
	public ZeroIScene
{
public:
	endScene(int what);
	~endScene();
	void Render();
	void Update(float eTime);
};

