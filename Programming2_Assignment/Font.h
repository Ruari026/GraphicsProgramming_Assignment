#pragma once

#include <SDL/SDL_ttf.h>

#include<string>

class Font
{
public:
	Font(const std::string filePath, int fontSize);
	~Font();
	TTF_Font* loadedFont;

private:
};