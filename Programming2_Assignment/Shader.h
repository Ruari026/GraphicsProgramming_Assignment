#pragma once
#include <string>
#include <GL\glew.h>
#include "transform.h"
#include "camera.h"

class Shader
{
public:
	Shader(const std::string& filename);

	void Bind(); //Set gpu to use our shaders
	void Update(Transform& transform, Camera& camera);

	std::string Shader::LoadShader(const std::string& fileName);
	void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint Shader::CreateShader(const std::string& text, unsigned int type);

	~Shader();


protected:
private:
	static const unsigned int NUM_SHADERS = 2; // number of shaders (Each shader program always has a vertex and fragment shader)

	enum
	{
		TRANSFORM_U,
		PROJECTION_U,
		NUM_UNIFORMS
	};

	GLuint program; // Track the shader program
	GLuint shaders[NUM_SHADERS]; //array of shaders
	GLuint uniforms[NUM_UNIFORMS]; //no of uniform variables
};
