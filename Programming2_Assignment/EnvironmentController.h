#pragma once
#include "Component.h"

#include "InputManager.h"
#include "Time.h"

#include <glm/glm.hpp>

class EnvironmentController : public Component
{
public:
	EnvironmentController(GameObject* parent);

	void Update();

private:
	const float rotationSpeed = (3.14f / 4.0f);
	const float rotationLimit = (3.14f / 8.0f);

	InputManager* inputManager;
};