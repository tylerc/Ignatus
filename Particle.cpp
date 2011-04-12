#include "All.hpp"

namespace Ignatus{

int Particle::Part_Count=0;

Particle::Particle(std::string img,Point<float> xy,Point<int> dim,int fps,Point<float> vel,sf::Color stint,sf::Color etint,float fric,float turn,float wiggle,bool loop,bool World):AniObject(img,xy,dim,fps,loop){
    Particle::Part_Count++;
    AddName("Particle");
    SetCollides(false);
    Etint=etint;
    Stint=stint;
    Mtint=sf::Color((etint.r+stint.r)/2,(etint.g+stint.g)/2,(etint.b+stint.b)/2,(etint.a+stint.a)/2);
    Loop=loop;
    Slife=Life;
    Decay=0;
    Fade=false;
    Friction=fric;
    Turn=turn;
    Wiggle=wiggle;
    Acceleration=0;
    Gravity=Pointf();
    Velocity=vel;
}

Particle::Particle(Particle::DNA dna):AniObject(dna.Img,dna.Position,dna.Dimensions,dna.FPS,dna.Loop){
    Particle::Part_Count++;
    SetCollides(false);
    AddName("Particle");
    Etint=dna.Etint;
    Stint=dna.Stint;
    Mtint=dna.Mtint;
    Loop=dna.Loop;
    Slife=dna.Slife;
    Life=Slife;
    Decay=dna.Decay;
    Fade=dna.Fade;
    Friction=dna.Friction;
    Turn=dna.Turn;
    Wiggle=dna.Wiggle;
    Acceleration=dna.Acceleration;
    Gravity=dna.Gravity;
    Velocity=dna.Velocity;
}

Particle::~Particle()
{
    Part_Count--;
}

void Particle::Update(){
    /**
    Change the movement angle based on Turn and +/- Wiggle.
    Acceleration, Gravity.
    */
    Point<float> Temp_Point=Velocity.TwoAngle();
    Temp_Point.x*=Friction;
    Temp_Point.y+=Turn+sf::Randomizer::Random(-Wiggle,Wiggle)+Acceleration;
    Velocity=Temp_Point.TwoVelocity();
    Velocity+=Gravity;
    /**
    Handle the tinting of the particle.
    */
    float per=float(Life)/float(Slife);
    sf::Color c;
    if(per>=.5){
        float pper=per-.5;
        c=Stint;
        c.r*=(pper*2);
        c.g*=(pper*2);
        c.b*=(pper*2);
        c.a*=(pper*2);
        c.r+=Mtint.r*(1-(pper*2));
        c.g+=Mtint.g*(1-(pper*2));
        c.b+=Mtint.b*(1-(pper*2));
        c.a+=Mtint.a*(1-(pper*2));
    }else{
        c=Mtint;
        c.r*=(per*2);
        c.g*=(per*2);
        c.b*=(per*2);
        c.a*=(per*2);
        c.r+=Etint.r*(1-(per*2));
        c.g+=Etint.g*(1-(per*2));
        c.b+=Etint.b*(1-(per*2));
        c.a+=Etint.a*(1-(per*2));
    }
    /**
    Decay and Life...
    Fading...
    */
    if(Fade){
        c.a*=per;
    }
    AS->SetColor(c);
    Life-=Decay;
}

void Particle::CreateShape(Particle::DNA dna,std::vector<Pointf> pos,bool Align){
    for(unsigned int a=0;a<pos.size();a++){
        if(Align){
            if(pos.size()>1){
                Pointf Angle=dna.Velocity.TwoAngle();
                Angle.y=pos[0].Get_Angle(pos[a]);
                dna.Velocity=Angle.TwoVelocity();
                dna.Position=pos[a];
                new Particle(dna);
            }
        }else{
            dna.Position=pos[a];
            new Particle(dna);
        }
    }
}

void Particle::Explosion(int num,Pointf range,Particle::DNA dna,bool even){
    float angle=(range.y-range.x)/num;
    for(int a=0;a<num;a++){
        Pointf ang=dna.Velocity.TwoAngle();
        ang.x=sf::Randomizer::Random(float(ang.x*.66),float(ang.x*1.33));
        ang.y= even ? range.x+angle*a : sf::Randomizer::Random(range.x,range.y);
        dna.Velocity=ang.TwoVelocity();
        new Particle(dna);
    }
}

void Particle::Ring(int num,Pointf range,Particle::DNA dna,bool even){
    float angle=(range.y-range.x)/num;
    for(int a=0;a<num;a++){
        Pointf ang=dna.Velocity.TwoAngle();
        ang.y= even ? range.x+angle*a : sf::Randomizer::Random(range.x,range.y);
        dna.Velocity=ang.TwoVelocity();
        new Particle(dna);
    }
}

/// //////////////

Particle::DNA::DNA(std::string img,Point<float> xy,Point<int> dim,int fps,Point<float> vel,sf::Color stint,sf::Color etint,float fric,float turn,float wiggle,bool loop,bool World){
    Img=img;
    Position=xy;
    Velocity=vel;
    this->World=World;
    Dimensions=dim;
    FPS=fps;
    Etint=etint;
    Stint=stint;
    Mtint=sf::Color((etint.r+stint.r)/2,(etint.g+stint.g)/2,(etint.b+stint.b)/2,(etint.a+stint.a)/2);
    Slife=1;
    Decay=0;
    Fade=false;
    Friction=fric;
    Turn=turn;
    Wiggle=wiggle;
    Acceleration=0;
    Gravity=Pointf();
    Velocity=vel;
}

}
