#define tp template<typename T,typename S,typename U>
#define a2r 0.017453292519943295769236907684886
#define r2a 57.295779513082320876798154814105

namespace Ignatus{

tp
Point<T,S,U>::Point()
{
    x=0;
    y=0;
    z=0;
}
tp
Point<T,S,U>::Point(T X)
{
    x=X;
    y=X;
    z=X;
}
tp
Point<T,S,U>::Point(T X,S Y)
{
    x=X;
    y=Y;
    z=0;
}
tp
Point<T,S,U>::Point(T X,S Y,U Z)
{
    x=X;
    y=Y;
    z=Z;
}
#ifdef SFML_SYSTEM_HPP
tp
Point<T,S,U>::Point(sf::Vector2<T> XY)
{
    x=XY.x;
    y=XY.y;
    z=0;
}
tp
Point<T,S,U>::Point(sf::Vector3<T> XYZ)
{
    x=XYZ.x;
    y=XYZ.y;
    z=XYZ.z;
}
tp
sf::Vector2<T> Point<T,S,U>::TwoVector(){
    return sf::Vector2<T>(x,y);
}
tp
sf::Vector3<T> Point<T,S,U>::ThreeVector(){
    return sf::Vector3<T>(x,y,z);
}
#ifdef SFML_GRAPHICS_HPP
tp
sf::Rect<T> Point<T,S,U>::TwoRect(Point<T,S,U> p2){
    sf::Rect<T> ret;
    ret.Left=GetMinMaxX(p2);
    ret.Right=GetMinMaxX(p2,false);
    ret.Top=GetMinMaxY(p2);
    ret.Bottom=GetMinMaxY(p2,false);
    return ret;
}
tp
sf::Rect<T> Point<T,S,U>::GetRectofPoints(std::vector<Point<T,S,U> >* ps){
    if(ps->size()>1){
        Point<Point<T>,Point<S> > ret;
        ret.x.x=(*ps)[0].x;
        ret.x.y=(*ps)[1].x;
        ret.y.x=(*ps)[0].y;
        ret.y.y=(*ps)[1].y;
        for(unsigned int a=0;a<ps->size();a++){
            if((*ps)[a].x<ret.x.x)ret.x.x=(*ps)[a].x;
            if((*ps)[a].x>ret.x.y)ret.x.y=(*ps)[a].x;
            if((*ps)[a].y<ret.y.x)ret.y.x=(*ps)[a].y;
            if((*ps)[a].y>ret.y.y)ret.y.y=(*ps)[a].y;
        }
        return sf::Rect<T>(ret.x.x,ret.x.y,ret.y.x,ret.y.y);
    }else{
        return sf::Rect<T>(0,0,0,0);
    }
}
#endif
#endif
tp
Point<T,S,U>::~Point(){}
tp
Point<T,S,U> Point<T,S,U>::TwoAngle()
{
    ///convert Z to zv and hor angle
    return Point<T,S,U>(Get_Distance(Point<T,S,U>()),Get_Angle(Point<T,S,U>())-180,0);
}
tp
Point<T,S,U> Point<T,S,U>::TwoVelocity()
{
    ///convert Z to zv and hor angle
    T X=x*cos(y*a2r);
    S Y=x*sin(y*a2r);
    return Point<T,S,U>(X,Y,0);
}
tp
Point<T,S,U> Point<T,S,U>::GetNearest(std::vector<Point<T,S,U> >* ps){
    Point<T,S,U> ret=(*ps)[0];
    for(unsigned int a=0;a<ps->size();a++){
        if(ret.Get_Distance((*ps)[a])<Get_Distance(ret)){
            ret=(*ps)[a];
        }
    }
    return ret;
}
tp
T Point<T,S,U>::Get_Distance(Point<T,S,U> p){
    return T(sqrt(T(x-p.x)*T(x-p.x)+T(y-p.y)*T(y-p.y)));
}
tp
T Point<T,S,U>::Get_Angle(Point<T,S,U> p){
    return T(atan2(T(p.y-y),T(p.x-x))*r2a);
}
tp
T Point<T,S,U>::GetMinMaxX(Point<T,S,U> p,bool min){
        if(x<p.x)if(min)return x;else return p.x;else if(!min)return x;else return p.x;
}
tp
S Point<T,S,U>::GetMinMaxY(Point<T,S,U> p,bool min){
        if(y<p.y)if(min)return y;else return p.y;else if(!min)return y;else return p.y;
}
tp
U Point<T,S,U>::GetMinMaxZ(Point<T,S,U> p,bool min){
        if(z<p.z)if(min)return z;else return p.z;else if(!min)return z;else return p.z;
}
tp
Point<T,S,U> Point<T,S,U>::GetMidPoint(Point<T,S,U> p){
    return (*this+p)/Point<T,S,U>(2);
}
tp
Point<T,S,U> Point<T,S,U>::GetMiddleofPoints(std::vector<Point<T,S,U> >* ps){
    T X=0;
    S Y=0;
    U Z=0;
    for(unsigned int a=0;a<ps->size();a++){
        X+=(*ps)[a].x;
        Y+=(*ps)[a].y;
        Z+=(*ps)[a].z;
    }
    X/=ps->size();
    Y/=ps->size();
    Z/=ps->size();
    return Point<T,S,U>(X,Y,Z);
}
///OLD FUNCTIONS
tp
Point<T,S,U> Point<T,S,U>::operator+=(Point<T,S,U> param){
    *this=*this+param;
    return *this;
}
tp
Point<T,S,U> Point<T,S,U>::operator-=(Point<T,S,U> param){
    *this=*this-param;
    return *this;
}
tp
Point<T,S,U> Point<T,S,U>::operator*=(Point<T,S,U> param) {
    *this=*this*param;
    return *this;
}
tp
Point<T,S,U> Point<T,S,U>::operator/=(Point<T,S,U> param) {
    *this=*this/param;
    return *this;
}
tp
Point<T,S,U> Point<T,S,U>::operator+(Point<T,S,U> param)
{
    return(Point<T,S,U>(x+param.x,y+param.y,z+param.z));
}
tp
Point<T,S,U> Point<T,S,U>::operator-(Point<T,S,U> param)
{
    return(Point<T,S,U>(x-param.x,y-param.y,z-param.z));
}
tp
Point<T,S,U> Point<T,S,U>::operator*(Point<T,S,U> param)
{
    return(Point<T,S,U>(x*param.x,y*param.y,z*param.z));
}
tp
Point<T,S,U> Point<T,S,U>::operator/(Point<T,S,U> param)
{
    Point<T,S,U> ret;
    if(param.x)ret.x=0;else ret.x=x/param.x;
    if(param.y)ret.y=0;else ret.y=y/param.y;
    if(param.z)ret.z=0;else ret.z=z/param.z;
    return(ret);
}
tp
bool Point<T,S,U>::operator==(Point<T,S,U> param)
{
    return (x==param.x and y==param.y and z==param.z);
}

tp
bool Point<T,S,U>::operator!=(Point<T,S,U> param)
{
    return !(*this==param);
}

}
