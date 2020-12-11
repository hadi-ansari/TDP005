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
    //Powerup p1{"test", sf::Vector2f(200, 200)};
    World world{};
    /*
    world.insert_object(std::make_shared<Big_Plane>(Big_Plane{sf::Vector2f (1600, 0)}));
    world.insert_object(std::make_shared<Big_Plane>(Big_Plane{sf::Vector2f (1600, 760)}));
    world.insert_object(std::make_shared<Big_Plane>(Big_Plane{sf::Vector2f (1600, 650)}));
    world.insert_object(std::make_shared<Big_Plane>(Big_Plane{sf::Vector2f (1600, 340)}));
    //world.insert_object(new Big_Plane{sf::Vector2f (1600, 480)});
    //world.insert_object(new Big_Plane{sf::Vector2f (1600, 700)});
    world.insert_object(std::make_shared<Small_Plane>(Small_Plane{sf::Vector2f ( 1600, 250)}));
    world.insert_object(std::make_shared<Small_Plane>(Small_Plane{sf::Vector2f ( 1600, 320)}));
    world.insert_object(std::make_shared<Small_Plane>(Small_Plane{sf::Vector2f ( 1600, 690)}));
    world.insert_object(std::make_shared<Small_Plane>(Small_Plane{sf::Vector2f ( 1600, 750)}));
    world.insert_object(std::make_shared<Bomb>(Bomb{sf::Vector2f ( 1600, 400)}));
    world.insert_object(std::make_shared<Bomb>(Bomb{sf::Vector2f ( 3000, 400)}));
    world.insert_object(std::make_shared<Powerup>(Powerup("Heal", "Health_sprite.png",sf::Vector2f ( 1600, 230))));
    world.insert_object(std::make_shared<Powerup>(Powerup("Shield", "Shield_sprite.png", sf::Vector2f ( 1600, 290))));
    world.insert_object(std::make_shared<Powerup>(Powerup("Tripleshot" , "Tripleshot_sprite.png", sf::Vector2f ( 1300, 380))));
*/
    world.run(window);

    return 0;
}