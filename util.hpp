#ifndef UTIL_HPP_INCLUDED
#define UTIL_HPP_INCLUDED

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Engine.hpp"

sf::Image load_image(std::string file);
sf::Font load_font(std::string file, int size);
std::string to_s(int i);
bool collision_between(GameObject* obj1, GameObject* obj2);

#endif // UTIL_HPP_INCLUDED
