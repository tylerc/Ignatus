#ifndef PARTICLE_HPP
#define PARTICLE_HPP

namespace Ignatus{

class Particle: public virtual AniObject{
public:
    bool Loop;
    int Slife;
    bool Decay;
    bool Fade;
    sf::Color Stint;
    sf::Color Etint;
    sf::Color Mtint;
    float Friction;
    float Turn;
    float Wiggle;
    float Acceleration;
    Pointf Gravity;
    struct DNA{
        std::string Img;
        Pointf Position;
        Pointf Velocity;
        bool World;
        Pointi Dimensions;
        int FPS;
        bool Loop;
        int Slife;
        bool Decay;
        bool Fade;
        sf::Color Stint;
        sf::Color Etint;
        sf::Color Mtint;
        float Friction;
        float Turn;
        float Wiggle;
        float Acceleration;
        Pointf Gravity;
        DNA(std::string img,Point<float> xy,Point<int> dim,int fps,Point<float> vel,sf::Color stint,sf::Color etint,float fric,float turn,float wiggle,bool loop=true,bool World=true);
    };
    Particle(std::string img,Point<float> xy,Point<int> dim,int fps,Point<float> vel,sf::Color stint,sf::Color etint,float fric,float turn,float wiggle,bool loop=true,bool World=true);
    Particle(Particle::DNA dna);
    static void CreateShape(Particle::DNA dna,std::vector<Pointf> pos,bool Align=false);
    static void Explosion(int num,Pointf range,Particle::DNA dna,bool even=false);
    static void Ring(int num,Pointf range,Particle::DNA dna,bool even=false);
    virtual ~Particle();
    void Update();
    static int Part_Count;
private:
};

}

#endif // PARTICLE_HPP
