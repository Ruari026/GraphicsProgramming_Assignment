#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Display.h" 

#include "GameScene.h"

#include "InputManager.h"
#include "SceneManager.h"

#include "GameObject.h"
#include "transform.h"
#include "Time.h"

enum class GameState
{ 
	PLAY, 
	EXIT 
};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void runGame();

private:

	void processInput();
	void gameLoop();
	void drawGame();

	Display* _gameDisplay;
	GameState _gameState;

	Time* time;
	InputManager* inputManager;
	SceneManager* sceneManager;
};
