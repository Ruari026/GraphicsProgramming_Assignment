#pragma once
#include "Component.h"
#include "Audio.h"

#include <string>

class AudioPlayer : public Component
{
public:
	AudioPlayer(GameObject* parent);
	void Update();

	void Init(std::string audioFilePath);
	void PlayAudio();
	void SetVolume(float newVolume);

private:
	Audio* audioclip;
	float playerVolume;
};

