#include "All.hpp"

Sound::Sound(std::string file, float volume=100.0f) : GameObject(false)
{
    if (!SB.LoadFromFile(file))
    {
        std::cout << "Couldn't load sound " << file << std::endl;
        exit(1);
    }
    S.SetBuffer(SB);
    S.SetVolume(volume);
}

Sound::~Sound()
{
    S.Stop();
}

void Sound::Play()
{
    S.Play();
}

float Sound::Volume()
{
    return S.GetVolume();
}

void Sound::Volume(float vol)
{
    S.SetVolume(vol);
}
