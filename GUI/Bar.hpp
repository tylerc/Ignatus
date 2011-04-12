#ifndef BAR_HPP
#define BAR_HPP

namespace Ignatus{

namespace GUI{

class Bar:public virtual GameObject{
public:
    float Percent;
    bool Hor;
    sf::Color Full,Empty,Back;
    Bar();
    Bar(sf::Color full,sf::Color empty,sf::Color back,Pointf xy,Pointi dim,bool hor=true);
    virtual ~Bar();
    virtual void Draw(sf::RenderWindow* App);
};
}
}

#endif // BAR_HPP
