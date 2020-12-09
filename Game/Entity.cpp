#include <SFML/Graphics.hpp>

#include "Entity.h"
Entity::Entity(sf::Vector2f location)
        :location(location)
{}

bool Entity::kill_me()
{
 return(location.x < 0 || location.x > 1600 || location.y < 0 || location.y > 900 || health < 1);
}


sf::Sprite Entity::get_sprite() const
{
    return sprite;
}
int Entity::get_health() const
{
    return health;
}