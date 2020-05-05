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
	TESTING GAMEOBJECT
	====================================================================================================
	*/
	GameObject* meshGameObject = new GameObject(this);
	sceneGameObjects.push_back(meshGameObject);

	// Transform
	meshGameObject->thisTransform->SetGlobalPos(glm::vec3(0.0f, 0.0f, 5.0f));
	meshGameObject->thisTransform->SetGlobalRot(glm::vec3(0.0f, (3.14f * 0.75f), 0.0f));

	// Movement
	MeshMovement* mm = meshGameObject->addComponent<MeshMovement>();
	mm->SetMovementDirection(glm::vec3(0.0f, 0.0f, 1.0f));
	mm->SetMovementMagnitude(7.5f);
	mm->SetRotationMagnitude(3.14f * 0.33f);



	/*
	====================================================================================================
	TESTING SHADERS
	====================================================================================================
	*/
	// Setting What Shader To Use
	ShaderType shaderType = ShaderType::GEOM_SHADER;

	// Initalising Renderer Shaders
	MeshRenderer* renderer = meshGameObject->addComponent<MeshRenderer>();
	string meshFilePath = "..\\res\\monkey3.obj";
	string textureFilePath = "..\\res\\gradient.jpg";
	string shaderFilePath = "";
	switch (shaderType)
	{
		case (ShaderType::MESH_SHADER):
		{
			shaderFilePath = "..\\res\\meshShader";
		}
		break;

		case (ShaderType::FOG_SHADER):
		{
			shaderFilePath = "..\\res\\fogShader";
		}
		break;

		case (ShaderType::TOON_SHADER):
		{
			shaderFilePath = "..\\res\\shaderToon";
		}
		break;

		case (ShaderType::RIM_SHADER):
		{
			shaderFilePath = "..\\res\\rimShader";
		}
		break;

		case (ShaderType::COMBINED_SHADER):
		{
			shaderFilePath = "..\\res\\combinedShader";
		}
		break;

		case (ShaderType::GEOM_SHADER):
		{
			shaderFilePath = "..\\res\\shaderGeoText";
		}
		break;
	}
	renderer->Init(meshFilePath, textureFilePath, shaderFilePath);


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

		case (ShaderType::RIM_SHADER):
		{
			glm::vec3 pos = *sceneCamera->thisTransform->GetGlobalPos();
			shader->setVec3("cameraPos", pos);
			shader->setFloat("rimSize", 0.25f);
		}
		break;

		case (ShaderType::COMBINED_SHADER):
		{
			// Fog Details
			shader->setVec4("fogColor", glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
			shader->setFloat("minDist", 5.0f);
			shader->setFloat("maxDist", 15.0f);

			// Toon Details
			shader->setVec3("lightDir", glm::vec3(0.0f, 0.0f, -1.0f));

			// Rim Details
			glm::vec3 pos = *sceneCamera->thisTransform->GetGlobalPos();
			shader->setVec3("cameraPos", pos);
			shader->setFloat("rimSize", 0.25f);
		}
		break;
	}
}