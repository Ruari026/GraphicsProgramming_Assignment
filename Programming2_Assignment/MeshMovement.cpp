#include "MeshMovement.h"
#include "Time.h"

MeshMovement::MeshMovement(GameObject* parent) : Component(parent)
{
	startPos = *parent->thisTransform->GetGlobalPos();
}

void MeshMovement::Update()
{
	currentTime += Time::GetDeltaTime();
	if (currentTime > 360)
	{
		currentTime -= 360;
	}

	// Movement
	glm::vec3 newPos = startPos + (movementDirection * (cosf(currentTime) * movementMagnitude));
	this->gameObject->thisTransform->SetGlobalPos(newPos);

	// Rotation
	glm::vec3 newRot = glm::vec3(0.0f, (currentTime * rotationMagnitude), 0.0f);
	this->gameObject->thisTransform->SetGlobalRot(newRot);

	
	// TODO: Move to own component
	Shader* r = this->gameObject->getComponent<MeshRenderer>()->GetShader();
	r->Bind();

	r->setFloat("Magnitude", (sin(currentTime) + 1.0f) * movementMagnitude);
}


void MeshMovement::SetMovementDirection(glm::vec3 newDirection)
{
	movementDirection = newDirection;
}


void MeshMovement::SetMovementMagnitude(float newMagnitude)
{
	movementMagnitude = newMagnitude;
}

void MeshMovement::SetRotationMagnitude(float newMagnitude)
{
	rotationMagnitude = newMagnitude;
}