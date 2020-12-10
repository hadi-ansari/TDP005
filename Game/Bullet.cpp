#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bullet.h"
#include "Entity.h"

//Bullet
Bullet::Bullet(sf::Vector2f location, std::string const& texture_name)
: Textured_object(location, 15, 3, texture_name)
{
    speed = 0.7f;
    health = 1;
}

// Player-Bullet
Player_Bullet::Player_Bullet(sf::Vector2f location)
: Bullet(location, "Bullet.png")
{}

bool Player_Bullet::tick(sf::Time delta, World &)
{
  location.x += speed * delta.asMilliseconds();
  return !kill_me();
}
void Player_Bullet::collision(std::vector<std::shared_ptr<Entity>> const& objects, World &)
{
    for(auto const& object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            //std::cout << "Colliding Player-Bullet with " << object -> get_type() << std::endl;
            std::string type = object -> get_type();

            if (type == "Big Plane" || type == "Small Plane" || type == "Bomb")
                health -= 1;
         }
    }
}

// Enemy Bullet
Enemy_Bullet::Enemy_Bullet(sf::Vector2f location)
: Bullet(location, "Enemy-Bullet.png")
{}

void Enemy_Bullet::collision(std::vector<std::shared_ptr<Entity>> const& objects, World &)
{
    for(auto const& object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            //std::cout << "Colliding Enemy-Bullet with " << object -> get_type() << std::endl;
            std::string type = object -> get_type();
            if (type == "Player")
                health -= 1;
        }
    }
}


