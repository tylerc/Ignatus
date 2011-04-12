#include "All.hpp"
namespace Ignatus{

Camera::Camera(Pointf center,Pointf dim,sf::RenderWindow* app){
    Target=null;
    Center=center;
    Half=dim*Pointf(.5);
    App=app;
    view=sf::View(Center.TwoVector(), Half.TwoVector());
    Zoom=Pointf(1);
}
Camera::Camera(sf::View view,sf::RenderWindow* app){
    Target=null;
    this->view=view;
    App=app;
    Half=Pointf(view.GetHalfSize());
    Center=Pointf(view.GetCenter());
    Zoom=Pointf(1);
}
void Camera::Activate(sf::RenderWindow* app){
    if(app==NULL)app=App;
    app->SetView(view);
}
void Camera::Move(Pointf off){
    Center=Center+off;
}
void Camera::SetZoom(Pointf factor){
    Zoom=Zoom*factor;
    Half=Half*factor;
}
void Camera::ResetZoom(){
    Half=Half/Zoom;
    Zoom=Pointf(1);
}
Pointf Camera::GetPosition(){
    return Pointf(Center.x-Half.x,Center.y-Half.y);
}
void Camera::SetHeight(float height){
    Zoom=Pointf(Zoom.x,1);
    Half.y=height/2;
}
void Camera::SetWidth(float width){
    Zoom=Pointf(1,Zoom.y);
    Half.x=width/2;
}
void Camera::SetSize(Pointf dim){
    SetWidth(dim.x);
    SetHeight(dim.y);
}
void Camera::SetCenter(Pointf center){
    Center=center.TwoVector();
}
Pointf Camera::GetZoom(){
    return Zoom;
}
Pointf Camera::GetCenter(){
    return Center;
}
Pointf Camera::GetDim(){
    return Half*Pointf(2);
}
void Camera::Update(){
    view.SetHalfSize(Half.TwoVector());
    view.SetCenter(Center.TwoVector());
    if(Target!=null){
        Pointf P=Target->Position;
        P.x+=Target->Dimensions.x/2;
        P.y+=Target->Dimensions.y/2;
        Center=P;
    }
}

}
