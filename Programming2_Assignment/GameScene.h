#pragma once

#include "Display.h"

#include "Component.h"
#include "AudioPlayer.h"
#include "BoxCollider.h"
#include "camera.h"
#include "PhysicsHandler.h"
#include "FontRenderer.h"
#include "MeshMovement.h"
#include "MeshRenderer.h"
#include "SphereCollider.h"
#include "SkyboxRenderer.h"
#include "ExplosionHandler.h"

#include "GameObject.h"

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