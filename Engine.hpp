/*
    TODO

    * [DONEISH] Events (yeah, yeah, we have them, but they could be more awesome) (THEY NEED TO BE MORE AWESOME!! WE NEED A WHILE_KEY_DOWN EVENT!!!)
    ** Events are now more awesome! :D Though I wonder if I could do even better...
    ** I can do better, need KeyPressed, KeyReleased, MouseMoved, etc.
    ** Or maybe an Eventable class, so States don't have to create Triggers
    * [DONEISH] Collision Detection
    * [DONEISH] Game States
    ** We could add push_state and pop_state as well as switch_state
    * [DONEISH] Font/Text class
    * [DONEISH] Rid thee of thy warnings
    * [DONEISH] Destroy All Memory Leaks
    * Turn off collision detection for special GameObjects
    * [DONEISH] Documentation
    * Engine doesn't clean GameObjects up after it gets closed down

    DONE

    * Object Life
    * Librarify
*/

/** \mainpage Scorched Sea/Ignatus/Ignesco/Engine

So you're making a game, and you actually have to think about how to start. How
do I load an image again? What exactly is needed for a particle effects? How do
I inform Goomba that he's just been stomped by Mario? All these things, and many
more are basically the same in every game, and your focus should be on what makes
your game unique, not what you've written 1000 times before.

This is what our engine is designed to fix. And because Tyler is being forced
to use C++, he draws inspiration from this quote:

    "Any sufficiently advanced technology is indistinguishable from magic."

His goal is to make game development with C++ less of a pain in the goddamn ass,
so much less that you actually forget that you're using C++ at all (until you
hit the "Compile" button, anyway). Magic is implemented everywhere possible,
magic that you will learn how to use in a few moments. For those who are worried,
consider this: The engine library itself compliles without any compiler warnings,
and there are no detectable memory leaks. It's magic, without the price.

You may have noticed that there are 4 names at the top of this page:

    - Scorched Sea
    - Ignatus
    - Ignesco
    - Engine

The first three are possible names for the game engine, which has survived thus
far nameless, as simply "The Engine". Scorched Sea and Ignatus don't mean
anything in particular, but Tyler thinks they sound cool. Ignesco also sounds
cool, with the added benefit of meaning ignite, glow, or take fire in Latin,
depending on your translation. Tyler is partial to Ignesco. Please cast your
vote or suggest a name.

As for how to harness that magic I mentioned earlier: <a href="_tutorial.html">Tutorial</a>.

*/

/** \page Tutorial

<h1>Tutorial</h1>

Let's face it, you'd probably rather be having sex than reading this tutorial.
So we'll try to make this as fun, short, and informative as possible so you can
build the game, make the money, impress the girl because you can have fun and
make ridiculous sums of cash at the same time to feed her shoe fetish, chocolate
lust, and take her luxurious vaccations to your beach house in the Carribean. A
beach house, in which, finally, after all your hard work, you get to have sex.
Glorious sex, the stuff dreams aspire to be, sex that both porn directors and
romance novelists fail to even imagine, let alone capture in their respective
mediums. If you're a woman, well, the story is going to be a bit different, get
ready to start beating nerds away with a goddamn stick, a savvy game developing
girl is going to be in high demand. I suggest getting a man with some muscle,
someone imposing enough to keep the other men in line, but smart enough to talk
code with you, and sensitive enough to know when the talking should stop, and the
loving should begin. As for the rest of the story, ladies, literally volumes of
them have been written, I suggest anything by Teresa Medeiros, she's pretty good
as far as romance authors go. Go look her up, I'll wait.

Anwyays, no matter your gender, right now you're at step 1, this tutorial, so let's
get started.

As with any great act, we must first set the stage. Like all other ambitious
projects, it starts with \c main.cpp :

\code
#include <Engine/util.hpp>
#include <Engine/Engine.hpp>

int main()
{
    Engine e("My Awesome Game!", 640, 480);

    e.Looptastic();

    return 0;
}
\endcode

Assuming the header files are included in your compiler's search path, and that
you've linked against the engine, sfml-system, sfml-window, sfml-graphics, and
sfml-audio, this will compile and produce a beautiful blank, black window! Yay!

This is so simple, that an explanation almost doesn't seem worth it. But let's
break it down. The two most important lines thus far, and the only ones that
really *do* anything you're probably not yet aware of are these two lines:

\code
Engine e("My Awesome Game!", 640, 480);
e.Looptastic();
\endcode

The first line is the constructor for the Engine class, the first argument is
the title for the game window, the second and third arguments are the width and
height of the game window, respectively. This gives us access to all the vast
resources that constitute the Engine. After this, you would do some basic
initialization of your game, and then you call \c Engine.Looptastic() , which
starts the game loop running.

If you examine the documentation, you'd find that this is the only constructor
for Engine, and the only arguments it takes. "BUT WAIT!", you might be thinking,
"surely there's more than just those three things that I'll need to change!"
Well, it turns out that in our experience, there isn't. That's it.

On the off-chance that there is something else that you need to change, we
provide facilities for doing so. In most cases you'll need at least a cursory
understanding of SFML, infact, we recommend a good working knowledge of SFML when
using this engine. It's not a requirement, but it helps, especially in cases like
this where you're doing something nonstandard.

Let's say you needed to change the framerate, how would you do it? There are a few
ways of doing it, and context usually determines which one is the best. No matter
how you do it though, you need to get access to the \c sf::App that \c Engine has
inside of it. The simplist and most obvious way is to do this:

\code
e.App->SetFramerateLimit(30);
\endcode

But thoughtful observers will note that this only works in the context of
\c main() , where the \c e variable exists. A more far-reaching version is
this:

\code
_E.App->SetFramerateLimit(30);
\endcode

_E is a macro that grabs the current instance of the engine, and will work
basically anywhere that \e Engine.hpp is included.

As it turns out, calling methods on App happens surprisingly often, so the
following form was implemented and can also be used to achieve the same result:

\code
_App(SetFramerateLimit(30));
\endcode

<h2>GameObjects, Text, AniObject, Sound/Music</h2>

TODO

<h2>Game States</h2>

TODO

<h2>I Need Help!</h2>

Read this Tutorial, make sure you haven't missed anything, look at the
documentation, and see if you can find what you're looking for in there. Then
look at your code and make sure you aren't doing anything wrong. If all else
fails, or if you would just talk to a person rather than code, talk to Tyler,
he'll tell you how it works, or what's gone wrong.

<h2>It Doesn't Do X!</h2>

(X meaning any feature that you think the engine should handle)

Yep, it doesn't, we're sorry. Odds are though that we have a really good reason
for it not doing X, it's because we haven't *needed* it. Tyler, as chief architect
of the engine, feels that the engine should do everything it needs to, and nothing
more. Bloat sucks, and is a general pain in the ass, exasterbated by the fact that
we're using C++, so adding a myriad of whimisical features is not a Good Thing(tm).

If you honestly feel that feature X would make the engine significantly better,
pitch it to one of the engine's developers. Better yet, implement it, give one
of the developers a preview of it, and ask them to integrate it. If they like it
enough, they'll put it in. If they don't put it in, don't take it personally or
anything, not every feature belongs in the engine, but that doesn't mean you can't
use it in your own game!

<h2>This Engine Sucks!</h2>

Really? I'm sorry, I didn't mean for it to suck. Tell ya what, tell me (Tyler)
about your problems, and I'll see what I can do to fix 'em, alright?

*/

#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "AniSprite.hpp"

#define fn(f) boost::bind(f, this)
#define fn1(f) boost::bind(f, this, _1)
#define _E (*Engine::GetEngine())
#define _App(f) _E.App->f
#define unless(exp) if(!(exp))
#define _Width (signed int)_App(GetWidth())
#define _Height (signed int)_App(GetHeight())

/// The base class for all objects in a game
/**

*/
class GameObject
{
public:
    int x,y,width,height;
    sf::Image Image;
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

/// Need easy Text? This is your class.
class Text : public virtual GameObject
{
public:
    sf::Font* Font;
    sf::String* String;

    virtual ~Text() {delete Font; delete String;};
    Text(std::string s, float size, std::string file);
    void Draw(sf::RenderWindow* App);
    void Reset();
};

/// Static images are boring, spice things up with easy animated images!
class AniObject : public virtual GameObject
{
public:
    AniSprite* AS;

    AniObject(std::string file, int width, int height, int frame_rate, bool endOnEnd);
    virtual ~AniObject();

    virtual void UpdateMagic();
};

/// All your sound effect needs, in one convient place.
class Sound : public virtual GameObject
{
public:
    sf::Sound S;
    sf::SoundBuffer SB;

    Sound(std::string file, float volume);
    virtual ~Sound();
    void Play();
    float Volume();
    void Volume(float vol);
};

/// Hear that bass blastin'? Nope? Use this class, rock the house.
class Music : public virtual GameObject
{
public:
    sf::Music M;

    Music(std::string file, float volume=100.0f, bool loop=false);
    virtual ~Music();
    void Play();
    void Stop();
    void Pause();
    float Volume();
    void Volume(float vol);
};

/// Pretty effects, in any color you want!
class Particles : public virtual AniObject{
    public:
    Particles(std::string img,int x,int y,int width,int height,int fps,bool eoe,float angle,float speed,sf::Color tint,float fric,float turn,float wiggle);
    ~Particles();
    void Update();
    static void Explosion(std::string img,int x,int y,int width,int height,int fps,bool eoe,int num,float speed,sf::Color tint,float fric,float turn,float wiggle);
    static void Line(std::string img,int x,int y,int width,int height,int fps,bool eoe,float angle,float spread,int num,float speed,sf::Color tint,float fric,float turn,float wiggle);
    static void Ring(std::string img,int x,int y,int width,int height,int fps,bool eoe,float num,bool rnd,float speed,sf::Color tint,float fric,float turn,float wiggle);
    float angle,speed,fric,turn,wiggle;
    sf::Color tint;
};

/// GameObjects need to be managed, and different game "screens" need to be separated, this is where it happens.
class State
{
public:
    std::vector<GameObject*> Objects;
    std::vector<GameObject*> CollisionObjects;
    /// How this game engine represents events, you won't need to worry about this struct unless you're particularly masochistic.
    struct Event
    {
        GameObject* owner;
        boost::function<void(sf::Event::Event)> func;
        sf::Event::EventType type;
        sf::Key::Code key;
        bool has_key;
    };
    std::vector<Event> Events;
    bool setup;
    bool killme;

    State();
    virtual ~State();
    void Add(GameObject* g);
    void AddEvent(Event Ev);
    virtual void Update();
    void SSetup();
    virtual void Setup();
    virtual void ChangeInto();
    virtual void ChangeOutOf();
    void AddCollider(GameObject* g);
    void RemoveCollider(GameObject* g);
};

/// The Boss of the entire operation, need anything to get done, you talk to this guy.
class Engine
{
public:
    sf::RenderWindow* App;
    const sf::Input* Input;
    State* CS;
    State* ToChange;

    Engine(std::string title="Completely Wonderful Generic Title", int width=800, int height=600);
    ~Engine();
    void ChangeState(State* S);
    void Looptastic();
    static Engine* GetEngine();
};

#endif // ENGINE_HPP_INCLUDED
