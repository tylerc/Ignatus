#include "All.hpp"

namespace Ignatus{
Part_DNA::Part_DNA(){
    img="";
    xy=Pointf();
    dim=Pointi();
    fps=0;
    vel=Pointf();
    tint=sf::Color(0,0,0);
    fric=0;
    turn=0;
    wiggle=0;
    eoe=false;
    world=true;
}
Part_DNA::Part_DNA(std::string img,Point<float> xy,Point<int> dim,int fps,bool eoe,Point<float> vel,sf::Color tint,float fric,float turn,float wiggle,bool world){
    this->img=img;
    this->xy=xy;
    this->dim=dim;
    this->fps=fps;
    this->vel=vel;
    this->tint=tint;
    this->fric=fric;
    this->turn=turn;
    this->wiggle=wiggle;
    this->eoe=eoe;
    this->world=world;
}

}
