#include "All.hpp"

State::State()
{
    setup = false;
    killme = false;
    ClearColor = sf::Color(0, 0, 0);
}

State::~State()
{
    while (Objects.size() != 0)
    {
        GameObject* g = Objects.back();
        Objects.pop_back();
        delete g;
    }
}

void State::Setup()
{
    //Text* t = new Text("You should totally create your\nown custom game state.", 30.0f, "Freshman.ttf");
}

void State::SSetup()
{
    if (setup == false)
    {
        setup = true;
        Setup();
    }
}

void State::Add(GameObject* g)
{
    WaitingObjects.push_back(g);
}

void State::AddEvent(Event Ev)
{
    Events.push_back(Ev);
}

void State::Update()
{
    while (WaitingObjects.size() > 0)
    {
        GameObject* g = WaitingObjects.front();
        Objects.push_back(g);
        WaitingObjects.erase(WaitingObjects.begin());
    }

    for (std::vector<GameObject*>::iterator pos = Objects.begin(); pos < Objects.end();)
    {
        if ((*pos)->life <= 0)
        {
            GameObject* g = *pos;
            Objects.erase(pos);
            for (std::vector<State::Event>::iterator pos2 = Events.begin(); pos2 < Events.end();)
            {
                if (pos2->owner == g)
                {
                    Events.erase(pos2);
                } else {
                    pos2++;
                }
            }
            for (std::vector<GameObject*>::iterator pos3 = CollisionObjects.begin(); pos3 < CollisionObjects.end();)
            {
                if ((*pos3) == g)
                {
                    CollisionObjects.erase(pos3);
                } else {
                    pos3++;
                }
            }
            delete g;
        } else {
            pos++;
        }
    }

    for (unsigned int i = 0; i < CollisionObjects.size(); i++)
    {
        for (unsigned int j = i+1; j < CollisionObjects.size(); j++)
        {
            if (collision_between(CollisionObjects[i], CollisionObjects[j]))
            {
                CollisionObjects[i]->Collision(CollisionObjects[j]);
                CollisionObjects[j]->Collision(CollisionObjects[i]);
            }
        }
    }

    // Process events
    sf::Event Event;
    while (_E.App->GetEvent(Event))
    {
        // Close window : exit
        if (Event.Type == sf::Event::Closed)
            _E.App->Close();
        if (Event.Type == sf::Event::KeyReleased)
        {
            //if (Event.Key.Code == sf::Key::Escape)
            //    _E.App->Close();
        }
        for (unsigned int i = 0; i < Events.size(); i++)
        {
            if (Event.Type == Events[i].type)
            {
                if (Events[i].has_key == true and Event.Key.Code == Events[i].key)
                {
                    Events[i].func(Event);
                } else if (Events[i].has_key == false) {
                    Events[i].func(Event);
                }
            }
        }
    }

    for (unsigned int i = 0; i < Objects.size(); i++)
    {
        Objects[i]->UpdateMagic();
        Objects[i]->Update();
    }

    // Clear the screen
    _E.App->Clear(ClearColor);

    for (unsigned int i = 0; i < Objects.size(); i++)
    {
        Objects[i]->Draw(_E.App);
    }

    // Display window contents on screen
    _E.App->Display();
}

void State::ChangeInto()
{
}

void State::ChangeOutOf()
{
}

void State::AddCollider(GameObject* g)
{
    CollisionObjects.push_back(g);
}

void State::RemoveCollider(GameObject* g)
{
    for (std::vector<GameObject*>::iterator pos3 = CollisionObjects.begin(); pos3 < CollisionObjects.end();)
    {
        if ((*pos3) == g)
        {
            CollisionObjects.erase(pos3);
        } else {
            pos3++;
        }
    }
}
