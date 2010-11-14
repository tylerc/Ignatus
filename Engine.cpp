#include "All.hpp"
//#include "util.hpp"

Engine* E;

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
