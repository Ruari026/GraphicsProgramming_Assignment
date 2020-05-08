#include "ExplosionHandler.h"
#include "GameObject.h"
#include "Time.h"
#include "MeshRenderer.h"

ExplosionHandler::ExplosionHandler(GameObject* parent) : Component(parent)
{
	currentTime = 0;
}

void ExplosionHandler::Update()
{
	currentTime += Time::GetDeltaTime();
	if (currentTime > 360)
	{
		currentTime -= 360;
	}

	if (geometryShader == nullptr)
	{
		geometryShader = this->gameObject->getComponent<MeshRenderer>()->GetShader();
	}
	geometryShader->Bind();
}

void ExplosionHandler::SetMaxSize(float newMaxSize)
{
	this->maxExplosionSize = newMaxSize;
}

float ExplosionHandler::GetMaxSize()
{
	return this->maxExplosionSize;
}