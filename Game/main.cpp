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
    world.insert_object(new Big_Plane{sf::Vector2f (1600, 0)});
    world.insert_object(new Big_Plane{sf::Vector2f (1600, 760)});
    world.insert_object(new Big_Plane{sf::Vector2f (1600, 650)});
    world.insert_object(new Big_Plane{sf::Vector2f (1600, 340)});
    world.insert_object(new Big_Plane{sf::Vector2f (1600, 480)});
    world.insert_object(new Big_Plane{sf::Vector2f (1600, 700)});
    world.insert_object(new Small_Plane{sf::Vector2f ( 1600, 250)});
    world.insert_object(new Small_Plane{sf::Vector2f ( 1600, 320)});
    world.insert_object(new Small_Plane{sf::Vector2f ( 1600, 690)});
    world.insert_object(new Small_Plane{sf::Vector2f ( 1600, 750)});
    world.insert_object(new Bomb{sf::Vector2f ( 1600, 400)});
    world.insert_object(new Heal{sf::Vector2f ( 1600, 250)});
    world.insert_object(new Shield{sf::Vector2f ( 1700, 250)});
    world.insert_object(new Tripleshot{sf::Vector2f ( 1800, 250)});

    world.run(window);

    return 0;
}