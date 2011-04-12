#ifndef SLIDEBAR_HPP
#define SLIDEBAR_HPP

namespace Ignatus{

class SlideBar:public virtual GameObject{
public:
    sf::Rect<float> Area;
    sf::Rect<float> BtnArea;
    bool Sideways;
    Pointf MinMax;
    float Value;
    SlideBar();
    SlideBar(sf::Rect<float> area,sf::Rect<float> btnarea,Pointf minmax,bool sideways=true);
    virtual ~SlideBar();
    virtual void UpdateMagic();
};

}

#endif // SLIDEBAR_HPP
