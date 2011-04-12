#ifndef PARTICLES_HPP_INCLUDED
#define PARTICLES_HPP_INCLUDED

namespace Ignatus{

/// Pretty effects, in any color you want!
class Particles : public virtual AniObject{
public:
    sf::Color tint;
    float fric;
    float turn;
    float wiggle;
    Particles(std::string img,Point<float> xy,Point<int> dim,int fps,bool eoe,Point<float> vel,sf::Color tint,float fric,float turn,float wiggle,bool World=true);
    Particles(Part_DNA dna);
    ~Particles();
    void Update();
    static void Explosion(std::string img,Point<float> xy,Point<int> dim,int fps,bool eoe,int num,float speed,sf::Color tint,float fric,float turn,float wiggle,bool World=true);
    static void Ring(std::string img,Point<float> xy,Point<int> dim,int fps,bool eoe,float num,bool rnd,float speed,sf::Color tint,float fric,float turn,float wiggle,bool World=true);
};
}
#endif // PARTICLES_HPP_INCLUDED
