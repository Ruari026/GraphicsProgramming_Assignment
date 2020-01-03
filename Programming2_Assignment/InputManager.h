#pragma once
#include <SDL\SDL.h>
#include <map>

class InputManager
{
public:
	static InputManager* Instance();

	void HandleInput();

	bool IsKeyPressedDown(SDL_Keycode keyCode);
	bool IsKeyPressedUp(SDL_Keycode keyCode);

	bool IsQuittingGame();
private:
	InputManager();

	static InputManager* instance;

	SDL_Event currentEvent;

	std::map<SDL_Keycode, bool> pressedKeys;
};