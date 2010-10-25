#ifndef ANISPRITE_HPP_INCLUDED
#define ANISPRITE_HPP_INCLUDED

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

/// You know AniObject? It whores almost everything out to this class.
class AniSprite : public sf::Sprite
{
public:
	AniSprite();
	AniSprite(const sf::Image& Img, int frameWidth, int frameHeight,float fps,bool center);
	~AniSprite(void);
	sf::IntRect GetFramePosition(int frame);
	int GetFrameCount();
	bool IsPlaying();
	void SetFrame(int frame);
	void SetLoopSpeed(float fps);
	void SetEndonEnd(bool end);
	void SetFrameSize(int frameWidth, int frameHeight);
	void SetCent();
	void Play();
	void Play(int start, int end);
	void Stop();
	void Update();
private:
	sf::Clock clock;
	float fps;
	bool isPlaying;
	int loopStart;
	int loopEnd;
	int currentFrame;
	int frameWidth;
	int frameHeight;
	bool endonend;
};
#endif // ANISPRITE_HPP_INCLUDED
