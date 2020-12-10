#include <string>
#include <utility>

#include "Powerup.h"

Powerup::Powerup(std::string name, std::string const& texture_name ,sf::Vector2f location)
: name(std::move(name)), Textured_object(location, 35, 35, texture_name)
{
    health = 1;
    speed = 0.2f;
}

void Powerup::collision(std::vector<std::shared_ptr<Entity>> const& objects)
{
    for(auto const& object: objects)
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