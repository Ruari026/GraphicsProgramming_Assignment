#include "Time.h"

int Time::deltaTime = 0;

Time::Time()
{
	lastTick = 0;
}
Time::~Time()
{

}


void Time::Update()
{
	uint32_t tickTime = SDL_GetTicks();

	deltaTime = tickTime - lastTick;

	lastTick = tickTime;
}