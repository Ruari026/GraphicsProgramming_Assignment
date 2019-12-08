#include "MainGame.h"
#include <iostream>
#include <string>

MainGame::MainGame()
{
	_gameState = GameState::PLAY;
	_gameDisplay = new Display(1024, 768); //new display
	myCamera = new Camera(glm::vec3(0, 0.5f, -10), 70.0f, (_gameDisplay->getWidth() / _gameDisplay->getHeight()), 0.01f, 1000.0f);

	cube = new GameObject("..\\res\\Polaroid.obj", "..\\res\\bricks.jpg", "..\\res\\shader");
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
		processInput();
		drawGame();
	}
}

void MainGame::processInput()
{
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) //get and process events
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		}
	}
}


void MainGame::drawGame()
{
	_gameDisplay->clearDisplay(0.0f, 1.0f, 1.0f, 1.0f);

	counter += 0.001f;
	cube->transform.SetRot(glm::vec3(0, counter, 0));

	cube->updateGameObject();
	cube->renderGameObject(myCamera);

	glEnableClientState(GL_COLOR_ARRAY);
	glEnd();

	_gameDisplay->swapBuffer();
}