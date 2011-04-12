#include "All.hpp"

namespace Ignatus{

State::State()
{
    setup = false;
    killme = false;
    ClearColor = sf::Color(0, 0, 0);
}

State::~State()
{
    while (GameObjects.size() != 0)
    {
//        GameObject* g = GameObjects.back();
        GameObjects.pop_back();
//        if (g->DoNotDelete == false)
//            delete g;
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
    g->MyState=this;
    WaitingObjects.push_back(g);
}
void State::RemoveObject(GameObject* go_away){
    for (std::vector<GameObject*>::iterator pos = GameObjects.begin(); pos < GameObjects.end();)
    {
        if ((*pos) == go_away)
        {
            //RemoveObject(pos);
            GameObject* g = *pos;
            GameObjects.erase(pos);
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
}
void State::AddEvent(Event Ev)
{
    Events.push_back(Ev);
}

void State::Update(){
    debug("State: Tick")
    /**
    Here we loop through all added GameObjects
    If GameObjects have been added, we do it properly here.
    We also set a boolean Added to true so we can sort
     the them by depth, doing this each step is laggy and
     causes jittery looks.
    */
    bool Added=false;
    debug("State: Waiting for "<<WaitingObjects.size()<<" Objects to add")
    while (WaitingObjects.size() > 0){
        debug("State: Adding Objects")
        Added=true;
        GameObject* g = WaitingObjects.front();
        GameObjects.push_back(g);
        WaitingObjects.erase(WaitingObjects.begin());
    }
    /**
    Sort vector based on Depth values.
    */
    if(Added){
        debug("State: Sorting Objects")
        sort(GameObjects.begin(),GameObjects.end(),Sort_GameObjects);
    }
    /**
    This, err... I think it removes
     GameObjects if their Life <= 0
    */
    debug("State: Death of Objects")
    for (std::vector<GameObject*>::iterator pos = GameObjects.begin(); pos < GameObjects.end();)
    {
        if ((*pos)->Life <= 0)
        {
            GameObject* g = *pos;
            GameObjects.erase(pos);
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
    /**
    Here all collision is handled for all GameObjects.
    */
    debug("State: Collision")
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
    /**
    This is where we process all our events...
    */
    debug("State: Events")
    sf::Event Event;
    while (_E.App->GetEvent(Event)){
        /**
        Done Playing and you hit the pretty X...
        */
        if (Event.Type == sf::Event::Closed){
            _E.App->Close();
        }
        /**
        This handles the mouse so you don't have to.
        Use MouseX,MouseY, and Mouse_Pos for mouse location stuff.
        */
        if(Event.Type==sf::Event::MouseMoved){
            Mouse_Pos=Pointf(_E.App->ConvertCoords(_E.App->GetInput().GetMouseX(), _E.App->GetInput().GetMouseY()))*_E.World_View->GetZoom();
            Mouse_Pos=Mouse_Pos+_E.World_View->GetPosition();
            MouseX=Mouse_Pos.x;
            MouseY=Mouse_Pos.y;
        }
        /**
        This is so our Cameras don't get messed up...
        */
        if(Event.Type==sf::Event::Resized){
            _E.Screen_View->SetSize(Pointf(Event.Size.Width,Event.Size.Height));
        }
        for (unsigned int i = 0; i < Events.size(); i++){
            if (Event.Type == Events[i].type){
                if (Events[i].has_key == true and Event.Key.Code == Events[i].key){
                    this->Ev = Event;
                    Events[i].func();
                } else if (Events[i].has_key == false) {
                    this->Ev = Event;
                    Events[i].func();
                }
            }
        }
    }
    /**
    Update each GameObject's UpdateMagic()
    UpdateMagic() Calls Update()
    Draw each GameObject in their 'camera' view.
    */
    debug("State: Object Updates "<<GameObjects.size()<<" ")
    for (unsigned int i = 0; i < GameObjects.size(); i++)
    {
        debug("State: Update Magic")
        GameObjects[i]->UpdateMagic();
        if(GameObjects[i]->World){
            debug("State: Changing Views")
            _E.World_View->Activate();
        }
        debug("State: Drawing")
        GameObjects[i]->Draw(_E.App);
        debug("State: Reset View")
        _E.Screen_View->Activate();
    }
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

}
