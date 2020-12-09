#include <SFML/Graphics.hpp>

#include "Entity.h"
Entity::Entity(sf::Vector2f location)
        :location(location)
{}

sf::Sprite Entity::get_sprite() const
{
    return sprite;
}
int Entity::get_health() const
{
    return health;
}