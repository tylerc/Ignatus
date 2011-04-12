#include "../All.hpp"

namespace Ignatus{

namespace GUI{

Bar::Bar():GameObject(false){
    Name="Bar";
    Full=sf::Color::Black;
    Empty=sf::Color::Black;
    Back=sf::Color::Black;
    Percent=0;
    Hor=true;
}

Bar::Bar(sf::Color full,sf::Color empty,sf::Color back,Pointf xy,Pointi dim,bool hor){
    Full=full;
    Empty=empty;
    Back=back;
    Position=xy;
    Dimensions=dim;
    Percent=1;
    Hor=hor;
    Name="Bar";
    AddName("Bar");
}

Bar::~Bar(){}

void Bar::Draw(sf::RenderWindow* App)
{
    Position=Position+Velocity;
    if(App){
        float Red=Full.r*Percent+Empty.r*(1-Percent);
        float Green=Full.g*Percent+Empty.g*(1-Percent);
        float Blue=Full.b*Percent+Empty.b*(1-Percent);
        sf::Color Display=sf::Color(Red,Green,Blue);
        App->Draw(sf::Shape::Rectangle(Position.x,Position.y,Position.x+Dimensions.x,Position.y+Dimensions.y,Back));
        if(Hor){
            App->Draw(sf::Shape::Rectangle(Position.x,Position.y,Position.x+Dimensions.x*Percent,Position.y+Dimensions.y,Display));
        }else{
            App->Draw(sf::Shape::Rectangle(Position.x,Position.y,Position.x+Dimensions.x,Position.y+Dimensions.y*Percent,Display));
        }
    }
}
}
}
