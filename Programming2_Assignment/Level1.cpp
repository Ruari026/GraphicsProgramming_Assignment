#include "Level1.h"

Level1::Level1() : GameScene()
{
	// Camera
	GameObject* cameraGameObject = new GameObject(this);
	sceneCamera = cameraGameObject->addComponent<Camera>();
	sceneCamera->Init(70.0f, (DISPLAY_WIDTH / DISPLAY_HEIGHT), 0.01f, 1000.0f);
	cameraGameObject->thisTransform->SetGlobalPos(glm::vec3(0.0f, 5.0f, -10.0f));


	// Camera Mount
	GameObject* mountGameObject = new GameObject(this);
	sceneGameObjects.push_back(mountGameObject);

	CameraMount* cameraMount = mountGameObject->addComponent<CameraMount>();
	cameraGameObject->thisTransform->SetParent(mountGameObject->thisTransform);
	mountGameObject->thisTransform->SetGlobalPos(glm::vec3(0.0f, 10.0f, 0.0f));


	// Environment - Controller Anchor
	GameObject* anchorParent = new GameObject(this);
	sceneGameObjects.push_back(anchorParent);
	anchorParent->addComponent<EnvironmentController>();


	// Environment - Starting Platform
	glm::vec3 environmentCenter = glm::vec3(0.0f, 0.0f, 12.0f);
	int environmentWidth = 3, environmentHeight = 8;
	for (int i = 0; i < environmentHeight; i++)
	{
		// Platform Ground
		for (int j = 0; j < environmentWidth; j++)
		{
			Platform* newPlatform = new Platform(this);
			sceneGameObjects.push_back(newPlatform);
			newPlatform->thisTransform->SetParent(anchorParent->thisTransform);

			glm::vec3 platformPosition = environmentCenter;
			platformPosition.x += ((j * 2) - (environmentWidth - 1)) * 2;
			platformPosition.z += ((i * 2) - (environmentHeight - 1)) * 2;

			newPlatform->thisTransform->SetLocalPos(platformPosition);
		}


		// Platform Fence Walls
		Fence* leftFence = new Fence(this);
		sceneGameObjects.push_back(leftFence);
		leftFence->thisTransform->SetParent(anchorParent->thisTransform);

		glm::vec3 fencePos = environmentCenter;
		fencePos.x += (environmentWidth / 2) * 5.75f;
		fencePos.y += 0.6f;
		fencePos.z += ((i * 2) - (environmentHeight - 1)) * 2;
		leftFence->thisTransform->SetLocalPos(fencePos);


		Fence* rightFence = new Fence(this);
		sceneGameObjects.push_back(rightFence);
		rightFence->thisTransform->SetParent(anchorParent->thisTransform);

		fencePos = environmentCenter;
		fencePos.x += (-environmentWidth / 2) * 5.75f;
		fencePos.y += 0.6f;
		fencePos.z += ((i * 2) - (environmentHeight - 1)) * 2;
		rightFence->thisTransform->SetLocalPos(fencePos);
	}
	

	// Environment - Start Point
	StartPlate* startPoint = new StartPlate(this);
	sceneGameObjects.push_back(startPoint);
	startPoint->thisTransform->SetParent(anchorParent->thisTransform);
	startPoint->thisTransform->SetGlobalPos(glm::vec3(0.0f, 0.1f, 0.0f));


	// Environment - End Point
	EndPlate* endPoint = new EndPlate(this);
	sceneGameObjects.push_back(endPoint);
	endPoint->thisTransform->SetParent(anchorParent->thisTransform);
	endPoint->thisTransform->SetGlobalPos(glm::vec3(0.0f, 0.1f, 24.0f));


	// Player Ball
	GameObject* theBall = new PlayerBall(this);
	sceneGameObjects.push_back(theBall);
	theBall->thisTransform->SetGlobalPos(glm::vec3(0.0f, 10.0f, 0.0f));
	cameraMount->SetFollowTarget(theBall);


	// UI - Controls
	GameObject* sceneTitle = new GameObject(this);
	sceneGameObjects.push_back(sceneTitle);
	sceneTitle->thisTransform->SetGlobalPos(glm::vec3(25.0f, (DISPLAY_HEIGHT - 67), 0.0f));

	FontRenderer* ft = sceneTitle->addComponent<FontRenderer>();
	ft->Init("..\\res\\Cartoon.ttf", 18);
	ft->setTextWrapLength(DISPLAY_WIDTH / 2);
	ft->SetFontText("=== SUPER POLAROID BALL ===");


	// UI - Controls
	GameObject* textTest = new GameObject(this);
	sceneGameObjects.push_back(textTest);
	textTest->thisTransform->SetGlobalPos(glm::vec3(25.0f, (DISPLAY_HEIGHT - 150), 0.0f));

	FontRenderer* fr = textTest->addComponent<FontRenderer>();
	fr->Init("..\\res\\Cartoon.ttf", 12);
	fr->setTextWrapLength(DISPLAY_WIDTH / 4);
	fr->SetFontText("CONTROLS:               WASD - Tilt Level      1-5 - Change Scene");
}