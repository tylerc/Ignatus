#include "All.hpp"

namespace Ignatus{

Engine* E;

Engine::Engine(std::string title, int width, int height, State* changeto)
{
    DEBUG=false;
    E = this;
    ClearColor=sf::Color(0,0,0);
    // Create the main rendering window
    App = new sf::RenderWindow(sf::VideoMode(width, height,32), title);
    App->EnableKeyRepeat(false);
    World_View=new Camera(App->GetDefaultView(),App);
    Screen_View=new Camera(App->GetDefaultView(),App);
    Screen_View->Activate();
    //App->ShowMouseCursor(false);
    App->SetFramerateLimit(60);
    Input = &App->GetInput();
    EngineState=new State();
    EngineState->SSetup();
    srand(time(0));

    ToChange = NULL;
    CS = changeto;
    CS->MyEngine=this;
    CS->SSetup();
}

void Engine::ChangeState(State* S)
{
    debug("Going to change State")
    S->MyEngine=this;
    ToChange = S;
}

Engine* Engine::GetEngine()
{
    return E;
}

void Engine::Looptastic(){
    debug("Entering Game Loop")
    /**
    This the 'main' and currently the only
     loop that runs your games.
    */
    // Start game loop
    while (App->IsOpened()){
        debug("'Tick'")
        ///If we want to change states...
        if (ToChange != NULL){
            debug("Changing State")
            CS->ChangeOutOf();
            if (CS->killme == true){
                debug("Killing State")
                delete CS;
            }
            CS = ToChange;
            ToChange=null;
            CS->SSetup();
            CS->ChangeInto();
        }
        /**
        All of our pretty graphics and logic is here...
        */
        debug("World View Update")
        World_View->Update();
        debug("Screen View Update")
        Screen_View->Update();
        debug("Screen Clear")
        App->Clear(ClearColor);
        debug("SC Update")
        CS->Update();
        debug("Engine State Update")
        //EngineState->Update();
        /**
        This is for taking screenshots and stuff...
        */
        if(TakeScreenshot){
            debug("Taking Screenshot")
            ScreenShot=App->Capture();
            ScreenShotImg=sf::Sprite(ScreenShot);
            if(ScreenshotName!=""){
                debug("Saving Screenshot")
                ScreenShot.SaveToFile(ScreenshotName);
            }
            ScreenshotName="";
            TakeScreenshot=false;
        }
        /**
        Finally we show you the game.*/
        debug("Displaying Screen")
        App->Display();
    }
}
void Engine::CaptureScreenshot(std::string filename){
    if(!TakeScreenshot){
        TakeScreenshot=true;
        ScreenshotName=filename;
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

}
