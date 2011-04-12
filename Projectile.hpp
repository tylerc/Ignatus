#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

namespace Ignatus{

class Projectile :public virtual AniObject{
public:
    Projectile(std::string img,Pointf xy,Pointi dim,Pointf grav,float range,Part_DNA dna);
    ~Projectile();
    virtual void Update();
    virtual void Step();
    Pointf Gravity;
    std::vector<Part_DNA> Parts;
};
}
#endif // PROJECTILE_HPP
