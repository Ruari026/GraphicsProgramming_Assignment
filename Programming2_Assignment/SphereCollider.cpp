#include "SphereCollider.h"
#include "GameObject.h"

SphereCollider::SphereCollider(GameObject* parent) : Component(parent)
{
}


void SphereCollider::Update()
{
}


/*
====================================================================================================
Sphere Collider Size
====================================================================================================
*/
// Getters
float SphereCollider::GetSphereSize()
{
	return this->sphereRadius;
}
// Setters
void SphereCollider::SetSphereSize(float r)
{
	this->sphereRadius = r;
}

/*
====================================================================================================
Sphere Collider Offset
====================================================================================================
*/
// Getters
glm::vec3 SphereCollider::GetColliderOffset()
{
	return this->colliderOffset;
}
// Setters
void SphereCollider::SetColliderOffset(glm::vec3 offset)
{
	this->colliderOffset.x = offset.x;
	this->colliderOffset.y = offset.y;
	this->colliderOffset.z = offset.z;
}
void SphereCollider::SetColliderOffset(float x, float y, float z)
{
	this->colliderOffset.x = x;
	this->colliderOffset.y = y;
	this->colliderOffset.z = z;
}