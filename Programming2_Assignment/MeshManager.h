#pragma once

#include <string>
#include <map>

#include "Mesh.h"

class MeshManager
{
public:
	static MeshManager* Instance();
	Mesh* GetMesh(std::string fileName);

private:
	MeshManager();

	static MeshManager* instance;

	std::map<std::string, Mesh*> loadedModels;
};