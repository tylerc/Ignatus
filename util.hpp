#ifndef UTIL_HPP_INCLUDED
#define UTIL_HPP_INCLUDED

namespace Ignatus{

std::string to_s(int i);
bool collision_between(GameObject* obj1, GameObject* obj2);
float degrees_to_radians(float angle);
bool Sort_GameObjects(GameObject* a,GameObject* b);

}

#endif // UTIL_HPP_INCLUDED
