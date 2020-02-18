#include "Shader.h"
#include <iostream>
#include <fstream>


Shader::Shader(const std::string& filename)
{
	// Completing the filepaths for both shader types
	std::string vertPath = filename + ".vert";
	std::string geomPath = filename + ".geom";
	std::string fragPath = filename + ".frag";

	// create shader program (openGL saves as ref number)
	program = glCreateProgram();
	if (ShaderExists(vertPath))
	{
		GLuint vertShader = CreateShader(LoadShader(vertPath), GL_VERTEX_SHADER); // create vertex shader
		shaders[0] = vertShader;
	}
	if (ShaderExists(geomPath))
	{
		GLuint geomShader = CreateShader(LoadShader(geomPath), GL_GEOMETRY_SHADER); // create geometry shader
		shaders[1] = geomShader;
	}
	if (ShaderExists(fragPath))
	{
		GLuint fragShader = CreateShader(LoadShader(fragPath), GL_FRAGMENT_SHADER); // create fragment shader
		shaders[2] = fragShader;
	}

	// add both the new fragment and new vertex shaders to the shader program
	for (unsigned int i = 0; i < NUM_SHADERS; i++)
	{
		glAttachShader(program, shaders[i]);
	}

	// Tells OpenGl What part of the data to read in as what variable
	glBindAttribLocation(program, 0, "position");
	glBindAttribLocation(program, 1, "texCoord");
	glBindAttribLocation(program, 2, "normal");

	glLinkProgram(program); //create executables that will run on the GPU shaders
	CheckShaderError(program, GL_LINK_STATUS, true, "Error: Shader program linking failed"); // check for error

	glValidateProgram(program); //check the entire program is valid
	CheckShaderError(program, GL_VALIDATE_STATUS, true, "Error: Shader program not valid");

	uniforms[TRANSFORM_U] = glGetUniformLocation(program, "transform"); // associate with the location of uniform variable within a program
	uniforms[PROJECTION_U] = glGetUniformLocation(program, "projection");
}
Shader::~Shader()
{
	for (unsigned int i = 0; i < NUM_SHADERS; i++)
	{
		glDetachShader(program, shaders[i]); //detach shader from program
		glDeleteShader(shaders[i]); //delete the sahders
	}
	glDeleteProgram(program); // delete the program
}


void Shader::Bind()
{
	glUseProgram(program); //installs the program object specified by program as part of rendering state
}


void Shader::Update(Transform& transform, Camera& camera)
{
	glm::mat4 model = transform.GetModel();
	glm::mat4 viewProjection = camera.GetViewProjection();

	glUniformMatrix4fv(uniforms[TRANSFORM_U], 1, GLU_FALSE, &model[0][0]);
	glUniformMatrix4fv(uniforms[PROJECTION_U], 1, GLU_FALSE, &viewProjection[0][0]);
}


bool Shader::ShaderExists(const std::string& fileName)
{
	std::ifstream file;
	file.open((fileName).c_str());

	if (file.is_open())
	{
		return true;
	}
	else
	{
		return false;
	}
}

GLuint Shader::CreateShader(const std::string& text, unsigned int type)
{
	GLuint shader = glCreateShader(type); //create shader based on specified type

	if (shader == 0) //if == 0 shader no created
		std::cerr << "Error type creation failed " << type << std::endl;

	const GLchar* stringSource[1]; //convert strings into list of c-strings
	stringSource[0] = text.c_str();
	GLint lengths[1];
	lengths[0] = text.length();

	glShaderSource(shader, 1, stringSource, lengths); //send source code to opengl
	glCompileShader(shader); //get open gl to compile shader code

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error compiling shader!"); //check for compile error

	return shader;
}

std::string Shader::LoadShader(const std::string& fileName)
{
	std::ifstream file;
	file.open((fileName).c_str());

	std::string output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		std::cerr << "Unable to load shader: " << fileName << std::endl;
	}

	return output;
}


void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	}
}

// ------------------------------------------------------------------------
void Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(program, name.c_str()), (int)value);

	if ((glGetUniformLocation(program, name.c_str()) == -1))
	{
		std::cerr << "Unable to load shader: " << name.c_str() << std::endl;
		__debugbreak();
	}
}
// ------------------------------------------------------------------------
void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(program, name.c_str()), value);

	if ((glGetUniformLocation(program, name.c_str()) == -1))
	{
		std::cerr << "Unable to load shader: " << name.c_str() << std::endl;
		__debugbreak();
	}
}
// ------------------------------------------------------------------------
void Shader::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(program, name.c_str()), value);

	if ((glGetUniformLocation(program, name.c_str()) == -1))
	{
		std::cerr << "Unable to load shader: " << name.c_str() << std::endl;
		__debugbreak();
	}
}
// ------------------------------------------------------------------------
void Shader::setVec2(const std::string& name, const glm::vec2& value) const
{
	glUniform2fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]);

	if ((glGetUniformLocation(program, name.c_str()) == -1))
	{
		std::cerr << "Unable to load shader: " << name.c_str() << std::endl;
		__debugbreak();
	}
}
void Shader::setVec2(const std::string& name, float x, float y) const
{
	glUniform2f(glGetUniformLocation(program, name.c_str()), x, y);

	if ((glGetUniformLocation(program, name.c_str()) == -1))
	{
		std::cerr << "Unable to load shader: " << name.c_str() << std::endl;
		__debugbreak();
	}
}
// ------------------------------------------------------------------------
void Shader::setVec3(const std::string& name, const glm::vec3& value) const
{
	glUniform3fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]);

	if ((glGetUniformLocation(program, name.c_str()) == -1))
	{
		std::cerr << "Unable to load shader: " << name.c_str() << std::endl;
		__debugbreak();
	}
}
void Shader::setVec3(const std::string& name, float x, float y, float z) const
{
	glUniform3f(glGetUniformLocation(program, name.c_str()), x, y, z);

	if ((glGetUniformLocation(program, name.c_str()) == -1))
	{
		std::cerr << "Unable to load shader: " << name.c_str() << std::endl;
		__debugbreak();
	}
}
// ------------------------------------------------------------------------
void Shader::setVec4(const std::string& name, const glm::vec4& value) const
{
	glUniform4fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]);

	if ((glGetUniformLocation(program, name.c_str()) == -1))
	{
		std::cerr << "Unable to load shader: " << name.c_str() << std::endl;
		__debugbreak();
	}
}
void Shader::setVec4(const std::string& name, float x, float y, float z, float w) const
{
	glUniform4f(glGetUniformLocation(program, name.c_str()), x, y, z, w);

	if ((glGetUniformLocation(program, name.c_str()) == -1))
	{
		std::cerr << "Unable to load shader: " << name.c_str() << std::endl;
		__debugbreak();
	}
}
// ------------------------------------------------------------------------
void Shader::setMat2(const std::string& name, const glm::mat2& mat) const
{
	glUniformMatrix2fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]);

	if ((glGetUniformLocation(program, name.c_str()) == -1))
	{
		std::cerr << "Unable to load shader: " << name.c_str() << std::endl;
		__debugbreak();
	}
}
// ------------------------------------------------------------------------
void Shader::setMat3(const std::string& name, const glm::mat3& mat) const
{
	glUniformMatrix3fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]);

	if ((glGetUniformLocation(program, name.c_str()) == -1))
	{
		std::cerr << "Unable to load shader: " << name.c_str() << std::endl;
		__debugbreak();
	}
}
// ------------------------------------------------------------------------
void Shader::setMat4(const std::string& name, const glm::mat4& mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]);

	if ((glGetUniformLocation(program, name.c_str()) == -1))
	{
		std::cerr << "Unable to load shader: " << name.c_str() << std::endl;
		__debugbreak();
	}
}