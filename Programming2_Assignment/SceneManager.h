#pragma once

#include <string>
#include <map>

class GameScene;

class SceneManager
{
public:
	static SceneManager* Instance();
	void LoadScene(std::string newSceneName);

	GameScene* currentScene;
private:
	SceneManager();

	static SceneManager* instance;
};