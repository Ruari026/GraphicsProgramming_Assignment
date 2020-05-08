#include "Skybox.h"
#include "stb_image.h"
#include <cassert>
#include <iostream>

Skybox::Skybox(std::vector<std::string> fileNames)
{
	glGenTextures(1, &textureHandler);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureHandler);

	int width, height, nrChannels;
	for (unsigned int i = 0; i < fileNames.size(); i++)
	{
		unsigned char *data = stbi_load(fileNames[i].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
				0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
			);
			stbi_image_free(data);
		}
		else
		{
			std::cout << "Cubemap texture failed to load at path: " << fileNames[i] << std::endl;
			stbi_image_free(data);
		}
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

Skybox::~Skybox()
{
	glDeleteTextures(1, &textureHandler); // number of and address of textures
}

void Skybox::Bind(unsigned int unit)
{
	assert(unit >= 0 && unit <= 31); /// check we are working with one of the 32 textures

	glActiveTexture(GL_TEXTURE_CUBE_MAP + unit); //set acitve texture unit
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureHandler); //type of and texture to bind to unit
}