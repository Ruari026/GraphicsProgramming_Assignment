#include "RaymarchHandler.h"

#include "GameObject.h"
#include "GameScene.h"

#include "ShaderManager.h"
#include "TextureManager.h"
#include "MeshManager.h"

#include "Display.h"

#include <iostream>

RaymarchHandler::RaymarchHandler(GameObject* parent) : Component(parent)
{
	// Raymarching compute shader
	computeShader = ShaderManager::Instance()->GetShader("..\\res\\raymarchShader");
	// Quad Rendering Shader
	renderShader = ShaderManager::Instance()->GetShader("..\\res\\meshShader");

	// Plane to render generated texture to
	renderPlane = MeshManager::Instance()->GetMesh("..\\res\\plane.obj");

	// Creating A Texture To Render The Output To
	glGenTextures(1, &outputTexture);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, outputTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0, GL_RGBA, GL_FLOAT,
		NULL);
	glBindImageTexture(0, outputTexture, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);
}

void RaymarchHandler::Init(GameObject* sphere, GameObject* cube)
{
	this->testSphere = sphere;
	this->testCube = cube;
}

void RaymarchHandler::Update()
{
	// Binding the compute shader
	computeShader->Bind();

	// Binding the image that gets rendered to the screen
	glBindTexture(GL_TEXTURE_2D, outputTexture);

	// Setting it so that the image can be read from and written to
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
	glBindImageTexture(0, outputTexture, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);



	// Passing through scene details
	// Camera Details
	glm::vec3 cameraPos = *gameObject->parentScene->GetSceneCamera()->thisTransform->GetGlobalPos();
	glm::vec3 cameraForward = gameObject->parentScene->GetSceneCamera()->GetCameraForward();
	float cameraFOV = gameObject->parentScene->GetSceneCamera()->GetCameraFOV();

	computeShader->setVec3("cameraPos", cameraPos);
	computeShader->setVec3("cameraForward", cameraForward);
	computeShader->setFloat("cameraFOV", cameraFOV);

	// Shapes Details
	computeShader->setVec3("cubePos", *testCube->thisTransform->GetGlobalPos());
	computeShader->setVec3("spherePos", *testSphere->thisTransform->GetGlobalPos());

	// Dispatching the compute shader so that it can run for every pixel on the game window
	glDispatchCompute(DISPLAY_WIDTH, DISPLAY_HEIGHT, 1);



	// make sure writing to image has finished before read
	glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
	{ 
		// Shader
		renderShader->Bind();

		// Texture
		glActiveTexture(GL_TEXTURE0 + 0); //set acitve texture unit
		glBindTexture(GL_TEXTURE_2D, outputTexture); //type of and texture to bind to unit

		// Mesh
		renderPlane->draw();
	}
}