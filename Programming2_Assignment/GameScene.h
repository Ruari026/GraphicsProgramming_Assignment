#pragma once

#include "Display.h"

#include "Component.h"
#include "BoxCollider.h"
#include "camera.h"
#include "CameraMount.h"
#include "EnvironmentController.h"
#include "PhysicsHandler.h"
#include "Renderer.h"
#include "SphereCollider.h"

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