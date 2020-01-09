#include "StartPlate.h"

StartPlate::StartPlate(GameScene* scene) : GameObject(scene)
{
	// Renderer
	MeshRenderer* renderer = this->addComponent<MeshRenderer>();
	renderer->Init("..\\res\\StartPlate.obj", "..\\res\\Plate.png", "..\\res\\meshShader");
}