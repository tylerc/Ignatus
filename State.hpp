#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

namespace Ignatus{

/// GameObjects need to be managed, and different game "screens" need to be separated, this is where it happens.
class State
{
public:
    Engine* MyEngine;
    std::vector<GameObject*> GameObjects;
    std::vector<GameObject*> WaitingObjects;
    std::vector<GameObject*> CollisionObjects;
    int MouseX,MouseY;
    Point<float> Mouse_Pos;
    /// How this game engine represents events, you won't need to worry about this struct unless you're particularly masochistic.
    struct Event
    {
        GameObject* owner;
        boost::function<void()> func;
        sf::Event::EventType type;
        sf::Key::Code key;
        bool has_key;
    };
    std::vector<Event> Events;
    bool setup;
    bool killme;
    sf::Color ClearColor;
    sf::RenderWindow* App;
    sf::Event Ev;

    State();
    virtual ~State();
    void Add(GameObject* g);
    void RemoveObject(GameObject* g);
    void AddEvent(Event Ev);
    virtual void Update();
    void SSetup();
    virtual void Setup();
    virtual void ChangeInto();
    virtual void ChangeOutOf();
    void AddCollider(GameObject* g);
    void RemoveCollider(GameObject* g);
};
}

#endif // STATE_HPP_INCLUDED
