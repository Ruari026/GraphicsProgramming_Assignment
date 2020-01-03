#include "ShaderManager.h"
ShaderManager* ShaderManager::instance = nullptr;

ShaderManager::ShaderManager()
{
}

ShaderManager* ShaderManager::Instance()
{
	if (instance == nullptr)
	{
		instance = new ShaderManager();
	}
	return instance;
}

Shader* ShaderManager::GetShader(std::string fileName)
{
	Shader* shaderToGet = nullptr;
	shaderToGet = loadedShaders[fileName];

	if (shaderToGet == nullptr)
	{
		// Model hasn't been loaded before
		Shader* loadedShader = new Shader(fileName);
		loadedShaders.insert(make_pair(fileName, loadedShader));

		shaderToGet = loadedShader;
	}

	return shaderToGet;
}