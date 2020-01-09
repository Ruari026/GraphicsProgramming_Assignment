#include "TestLevel.h"


#include "Font.h"

TestLevel::TestLevel() : GameScene()
{
	// Camera
	GameObject* cameraGameObject = new GameObject(this);
	sceneCamera = cameraGameObject->addComponent<Camera>();
	sceneCamera->Init(70.0f, (DISPLAY_WIDTH / DISPLAY_HEIGHT), 0.01f, 1000.0f);
	cameraGameObject->thisTransform->SetGlobalPos(glm::vec3(0.0f, 5.0f, -10.0f));


	// UI
	GameObject* textTest = new GameObject(this);
	sceneGameObjects.push_back(textTest);
	textTest->thisTransform->SetGlobalPos(glm::vec3(25.0f, DISPLAY_HEIGHT / 1.5f, 0.0f));

	FontRenderer* ft = textTest->addComponent<FontRenderer>();
	ft->Init("..\\res\\Cartoon.ttf", 12);
	ft->SetFontText("Hello World Geronimo");


	// Player
	PlayerBall* newBall = new PlayerBall(this);
	sceneGameObjects.push_back(newBall);
}