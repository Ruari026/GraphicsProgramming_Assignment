#pragma once

#include <SDL/SDL.h>
#include <GL\glew.h>
#include <iostream>
#include <string>

#define DISPLAY_WIDTH 1024
#define DISPLAY_HEIGHT 1024

using namespace std;

class Display
{
public:
	Display(float width, float height);
	~Display();
	void swapBuffer();
	void clearDisplay(float r, float g, float b, float a);

private:

	void returnError(std::string errorString);

	SDL_GLContext glContext; //global variable to hold the context
	SDL_Window* sdlWindow; //holds pointer to out window
};