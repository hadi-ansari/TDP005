#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bullet.h"
#include "Entity.h"

//Bullet
Bullet::Bullet(sf::Vector2f location) : Entity(location)
{}

// Player-Bullet
Player_Bullet::Player_Bullet(sf::Vector2f location): Bullet(location)
{
    speed = 700.0f;
    health = 1;
    if(!texture.loadFromFile("Bullet.png", sf::IntRect(0, 0, 15, 3)))
    {
        std::cerr << "Error" << std::endl;
    }
    sprite.setTexture(texture);
}

void Player_Bullet::tick(sf::Time const& delta)
{
  location.x += speed * (delta.asMicroseconds() / 1000000.0f);
  sprite.setPosition(location);
}
bool Player_Bullet::kill_me() {
    return (location.x < 0 || location.y < 0 || location.y > 768 || health < 1);
}
void Player_Bullet::collision(std::vector<Entity *> const&objects)
{
    for(auto object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> sprite).getGlobalBounds()) )
        {
            std::cout << "Colliding Player-Bullet with " << object -> get_type() << std::endl;
            std::string type = object -> get_type();

            if (type == "Big Plane" || type == "Small Plane" || type == "Bomb")
                health -= 1;
         }
    }
}
std::string Player_Bullet::get_type()
{
    return "Player-Bullet";
}

