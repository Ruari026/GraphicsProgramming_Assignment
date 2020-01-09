#pragma once

#include "Display.h"

#include "Component.h"
#include "BallController.h"
#include "BoxCollider.h"
#include "camera.h"
#include "CameraMount.h"
#include "EnvironmentController.h"
#include "PhysicsHandler.h"
#include "FontRenderer.h"
#include "MeshRenderer.h"
#include "SphereCollider.h"

#include "GameObject.h"
#include "EndPlate.h"
#include "Fence.h"
#include "Platform.h"
#include "PlayerBall.h"
#include "StartPlate.h"
#include "Well.h"

class GameScene
{
public:
	GameScene();
	~GameScene();

	void RunScene();

	Camera* GetSceneCamera();
	vector<BoxCollider*> GetSceneColliders();

protected:
	Camera* sceneCamera;
	vector<GameObject*> sceneGameObjects;
};