#pragma once
#include "Component.h"
class CameraMount : public Component
{
public:
	CameraMount(GameObject* parent);
	void Update();

	void SetFollowTarget(GameObject* newTarget);

private:
	GameObject* followTarget;
};