#include "Fence.h"

Fence::Fence(GameScene* scene) : GameObject(scene)
{
	// Renderer
	MeshRenderer* renderer = this->addComponent<MeshRenderer>();
	renderer->Init("..\\res\\Fence.obj", "..\\res\\Environment.png", "..\\res\\meshShader");

	// Collider
	BoxCollider* collider = this->addComponent<BoxCollider>();
	collider->SetBoxSize(0.25f, 2.0f, 0.5f);
	collider->SetColliderOffset(0.0f, 0.0f, 0.0f);
}