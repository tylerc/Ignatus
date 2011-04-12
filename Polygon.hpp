#ifndef POLYGON_HPP
#define POLYGON_HPP

namespace Ignatus{

class Polygon:public virtual GameObject{
public:
    sf::Shape MyShape;
    Polygon(sf::Color outline=sf::Color::White,bool doutline=true,sf::Color fill=sf::Color::White,bool dfill=false);
    void AddPoint(Pointf loc);
    virtual ~Polygon();
    virtual void Draw(sf::RenderWindow* App);
    void Fill(bool dfill);
    bool Fill();
    void Outline(bool doutline);
    bool Outline();
private:
    sf::Color MyFill,MyOutline;
    bool MyDfill,MyDoutline;
};

}

#endif // POLYGON_HPP
