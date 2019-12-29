#pragma once

#include "Display.h"
#include "camera.h"

#include "GameObject.h"
#include "Platform.h"
#include "PlayerBall.h"
#include "Fence.h"

class GameScene
{
public:
	GameScene(Display* _GameDisplay);

	void RunScene();

	Camera* GetSceneCamera();
	vector<BoxCollider*> GetSceneColliders();

protected:
	Camera* sceneCamera;
	vector<GameObject*> sceneGameObjects;
};