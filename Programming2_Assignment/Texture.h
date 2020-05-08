#pragma once
#include <string>
#include <vector>
#include <GL\glew.h>

class Texture
{
public:
	Texture(const std::string& fileName);
	~Texture();

	virtual void Bind(unsigned int unit); // bind upto 32 textures

protected:
	Texture();

	GLuint textureHandler;
};