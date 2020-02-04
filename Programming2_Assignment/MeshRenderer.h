#pragma once
#include "Component.h"

#include "MeshManager.h"
#include "Mesh.h"
#include "ShaderManager.h"
#include "Shader.h"
#include "TextureManager.h"
#include "Texture.h"

#include <string>

class MeshRenderer : public Component
{
public:
	MeshRenderer(GameObject* parent);
	void Update();

	void Init(std::string meshFileName, std::string textureFileName, std::string shaderFileName);

	Mesh* GetMesh();
	Texture* GetTexture();
	Shader* GetShader();

private:

	Camera* camera;

	Mesh* mesh;
	Texture* texture;
	Shader* shader;
};