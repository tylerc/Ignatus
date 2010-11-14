#include "All.hpp"

Particles::Particles(std::string img,int x,int y,int width,int height,int fps,bool eoe,float angle,float speed,sf::Color tint,float fric,float turn,float wiggle):AniObject(img,x,y,width,height,fps,eoe){
    this->angle=angle;
    this->speed=speed;
    this->tint=tint;
    this->fric=fric;
    this->wiggle=wiggle;
    this->turn=turn;
    this->fx=x;
    this->fy=y;
    this->sspeed=speed;
    SetCollides(false);
    Sprite->SetCenter(width/2,height/2);
    Sprite->SetColor(tint);
}
Particles::~Particles(){}
void Particles::Update(){
    angle+=turn+sf::Randomizer::Random(-wiggle,wiggle);
    fx=fx+speed*cos(angle*0.01745);
    fy=fy+speed*sin(angle*0.01745);
    x=fx;
    y=fy;
    float r=tint.r;
    float g=tint.g;
    float b=tint.b;
    float a=255;
    if(speed<=3){
        a=(speed/3)*255;
    }
    tint=sf::Color(r,g,b,a);
    Sprite->SetColor(tint);
    speed*=fric;
    if(speed<=1 or x<0 or y<0 or x>_Width or y>_Height){
        life=0;
    }
}
void Particles::Explosion(std::string img,float x,float y,int width,int height,int fps,bool eoe,int num,float speed,sf::Color tint,float fric,float turn,float wiggle)
{
    for(int a=0;a<num;a++){
        Particles* P = new Particles(img,x,y,width,height,fps,eoe,rand()%360,sf::Randomizer::Random(speed/2,speed*1.5),tint,fric,turn,wiggle);
    }
}
void Particles::Line(std::string img,float x,float y,int width,int height,int fps,bool eoe,float angle,float spread,int num,float speed,sf::Color tint,float fric,float turn,float wiggle){
    for(int a=0;a<num;a++){
        Particles* P = new Particles(img,x,y,width,height,fps,eoe,angle+sf::Randomizer::Random(-spread,spread),sf::Randomizer::Random(1.f,speed),tint,fric,turn,wiggle);
        Particles* G = new Particles(img,x,y,width,height,fps,eoe,angle+180+sf::Randomizer::Random(-spread,spread),sf::Randomizer::Random(1.f,speed),tint,fric,turn,wiggle);
    }
}
void Particles::Ring(std::string img,float x,float y,int width,int height,int fps,bool eoe,float num,bool rnd,float speed,sf::Color tint,float fric,float turn,float wiggle){
    int step=360/num;
    for(int a=0;a<num;a++){
        if(rnd==false){
            Particles* P=new Particles(img,x,y,width,height,fps,eoe,step*a+rand()%360,speed,tint,fric,turn,wiggle);
        }else{
            Particles* P=new Particles(img,x,y,width,height,fps,eoe,rand()%360,speed,tint,fric,turn,wiggle);
        }
    }
}
void Particles::Wall(std::string img,float x,float y,int width,int height,int fps,bool eoe,float num,float angle,float speed,sf::Color tint,float fric,float turn,float wiggle){
    int step=speed/num;
    for(int a=0;a<num;a++){
        Particles* P=new Particles(img,x,y,width,height,fps,eoe,angle-90,step*a+2,tint,fric,turn,wiggle);
        Particles* G=new Particles(img,x,y,width,height,fps,eoe,angle+90,step*a+2,tint,fric,turn,wiggle);
    }
}
