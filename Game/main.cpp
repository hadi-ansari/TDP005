#include <SFML/Graphics.hpp>
#include <iostream>

#include "World.h"
#include "Enemy.h"
#include "Bullet.h"

size_t const width = 1024;
size_t const height = 768;
int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Test game");
    window.setVerticalSyncEnabled(true);
    // window.setKeyRepeatEnabled(false);

    sf::Vector2f test{300, 200};
    World world{};
    world.insert_object(new Big_Plane{});
    world.run(window);

    return 0;
}