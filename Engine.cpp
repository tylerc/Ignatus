#include "Engine.hpp"
#include "util.hpp"

Engine* E;

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
    Image = NULL;
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
    Image = _E.LoadImage(file);
    Image->SetSmooth(false);
    AS = new AniSprite(*Image, width, height, frame_rate, endOnEnd);
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
    S.Stop();
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
    M.Stop();
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

Particles::Particles(std::string img,int x,int y,int width,int height,int fps,bool eoe,float angle,float speed,sf::Color tint,float fric,float turn,float wiggle):AniObject(img,width,height,fps,eoe){
    this->angle=angle;
    this->speed=speed;
    this->tint=tint;
    this->fric=fric;
    this->wiggle=wiggle;
    this->turn=turn;
    this->fx=x;
    this->fy=y;
    this->sspeed=speed;
    SetCollides(false);
    Sprite->SetCenter(width/2,height/2);
    Sprite->SetColor(tint);
}
Particles::~Particles(){}
void Particles::Update(){
    angle+=turn+sf::Randomizer::Random(-wiggle,wiggle);
    fx=fx+speed*cos(angle*0.01745);
    fy=fy+speed*sin(angle*0.01745);
    x=fx;
    y=fy;
    float r=tint.r;
    float g=tint.g;
    float b=tint.b;
    float a=255;
    if(speed<=3){
        a=(speed/3)*255;
    }
    tint=sf::Color(r,g,b,a);
    Sprite->SetColor(tint);
    speed*=fric;
    if(speed<=1 or x<0 or y<0 or x>_Width or y>_Height){
        life=0;
    }
}
void Particles::Explosion(std::string img,float x,float y,int width,int height,int fps,bool eoe,int num,float speed,sf::Color tint,float fric,float turn,float wiggle)
{
    for(int a=0;a<num;a++){
        Particles* P = new Particles(img,x,y,width,height,fps,eoe,rand()%360,sf::Randomizer::Random(speed/2,speed*1.5),tint,fric,turn,wiggle);
    }
}
void Particles::Line(std::string img,float x,float y,int width,int height,int fps,bool eoe,float angle,float spread,int num,float speed,sf::Color tint,float fric,float turn,float wiggle){
    for(int a=0;a<num;a++){
        Particles* P = new Particles(img,x,y,width,height,fps,eoe,angle+sf::Randomizer::Random(-spread,spread),sf::Randomizer::Random(1.f,speed),tint,fric,turn,wiggle);
        Particles* G = new Particles(img,x,y,width,height,fps,eoe,angle+180+sf::Randomizer::Random(-spread,spread),sf::Randomizer::Random(1.f,speed),tint,fric,turn,wiggle);
    }
}
void Particles::Ring(std::string img,float x,float y,int width,int height,int fps,bool eoe,float num,bool rnd,float speed,sf::Color tint,float fric,float turn,float wiggle){
    int step=360/num;
    for(int a=0;a<num;a++){
        if(rnd==false){
            Particles* P=new Particles(img,x,y,width,height,fps,eoe,step*a+rand()%360,speed,tint,fric,turn,wiggle);
        }else{
            Particles* P=new Particles(img,x,y,width,height,fps,eoe,rand()%360,speed,tint,fric,turn,wiggle);
        }
    }
}
void Particles::Wall(std::string img,float x,float y,int width,int height,int fps,bool eoe,float num,float angle,float speed,sf::Color tint,float fric,float turn,float wiggle){
    int step=speed/num;
    for(int a=0;a<num;a++){
        Particles* P=new Particles(img,x,y,width,height,fps,eoe,angle-90,step*a+2,tint,fric,turn,wiggle);
        Particles* G=new Particles(img,x,y,width,height,fps,eoe,angle+90,step*a+2,tint,fric,turn,wiggle);
    }
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

sf::Image* Engine::LoadImage(std::string file)
{
    if (Images[file] == NULL)
    {
        sf::Image* image = new sf::Image;
        if (!image->LoadFromFile(file))
        {
            std::cout << "Couldn't load image " << file << std::endl;
            exit(1);
        }
        Images[file] = image;
        return image;
    } else {
        return Images[file];
    }
}

Engine::~Engine()
{
    delete CS;
    while (Images.size() != 0)
    {
        delete Images.begin()->second;
        Images.erase(Images.begin());
    }
    App->Close();
    delete App;
}
