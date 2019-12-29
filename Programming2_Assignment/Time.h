#pragma once
#include <SDL/SDL.h>

class Time
{
public:

	static float deltaTime;

	Time();
	~Time();

	void Update();

private:
	uint32_t lastTick;
};