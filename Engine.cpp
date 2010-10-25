#include "Engine.hpp"
#include "util.hpp"

Engine* E;

GameObject::GameObject(std::string file, int x, int y, bool collides)
{
    if (!Image.LoadFromFile(file))
    {
        std::cout << "Couldn't load image " << file << std::endl;
        exit(1);
    }
    Image.SetSmooth(false);
    Sprite = new sf::Sprite(Image);
    this->width = Image.GetWidth();
    this->height = Image.GetHeight();
    this->x = x;
    this->y = y;
    this->name = "GameObject";
    this->life = 1;
    _E.CS->Add(this);
    Collides = collides;
    if (collides)
        _E.CS->AddCollider(this);
}

GameObject::GameObject(bool collides)
{
    life = 1;
    name = "GameObject";
    x = 0;
    y = 0;
    Sprite = NULL;
    _E.CS->Add(this);
    Collides = collides;
    if (collides)
        _E.CS->AddCollider(this);
}

GameObject::~GameObject()
{
    //std::cout << "Bye " << this->name << "!\n";
    if (Sprite != NULL)
    {
        delete Sprite;
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
    _E.CS->AddEvent(Ev);
}

void GameObject::KeyReleased(sf::Key::Code key, boost::function<void(sf::Event::Event)> func)
{
    State::Event Ev;
    Ev.owner = this;
    Ev.func = func;
    Ev.type = sf::Event::KeyReleased;
    Ev.key = key;
    Ev.has_key = true;
    _E.CS->AddEvent(Ev);
}

void GameObject::AddEvent(sf::Event::EventType type, boost::function<void(sf::Event::Event)> func)
{
    State::Event Ev;
    Ev.owner = this;
    Ev.func = func;
    Ev.type = type;
    Ev.has_key = false;
    _E.CS->AddEvent(Ev);
}

void GameObject::SetCollides(bool collides)
{
    if (Collides != collides)
    {
        if (collides == true)
        {
            _E.CS->AddCollider(this);
        } else {
            _E.CS->RemoveCollider(this);
        }
    }
}

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

AniObject::AniObject(std::string file, int width, int height, int frame_rate, bool endOnEnd) : GameObject(true)
{
    if (!Image.LoadFromFile(file))
    {
        std::cout << "Couldn't load image " << file << std::endl;
        exit(1);
    }
    Image.SetSmooth(false);
    AS = new AniSprite(Image, width, height, frame_rate, endOnEnd);
    Sprite = AS;
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->name = "AniObject";
    this->life = 1;
    AS->Play();
}

AniObject::~AniObject()
{
}

void AniObject::UpdateMagic()
{
    GameObject::Update();
    AS->Update();
}

Sound::Sound(std::string file, float volume=100.0f) : GameObject(false)
{
    if (!SB.LoadFromFile(file))
    {
        std::cout << "Couldn't load sound " << file << std::endl;
        exit(1);
    }
    S.SetBuffer(SB);
    S.SetVolume(volume);
}

Sound::~Sound()
{
}

void Sound::Play()
{
    S.Play();
}

float Sound::Volume()
{
    return S.GetVolume();
}

void Sound::Volume(float vol)
{
    S.SetVolume(vol);
}

Music::Music(std::string file, float volume, bool loop)
{
    if (!M.OpenFromFile(file))
    {
        std::cout << "Couldn't load music " << file << std::endl;
        exit(1);
    }
    M.SetVolume(volume);
    M.SetLoop(loop);
}

Music::~Music()
{
}

void Music::Play()
{
    M.Play();
}

void Music::Stop()
{
    M.Stop();
}

void Music::Pause()
{
    M.Pause();
}

float Music::Volume()
{
    return M.GetVolume();
}

void Music::Volume(float vol)
{
    M.SetVolume(vol);
}

State::State()
{
    setup = false;
    killme = false;
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
    Objects.push_back(g);
}

void State::AddEvent(Event Ev)
{
    Events.push_back(Ev);
}

void State::Update()
{
    for (std::vector<GameObject*>::iterator pos = Objects.begin(); pos < Objects.end();)
    {
        if ((*pos)->life == 0)
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
        for (unsigned int j = i; j < CollisionObjects.size(); j++)
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
            if (Event.Key.Code == sf::Key::Escape)
                _E.App->Close();
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

    // Clear the screen (fill it with black color)
    _E.App->Clear();

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

Engine::Engine(std::string title, int width, int height)
{
    E = this;
    // Create the main rendering window
    App = new sf::RenderWindow(sf::VideoMode(width, height, 32), title);
    App->EnableKeyRepeat(false);
    //App->ShowMouseCursor(false);
    App->SetFramerateLimit(60);
    //const sf::Input& Input = App->GetInput(); // Allows us to get real-time input-state
    Input = &App->GetInput();

    srand(time(0));

    ToChange = NULL;
    CS = new State;
    CS->SSetup();
}

void Engine::ChangeState(State* S)
{
    //CS = S;
    //CS->SSetup();
    ToChange = S;
}

Engine* Engine::GetEngine()
{
    return E;
}

void Engine::Looptastic()
{
    // Start game loop
    while (App->IsOpened())
    {
        if (ToChange != NULL)
        {
            CS->ChangeOutOf();
            if (CS->killme == true)
            {
                delete CS;
            }
            CS = ToChange;
            ToChange = NULL;
            CS->SSetup();
            CS->ChangeInto();
        }
        CS->Update();
    }
}
Engine::~Engine()
{
    App->Close();
    delete App;
}
