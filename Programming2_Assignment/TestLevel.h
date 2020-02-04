#pragma once
#include "GameScene.h"
class TestLevel : public GameScene
{
public:
	TestLevel();

private:
	enum ShaderType
	{
		MESH_SHADER,
		FOG_SHADER,
		TOON_SHADER
	};
};