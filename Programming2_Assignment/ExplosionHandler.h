#pragma once
#include "Component.h"
#include "Shader.h"

class ExplosionHandler : public Component
{
public:
	ExplosionHandler(GameObject* parent);
	void Update();

	void SetMaxSize(float newMaxSize);
	float GetMaxSize();

private:
	float currentTime;
	float maxExplosionSize;
	Shader* geometryShader;
};