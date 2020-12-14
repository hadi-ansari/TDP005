#include "Entity.h"
#include "Texture_manager.h"

Entity::Entity(sf::Vector2f location, int width, int height)
        :location{location}, width{width}, height{height}
{
    sprite.setPosition(location);
}
bool Entity::tick(sf::Time delta, World & world)
{
    location.x -= delta.asMilliseconds() * speed;
    return !kill_me();
}
bool Entity::kill_me() const
{
 return(-150 > location.x || location.x > 1600 || location.y < 0 || location.y > 900 || health < 1);
}

int Entity::get_health() const
{
    return health;
}
Textured_object::Textured_object(sf::Vector2f location, int width, int height, std::string const& texture_name)
: Entity(location, width, height)
{
    sf::Texture *t = Texture_Manager::get(texture_name, width, height);
    sprite.setTexture(*t);
}

void Textured_object::render(sf::RenderWindow &window)
{
    sprite.setPosition(location);
    window.draw(sprite);
}