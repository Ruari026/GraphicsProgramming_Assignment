#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Display.h" 
#include "GameObject.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "transform.h"

enum class GameState { PLAY, EXIT };

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

private:

	void processInput();
	void gameLoop();
	void drawGame();

	Display* _gameDisplay;
	GameState _gameState;
	Camera* myCamera;

	GameObject* cube;

	Transform transform;

	float counter = 0;
};
