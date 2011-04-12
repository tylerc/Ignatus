#ifndef ALL_HPP_INCLUDED
#define ALL_HPP_INCLUDED

#include "IncludesAndDefines.hpp"

// Supporting classes
namespace Ignatus{

class GameObject;
class Engine;
class State;
//class Particles;
//struct Particles::Dna;
}

#include "AniSprite.hpp"
#include "Point.hpp"
#include "Camera.hpp"
#include "Part_DNA.hpp"

// GameObjects + Children
#include "GameObject.hpp"
#include "Polygon.hpp"
#include "AniObject.hpp"
#include "2D_Model.hpp"
#include "Particle.hpp"
#include "Particles.hpp"
#include "Projectile.hpp"
#include "Text.hpp"
#include "Sound.hpp"
#include "Music.hpp"

// GUI
#include "GUI/Bar.hpp"
#include "GUI/SlideBar.hpp"

// Game Running Infrastructure
#include "State.hpp"
#include "Engine.hpp"
#include "util.hpp"

#endif // ALL_HPP_INCLUDED
