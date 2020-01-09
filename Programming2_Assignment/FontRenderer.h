#pragma once
#include "Component.h"
#include "Font.h"
#include "Shader.h"

#include <string>

class FontRenderer : public Component
{
public:
	FontRenderer(GameObject* parent);
	~FontRenderer();
	void Update();

	void Init(std::string fontFilePath, int fontSize);
	void SetFontText(std::string newText);
	void SetFontColor(SDL_Color newColor);
	void setTextWrapLength(int newWrapLength);

private:
	Font* font;

	// Text Details
	std::string fontText;
	SDL_Color fontColor;
	int wrapLength;

	// Information required to render to the screen
	SDL_Surface* fontTextSurface;
	GLuint fontTextTexture;
};