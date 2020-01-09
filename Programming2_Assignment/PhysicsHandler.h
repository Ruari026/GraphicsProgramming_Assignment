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

	glm::vec3* GetVelocity();
	void SetVelocity(glm::vec3 newVelocity);
	glm::vec3* GetTorque();
	void SetTorque(glm::vec3 newTorque);

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
	// Translational Forces
	glm::vec3 velocity;
	void ReflectVelocity(glm::vec3 hitNormal);
	// Rotational Forces
	glm::vec3 torque;
};

