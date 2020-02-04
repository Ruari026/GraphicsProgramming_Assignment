#include "SceneManager.h"

#include "TestLevel.h"

/*
====================================================================================================
Singleton Pattern
====================================================================================================
*/
SceneManager* SceneManager::instance = nullptr;
SceneManager::SceneManager()
{
}

SceneManager* SceneManager::Instance()
{
	if (instance == 0)
	{
		instance = new SceneManager();
	}
	return instance;
}


/*
====================================================================================================
Game Scene Changing
====================================================================================================
*/
void SceneManager::LoadScene(std::string newSceneName)
{
	if (newSceneName == "TestLevel")
	{
		currentScene = new TestLevel();
	}
}