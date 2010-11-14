#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#define fn(f) boost::bind(f, this)
#define fn1(f) boost::bind(f, this, _1)
#define _E (*Engine::GetEngine())
#define _CS _E.CS
#define _App(f) _E.App->f
#define unless(exp) if(!(exp))
#define _Width (signed int)_App(GetWidth())
#define _Height (signed int)_App(GetHeight())
#define center_x x+width/2
#define center_y y+height/2
