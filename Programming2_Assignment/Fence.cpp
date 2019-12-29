#include "Fence.h"

Fence::Fence(GameScene* scene) : GameObject(scene)
{
	// Renderer
	Renderer* renderer = this->addComponent<Renderer>();
	renderer->Init("..\\res\\Fence.obj", "..\\res\\Environment.png", "..\\res\\shader");

	// Collider
	BoxCollider* collider = this->addComponent<BoxCollider>();
	collider->SetBoxSize(0.5f, 4.0f, 1.0f);
	collider->SetColliderOffset(0.0f, 0.0f, 0.0f);
}