#include "All.hpp"

namespace Ignatus{

std::string to_s(int i)
{
    std::ostringstream stm;
    stm << i;
    return stm.str();
}

bool collision_between(GameObject* obj1, GameObject* obj2)
{
    return sf::Rect<int>(obj1->Position.x,obj1->Position.y,obj1->Position.x+obj1->Dimensions.x,obj1->Position.y+obj1->Dimensions.y).Intersects(sf::Rect<int>(obj2->Position.x,obj2->Position.y,obj2->Position.x+obj2->Dimensions.x,obj2->Position.y+obj2->Dimensions.y));
}

float degrees_to_radians(float angle)
{
    return angle * 3.141592653589793/180;
}

bool Sort_GameObjects(GameObject* a,GameObject* b){
    return (a->Depth<b->Depth);
}

}
