#include <string>
#include <utility>

#include "Powerup.h"

Powerup::Powerup(const std::string& name, sf::Vector2f location): name(name), Entity(location)
{
    health = 1;
    speed = 0.2f;
    width = 35;
    height = 35;
    if(name == "Heal")
    {
        texture.loadFromFile("Health_sprite.png", sf::IntRect(0, 0, width, height));
    }
    else if(name == "Shield")
    {
        texture.loadFromFile("Shield_sprite.png", sf::IntRect(0, 0, width, height));

    }
    else if(name == "Tripleshot")
    {
        texture.loadFromFile("Tripleshot_sprite.png", sf::IntRect(0, 0, width, height));
    }
    sprite.setTexture(texture);
}

void Powerup::collision(std::vector<Entity*> const& objects)
{
    for(auto object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            //std::cout << "Colliding "<< name << " with " << object -> get_type() <<  std::endl;
            std::string type = object -> get_type();

            if(type == "Player")
                health -= 1;
        }
    }

}