#include "MainGame.h"
#include <iostream>
#include <string>

MainGame::MainGame()
{
	_gameState = GameState::PLAY;
	_gameDisplay = Display::Instance();

	// Game Managers
	time = new Time();
	inputManager = InputManager::Instance();
	sceneManager = SceneManager::Instance();
}
MainGame::~MainGame()
{ 
}


void MainGame::runGame()
{
	sceneManager->LoadScene("TestLevel");

	gameLoop();
}


void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		time->Update();

		processInput();
		drawGame();
	}
}


void MainGame::processInput()
{
	// Handing whether the game is currently being quit
	inputManager->HandleInput();
	if (inputManager->IsQuittingGame())
	{
		_gameState = GameState::EXIT;
	}
}


void MainGame::drawGame()
{
	_gameDisplay->clearDisplay(0.0f, 1.0f, 1.0f, 1.0f);

	sceneManager->currentScene->RunScene();

	glEnableClientState(GL_COLOR_ARRAY);
	glEnd();

	_gameDisplay->swapBuffer();
}