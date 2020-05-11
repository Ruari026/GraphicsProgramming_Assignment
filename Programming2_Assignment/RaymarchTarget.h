#pragma once
#include "Component.h"
class RaymarchTarget : public Component
{
public:
	RaymarchTarget(GameObject* parent);
	void Update();

	//void SetRaymarchTargetShape(PrimitiveShape newShape);
	//PrimitiveShape GetRaymarchTargetShape();

private:
	//PrimitiveShape objectShape;

	/*enum PrimitiveShape
	{
		SPHERE,
		CUBE
	};*/
};