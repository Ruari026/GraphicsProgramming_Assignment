#include "TestLevel.h"


#include "Font.h"

TestLevel::TestLevel() : GameScene()
{
	/*
	====================================================================================================
	CAMERA
	====================================================================================================
	*/
	GameObject* cameraGameObject = new GameObject(this);
	// Camera - Transform
	sceneCamera = cameraGameObject->addComponent<Camera>();
	sceneCamera->Init(70.0f, (DISPLAY_WIDTH / DISPLAY_HEIGHT), 0.01f, 1000.0f);
	cameraGameObject->thisTransform->SetGlobalPos(glm::vec3(0.0f, 1.75f, -5.0f));



	/*
	====================================================================================================
	TEST GAMEOBJECT
	====================================================================================================
	*/
	GameObject* meshGameObject = new GameObject(this);
	sceneGameObjects.push_back(meshGameObject);

	// Transform
	meshGameObject->thisTransform->SetGlobalPos(glm::vec3(0.0f, 0.0f, 0.0f));
	meshGameObject->thisTransform->SetGlobalRot(glm::vec3(0.0f, (3.14f * 0.83f), 0.0f));



	/*
	====================================================================================================
	TESTING SHADERS
	====================================================================================================
	*/
	// Setting What Shader To Use
	ShaderType shaderType = ShaderType::TOON_SHADER;


	// Initalising Renderer Shaders
	MeshRenderer* renderer = meshGameObject->addComponent<MeshRenderer>();
	switch (shaderType)
	{
		case (ShaderType::MESH_SHADER):
		{
			renderer->Init("..\\res\\monkey3.obj", "..\\res\\bricks.jpg", "..\\res\\meshShader");
		}
		break;

		case (ShaderType::FOG_SHADER):
		{
			renderer->Init("..\\res\\monkey3.obj", "..\\res\\bricks.jpg", "..\\res\\fogShader");
		}
		break;

		case (ShaderType::TOON_SHADER):
		{
			renderer->Init("..\\res\\monkey3.obj", "..\\res\\bricks.jpg", "..\\res\\shaderToon");
		}
		break;
	}
	

	// Changing Shader Properties
	Shader* shader = renderer->GetShader();
	shader->Bind();
	switch (shaderType)
	{
		case (ShaderType::FOG_SHADER):
		{
			shader->setVec4("fogColor", glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
			shader->setFloat("minDist", 0.0f);
			shader->setFloat("maxDist", 10.0f);
			shader->setVec3("cam_pos", *cameraGameObject->thisTransform->GetGlobalPos());
		}
		break;

		case (ShaderType::TOON_SHADER):
		{
			shader->setVec3("lightDir", glm::vec3(0.0f, 0.0f, -1.0f));
		}
		break;
	}
}