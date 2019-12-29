#include "GameScene.h"

GameScene::GameScene(Display* _gameDisplay)
{
}

void GameScene::RunScene()
{
	// Scene GameObjects
	int capacity = sceneGameObjects.size();
	for (int i = 0; i < sceneGameObjects.size(); i++)
	{
		sceneGameObjects[i]->updateGameObject();
	}
}


Camera* GameScene::GetSceneCamera()
{
	return this->sceneCamera;
}
vector<BoxCollider*> GameScene::GetSceneColliders()
{
	vector<BoxCollider*> sceneColliders;

	for (int i = 0; i < sceneGameObjects.size(); i++)
	{
		BoxCollider* boxCollider = nullptr;
		boxCollider = sceneGameObjects[i]->getComponent<BoxCollider>();
		
		if (boxCollider != nullptr)
		{
			sceneColliders.push_back(boxCollider);
		}
	}

	return sceneColliders;
}