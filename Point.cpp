#include "Point.hpp"
#include <math.h>
Point::Point(float x,float y){
    this->x=x;
    this->y=y;
}
Point::Point(){};
Point::~Point(){};
Point Point::get_vel(float speed,float angle){
    angle*=3.141592653589793/180;
    return Point(speed*cos(angle),speed*sin(angle));
}
Point Point::get_vel(Point p){
    p.y*=3.141592653589793/180;
    return Point(p.x*cos(p.y),p.x*sin(p.y));
}
Point Point::get_ang(float vx,float vy){
    return Point(sqrt(vx*vx+vy*vy),atan2(vy,vx)*57.29578);
}
Point Point::get_ang(Point p){
    return Point(sqrt(p.x*p.x+p.y*p.y),atan2(p.y,p.x)*57.29578);
}
Point Point::operator+(Point param){
    return(Point(x+param.x,y+param.y));
}
Point Point::operator-(Point param){
    return(Point(x-param.x,y-param.y));
}
Point Point::operator*(Point param){
    return(Point(x*param.x,y*param.y));
}
Point Point::operator/(Point param){
    if(param.x==0){
        param.x=1;
        x=0;
    }
    if(param.y==0){
        param.y=1;
        y=0;
    }
    return(Point(x/param.x,y/param.y));
}
bool Point::operator==(Point param){
    return (x==param.x and y==param.y);
}
