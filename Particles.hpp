#ifndef PARTICLES_HPP_INCLUDED
#define PARTICLES_HPP_INCLUDED

/// Pretty effects, in any color you want!
class Particles : public virtual AniObject
{
public:
    Particles(std::string img,int x,int y,int width,int height,int fps,bool eoe,float angle,float speed,sf::Color tint,float fric,float turn,float wiggle);
    ~Particles();
    void Update();
    static void Explosion(std::string img,float x,float y,int width,int height,int fps,bool eoe,int num,float speed,sf::Color tint,float fric,float turn,float wiggle);
    static void Line(std::string img,float x,float y,int width,int height,int fps,bool eoe,float angle,float spread,int num,float speed,sf::Color tint,float fric,float turn,float wiggle);
    static void Ring(std::string img,float x,float y,int width,int height,int fps,bool eoe,float num,bool rnd,float speed,sf::Color tint,float fric,float turn,float wiggle);
    static void Wall(std::string img,float x,float y,int width,int height,int fps,bool eoe,float num,float angle,float speed,sf::Color tint,float fric,float turn,float wiggle);
    float angle,speed,fric,turn,wiggle,fx,fy,sspeed;
    sf::Color tint;
};

#endif // PARTICLES_HPP_INCLUDED
