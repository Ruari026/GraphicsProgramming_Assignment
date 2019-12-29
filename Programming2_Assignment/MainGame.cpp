#include "MainGame.h"
#include <iostream>
#include <string>

MainGame::MainGame()
{
	_gameState = GameState::PLAY;
	_gameDisplay = new Display(1024, 1024); //new display

	// Timer
	time = new Time();

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
	SDL_Event event;

	// Consumes the current event and acts appropriately
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
			{
				_gameState = GameState::EXIT;
			}
			break;
		}
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