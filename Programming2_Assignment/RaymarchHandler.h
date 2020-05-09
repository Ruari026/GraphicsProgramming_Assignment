#pragma once
#include "Component.h"
class RaymarchHandler : public Component
{
public:
	RaymarchHandler(GameObject* parent);
	void Update();
};