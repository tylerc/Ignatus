#include "util.hpp"

sf::Image load_image(std::string file)
{
    sf::Image loading;
    if (!loading.LoadFromFile(file))
    {
        std::cout << "Couldn't load image " << file << std::endl;
        exit(1);
    }
    return loading;
}

sf::Font load_font(std::string file, int size)
{
    sf::Font loading;
    if (!loading.LoadFromFile(file, size))
    {
        std::cout << "Couldn't load font " << file << std::endl;
        exit(1);
    }
    return loading;
}

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
