#include "BoxCollider.h"
#include "GameObject.h"


BoxCollider::BoxCollider(GameObject* parent) : Component(parent)
{
}


void BoxCollider::Update()
{
}


/*
====================================================================================================
Box Collider Size
====================================================================================================
*/
// Getter
glm::vec3 BoxCollider::GetBoxSize()
{
	return this->boxSize;
}
// Setters
void BoxCollider::SetBoxSize(glm::vec3 size)
{
	this->boxSize.x = size.x;
	this->boxSize.y = size.y;
	this->boxSize.z = size.z;
}
void BoxCollider::SetBoxSize(float w, float h, float d)
{
	this->boxSize.x = w;
	this->boxSize.y = h;
	this->boxSize.z = d;
}


/*
====================================================================================================
Box Collider Offset
====================================================================================================
*/
// Getter
glm::vec3 BoxCollider::GetColliderOffset()
{
	return this->colliderOffset;
}
// Setters
void BoxCollider::SetColliderOffset(glm::vec3 offset)
{
	this->colliderOffset.x = offset.x;
	this->colliderOffset.y = offset.y;
	this->colliderOffset.z = offset.z;
}
void BoxCollider::SetColliderOffset(float x, float y, float z)
{
	this->colliderOffset.x = x;
	this->colliderOffset.y = y;
	this->colliderOffset.z = z;
}