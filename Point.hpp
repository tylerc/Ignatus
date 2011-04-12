#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED
namespace Ignatus{
/// Point is for using velocities and angle movement. Also used for coords.
/**
This basicly as two values or a given type; x and y. This allows you to return two variables of the same type rather than only one value.
Also has a few funtions for converting velocity to angles and speed.
Supports basic math, like adding, also allows to check if Points have the same value.
*/
template <typename T, typename S=T,typename U=T>
class Point{
public:
    /// This is the first of the the pair of coords, called x because of standard coords.
    /**
    This is also the type returned for funtions that return a spacific number.
    */
    T x;
    /// This is the first of the the pair of coords, called x because of standard coords.
    S y;
    /// This is the first of the the pair of coords, called x because of standard coords.
    U z;
    Point<T,S,U>();
    Point<T,S,U>(T X);
    Point<T,S,U>(T X,S Y);
    Point<T,S,U>(T X,S Y,U Z);
#ifdef SFML_SYSTEM_HPP
    Point<T,S,U>(sf::Vector2<T> XY);
    Point<T,S,U>(sf::Vector3<T> XYZ);

    sf::Vector2<T> TwoVector();
    sf::Vector3<T> ThreeVector();
#ifdef SFML_GRAPHICS_HPP
    sf::Rect<T> TwoRect(Point<T,S,U> p2);
    static sf::Rect<T> GetRectofPoints(std::vector<Point<T,S,U> >* ps);
#endif
#endif
    ~Point<T,S,U>();

    Point<T,S,U> TwoAngle();
    Point<T,S,U> TwoVelocity();
    Point<T,S,U> GetMidPoint(Point<T,S,U> p);
    Point<T,S,U> GetNearest(std::vector<Point<T,S,U> >* ps);

    T Get_Distance(Point<T,S,U> p);
    T Get_Angle(Point<T,S,U> p);
    T GetMinMaxX(Point<T,S,U> p,bool min=true);
    S GetMinMaxY(Point<T,S,U> p,bool min=true);
    U GetMinMaxZ(Point<T,S,U> p,bool min=true);

    static Point<T,S,U> GetMiddleofPoints(std::vector<Point<T,S,U> >* ps);
    bool operator==(Point<T,S,U> param);
    bool operator!=(Point<T,S,U> param);
    Point<T,S,U> operator+=(Point<T,S,U> param);
    Point<T,S,U> operator+(Point<T,S,U> param);
    Point<T,S,U> operator-=(Point<T,S,U> param);
    Point<T,S,U> operator-(Point<T,S,U> param);
    Point<T,S,U> operator*=(Point<T,S,U> param);
    Point<T,S,U> operator*(Point<T,S,U> param);
    Point<T,S,U> operator/=(Point<T,S,U> param);
    Point<T,S,U> operator/(Point<T,S,U> param);
};

typedef Point<int,int,int> Pointi;
typedef Point<float,float,float> Pointf;

};// namespace Ignatus
#include "Point.inl"

#endif // POINT_HPP_INCLUDED
