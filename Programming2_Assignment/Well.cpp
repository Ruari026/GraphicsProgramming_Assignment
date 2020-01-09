#include "Well.h"

Well::Well(GameScene* scene) : GameObject(scene)
{
	// Renderer
	MeshRenderer* renderer = this->addComponent<MeshRenderer>();
	renderer->Init("..\\res\\Well.obj", "..\\res\\Plate.png", "..\\res\\meshShader");

	// Collider
	BoxCollider* collider = this->addComponent<BoxCollider>();
	collider->SetBoxSize(2.0f, 2.0f, 1.25f);
	collider->SetColliderOffset(0.0f, 0.0f, 0.0f);
}