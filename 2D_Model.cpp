#include "All.hpp"

namespace Ignatus{

TwoD_Model::TwoD_Model(std::string img,Pointi dim,float fps,bool eoe):GameObject(true){
    TwoD_Model::Animation ani=TwoD_Model::Animation(img,dim,fps,eoe);
    Dim=dim;
    FPS=fps;
    Animations.push_back(ani);
    Sprite = Animations[0].Frames;
    AddName("TwoD_Model");
    this->Name = "TwoD_Model";
    this->Life = 1;
    Animations[0].Frames->Play();
    CurFrame="Stand";
}

TwoD_Model::~TwoD_Model(){}

AniSprite* TwoD_Model::GetFrame(std::string name){
    for(unsigned int a=0;a<Animations.size();a++){
        if(Animations[a].Name==name)return Animations[a].Frames;
    }
    return GetFrame();
}

int TwoD_Model::GetFrameID(std::string name){
    for(unsigned int a=0;a<Animations.size();a++){
        if(Animations[a].Name==name)return a;
    }
    return 0;
}

void TwoD_Model::UpdateMagic()
{
    GameObject::UpdateMagic();
    for(unsigned int a=0;a<Animations.size();a++)
        if(CurFrame==Animations[a].Name)
            Animations[a].Frames->Update();
}

void TwoD_Model::SetFrame(std::string name){
    int a=GetFrameID(name);
    Sprite=Animations[a].Frames;
    for(unsigned int b=0;b<Animations.size();b++){
        Animations[b].Frames->Stop();
    }
    Animations[a].Frames->Play();
    CurFrame=Animations[a].Name;
}

void TwoD_Model::AddFrame(std::string img,std::string name,bool eoe){
    TwoD_Model::Animation ani=TwoD_Model::Animation(img,Dim,FPS,eoe,name);
    Animations.push_back(ani);
}

///Animation

TwoD_Model::Animation::Animation(std::string file,Pointi dim,int fps,bool eoe,std::string name){
    Name=name;
    sf::Image* img=Engine::GetEngine()->LoadImage(file);
    Frames=new AniSprite(*img,dim.x,dim.y,fps,eoe);
}

}
