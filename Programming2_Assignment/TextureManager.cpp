#include "TextureManager.h"
TextureManager* TextureManager::instance = nullptr;

TextureManager::TextureManager()
{
}

TextureManager* TextureManager::Instance()
{
	if (instance == nullptr)
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