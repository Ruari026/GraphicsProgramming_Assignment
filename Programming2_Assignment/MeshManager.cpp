#include "MeshManager.h"
MeshManager* MeshManager::instance = NULL;

MeshManager::MeshManager()
{
	instance = 0;
}

MeshManager* MeshManager::Instance()
{
	if (instance == 0)
	{
		instance = new MeshManager();
	}
	return instance;
}

Mesh* MeshManager::GetMesh(std::string fileName)
{
	Mesh* meshToGet = nullptr;
	meshToGet = loadedModels[fileName];

	if (meshToGet == nullptr)
	{
		// Model hasn't been loaded before
		Mesh* loadedMesh = new Mesh(fileName);
		loadedModels.insert(make_pair(fileName, loadedMesh));

		meshToGet = loadedMesh;
	}

	return meshToGet;
}