#include "All.hpp"

GameObject::GameObject(std::string file, int x, int y, bool collides)
{
    Image = _E.LoadImage(file);
    Image->SetSmooth(false);
    Sprite = new sf::Sprite(*Image);
    this->width = Image->GetWidth();
    this->height = Image->GetHeight();
    this->x = x;
    this->y = y;
    this->name = "GameObject";
    this->life = 1;
    _CS->Add(this);
    Collides = collides;
    if (collides)
        _CS->AddCollider(this);
}

GameObject::GameObject(bool collides)
{
    life = 1;
    name = "GameObject";
    x = 0;
    y = 0;
    Sprite = NULL;
    Image = NULL;
    _CS->Add(this);
    Collides = collides;
    if (collides)
        _CS->AddCollider(this);
}

GameObject::~GameObject()
{
    //std::cout << "Bye " << this->name << "!\n";
    if (Sprite != NULL)
    {
        delete Sprite;
    }
    if (Image != NULL)
    {
        //delete Image;
    }
}

void GameObject::Update() {}

void GameObject::Draw(sf::RenderWindow* App)
{
    if (Sprite != NULL)
    {
        Sprite->SetPosition(x, y);
        App->Draw(*Sprite);
    }
}

void GameObject::Collision(GameObject* g) {}

void GameObject::UpdateMagic()
{
    for (unsigned int i = 0; i < WhileKeyPressedChecks.size(); i++)
    {
        if (_E.Input->IsKeyDown(WhileKeyPressedChecks[i].Key))
        {
            WhileKeyPressedChecks[i].func();
        }
    }
}

void GameObject::WhileKeyDown(sf::Key::Code Key, boost::function<void()> func)
{
    KeyCheck kc;
    kc.Key = Key;
    kc.func = func;
    WhileKeyPressedChecks.push_back(kc);
}

void GameObject::KeyPressed(sf::Key::Code key, boost::function<void(sf::Event::Event)> func)
{
    State::Event Ev;
    Ev.owner = this;
    Ev.func = func;
    Ev.type = sf::Event::KeyPressed;
    Ev.key = key;
    Ev.has_key = true;
    _CS->AddEvent(Ev);
}

void GameObject::KeyReleased(sf::Key::Code key, boost::function<void(sf::Event::Event)> func)
{
    State::Event Ev;
    Ev.owner = this;
    Ev.func = func;
    Ev.type = sf::Event::KeyReleased;
    Ev.key = key;
    Ev.has_key = true;
    _CS->AddEvent(Ev);
}

void GameObject::AddEvent(sf::Event::EventType type, boost::function<void(sf::Event::Event)> func)
{
    State::Event Ev;
    Ev.owner = this;
    Ev.func = func;
    Ev.type = type;
    Ev.has_key = false;
    _CS->AddEvent(Ev);
}

void GameObject::SetCollides(bool collides)
{
    if (Collides != collides)
    {
        if (collides == true)
        {
            _CS->AddCollider(this);
        } else {
            _CS->RemoveCollider(this);
        }
    }
}
