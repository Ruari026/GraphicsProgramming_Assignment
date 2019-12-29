#include "TextureManager.h"
TextureManager* TextureManager::instance = NULL;

TextureManager::TextureManager()
{
	instance = 0;
}

TextureManager* TextureManager::Instance()
{
	if (instance == 0)
	{
		instance = new TextureManager();
	}
	return instance;
}

Texture* TextureManager::GetTexture(std::string fileName)
{
	Texture* textureToGet = nullptr;
	textureToGet = loadedTextures[fileName];

	if (textureToGet == nullptr)
	{
		// Model hasn't been loaded before
		Texture* loadedTexture = new Texture(fileName);
		loadedTextures.insert(make_pair(fileName, loadedTexture));

		textureToGet = loadedTexture;
	}

	return textureToGet;
}