#include <SFML/Graphics.hpp>
#include <iostream>

#include "World.h"
#include "Enemy.h"

size_t const width = 1024;
size_t const height = 768;
int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Sky Wars", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    // window.setKeyRepeatEnabled(false);

    World world{};
    world.insert_object(new Big_Plane{sf::Vector2f (1000, 0)});
    world.insert_object(new Small_Plane{sf::Vector2f ( 880, 250)});
    world.insert_object(new Bomb{sf::Vector2f ( 950, 400)});
    world.run(window);

    return 0;
}