#include "BallController.h"

#include "GameObject.h"

BallController::BallController(GameObject* parent) : Component(parent)
{
	inputManager = InputManager::Instance();
	sceneManager = SceneManager::Instance();
}


void BallController::Update()
{
	RespawnBall();

	ChangeScene();
}


void BallController::RespawnBall()
{
	glm::vec3 ballPosition = *gameObject->thisTransform->GetGlobalPos();
	if (ballPosition.y < respawnHeight)
	{
		// Moving the ball to it's start point
		gameObject->thisTransform->SetGlobalPos(respawnPos);

		// Removing any movement forces on the ball
		PhysicsHandler* physics = gameObject->getComponent<PhysicsHandler>();
		physics->SetVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
	}
}


void BallController::ChangeScene()
{
	if (inputManager->IsKeyPressedDown(SDLK_1))
	{
		sceneManager->LoadScene("Level1");
	}
	else if (inputManager->IsKeyPressedDown(SDLK_2))
	{
		sceneManager->LoadScene("Level2");
	}
}