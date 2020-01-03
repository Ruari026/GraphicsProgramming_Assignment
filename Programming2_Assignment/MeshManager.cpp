#include "MeshManager.h"
MeshManager* MeshManager::instance = nullptr;

MeshManager::MeshManager()
{
}

MeshManager* MeshManager::Instance()
{
	if (instance == nullptr)
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