#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

/// The Boss of the entire operation, need anything to get done, you talk to this guy.
/**
This runs the show. It gets you off the ground with an SFML RenderWindow, handles States
and state changes, as well as image caching. If you're looking for a place to start, start
here, if not, I can hear the other classes calling your name.
*/
class Engine
{
public:
    sf::RenderWindow* App; //!< Engine's SFML RenderWindow, your game is drawn on this.
    const sf::Input* Input; //!< Handle to the RenderWindow's input, if you need info on the current state of the keyboard, mouse, etc., go here.
    State* CS; //!< Pointer to the current game State.
    State* ToChange; //!< Pointer to the state that's about to be changed into.
    std::map<std::string,sf::Image*> Images; //!< Engine's cache of all the images (reduces both memory use and lag).
    std::map<std::string,sf::Image*> ImagesIter; //!< Iterator for the image cache.

    /// The Engine's constuctor.
    /**
    Creates everything you need to get up off the ground. Takes 3 parameters, the title, the width, and the height of the
    window. After calling the constructor, it's advised that you create your own instance of the State class (though an empty
    one is created for you by default). After your state initialization is done, call Looptastic to start the game loop!
    */
    Engine(std::string title="Completely Wonderful Generic Title", int width=800, int height=600);
    /// The Engine's destructor, cleans up EVERYTHING! You dirty scoudrel.
    /**
    So I was sitting around one day, and I was like, WTF? You allocated way too much freakin' memory! So what did I do?
    I freed the memory for your class! MUAHAHAHA! THEN I CALLED THIS DESTRUCTOR! And EVERYTHING was gone! :D

    Do it again, and you're dead. Thanks. :)
    */
    ~Engine();
    /// Changes the currently active game state.
    /**
    Changes the current game state, the former state is allowed to finish it's iteration before this happens.
    If the state has the variable killme set to true, the engine will deallocate the state's memory, otherwise
    it's kept around so you can still keep a pointer to it.
    */
    void ChangeState(State* S);
    /// The game loop. 'Nuf said.
    /**
    jk?
    Alright, so basically, the engine handles various maintenence tasks, and then calls State's update function.
    Other than that, it's your basic everyday game loop.
    */
    void Looptastic();
    /// Loads an image for GameObjects, odds are you won't need to use this unless you're hacking on Engine internals.
    /**
    Loads an image from file, and caches in the Images map.

    Memory leak notes:

    This, and the Images and ImagesIter functions above this, are used for caching loaded images, so
    things like particles don't have to reload the image each time a new one is created. This boths
    saves memory, and leaks memory, depending on your perspective. It saves memory because formerly
    when we would create 1000 Particles, we would also be loading 1000 images. Now we would only load
    1 image, but that image stays in memory regardless of whether there's a Particle object instantiated.
    */
    sf::Image* LoadImage(std::string file);
    /// Magic. Look away.
    /**
    Used internally so we can access the current instance of the Engine using _E.
    Unless your name is Tyler Church, you will never need to worry about this function.
    */
    static Engine* GetEngine();
};

#endif // ENGINE_HPP_INCLUDED
