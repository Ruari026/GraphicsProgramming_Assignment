#include "AudioPlayer.h"

AudioPlayer::AudioPlayer(GameObject* parent) : Component(parent)
{
}
void AudioPlayer::Init(std::string audioFilePath)
{
	this->audioclip = new Audio(audioFilePath.c_str());
}

void AudioPlayer::Update()
{
}

void AudioPlayer::PlayAudio()
{
	this->audioclip->playSound(0);
}


void AudioPlayer::SetVolume(float newVolume)
{
	this->playerVolume = newVolume;
}