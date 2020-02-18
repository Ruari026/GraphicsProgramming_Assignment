#pragma once
#include "Component.h"
#include "GameObject.h"

#include <glm/glm.hpp>

class MeshMovement : public Component
{
public:
	MeshMovement(GameObject* parent);
	void Update();

	void SetMovementDirection(glm::vec3 newDirection);
	void SetMovementMagnitude(float newMagnitude);
	void SetRotationMagnitude(float newMagnitude);

private:
	glm::vec3 movementDirection;
	float movementMagnitude;
	float rotationMagnitude;

	glm::vec3 startPos;
	float currentTime;
};