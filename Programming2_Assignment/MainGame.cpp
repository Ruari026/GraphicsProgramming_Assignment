#include "MainGame.h"
#include <iostream>
#include <string>

MainGame::MainGame()
{
	_gameState = GameState::PLAY;
	_gameDisplay = new Display(1024, 1024); //new display

	// Timer
	time = new Time();
	inputManager = InputManager::Instance();

	currentScene = new Level1(_gameDisplay);
}
MainGame::~MainGame()
{ 
}


void MainGame::run()
{
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
	inputManager->HandleInput();

	// Quitting the game
	if (inputManager->IsQuittingGame())
	{
		_gameState = GameState::EXIT;
	}
}


void MainGame::drawGame()
{
	_gameDisplay->clearDisplay(0.0f, 1.0f, 1.0f, 1.0f);

	currentScene->RunScene();

	glEnableClientState(GL_COLOR_ARRAY);
	glEnd();

	_gameDisplay->swapBuffer();
}