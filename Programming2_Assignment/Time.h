#pragma once
#include <SDL/SDL.h>
#include <iostream>

class Time
{
public:

	static int deltaTime;

	Time();
	~Time();

	void Update();

private:
	uint32_t lastTick;
};