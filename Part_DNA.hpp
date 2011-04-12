#ifndef PART_DNA_HPP
#define PART_DNA_HPP
 namespace Ignatus{

struct Part_DNA{
    std::string img;
    Pointf xy,vel;
    Pointi dim;
    bool eoe,world;
    int fps;
    float fric,turn,wiggle;
    sf::Color tint;
    Part_DNA();
    Part_DNA(std::string img,Point<float> xy,Point<int> dim,int fps,bool eoe,Point<float> vel,sf::Color tint,float fric,float turn,float wiggle,bool world=true);
};
}
#endif // PART_DNA_HPP
