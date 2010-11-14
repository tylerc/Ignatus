#include "All.hpp"

Text::Text(std::string s, float size, std::string file="FreeSans.ttf") : GameObject(false)
{
    name = "Text";
    Font = new sf::Font;
    if (!Font->LoadFromFile(file, (int)size))
    {
        std::cout << "Couldn't load font " << file << std::endl;
        exit(1);
    }
    String = new sf::String(s, *Font, size);
    Reset();
}

void Text::Reset()
{
    width = (int)String->GetRect().GetWidth();
    height = (int)String->GetRect().GetHeight();
}

void Text::Draw(sf::RenderWindow* App)
{
    String->SetPosition(x, y);
    App->Draw(*String);
}
