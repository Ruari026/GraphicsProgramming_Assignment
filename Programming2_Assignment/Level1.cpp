#include "Level1.h"

Level1::Level1(Display* _gameDisplay) : GameScene(_gameDisplay)
{
	// Camera
	GameObject* cameraGameObject = new GameObject(this);
	sceneCamera = cameraGameObject->addComponent<Camera>();
	sceneCamera->Init(70.0f, (_gameDisplay->getWidth() / _gameDisplay->getHeight()), 0.01f, 1000.0f);
	cameraGameObject->thisTransform->SetGlobalPos(glm::vec3(0.0f, 5.0f, -10.0f));


	// Camera Mount
	GameObject* mountGameObject = new GameObject(this);
	sceneGameObjects.push_back(mountGameObject);
	mountGameObject->thisTransform->SetGlobalPos(glm::vec3(0.0f, 0.0f, 0.0f));

	CameraMount* cameraMount = mountGameObject->addComponent<CameraMount>();
	cameraGameObject->thisTransform->SetParent(mountGameObject->thisTransform);

	// Environment - Controller Anchor
	GameObject* anchorParent = new GameObject(this);
	sceneGameObjects.push_back(anchorParent);
	anchorParent->addComponent<EnvironmentController>();

	// Environment - Starting Platform
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			GameObject* newPlatform = new Platform(this); // Left Tilted Platform
			sceneGameObjects.push_back(newPlatform);
			newPlatform->thisTransform->SetParent(anchorParent->thisTransform);

			glm::vec3 newTransform;
			newTransform.x = ((i * 2) - 4) * 2;
			newTransform.z = ((j * 2) - 4) * 2;

			newPlatform->thisTransform->SetLocalPos(newTransform);
		}
	}


	// Player Ball
	GameObject* theBall = new PlayerBall(this);
	sceneGameObjects.push_back(theBall);
	theBall->thisTransform->SetGlobalPos(glm::vec3(0.0f, 10.0f, 0.0f));
	cameraMount->SetFollowTarget(theBall);
}