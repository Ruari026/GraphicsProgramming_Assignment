#include "Platform.h"

Platform::Platform(GameScene* scene) : GameObject(scene)
{
	// Renderer
	Renderer* renderer = this->addComponent<Renderer>();
	renderer->Init("..\\res\\Tile_Crossroads.obj", "..\\res\\Environment.png", "..\\res\\shader");

	// Collider
	BoxCollider* collider = this->addComponent<BoxCollider>();
	collider->SetBoxSize(2.0f, 0.1f, 2.0f);
	collider->SetColliderOffset(0.0f, 0.0f, 0.0f);
}