#pragma once

class GameObject;

class Component
{
public:
	Component(GameObject* parent)
	{
		gameObject = parent;
	}
	~Component();

	virtual void Update() = 0;

private:
	GameObject* gameObject;
};