#include <string>

#include "Enemy.h"

Big_Plane::Big_Plane()
{
    location = {900, 0};
    health = 2;
    speed = 150.0f;
    if(!texture.loadFromFile("Enemy2_85x27.png", sf::IntRect(0, 0, 85, 27)))
    {
        std::cerr << "Error" << std::endl;
    }
    sprite.setTexture(texture);
}

void Big_Plane::tick(sf::Time const& delta)
{
  // location.x -= 1;
  location.x -= delta.asMicroseconds() * speed / 1000000.0f;
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

            if (type == "P")
                health -= 2;
            else if(type == "PB")
                health -= 1;
        }
    }
}
std::string Big_Plane::get_type() {
    return "BP";
}