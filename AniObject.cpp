#include "All.hpp"

namespace Ignatus{
AniObject::AniObject(std::string file,Point<float> xy, Point<int> dim, int frame_rate, bool endOnEnd) : GameObject(true)
{
    Image = _E.LoadImage(file);
    Image->SetSmooth(false);
    AS = new AniSprite(*Image, dim.x, dim.y, frame_rate, endOnEnd);
    Sprite = AS;
    Dimensions=dim;
    Center=Position+Pointf(dim.x,dim.y)/Pointf(2);
    Position=xy;
    AddName("AniObject");
    this->Name = "AniObject";
    this->Life = 1;
    AS->Play();
}

AniObject::~AniObject()
{
}

void AniObject::UpdateMagic()
{
    GameObject::UpdateMagic();
    if(AS!=NULL)
        AS->Update();
}

}
