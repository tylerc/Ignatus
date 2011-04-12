#include "All.hpp"

namespace Ignatus{

Text::Text(std::string s, float size, std::string file="FreeSans.ttf") : GameObject(false)
{
    Name = "Text";
    AddName("Text");
    Font = new sf::Font;
    if (!Font->LoadFromFile(file, (int)size))
    {
        std::cout << "Couldn't load font " << file << std::endl;
        exit(1);
    }
    Label = new sf::String(s, *Font, size);
    Reset();
}

void Text::Reset()
{
    Dimensions.x = (int)Label->GetRect().GetWidth();
    Dimensions.y = (int)Label->GetRect().GetHeight();
}

void Text::Draw(sf::RenderWindow* App)
{
    Label->SetPosition(Position.x, Position.y);
    App->Draw(*Label);
}

}
