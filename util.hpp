#ifndef UTIL_HPP_INCLUDED
#define UTIL_HPP_INCLUDED

std::string to_s(int i);
bool collision_between(GameObject* obj1, GameObject* obj2);
float degrees_to_radians(float angle);
float distance_between(int x1, int y1, int x2, int y2);

#endif // UTIL_HPP_INCLUDED
