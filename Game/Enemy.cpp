#include <string>

#include "Enemy.h"
//
Enemy::Enemy(sf::Vector2f location):Entity(location)
{}

// Bomb
Bomb::Bomb(sf::Vector2f location):Enemy(location)
{
    health = 1;
    speed = 0.2f;
    width = 50;
    height = 50;
    if(!texture.loadFromFile("Bomb50x50.png", sf::IntRect(0, 0, width, height)))
    {
        std::cerr << "Error" << std::endl;
    }
    sprite.setTexture(texture);
}
void Bomb::tick(sf::Time const& delta)
{
    location.x -= delta.asMilliseconds() * speed;
    sprite.setPosition(location);
}
bool Bomb::kill_me()
{
    return (location.x < 0 || location.y < 0 || location.y > 768 || health < 1);
}
void Bomb::collision(std::vector<Entity*> const& objects)
{
    for(auto object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> sprite).getGlobalBounds()) )
        {
            std::cout << "Colliding Bomb with " << object -> get_type() <<  std::endl;
            std::string type = object -> get_type();

            if(type == "Player-Bullet" || type == "Player")
                health -= 1;
        }
    }

}
std::string Bomb::get_type()
{
    return "Bomb";
}

// Small Plane
Small_Plane::Small_Plane(sf::Vector2f location): Enemy(location)
{
    health = 1;
    speed = 0.5f;
    width = 75;
    height = 22;
    if(!texture.loadFromFile("Enemy1_75x22.png", sf::IntRect(0, 0, width, height)))
    {
        std::cerr << "Error" << std::endl;
    }
    sprite.setTexture(texture);
}

void Small_Plane::tick(sf::Time const& delta)
{
    location.x -= delta.asMilliseconds() * speed;
    sprite.setPosition(location);
}
bool Small_Plane::kill_me()
{
    return (location.x < 0 || location.y < 0 || location.y > 768 || health < 1);
}

void Small_Plane::collision(std::vector<Entity*> const& objects)
{
    for(auto object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> sprite).getGlobalBounds()) )
        {
            std::cout << "Colliding Small Plane with " << object -> get_type()<< std::endl;
            std::string type = object -> get_type();

            if (type == "Player" || type == "Player-Bullet")
                health -= 1;
        }
    }
}
std::string Small_Plane::get_type() {
    return "Small Plane";
}

// Big Plane
Big_Plane::Big_Plane(sf::Vector2f location): Enemy(location)
{
    health = 2;
    speed = 0.3f;
    width = 100;
    height = 31;
    if(!texture.loadFromFile("Enemy2_100x31.png", sf::IntRect(0, 0, width, height)))
    {
        std::cerr << "Error" << std::endl;
    }
    sprite.setTexture(texture);
}

void Big_Plane::tick(sf::Time const& delta)
{
  location.x -= delta.asMilliseconds() * speed;
  sprite.setPosition(location);
}
bool Big_Plane::kill_me()
{
    return (location.x < 0 || location.y < 0 || location.y > 768 || health < 1);
}

void Big_Plane::collision(std::vector<Entity*> const& objects)
{
    for(auto object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> sprite).getGlobalBounds()) )
        {
            std::cout << "Colliding Big Plane with " << object -> get_type()<< std::endl;
            std::string type = object -> get_type();

            if (type == "Player")
                health -= 2;
            else if(type == "Player-Bullet")
                health -= 1;
        }
    }
}
std::string Big_Plane::get_type() {
    return "Big Plane";
}

