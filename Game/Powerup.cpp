
#include "Powerup.h"

Powerup::Powerup(string name, string const& texture_name ,sf::Vector2f location)
: name(move(name)), Textured_object(location, 35, 35, texture_name)
{
    health = 1;
    speed = 0.2f;
}

void Powerup::collision(vector<shared_ptr<Entity>> const& objects, World &)
{
    for(auto const& object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            string type = object -> get_type();

            if(type == "Player")
                health -= 1;
        }
    }

}