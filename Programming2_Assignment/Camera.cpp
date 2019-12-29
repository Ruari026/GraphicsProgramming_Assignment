#include "camera.h"
#include "GameObject.h"

Camera::Camera(GameObject* parent) : Component(parent)
{
	thisTransform = parent->thisTransform;
}

void Camera::Init(float fov, float aspect, float zNear, float zFar)
{
	this->perspectiveProjection = glm::perspective(fov, aspect, zNear, zFar);
	this->orthographicProjection = glm::ortho((-1024.0f / 150), (1024.0f / 150), (-1024.0f / 200), (1024.0f / 200), zNear, zFar);
}

void Camera::Update()
{

}

glm::mat4 Camera::GetViewProjection()
{
	glm::vec3 pos = *thisTransform->GetGlobalPos();
	glm::vec3 forward = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	bool cameraPerspective = true;
	if (cameraPerspective)
	{
		return perspectiveProjection * glm::lookAt(pos, pos + forward, up);
	}
	else
	{
		return orthographicProjection * glm::lookAt(pos, pos + forward, up);
	}
}