#include "Platform.h"

Platform::Platform(GameScene* scene) : GameObject(scene)
{
	// Renderer
	MeshRenderer* renderer = this->addComponent<MeshRenderer>();
	renderer->Init("..\\res\\Tile_Crossroads.obj", "..\\res\\Environment.png", "..\\res\\meshShader");

	// Collider
	BoxCollider* collider = this->addComponent<BoxCollider>();
	collider->SetBoxSize(2.0f, 0.1f, 2.0f);
	collider->SetColliderOffset(0.0f, 0.0f, 0.0f);
}