#include "CameraMount.h"
#include "GameObject.h"

#include <glm/glm.hpp>
#include <glm/gtx/compatibility.hpp>

CameraMount::CameraMount(GameObject* parent) : Component(parent)
{
}


void CameraMount::Update()
{
	glm::vec3 currentPosition = *gameObject->thisTransform->GetGlobalPos();
	glm::vec3 targetPosition = *followTarget->thisTransform->GetGlobalPos();

	glm::vec3 newPos = glm::lerp(currentPosition, targetPosition, (Time::GetDeltaTime() * 10.0f));
	this->gameObject->thisTransform->SetGlobalPos(newPos);
}


void CameraMount::SetFollowTarget(GameObject* newTarget)
{
	this->followTarget = newTarget;
}