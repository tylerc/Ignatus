#ifndef SOUND_HPP_INCLUDED
#define SOUND_HPP_INCLUDED

namespace Ignatus{

/// All your sound effect needs, in one convient place.
class Sound : public virtual GameObject
{
public:
    sf::Sound S;
    sf::SoundBuffer SB;

    Sound(std::string file, float volume);
    virtual ~Sound();
    void Play();
    float Volume();
    void Volume(float vol);
};
}
#endif // SOUND_HPP_INCLUDED
