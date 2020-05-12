#pragma once
#include "Component.h"
#include "Shader.h"
#include "Texture.h"

#include <string>
#include <GL\glew.h>

class RaymarchHandler : public Component
{
public:
	RaymarchHandler(GameObject* parent);
	void Init(GameObject* sphere, GameObject* cube);

	void Update();

private:
	Shader* computeShader;
	Shader* renderShader;

	GLuint outputTexture;

	GameObject* testSphere;
	GameObject* testCube;
};