#include "TestLevel.h"


#include "Font.h"

TestLevel::TestLevel() : GameScene()
{
	// Camera
	GameObject* cameraGameObject = new GameObject(this);

	sceneCamera = cameraGameObject->addComponent<Camera>();
	sceneCamera->Init(70.0f, (DISPLAY_WIDTH / DISPLAY_HEIGHT), 0.01f, 1000.0f);
	cameraGameObject->thisTransform->SetGlobalPos(glm::vec3(0.0f, 1.75f, -5.0f));


	// Test Gameobject
	GameObject* meshGameObject = new GameObject(this);
	sceneGameObjects.push_back(meshGameObject);

	meshGameObject->thisTransform->SetGlobalRot(glm::vec3(0.0f, (3.14f * 0.75f), 0.0f));

	MeshRenderer* renderer = meshGameObject->addComponent<MeshRenderer>();
	renderer->Init("..\\res\\monkey3.obj", "..\\res\\bricks.jpg", "..\\res\\shaderToon");


	// Shader Testing
	Shader* shader = renderer->GetShader();
	shader->Bind();
	shader->setVec3("lightDir", glm::vec3(0.0f, 0.0f, 1.0f));
}