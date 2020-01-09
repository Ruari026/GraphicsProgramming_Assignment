#include "FontRenderer.h"

#include "GameObject.h"
#include "GameScene.h"

#include <glm/glm.hpp>

FontRenderer::FontRenderer(GameObject* parent) : Component(parent)
{
}
FontRenderer::~FontRenderer()
{
	glDeleteTextures(1, &fontTextTexture);
	SDL_FreeSurface(fontTextSurface);
}


void FontRenderer::Update()
{
	// Settings for rendering in screen space
	glOrtho(0, DISPLAY_WIDTH, 0, DISPLAY_HEIGHT, -1, 1);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glGenTextures(1, &fontTextTexture);
	glBindTexture(GL_TEXTURE_2D, fontTextTexture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, fontTextSurface->w, fontTextSurface->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, fontTextSurface->pixels);

	// Rendering Text To The Screen
	glBegin(GL_QUADS);
	{
		// Font's position on the screen
		glm::vec3 fontPos = *gameObject->thisTransform->GetGlobalPos();

		glTexCoord2f(0, 1); 
		glVertex2f(fontPos.x, fontPos.y);

		glTexCoord2f(1, 1); 
		glVertex2f(fontPos.x + fontTextSurface->w, fontPos.y);

		glTexCoord2f(1, 0); 
		glVertex2f(fontPos.x + fontTextSurface->w, fontPos.y + fontTextSurface->h);

		glTexCoord2f(0, 0); 
		glVertex2f(fontPos.x, fontPos.y + fontTextSurface->h);
	}
	glEnd();


	// Cleaning up
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glDeleteTextures(1, &fontTextTexture);
}


void FontRenderer::Init(std::string fontFilePath, int fontSize)
{
	font = new Font(fontFilePath, fontSize);
}


void FontRenderer::SetFontText(std::string newText)
{
	// No point changing the text if it is the same as the new text value
	if (fontText != newText)
	{
		fontText = newText;

		// Cleaning up previously created resources
		glDeleteTextures(1, &fontTextTexture);
		SDL_FreeSurface(fontTextSurface);

		// Using Font Text String to create a surface
		fontTextSurface = TTF_RenderText_Blended_Wrapped(font->loadedFont, fontText.c_str(), fontColor, wrapLength);
	}
}

void FontRenderer::SetFontColor(SDL_Color newColor)
{
	this->fontColor = newColor;
}

void FontRenderer::setTextWrapLength(int newWrapLength)
{
	this->wrapLength = newWrapLength;
}