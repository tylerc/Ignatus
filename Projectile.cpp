#include "All.hpp"

namespace Ignatus{

Projectile::Projectile(std::string img,Pointf xy,Pointi dim,Pointf grav,float range,Part_DNA dna):AniObject(img,xy,dim,15,false)
{
    Gravity=grav;
    Life=range;
    AddName("Projectile");
    Parts.push_back(dna);
}

Projectile::~Projectile(){}

void Projectile::Update(){
    Step();
    Velocity=Velocity+Gravity;
    Life-=Velocity.TwoAngle().x;
    Sprite->SetRotation(-Velocity.TwoAngle().y);
    for(unsigned int a=0;a<Parts.size();a++){
        Part_DNA dna=Parts[a];
        dna.xy=dna.xy+Position;
        dna.vel.y+=Velocity.TwoAngle().y;
        new Particles(dna);
    }
}
void Projectile::Step(){}

}
