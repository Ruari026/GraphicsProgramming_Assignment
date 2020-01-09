#include "EnvironmentController.h"

#include "GameObject.h"

EnvironmentController::EnvironmentController(GameObject* parent) : Component(parent)
{
	inputManager = InputManager::Instance();
}

void EnvironmentController::Update()
{
	// Environment's Start Rotation
	glm::vec3 environmentRotation = *gameObject->thisTransform->GetGlobalRotEuler();


	// Changing rotation based on user input
	// Vertical input
	if (inputManager->IsKeyPressedDown(SDLK_w))
	{
		environmentRotation.x += (rotationSpeed * Time::GetDeltaTime());
	}
	else if (inputManager->IsKeyPressedDown(SDLK_s))
	{
		environmentRotation.x -= (rotationSpeed * Time::GetDeltaTime());
	}
	// Horizontal input
	if (inputManager->IsKeyPressedDown(SDLK_d))
	{
		environmentRotation.z += (rotationSpeed * Time::GetDeltaTime());
	}
	else if (inputManager->IsKeyPressedDown(SDLK_a))
	{
		environmentRotation.z -= (rotationSpeed * Time::GetDeltaTime());
	}


	// Constraining rotation
	// Constraining x axis
	if (environmentRotation.x > rotationLimit)
	{
		environmentRotation.x = rotationLimit;
	}
	else if (environmentRotation.x < -rotationLimit)
	{
		environmentRotation.x = -rotationLimit;
	}
	// Constraining z axis
	if (environmentRotation.z > rotationLimit)
	{
		environmentRotation.z = rotationLimit;
	}
	else if (environmentRotation.z < -rotationLimit)
	{
		environmentRotation.z = -rotationLimit;
	}


	// Setting environment's new rotation
	gameObject->thisTransform->SetGlobalRot(environmentRotation);
}