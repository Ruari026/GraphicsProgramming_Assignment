#pragma once
#include "Component.h"

#include "InputManager.h";
#include "SceneManager.h"

#include <glm/glm.hpp>

class BallController : public Component
{
public:
	BallController(GameObject* parent);
	void Update();

private:
	void RespawnBall();
	void ChangeScene();

	const float respawnHeight = -25.0f;
	glm::vec3 respawnPos = glm::vec3(0.0f, 5.0f, 0.0f);

	InputManager* inputManager;
	SceneManager* sceneManager;
};