#ifndef GAMEOBJECT_HPP_INCLUDED
#define GAMEOBJECT_HPP_INCLUDED

/// The base class for all objects in a game.
/**
This uses some basic values and handles them very well, such as the posistion
of the image on the screen and handling the image itself.
*/
class GameObject
{
public:
    int x,y,width,height;
    sf::Image* Image;
    sf::Sprite* Sprite;
    /// Used for WhileKeyDown and friends, mere mortals need not worry about how it works.
    struct KeyCheck
    {
        sf::Key::Code Key;
        boost::function<void()> func;
    };
    std::vector<KeyCheck> WhileKeyPressedChecks;
    sf::Event Event;
    std::string name;
    int life;
    bool Collides;

    virtual void Update();
    virtual void Collision(GameObject* g);
    virtual void Draw(sf::RenderWindow *App);
    GameObject(std::string file, int x=0, int y=0, bool collides=true);
    GameObject(bool collides=true);
    virtual ~GameObject();
    virtual void UpdateMagic();
    void AddEvent(sf::Event::EventType type,  boost::function<void(sf::Event::Event)> func);
    void KeyPressed(sf::Key::Code key, boost::function<void(sf::Event::Event)> func);
    void KeyReleased(sf::Key::Code key, boost::function<void(sf::Event::Event)> func);
    void WhileKeyDown(sf::Key::Code Key, boost::function<void()> func);
    void SetCollides(bool collides);
};

#endif // GAMEOBJECT_HPP_INCLUDED

