#pragma once
#include "Component.h"

#include <glm/glm.hpp>

class SphereCollider : public Component
{
public:
	SphereCollider(GameObject* parent);
	void Update();

	float GetSphereSize();
	void SetSphereSize(float r);

	glm::vec3 GetColliderOffset();
	void SetColliderOffset(glm::vec3 offset);
	void SetColliderOffset(float x, float y, float z);

private:
	float sphereRadius = 1;

	glm::vec3 colliderOffset;
};