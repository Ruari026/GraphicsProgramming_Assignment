#include "PhysicsHandler.h"

#include "GameObject.h"
#include "GameScene.h"

#include <iostream>
#include <algorithm>

PhysicsHandler::PhysicsHandler(GameObject* parent) : Component(parent)
{
}

void PhysicsHandler::Update()
{
	// Position at start of update
	glm::vec3 newPosition = *gameObject->thisTransform->GetGlobalPos();

	float timeStep = Time::deltaTime;
	if (timeStep > maxTimeStep)
	{
		timeStep = maxTimeStep;
	}


	// STEP 1 - Movement Equations
	// Calculating Velocity
	velocity.x = ((velocity.x) / (-1 * airResistance)) * (-1 * airResistance) * exp(-1 * airResistance * timeStep);
	velocity.y = (-1 * airResistance) * (((velocity.y) + (gravity / airResistance)) / (-1 * airResistance)) * exp((-1 * airResistance * timeStep)) - ((gravity) / (airResistance));
	velocity.z = ((velocity.z) / (-1 * airResistance)) * (-1 * airResistance) * exp(-1 * airResistance * timeStep);
	// Calculating Position TODO: fix y position to include air resistance
	newPosition.x = (newPosition.x - (velocity.x / (-1 * airResistance))) + (velocity.x / (-1 * airResistance)) * exp(-1 * airResistance * timeStep);
	newPosition.y = ((gravity * timeStep) / 2) + (velocity.y * timeStep) + newPosition.y;
	newPosition.z = (newPosition.z - (velocity.z / (-1 * airResistance))) + (velocity.z / (-1 * airResistance)) * exp(-1 * airResistance * timeStep);
	 

	// STEP 2 - Collision Checks
	// Getting other colliders in the scene
	vector<BoxCollider*> otherColliders = gameObject->parentScene->GetSceneColliders();
	// Checking if collision is occuring
	glm::vec3 hitNormal;
	bool collided = false;
	for (int i = 0; i < otherColliders.size(); i++)
	{
		if (CheckCollision(newPosition, otherColliders[i]))
		{
			collided = true;
			hitNormal = GetCollidedNormal(newPosition, otherColliders[i]);
		}
	}


	// STEP 3 - Collsion Resolution
	if (!collided)
	{
		// Object can continue it's movement in it's current direction
		gameObject->thisTransform->SetGlobalPos(newPosition);
	}
	else
	{
		// Object has collided so must reflect off of the hit surface
		// Handling change in Velocity
		ReflectVelocity(hitNormal);

		// TODO: Handling Addition of Torque
	}
}


/*
====================================================================================================
Collision Handling
====================================================================================================
*/
bool PhysicsHandler::CheckCollision(glm::vec3 newPosition, BoxCollider* otherCollider)
{
	// This Sphere Collider Details
	SphereCollider* thisCollider = this->gameObject->getComponent<SphereCollider>();
	glm::vec3 spherePos = newPosition;
	float sphereRadius = thisCollider->GetSphereSize();

	// Other Box Collider Details
	glm::vec3 boxPos = *otherCollider->gameObject->thisTransform->GetGlobalPos() + otherCollider->GetColliderOffset();
	glm::quat boxRot = *otherCollider->gameObject->thisTransform->GetGlobalRotQuaternion();
	glm::vec3 boxSize = otherCollider->GetBoxSize();

	// Getting sphere position relative to rotated box
	glm::vec3 localPos = spherePos - boxPos;
	glm::vec3 rotatedLocalPos = inverse(boxRot) * localPos;

	// difference between sphere center & box center
	glm::vec3 edgePos = glm::clamp(rotatedLocalPos, (-boxSize), (boxSize));

	// Checking collision
	float length = glm::length(edgePos - rotatedLocalPos);
	bool collided = length < sphereRadius;
	return collided;
}

glm::vec3 PhysicsHandler::GetCollidedNormal(glm::vec3 newPosition, BoxCollider* otherCollider)
{
	// Difference between sphere center & box center
	glm::vec3 edgePos = GetCollisionPoint(newPosition, otherCollider);

	// Box details
	glm::vec3 boxSize = otherCollider->GetBoxSize();
	glm::quat boxRot = *otherCollider->gameObject->thisTransform->GetGlobalRotQuaternion();

	// Getting normal based on local positions
	glm::vec3 localNormal;
	// Height
	if (edgePos.y >= boxSize.y)
	{
		localNormal += glm::vec3(0.0f, 1.0f, 0.0f);
	}
	else if (edgePos.y <= -boxSize.y)
	{
		localNormal += glm::vec3(0.0f, -1.0f, 0.0f);
	}
	// Width
	if (edgePos.x >= boxSize.x)
	{
		localNormal += glm::vec3(1.0f, 0.0f, 0.0f);
	}
	else if (edgePos.x <= -boxSize.x)
	{
		localNormal += glm::vec3(-1.0f, 0.0f, 0.0f);
	}
	// Depth
	if (edgePos.z >= boxSize.z)
	{
		localNormal += glm::vec3(0.0f, 0.0f, 1.0f);
	}
	else if (edgePos.z <= -boxSize.z)
	{
		localNormal += glm::vec3(0.0f, 0.0f, -1.0f);
	}

	// Getting normal based on box collider's rotation
	glm::vec3 rotatedNormal = boxRot * localNormal;
	return (glm::normalize(rotatedNormal));
}

glm::vec3 PhysicsHandler::GetCollisionPoint(glm::vec3 newPosition, BoxCollider* otherCollider)
{
	// This Sphere Collider Details
	SphereCollider* thisCollider = this->gameObject->getComponent<SphereCollider>();
	glm::vec3 spherePos = newPosition;
	float sphereRadius = thisCollider->GetSphereSize();

	// Other Box Collider Details
	glm::vec3 boxPos = *otherCollider->gameObject->thisTransform->GetGlobalPos() + otherCollider->GetColliderOffset();
	glm::quat boxRot = *otherCollider->gameObject->thisTransform->GetGlobalRotQuaternion();
	glm::vec3 boxSize = otherCollider->GetBoxSize();

	// Getting sphere position relative to rotated box
	glm::vec3 localPos = spherePos - boxPos;
	glm::vec3 rotatedLocalPos = inverse(boxRot) * localPos;

	// difference between sphere center & box center
	glm::vec3 edgePos = glm::clamp(rotatedLocalPos, (-boxSize), (boxSize));
	return edgePos;
}


/*
====================================================================================================
Forces Handling
====================================================================================================
*/
void PhysicsHandler::ReflectVelocity(glm::vec3 hitNormal)
{
	glm::vec3 inputVelocity = this->velocity;

	float dotProduct = glm::dot(inputVelocity, hitNormal);

	glm::vec3 outputVelocity = inputVelocity - ((2 * dotProduct) * hitNormal);
	outputVelocity = (outputVelocity * 0.3f);
	this->velocity = outputVelocity;
}