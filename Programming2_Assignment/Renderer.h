#pragma once
#include "Component.h"

#include "MeshManager.h"
#include "Mesh.h"
#include "ShaderManager.h"
#include "Shader.h"
#include "TextureManager.h"
#include "Texture.h"

#include <string>

class Renderer : public Component
{
public:
	Renderer(GameObject* parent);
	void Init(std::string meshFileName, std::string textureFileName, std::string shaderFileName);

	void Update();

private:

	Camera* camera;

	Mesh* mesh;
	Texture* texture;
	Shader* shader;
};