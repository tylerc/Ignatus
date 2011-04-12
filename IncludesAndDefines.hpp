#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#define fn(f) boost::bind(&f, this)
#define _E (*Engine::GetEngine())
#define _CS _E.CS
#define _App(f) _E.App->f
#define unless(exp) if(!(exp))
#define _Width (signed int)_App(GetWidth())
#define _Height (signed int)_App(GetHeight())
#define center_x Position.x+Dimensions.x/2
#define center_y Position.y+Dimensions.y/2
#define center_p(T) Point<T>(center_x,center_y)
#define Point0(T) Point<T>()
#define error(var) std::cout<<"Error: "<<var<<"!"<<std::endl;
#define debug(var) if(_E.DEBUG)std::cout<<"Debuging: "<<var<<"..."<<std::endl;
#define null 0
#define make(var, type) dynamic_cast<type>(var)
