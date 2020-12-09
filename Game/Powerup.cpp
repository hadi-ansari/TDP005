#include <string>

#include "Powerup.h"

Powerup::Powerup(sf::Vector2f location):Entity(location)
        {}

// ---------Heal Powerup----------
Heal::Heal(sf::Vector2f location):Powerup(location){
    health = 1;
    speed = 0.2f;
    width = 35;
    height = 35;

    if(!texture.loadFromFile("Health_sprite.png", sf::IntRect(0, 0, width, height)))
    {
        std::cerr << "Error" << std::endl;
    }
    sprite.setTexture(texture);
}

void Heal::tick(sf::Time const& delta)
{
    location.x -= delta.asMilliseconds() * speed;
    sprite.setPosition(location);
}
void Heal::collision(std::vector<Entity*> const& objects)
{
    for(auto object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            //std::cout << "Colliding Heal with " << object -> get_type() <<  std::endl;
            std::string type = object -> get_type();

            if(type == "Player")
                health -= 1;
        }
    }

}
std::string Heal::get_type()
{
    return "Heal";
}
// ---------Shield Powerup----------
Shield::Shield(sf::Vector2f location):Powerup(location){
    health = 1;
    speed = 0.2f;
    width = 35;
    height = 35;

    if(!texture.loadFromFile("Shield_sprite.png", sf::IntRect(0, 0, width, height)))
    {
        std::cerr << "Error" << std::endl;
    }
    sprite.setTexture(texture);
}

void Shield::tick(sf::Time const& delta)
{
    location.x -= delta.asMilliseconds() * speed;
    sprite.setPosition(location);
}
void Shield::collision(std::vector<Entity*> const& objects)
{
    for(auto object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            //std::cout << "Colliding Shield with " << object -> get_type() <<  std::endl;
            std::string type = object -> get_type();

            if(type == "Player")
                health -= 1;
        }
    }

}
std::string Shield::get_type()
{
    return "Shield";
}

// ---------Triple-shot Powerup----------
Tripleshot::Tripleshot(sf::Vector2f location):Powerup(location){
    health = 1;
    speed = 0.2f;
    width = 35;
    height = 35;

    if(!texture.loadFromFile("Tripleshot_sprite.png", sf::IntRect(0, 0, width, height)))
    {
        std::cerr << "Error" << std::endl;
    }
    sprite.setTexture(texture);
}

void Tripleshot::tick(sf::Time const& delta)
{
    location.x -= delta.asMilliseconds() * speed;
    sprite.setPosition(location);
}
void Tripleshot::collision(std::vector<Entity*> const& objects)
{
    for(auto object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            //std::cout << "Colliding Triple-shot with " << object -> get_type() <<  std::endl;
            std::string type = object -> get_type();

            if(type == "Player")
                health -= 1;
        }
    }

}
std::string Tripleshot::get_type()
{
    return "Tripleshot";
}