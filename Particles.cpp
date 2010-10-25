#include "Engine.hpp"

Particles::Particles(std::string img,int x,int y,int width,int height,int fps,bool eoe,float angle,float speed,sf::Color tint,float fric,float turn,float wiggle):AniObject(img,width,height,fps,eoe){
    this->angle=angle;
    this->speed=speed;
    this->tint=tint;
    this->fric=fric;
    this->wiggle=wiggle;
    this->turn=turn;
    this->x=x;
    this->y=y;
    SetCollides(false);
    Sprite->SetColor(tint);
}
Particles::~Particles(){}
void Particles::Update(){
    angle+=turn+sf::Randomizer::Random(-wiggle,wiggle);
    x=x+speed*cos(angle*0.01745);
    y=y+speed*sin(angle*0.01745);
    speed*=fric;
    if(speed<=1 or x<0 or y<0 or x>_Width or y>_Height){
        life=0;
    }
}
