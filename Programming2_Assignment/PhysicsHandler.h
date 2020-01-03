#pragma once
#include "Component.h"
#include "Time.h"

#include "BoxCollider.h"
#include "SphereCollider.h"

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

class PhysicsHandler : public Component
{
public: 
	PhysicsHandler(GameObject* parent);
	void Update();

private:
	// World Values
	float maxTimeStep = 0.01f;

	float gravity = -3.0f;
	const float airResistance = 0.01f;

	// Collision Handling
	bool CheckCollision(glm::vec3 newPosition, BoxCollider* otherCollider);
	glm::vec3 GetCollidedNormal(glm::vec3 newPosition, BoxCollider* otherCollider);
	glm::vec3 GetCollisionPoint(glm::vec3 newPosition, BoxCollider* otherCollider);

	// Forces Handling
	void ReflectVelocity(glm::vec3 hitNormal);
	void AddTorque(glm::vec3 hitPos, glm::vec3 hitNormal);

	// Movement
	glm::vec3 velocity;
	glm::vec3 torque;
};

