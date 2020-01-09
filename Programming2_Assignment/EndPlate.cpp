#include "EndPlate.h"

EndPlate::EndPlate(GameScene* scene) : GameObject(scene)
{
	// Renderer
	MeshRenderer* renderer = this->addComponent<MeshRenderer>();
	renderer->Init("..\\res\\EndPlate.obj", "..\\res\\Plate.png", "..\\res\\meshShader");
}