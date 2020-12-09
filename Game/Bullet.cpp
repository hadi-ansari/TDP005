#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bullet.h"
#include "Entity.h"

//Bullet
Bullet::Bullet(sf::Vector2f location) : Entity(location)
{
    speed = 0.7f;
    health = 1;
    width = 15;
    height = 3;
}

// Player-Bullet
Player_Bullet::Player_Bullet(sf::Vector2f location): Bullet(location)
{
    texture.loadFromFile("Bullet.png", sf::IntRect(0, 0, width, height));
    sprite.setTexture(texture);
}

void Player_Bullet::tick(sf::Time const& delta)
{
  location.x += speed * delta.asMilliseconds();
  sprite.setPosition(location);
}
void Player_Bullet::collision(std::vector<Entity *> const&objects)
{
    for(auto object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            std::cout << "Colliding Player-Bullet with " << object -> get_type() << std::endl;
            std::string type = object -> get_type();

            if (type == "Big Plane" || type == "Small Plane" || type == "Bomb")
                health -= 1;
         }
    }
}

// Enemy Bullet
Enemy_Bullet::Enemy_Bullet(sf::Vector2f location): Bullet(location)
{

    texture.loadFromFile("Enemy-Bullet.png", sf::IntRect(0, 0, width, height));
    sprite.setTexture(texture);
}

void Enemy_Bullet::collision(std::vector<Entity *> const&objects)
{
    for(auto object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            std::cout << "Colliding Enemy-Bullet with " << object -> get_type() << std::endl;
            std::string type = object -> get_type();
            if (type == "Player")
                health -= 1;
        }
    }
}


