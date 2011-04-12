#include "../All.hpp"

namespace Ignatus{

SlideBar::SlideBar():GameObject(){}

SlideBar::SlideBar(sf::Rect<float> area,sf::Rect<float> btnarea,Pointf minmax,bool sideways):GameObject(){
    Area=area;
    BtnArea=btnarea;
    MinMax=minmax;
    Sideways=sideways;
    Value=0;
}

SlideBar::~SlideBar(){}

void SlideBar::UpdateMagic(){
    GameObject::Update();
    GameObject::UpdateMagic();
    //_E.App->.Draw(sf::Shape:Rectangle())
}

}
