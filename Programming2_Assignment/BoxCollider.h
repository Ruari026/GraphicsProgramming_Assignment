#pragma once
#include "Component.h"

#include<glm/glm.hpp>

class BoxCollider : public Component
{
public:
	BoxCollider(GameObject* parent);
	void Update();

	void SetBoxSize(glm::vec3 size);
	void SetBoxSize(float w, float h, float d);
	glm::vec3 GetBoxSize();

	void SetColliderOffset(glm::vec3 offset);
	void SetColliderOffset(float x, float y, float z);
	glm::vec3 GetColliderOffset();

private:
	glm::vec3 boxSize;
	glm::vec3 colliderOffset;
};