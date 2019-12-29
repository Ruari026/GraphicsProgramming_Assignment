#pragma once

#include <string>
#include <map>

#include "Shader.h"

class ShaderManager
{
public:
	static ShaderManager* Instance();
	Shader* GetShader(std::string fileName);

private:
	ShaderManager();

	static ShaderManager* instance;

	std::map<std::string, Shader*> loadedShaders;
};