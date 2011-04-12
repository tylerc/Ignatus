#ifndef CAMERA_HPP
#define CAMERA_HPP


namespace Ignatus{

class Camera{
    sf::RenderWindow* App;
    sf::View view;
    Pointf Zoom,Center,Half;
public:
    Pointf Velocity;
    GameObject* Target;
    Camera(Pointf center,Pointf dim,sf::RenderWindow* app);
    Camera(sf::View view,sf::RenderWindow* app);
    Pointf GetPosition();
    void Activate(sf::RenderWindow* app=NULL);
    void Move(Pointf off);
    void SetZoom(Pointf factor);
    void ResetZoom();
    void SetWidth(float width);
    void SetHeight(float height);
    void SetSize(Pointf dim);
    void Update();

    void SetCenter(Pointf center);
    Pointf GetCenter();
    Pointf GetDim();
    Pointf GetZoom();
};

}

#endif // CAMERA_HPP
