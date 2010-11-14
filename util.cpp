#include "All.hpp"

std::string to_s(int i)
{
    std::ostringstream stm;
    stm << i;
    return stm.str();
}

bool collision_between(GameObject* obj1, GameObject* obj2)
{
    if (obj1->y + obj1->height < obj2->y)
        return false;
    if (obj1->y > obj2->y + obj2->height)
        return false;
    if (obj1->x + obj1->width < obj2->x)
        return false;
    if (obj1->x > obj2->x + obj2->width)
        return false;

    return true;
}

float degrees_to_radians(float angle)
{
    return angle * 3.141592653589793/180;
}

float distance_between(int x1, int y1, int x2, int y2)
{
    int a = x2-x1;
    int b = y2-y1;
    return sqrt(a*a + b*b);
}
