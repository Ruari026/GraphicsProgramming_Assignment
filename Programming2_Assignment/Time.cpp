#include "Time.h"

float Time::deltaTime = 0;

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

	deltaTime = (tickTime - lastTick) / 1000.0f;

	lastTick = tickTime;
}


float Time::GetDeltaTime()
{
	return Time::deltaTime;
}