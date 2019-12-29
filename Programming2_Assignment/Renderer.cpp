#include "Renderer.h"

#include "GameObject.h"
#include "GameScene.h"

Renderer::Renderer(GameObject* parent) : Component(parent)
{
	this->camera = parent->parentScene->GetSceneCamera();
}

void Renderer::Init(std::string meshFilePath, std::string textureFilePath, std::string shaderFilePath)
{
	mesh = MeshManager::Instance()->GetMesh(meshFilePath);

	texture = TextureManager::Instance()->GetTexture(textureFilePath);

	shader = ShaderManager::Instance()->GetShader(shaderFilePath);
}

void Renderer::Update()
{
	shader->Bind();
	shader->Update(*gameObject->thisTransform, *camera);
	texture->Bind(0);
	mesh->draw();
}