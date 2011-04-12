#include "All.hpp"
namespace Ignatus{

Polygon::Polygon(sf::Color outline,bool doutline,sf::Color fill,bool dfill):GameObject(){
    MyShape=sf::Shape();
    MyFill=fill;
    MyDfill=dfill;
    MyOutline=outline;
    MyDoutline=doutline;
    MyShape.EnableFill(MyDfill);
    MyShape.EnableOutline(MyDoutline);
    MyShape.SetOutlineWidth(2);
}

Polygon::~Polygon(){}

bool Polygon::Fill(){
    return MyDfill;
}
bool Polygon::Outline(){
    return MyDoutline;
}
void Polygon::Fill(bool dfill){
    MyDfill=dfill;
    MyShape.EnableFill(MyDfill);
}
void Polygon::Outline(bool doutline){
    MyDoutline=doutline;
    MyShape.EnableOutline(MyDoutline);
}

void Polygon::AddPoint(Pointf loc){
    MyShape.AddPoint (loc.TwoVector(),MyFill,MyOutline);
}

void Polygon::Draw(sf::RenderWindow* App){
    App->Draw(MyShape);
}

}
