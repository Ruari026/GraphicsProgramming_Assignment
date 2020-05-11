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
	void Update();

private:
	Shader* computeShader;
	Shader* renderShader;

	GLuint outputTexture;
	GLuint quad_vao;
};