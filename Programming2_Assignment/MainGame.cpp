#include "MainGame.h"
#include <iostream>
#include <string>

MainGame::MainGame()
{
	_gameState = GameState::PLAY;
	_gameDisplay = new Display(1024, 768); //new display
	_gameCamera = new Camera(glm::vec3(0, 0.5f, -5), 70.0f, (_gameDisplay->getWidth() / _gameDisplay->getHeight()), 0.01f, 1000.0f);

	testGameObject = new GameObject("..\\res\\Polaroid.obj", "..\\res\\Polaroid.png", "..\\res\\shader");
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
		time.Update();

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

	// Rotating GameObject
	counter += 0.001f * time.deltaTime;
	testGameObject->transform.SetRot(glm::vec3(-0.5f, counter, 0));


	testGameObject->updateGameObject();
	testGameObject->renderGameObject(_gameCamera);

	glEnableClientState(GL_COLOR_ARRAY);
	glEnd();

	_gameDisplay->swapBuffer();
}