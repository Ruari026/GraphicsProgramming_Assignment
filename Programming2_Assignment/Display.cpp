#include "Display.h"

Display::Display(float width, float height)
{
	sdlWindow = nullptr; //initialise to generate null access violation for debugging. 
	
	// Initalising SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// set up double buffer   
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Window Creation
	sdlWindow = SDL_CreateWindow("Super Polaroid Ball", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)width, (int)height, SDL_WINDOW_OPENGL);
	if (sdlWindow == nullptr)
	{
		returnError("window failed to create");
	}

	// Context Creation from Window
	glContext = SDL_GL_CreateContext(sdlWindow);
	if (glContext == nullptr)
	{
		returnError("SDL_GL context failed to create");
	}

	// Initalising GLEW
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		returnError("GLEW failed to initialise");
	}

	// Settings for rendering blending
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	//Settings for rendering depth buffering & overlap
	glEnable(GL_DEPTH_TEST); 
	glDepthFunc(GL_LEQUAL); //specifying how OpenGL compares depth values


	//dont draw faces that are not pointing at the camera
	glEnable(GL_CULL_FACE); 
}

Display::~Display()
{
	SDL_GL_DeleteContext(glContext); // deleting context
	SDL_DestroyWindow(sdlWindow); // deteting window
	SDL_Quit();
}

void Display::returnError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "press any  key to quit...";
	int in;
	std::cin >> in;
	SDL_Quit();
}

void Display::swapBuffer()
{
	//swapping buffers
	SDL_GL_SwapWindow(sdlWindow);
}

void Display::clearDisplay(float r, float g, float b, float a)
{
	glClearColor(r, b, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear colour and depth buffer - set colour to colour defined in glClearColor
}