#include "MeshRenderer.h"

#include "GameObject.h"
#include "GameScene.h"

MeshRenderer::MeshRenderer(GameObject* parent) : Component(parent)
{
	this->camera = parent->parentScene->GetSceneCamera();
}

void MeshRenderer::Init(std::string meshFilePath, std::string textureFilePath, std::string shaderFilePath)
{
	mesh = MeshManager::Instance()->GetMesh(meshFilePath);

	texture = TextureManager::Instance()->GetTexture(textureFilePath);

	shader = ShaderManager::Instance()->GetShader(shaderFilePath);
}

void MeshRenderer::Update()
{
	shader->Bind();
	shader->Update(*gameObject->thisTransform, *camera);
	texture->Bind(0);
	mesh->draw();
	glUseProgram(0);
}

Mesh* MeshRenderer::GetMesh()
{
	return this->mesh;
}

Texture* MeshRenderer::GetTexture()
{
	return this->texture;
}

Shader* MeshRenderer::GetShader()
{
	return this->shader;
}