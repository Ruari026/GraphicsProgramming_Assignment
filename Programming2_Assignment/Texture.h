#pragma once
#include <string>
#include <GL\glew.h>

class Texture
{
public:
	Texture(const std::string& fileName);
	~Texture();

	void Bind(unsigned int unit); // bind upto 32 textures

private:
	GLuint textureHandler;
};

