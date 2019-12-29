#pragma once

#include <string>
#include <map>

#include "Texture.h"

class TextureManager
{
public:
	static TextureManager* Instance();
	Texture* GetTexture(std::string fileName);

private:
	TextureManager();

	static TextureManager* instance;

	std::map<std::string, Texture*> loadedTextures;
};

