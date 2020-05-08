#pragma once
#include "Texture.h"

#include <string>
#include <vector>
#include <GL\glew.h>

class Skybox : public Texture
{
public:
	Skybox(std::vector<std::string> fileNames);
	~Skybox();

	void Bind(unsigned int unit);
};