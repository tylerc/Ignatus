#include "AniSprite.hpp"
AniSprite::AniSprite(void):sf::Sprite(){
	this->fps=1;
	this->currentFrame=0;
	this->isPlaying=false;
	this->loopStart=0;
	this->SetFrameSize(0, 0);
	this->endonend=false;
}
AniSprite::AniSprite(const sf::Image& Img, int frameW, int frameH, float fps,bool center) : sf::Sprite(Img){
	this->fps=fps;
	this->currentFrame=0;
	this->isPlaying=false;
	this->loopStart=0;
	this->SetFrameSize(frameW,frameH);
	this->endonend=false;
	if(center){
        this->SetCent();
	}
}
AniSprite::~AniSprite(void){}
sf::IntRect AniSprite::GetFramePosition(int frame){
	//get number across and down
	unsigned int across=(this->GetImage()->GetWidth()/this->frameWidth);
	//unsigned int down = (this->GetImage()->GetHeight() / this->frameHeight);
    int tileY=frame/across;//get Y on grid
    int tileX=frame%across;//get X on grid
	sf::IntRect result(
		tileX*this->frameWidth,
		tileY*this->frameHeight,
		tileX*this->frameWidth + this->frameWidth,
		tileY*this->frameHeight + this->frameHeight);
	return result;
}
int AniSprite::GetFrameCount(){
	unsigned int across=this->GetImage()->GetWidth()/this->frameWidth;
	unsigned int down=this->GetImage()->GetHeight()/this->frameHeight;
	return across*down;
}
bool AniSprite::IsPlaying(){
    return isPlaying;
}
void AniSprite::SetCent(){
    this->SetCenter(frameWidth/2,frameHeight/2);
}
void AniSprite::SetEndonEnd(bool end){
    endonend=end;
}
void AniSprite::SetFrameSize(int frameW, int frameH){
	this->frameWidth = frameW;
	this->frameHeight = frameH;
	this->SetSubRect(sf::IntRect(0,0,frameW,frameH));
}
void AniSprite::SetFrame(int frame){
	this->currentFrame = frame;
}
void AniSprite::SetLoopSpeed(float newfps){
	this->fps = newfps;
}
void AniSprite::Play(){
    this->Play(0,GetFrameCount());
}
void AniSprite::Play(int start, int end){
    if(isPlaying==false){
        loopStart=start;
        loopEnd=end;
        currentFrame=start;
        isPlaying=true;
        clock.Reset();
    }
}
void AniSprite::Stop(){
	isPlaying=false;
}
void AniSprite::Update(){
	if(isPlaying){
		int frameCount=loopEnd-loopStart;
 		float timePosition=(clock.GetElapsedTime()*fps);
		currentFrame=loopStart+(int)timePosition%frameCount;
		if(currentFrame==GetFrameCount()-1 and endonend==true){
		    isPlaying=false;
        }
		this->SetSubRect(GetFramePosition(currentFrame));
	}
}
