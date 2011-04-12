#include "All.hpp"

namespace Ignatus{

GameObject::GameObject(std::string file, Point<float> xy, bool collides)
{
    Image = _E.LoadImage(file);
    Image->SetSmooth(false);
    Sprite = new sf::Sprite(*Image);
    Dimensions=Point<int>(Image->GetWidth(),Image->GetHeight());
    Position=xy;
    Center=Position+Pointf(Dimensions.x,Dimensions.y)/Pointf(2);
    Depth=0;
    Velocity=Point<float>();
    AddName("GameObject");
    this->Name = "GameObject";
    this->Life = 1;
    this->DoNotDelete = false;
    World=true;
    Collides = collides;
    _CS->Add(this);
}

GameObject::GameObject(bool collides)
{
    Life = 1;
    Depth=0;
    AddName("GameObject");
    Name = "GameObject";
    Position=Point<float>();
    Velocity=Point<float>();
    Dimensions=Point<int>();
    Sprite = NULL;
    Image = NULL;
    World=true;
    Collides = collides;
    _CS->Add(this);
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
    if(Velocity!=Pointf())Position+=Velocity;
    if (Sprite != NULL)
    {
        Center=Position+Pointf(Dimensions.x,Dimensions.y)/Pointf(2);
        Sprite->SetPosition(Position.TwoVector());
        App->Draw(*Sprite);
    }else{
        Center=Position;
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
    Update();
}

void GameObject::WhileKeyDown(sf::Key::Code Key, boost::function<void()> func)
{
    KeyCheck kc;
    kc.Key = Key;
    kc.func = func;
    WhileKeyPressedChecks.push_back(kc);
}

void GameObject::KeyPressed(sf::Key::Code key, boost::function<void()> func)
{
    State::Event Ev;
    Ev.owner = this;
    Ev.func = func;
    Ev.type = sf::Event::KeyPressed;
    Ev.key = key;
    Ev.has_key = true;
    _CS->AddEvent(Ev);
}

void GameObject::KeyReleased(sf::Key::Code key, boost::function<void()> func)
{
    State::Event Ev;
    Ev.owner = this;
    Ev.func = func;
    Ev.type = sf::Event::KeyReleased;
    Ev.key = key;
    Ev.has_key = true;
    _CS->AddEvent(Ev);
}

void GameObject::AddEvent(sf::Event::EventType type, boost::function<void()> func)
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

GameObject* GameObject::GetNearest(std::string name){
    float closest=1000000;
    GameObject* Result=null;
    for(unsigned int a=0;a<_CS->GameObjects.size();a++){
        GameObject* g = _CS->GameObjects[a];
        if (g != this and (_CS->GameObjects[a]->Isa(name) == name))
        {
            float distance=Position.Get_Distance(g->Position);
            if (distance < closest)
            {
                closest = distance;
                Result = g;
            }
        }
    }
    return Result;
}

void GameObject::AddName(std::string NewName){
    Names.push_back(NewName);
}

std::string GameObject::Isa(std::string GetName){
    for(unsigned int a=0;a<Names.size();a++){
        if(GetName==Names[a]){
            return Names[a];
        }
    }
    return "";
}

}
