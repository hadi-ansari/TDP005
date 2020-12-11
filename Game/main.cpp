#include <SFML/Graphics.hpp>
#include <iostream>

#include "World.h"
#include "Enemy.h"
#include "Powerup.h"

size_t const width = 1600;
size_t const height = 900;
int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Sky Wars", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    // window.setKeyRepeatEnabled(false);

    World world{};
    world.run(window);

    return 0;
}