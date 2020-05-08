#pragma once
#include "Component.h"

#include "MeshManager.h"
#include "Mesh.h"
#include "ShaderManager.h"
#include "Shader.h"
#include "Skybox.h"

#include <string>
#include <vector>

class SkyboxRenderer : public Component
{
public:
	SkyboxRenderer(GameObject* parent);
	void Update();

	void Init(std::vector<std::string> texturesFilenames, std::string shaderFileName);

	Shader* GetShader();
	Skybox* GetSkybox();

private:

	Camera* camera;

	Skybox* skybox;
	Shader* shader;

	GLuint skyboxVAO, skyboxVBO;
};