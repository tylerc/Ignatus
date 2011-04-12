#ifndef MUSIC_HPP_INCLUDED
#define MUSIC_HPP_INCLUDED

namespace Ignatus{

/// Hear that bass blastin'? Nope? Use this class, rock the house.
class Music : public virtual GameObject
{
public:
    sf::Music M; //!< This is the raw SFML Music variable.

    ///This allows you to make music with one line.
    /**
    Adds music to your game with one line.
    Will not play the music, for that use the Play() function.
    */
    Music(std::string file, float volume=100.0f, bool loop=false);
    /// Deconstructor for Music, called when Life equal or less than 0.
    /**
    Cleans up the Music instance.
    */
    virtual ~Music();
    ///Plays the music.
    /**
    This is the actual funtion to play music you've added with the constructor.
    */
    void Play();
    /// Stops the playing music.
    /**
    If the music isn't playing, does nothing.
    */
    void Stop();
    /// Pauses the music.
    /**
    This is different from Stop(), when you call Play() again it plays from the position you paused, not the beginning.
    */
    void Pause();
    /// Gets the volume of the music.
    float Volume();
    /// Sets the volume of the music.
    /**
    Value is clipped to 0-100.
    */
    void Volume(float vol);
};
}
#endif // MUSIC_HPP_INCLUDED
