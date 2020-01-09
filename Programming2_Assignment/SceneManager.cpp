#include "SceneManager.h"

#include "Level1.h"
#include "Level2.h"
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
	if (newSceneName == "Level1")
	{
		currentScene = new Level1();
	}
	else if (newSceneName == "Level2")
	{
		currentScene = new Level2();
	}
	else if (newSceneName == "TestLevel")
	{
		currentScene = new TestLevel();
	}
}