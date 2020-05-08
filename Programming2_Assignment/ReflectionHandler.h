#pragma once
#include "Component.h"
#include "Shader.h"

class ReflectionHandler : public Component
{
public:
	ReflectionHandler(GameObject* parent);
	void Update();

private:
};