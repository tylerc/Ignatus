#ifndef MUSIC_HPP_INCLUDED
#define MUSIC_HPP_INCLUDED

/// Hear that bass blastin'? Nope? Use this class, rock the house.
class Music : public virtual GameObject
{
public:
    sf::Music M;

    Music(std::string file, float volume=100.0f, bool loop=false);
    virtual ~Music();
    void Play();
    void Stop();
    void Pause();
    float Volume();
    void Volume(float vol);
};

#endif // MUSIC_HPP_INCLUDED
