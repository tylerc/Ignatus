#include "All.hpp"

AniObject::AniObject(std::string file, int x, int y, int width, int height, int frame_rate, bool endOnEnd) : GameObject(true)
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
