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

	// Creating A Texture To Render The Output To
	glGenTextures(1, &outputTexture);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, outputTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0, GL_RGBA, GL_FLOAT,
		NULL);
	glBindImageTexture(0, outputTexture, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);

	// Setting up space to draw the texture to
	GLuint vao = 0, vbo = 0;
	/*float verts[] = 
	{
		-1.0f, -1.0f, 0.0f, 0.0f, 
		-1.0f, 1.0f, 0.0f, 1.0f, 
		1.0f, -1.0f, 1.0f, 0.0f, 
		1.0f, 1.0f, 1.0f, 1.0f 
	};*/
	float verts[] =
	{
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 1.0f, 1.0f
	};

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float), verts, GL_STATIC_DRAW);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	GLintptr stride = 4 * sizeof(float);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, stride, NULL);
	glEnableVertexAttribArray(1);
	GLintptr offset = 2 * sizeof(float);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (GLvoid *)offset);
	quad_vao = vao;
}

void RaymarchHandler::Update()
{
	/*
	// Binding the compute shader
	computeShader->Bind();

	// Binding the image that gets rendered to the screen
	glBindTexture(GL_TEXTURE_2D, testTexture->GetHandler());

	// Setting it so that the image can be read from and written to
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
	glBindImageTexture(0, testTexture->GetHandler(), 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);

	// Dispatching the compute shader so that it can run for every pixel on the game window
	glDispatchCompute(DISPLAY_WIDTH, DISPLAY_HEIGHT, 1); // 512^2 threads in blocks of 16^2
	*/


	// Binding the compute shader
	computeShader->Bind();

	// Binding the image that gets rendered to the screen
	glBindTexture(GL_TEXTURE_2D, outputTexture);

	// Setting it so that the image can be read from and written to
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
	glBindImageTexture(0, outputTexture, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);

	// Camera Details
	glm::vec3 cameraPos = *gameObject->parentScene->GetSceneCamera()->thisTransform->GetGlobalPos();
	glm::vec3 cameraForward = *gameObject->parentScene->GetSceneCamera()->thisTransform->GetForward();
	
	computeShader->setVec3("cameraPos", cameraPos);
	computeShader->setVec3("cameraForward", cameraForward);

	// Dispatching the compute shader so that it can run for every pixel on the game window
	glDispatchCompute((GLuint)DISPLAY_HEIGHT, (GLuint)DISPLAY_WIDTH, 1);


	// make sure writing to image has finished before read
	glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
	{ 
		// Shader
		renderShader->Bind();

		// Texture
		glActiveTexture(GL_TEXTURE0 + 0); //set acitve texture unit
		glBindTexture(GL_TEXTURE_2D, outputTexture); //type of and texture to bind to unit

		// Mesh
		/*glBindVertexArray(quad_vao);
		glDrawArrays(GL_TRIANGLES, 0, 4);
		glBindVertexArray(0);*/
		Mesh* m = MeshManager::Instance()->GetMesh("..\\res\\plane.obj");
		m->draw();
	}
}