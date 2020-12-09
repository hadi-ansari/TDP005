#include <SFML/Graphics.hpp>

#include "Entity.h"
Entity::Entity(sf::Vector2f location)
        :location(location)
{}
bool Entity::tick(sf::Time delta, World & world)
{
    location.x -= delta.asMilliseconds() * speed;
    sprite.setPosition(location);
    return !kill_me();
}
bool Entity::kill_me() const
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