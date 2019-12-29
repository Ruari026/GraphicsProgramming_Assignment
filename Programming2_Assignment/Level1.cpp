#include "Level1.h"

Level1::Level1(Display* _gameDisplay) : GameScene(_gameDisplay)
{
	// Camera
	GameObject* cameraGameObject = new GameObject(this);
	sceneCamera = cameraGameObject->addComponent<Camera>();
	sceneCamera->Init(70.0f, (_gameDisplay->getWidth() / _gameDisplay->getHeight()), 0.01f, 1000.0f);
	cameraGameObject->thisTransform->SetGlobalPos(glm::vec3(0.0f, 7.0f, -22.5f));

	// Player Ball
	GameObject* theBall = new PlayerBall(this);
	sceneGameObjects.push_back(theBall);
	theBall->thisTransform->SetGlobalPos(glm::vec3(3.0f, 2.0f, -4.0f));
	theBall->thisTransform->SetGlobalRot(glm::vec3(0.0, 0.0f, 0.0f));

	// Environment - Platforms
	GameObject* basePlatform = new Platform(this); // Middle Flat Platform
	sceneGameObjects.push_back(basePlatform);
	basePlatform->thisTransform->SetGlobalPos(glm::vec3(0.0f, 1.0f, 0.0f));
	basePlatform->thisTransform->SetGlobalRot(glm::vec3(0.0f, 0.0f, 0.0f));
	
	GameObject* newPlatform = new Platform(this); // Left Tilted Platform
	sceneGameObjects.push_back(newPlatform);
	newPlatform->thisTransform->SetGlobalPos(glm::vec3(4.0f, 1.0f, 0.0f));
	newPlatform->thisTransform->SetGlobalRot(glm::vec3(0.0f, 0.0f, 0.0f));
	newPlatform->thisTransform->SetParent(basePlatform->thisTransform);

	newPlatform = new Platform(this); // Left Tilted Platform
	sceneGameObjects.push_back(newPlatform);
	newPlatform->thisTransform->SetGlobalPos(glm::vec3(-4.0f, 1.0f, 0.0f));
	newPlatform->thisTransform->SetGlobalRot(glm::vec3(0.0f, 0.0f, 0.0f));
	newPlatform->thisTransform->SetParent(basePlatform->thisTransform);


	newPlatform = new Platform(this); // Middle Flat Platform
	sceneGameObjects.push_back(newPlatform);
	newPlatform->thisTransform->SetGlobalPos(glm::vec3(0.0f, 1.0f, 4.0f));
	newPlatform->thisTransform->SetGlobalRot(glm::vec3(0.0f, 0.0f, 0.0f));
	newPlatform->thisTransform->SetParent(basePlatform->thisTransform);

	newPlatform = new Platform(this); // Left Tilted Platform
	sceneGameObjects.push_back(newPlatform);
	newPlatform->thisTransform->SetGlobalPos(glm::vec3(4.0f, 1.0f, 4.0f));
	newPlatform->thisTransform->SetGlobalRot(glm::vec3(0.0f, 0.0f, 0.0f));
	newPlatform->thisTransform->SetParent(basePlatform->thisTransform);

	newPlatform = new Platform(this); // Left Tilted Platform
	sceneGameObjects.push_back(newPlatform);
	newPlatform->thisTransform->SetGlobalPos(glm::vec3(-4.0f, 1.0f, 4.0f));
	newPlatform->thisTransform->SetGlobalRot(glm::vec3(0.0f, 0.0f, 0.0f));
	newPlatform->thisTransform->SetParent(basePlatform->thisTransform);


	newPlatform = new Platform(this); // Middle Flat Platform
	sceneGameObjects.push_back(newPlatform);
	newPlatform->thisTransform->SetGlobalPos(glm::vec3(0.0f, 1.0f, -4.0f));
	newPlatform->thisTransform->SetGlobalRot(glm::vec3(0.0f, 0.0f, 0.0f));
	newPlatform->thisTransform->SetParent(basePlatform->thisTransform);

	newPlatform = new Platform(this); // Left Tilted Platform
	sceneGameObjects.push_back(newPlatform);
	newPlatform->thisTransform->SetGlobalPos(glm::vec3(4.0f, 1.0f, -4.0f));
	newPlatform->thisTransform->SetGlobalRot(glm::vec3(0.0f, 0.0f, 0.0f));
	newPlatform->thisTransform->SetParent(basePlatform->thisTransform);

	newPlatform = new Platform(this); // Left Tilted Platform
	sceneGameObjects.push_back(newPlatform);
	newPlatform->thisTransform->SetGlobalPos(glm::vec3(-4.0f, 1.0f, -4.0f));
	newPlatform->thisTransform->SetGlobalRot(glm::vec3(0.0f, 0.0f, 0.0f));
	newPlatform->thisTransform->SetParent(basePlatform->thisTransform);

	// Environment - Fences
	GameObject* newFence = new Fence(this); // Left Tilted Platform
	sceneGameObjects.push_back(newFence);
	newFence->thisTransform->SetGlobalPos(glm::vec3(-4.0f - 1.725f, 1.6f, -4.0f));
	newFence->thisTransform->SetGlobalRot(glm::vec3(0.0f, 0.0f, 0.0f));
	newFence->thisTransform->SetParent(basePlatform->thisTransform);
}