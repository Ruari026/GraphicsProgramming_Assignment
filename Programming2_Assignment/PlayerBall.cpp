#include "PlayerBall.h"

PlayerBall::PlayerBall(GameScene* scene) : GameObject(scene)
{
	// Renderer
	MeshRenderer* renderer = this->addComponent<MeshRenderer>();
	renderer->Init("..\\res\\Polaroid.obj", "..\\res\\Polaroid.png", "..\\res\\meshShader");

	// Collider
	SphereCollider* collider = this->addComponent<SphereCollider>();
	collider->SetSphereSize(1.0f);
	collider->SetColliderOffset(0.0f, 0.0f, 0.0f);

	// Physics Movement
	BallController* controller = this->addComponent<BallController>();
	PhysicsHandler* physics = this->addComponent<PhysicsHandler>();
}