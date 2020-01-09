#pragma once
#include <SDL/SDL.h>

class Time
{
public:
	Time();
	~Time();

	void Update();

	static float GetDeltaTime();

private:
	uint32_t lastTick;
	static float deltaTime;
};