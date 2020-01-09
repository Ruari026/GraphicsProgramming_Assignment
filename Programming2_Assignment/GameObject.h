#pragma once

#include "transform.h"

#include "Component.h"
#include "BallController.h"
#include "BoxCollider.h"
#include "camera.h"
#include "CameraMount.h"
#include "EnvironmentController.h"
#include "PhysicsHandler.h"
#include "FontRenderer.h"
#include "MeshRenderer.h"
#include "SphereCollider.h"

#include <string>
#include <vector>

class GameScene; // Forward declaration to avoid circular depedencies

class GameObject
{
public:
	GameObject(GameScene* scene)
	{
		parentScene = scene;
		
		thisTransform = new Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	}
	~GameObject()
	{
	}

	GameScene* parentScene;

	Transform* thisTransform;


	/*
	====================================================================================================
	Handling GameObject Components
	====================================================================================================
	*/
	template <class T>
	auto addComponent()
	{
		T* newComponent = new T(this);
		components.push_back(newComponent);

		return newComponent;
	}
	template <class T>
	auto getComponent()
	{
		T* component = nullptr;

		for (int i = 0; i < this->components.capacity(); i++)
		{
			T* x = dynamic_cast<T*>(components[i]);
			
			if (x != NULL)
			{
				component = x;
			}
		}

		return component;
	}

	void updateGameObject()
	{
		for (int i = 0; i < components.size(); i++)
		{
			components[i]->Update();
		}
	}

private:
	std::vector<Component*> components;
};