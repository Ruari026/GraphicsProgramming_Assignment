#pragma once
#include "Component.h"

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "transform.h"

class Camera : public Component
{
public:
	Camera(GameObject* parent);
	void Init(float fov, float aspect, float zNear, float zFar);

	void Update();
	glm::mat4 GetViewProjection();

	Transform* thisTransform;

private:
	glm::mat4 perspectiveProjection;
	glm::mat4 orthographicProjection;
};