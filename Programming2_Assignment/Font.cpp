#include "Font.h"

Font::Font(std::string filePath, int fontSize)
{
	TTF_Init();
	loadedFont = TTF_OpenFont(filePath.c_str(), fontSize);
}
Font::~Font()
{
	TTF_CloseFont(loadedFont);
}