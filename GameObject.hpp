#ifndef GAMEOBJECT_HPP_INCLUDED
#define GAMEOBJECT_HPP_INCLUDED

namespace Ignatus{

/// The base class for all objects in a game.
/**
This uses some basic values and handles them very well, such as the posistion
of the image on the screen and handling the image itself.
*/

class GameObject
{
private:
    bool DoNotDelete; //!< DEPRECIATED. DO NOT USE.
public:
    State* MyState;
    Engine* MyEngine;
    bool Collides; //!< Controls whether or not this GameObject can collide with other GameObjects, setting this is only meaningful inside a GameObject's constructor; outside of the constructor, call SetCollides.
    Pointf Position; //!< What the hell do you think this is? (it's a GameObject's x and y position, for the heathans).
    Pointf Velocity; //!< How much this GameObject will be moving each update.
    Pointi Dimensions; //!< The size of your pretty little GameObject.
    Pointf Center; //!< This is the middle of the GameObject's rect.
    bool World; //!< Defines whether the GameObject is drawn on the screen view camera or world view camera, defaults to true.
    float Depth; //!< The layer where your GameObject is drawn, lower depth, lower layer, default is zero.
    sf::Image* Image; //!< The raw SFML image data for the GameObject.
    sf::Sprite* Sprite; //!< The SFML sprite for your GameObject (you shouldn't really ever have to touch this).
    std::vector<std::string> Names; //!< A list of names for classification.

    /// Used for WhileKeyDown and friends, mere mortals need not worry about how it works.
    struct KeyCheck
    {
        sf::Key::Code Key;
        boost::function<void()> func;
    };
    std::vector<KeyCheck> WhileKeyPressedChecks; //!< All the KeyChecks for a given GameObject, non-Ignatus devs need not worry.
    std::string Name; //!< The name of this GameObject, this instance variable is being phased out.
    int Life; //!< The "life" of a GameObject, when it reaches zero, it gets removed from the game, memory is automagically freed.

    /// This is where your GameObjects will call code, this is called each step.
    /**
    Adds the x and y of two Points, just like adding integers.
    */
    virtual void Update();
    /// This is used internally, touch it and you die, override it and Tyler will eat your soul with a side of syrup.
    /**
    This is called once every Update, like the Update function, it takes care of some house-keeping tasks (like checking if
    certain keys are being pressed, etc. Don't override this unless you REALLY know what you're doing. (e.g. your name is Tyler, or
    Señor Jerrick)
    */
    virtual void UpdateMagic();
    /// This function gets called whenever this GameObject hits another GameObject!
    /**
    For the technically minded, this function is called when one GameObject's rect intersects another GameObject's rect.
    For the technically absent minded, this function draws pretty colors when you aren't looking :) .
    */
    virtual void Collision(GameObject* g);
    /// This function draws your GameObject on screen.
    /**
    For the most part, you should never need to override this unless your hacking on Ignatus internals.
    */
    virtual void Draw(sf::RenderWindow *App);
    /// GameObject's constructor, the most used function.
    /**
    This is not a constructor, it's a way of life. The entire engine started as an experiment so that we could do this:

    GameObject("image.png", Position);

    No code necessary to add the GameObject to the game, no code necessary to keep track of it and clean it up when it's dead.
    You create it, it does the rest. Programmatic orgasms await.
    */
    GameObject(std::string file, Point<float> xy, bool collides=true);
    /// Magical constructor for a blank GameObject.
    /**
    This is usually used for texts, Triggers, Backgorunds, ect.
    Basically GameObjects without a position or image.
    */
    GameObject(bool collides=true);
    /// This is a commonly overwritten function.
    /**
    With this you can set a behavour of the GameObject when it dies. Called when Life is equal to 0, or less then.
    */
    virtual ~GameObject();
    /// This allows you to add an event to your GameObject.
    /**
    Allows adding events that are not for a WhileKeyDown event, or any other key buttom event. This would be used for mouse events.
    Calls the given function when the event occures.
    */
    void AddEvent(sf::Event::EventType type,  boost::function<void()> func);
    /// Added an event with a given key to fire when that key is pressed.
    /**
    Given a key and a function to call when the key is pressed. Won't fire again untill the key is released and pressed again.
    */
    void KeyPressed(sf::Key::Code key, boost::function<void()> func);
    /// Add an event with a given key to fire when that key is released.
    /**
    Given a key and a function to call when the key is released. Won't fire again untill that key is pressed and released again.
    */
    void KeyReleased(sf::Key::Code key, boost::function<void()> func);
    /// Checks if a key is pressed each step.
    /**
    If a key is pressed it fires the given function, this will be called each step the key is pressed.
    */
    void WhileKeyDown(sf::Key::Code Key, boost::function<void()> func);
    /// Allows you to change the Collides flag.
    /**
    If the flag is changed to true it will call the Collision function.
    If set to false it will no longer call the Collision function.

    Do not call this function inside of the constructor, set the Collision variable.
    */
    void SetCollides(bool collides);
    /// Adds a given string to the list of names for a GameObject.
    /**
    Pushes back the Names vector for the GameObject, used to classify the GameObject.
    */
    void AddName(std::string NewName="GameObject");
    /// Allows to you check if a GameObject is a 'whatever'.
    /**
    checks the given string against the list of names, if one matches it returns that name, if not it returns an empty string.
    */
    std::string Isa(std::string GetName="");
    /// Returns the instance of the nearest GameObject with a given name.
    /**
    Allows you to grab the nearest 'whatever' GameObject to the calling GameObject.
    If no GameObject's exist with the given name it returns NULL.
    If the given name is "" it returns the nearest GameObject, besides itself, if it's the only GameObject then it returns NULL.
    */
    GameObject* GetNearest(std::string name="");
};
}
#endif // GAMEOBJECT_HPP_INCLUDED

