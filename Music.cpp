#include "All.hpp"

namespace Ignatus{

Music::Music(std::string file, float volume, bool loop)
{
    if (!M.OpenFromFile(file))
    {
        std::cout << "Couldn't load music " << file << std::endl;
        exit(1);
    }
    M.SetVolume(volume);
    M.SetLoop(loop);
}

Music::~Music()
{
    M.Stop();
}

void Music::Play()
{
    M.Play();
}

void Music::Stop()
{
    M.Stop();
}

void Music::Pause()
{
    M.Pause();
}

float Music::Volume()
{
    return M.GetVolume();
}

void Music::Volume(float vol)
{
    M.SetVolume(vol);
}

}
