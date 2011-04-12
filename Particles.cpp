#include "All.hpp"

namespace Ignatus{

Particles::Particles(std::string img,Point<float> xy,Point<int> dim,int fps,bool eoe,Point<float> vel,sf::Color tint,float fric,float turn,float wiggle,bool World):AniObject(img,xy,dim,fps,eoe){
    Velocity=vel.TwoVelocity();
    this->tint=tint;
    this->fric=fric;
    this->wiggle=wiggle;
    this->turn=turn;
    SetCollides(false);
    AddName("Particle");
    Sprite->SetCenter(dim.x/2,dim.y/2);
    Sprite->SetColor(tint);
    this->World=World;
    Depth=0.1;
}
Particles::Particles(Part_DNA dna):AniObject(dna.img,dna.xy,dna.dim,dna.fps,dna.eoe){
    Depth=0.1;
    AddName("Particle");
    Velocity=dna.vel.TwoVelocity();
    this->tint=dna.tint;
    this->fric=dna.fric;
    this->wiggle=dna.wiggle;
    this->turn=dna.turn;
    SetCollides(false);
    Sprite->SetCenter(dna.dim.x/2,dna.dim.y/2);
    Sprite->SetColor(dna.tint);
    this->World=dna.world;
}
Particles::~Particles(){}
void Particles::Update(){
    ///Convert velocity from vel to angle add random angle and convert back.
    Point<float> Temp_Point=Velocity.TwoAngle();
    Temp_Point.x*=fric;
    Temp_Point.y+=turn+sf::Randomizer::Random(-wiggle,wiggle);
    Velocity=Temp_Point.TwoVelocity();

    float r=tint.r;
    float g=tint.g;
    float b=tint.b;
    float a=255;
    if(Temp_Point.x<=3){
        a=(Temp_Point.x/3)*255;
    }
    ///Destroy particales off screen. V
    //if(AS->GetRect().Intersects(sf::Rect<int>(_E.Screen_View,obj2->Position.y,obj2->Position.x+obj2->Dimensions.x,obj2->Position.y+obj2->Dimensions.y)))
    if(Temp_Point.x<=1)Life=0;
    tint=sf::Color(r,g,b,a);
    Sprite->SetColor(tint);
}
void Particles::Explosion(std::string img,Point<float> xy,Point<int> dim,int fps,bool eoe,int num,float speed,sf::Color tint,float fric,float turn,float wiggle,bool World){
    for(int a=0;a<num;a++){
        new Particles(img,xy,dim,fps,eoe,Point<float>(sf::Randomizer::Random(speed/2,speed*1.5),rand()%360),tint,fric,turn,wiggle,World);
    }
}

void Particles::Ring(std::string img,Point<float> xy,Point<int> dim,int fps,bool eoe,float num,bool rnd,float speed,sf::Color tint,float fric,float turn,float wiggle,bool World){
    int step=360/num;
    int off=rand()%360;
    for(int a=0;a<num;a++){
        if(rnd==false){
            new Particles(img,xy,dim,fps,eoe,Point<float>(speed,a*step+off),tint,fric,turn,wiggle,World);
        }else{
            new Particles(img,xy,dim,fps,eoe,Point<float>(speed,rand()%360),tint,fric,turn,wiggle,World);
        }
    }
}

}
