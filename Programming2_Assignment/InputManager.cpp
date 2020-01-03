#include "InputManager.h"

#include <iostream>

InputManager* InputManager::instance = nullptr;
InputManager::InputManager()
{
}
InputManager* InputManager::Instance()
{
	if (instance == 0)
	{
		instance = new InputManager();
	}
	return instance;
}


void InputManager::HandleInput()
{
	// Consumes the current event and acts appropriately
	currentEvent = SDL_Event();
	while (SDL_PollEvent(&currentEvent))
	{
		if (currentEvent.type == SDL_KEYDOWN)
		{
			pressedKeys[currentEvent.key.keysym.sym] = true;
		}
		else if (currentEvent.type == SDL_KEYUP)
		{
			pressedKeys[currentEvent.key.keysym.sym] = false;
		}
	}
}


bool InputManager::IsKeyPressedDown(SDL_Keycode keyCode)
{
	if (pressedKeys[keyCode] == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::IsKeyPressedUp(SDL_Keycode keyCode)
{
	if (pressedKeys[keyCode] == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool InputManager::IsQuittingGame()
{
	if (currentEvent.type == SDL_QUIT)
	{
		return true;
	}
	else
	{
		return false;
	}
}