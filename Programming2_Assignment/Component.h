#pragma once

class GameObject;

class Component
{
public:
	Component(GameObject* parent)
	{
		gameObject = parent;

		gameObject;
	}
	~Component()
	{

	}

	virtual void Update() = 0;
	GameObject* gameObject;
};