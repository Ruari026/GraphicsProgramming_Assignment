#include "PlayerBall.h"

PlayerBall::PlayerBall(GameScene* scene) : GameObject(scene)
{
	// Renderer
	Renderer* renderer = this->addComponent<Renderer>();
	renderer->Init("..\\res\\Polaroid.obj", "..\\res\\Polaroid.png", "..\\res\\shader");

	// Collider
	SphereCollider* collider = this->addComponent<SphereCollider>();
	collider->SetSphereSize(0.9f);
	collider->SetColliderOffset(0.0f, 0.0f, 0.0f);

	// Physics Movement
	PhysicsHandler* physics = this->addComponent<PhysicsHandler>();
}