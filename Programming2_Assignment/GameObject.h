#pragma once
#include "transform.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Component.h"

#include <string>

using namespace std;

class GameObject
{
public:
	GameObject(string meshFilePath, string textureFilePath, string shaderFilePath)
	{
		mesh = new Mesh(meshFilePath);

		texture = new Texture(textureFilePath); //load texture

		shader = new Shader(shaderFilePath); //new shader
	}
	~GameObject()
	{

	}

	Mesh* mesh;
	Texture* texture;
	Shader* shader;

	Transform transform;

	void renderGameObject(Camera* mainCamera)
	{
		shader->Bind();
		shader->Update(transform, *mainCamera);
		texture->Bind(0);
		mesh->draw();
	}

	void updateGameObject()
	{

	}

private:
};