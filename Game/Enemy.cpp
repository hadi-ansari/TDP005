#include <string>

#include "Enemy.h"
#include "Bullet.h"
#include "World.h"
// Enemy
Enemy::Enemy(sf::Vector2f location, int width, int height, std::string const& texture_name)
:Textured_object(location, width, height, texture_name)
{}
void Enemy::collision(std::vector<std::shared_ptr<Entity>> const& objects)
{
    for(auto const& object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            //std::cout << "Colliding " << get_type() << " with " << object -> get_type()<< std::endl;
            std::string type = object -> get_type();

            if (type == "Player")
                health -= 2;
            else if(type == "Player-Bullet")
                health -= 1;
        }
    }
}
// Bomb
Bomb::Bomb(sf::Vector2f location):Enemy(location, 50, 50, "Bomb50x50.png")
{
    health = 1;
    speed = 0.2f;
}

// Small Plane
Small_Plane::Small_Plane(sf::Vector2f location): Enemy(location, 75, 22, "Enemy1_75x22.png")
{
    health = 1;
    speed = 0.5f;
    shoot_speed = 0.7f;
    shoot_clock.restart();
}
bool Small_Plane::tick(sf::Time delta, World & world)
{
    if(shoot_clock.getElapsedTime().asSeconds() > shoot_speed)
    {
        shoot_clock.restart();
        sf::Vector2f temp{location.x , location.y + 5 + float(height) / 2};
        world.insert_object(std::make_shared<Enemy_Bullet>(Enemy_Bullet{temp}));
    }
    return Entity::tick(delta, world);
}

// Big Plane
Big_Plane::Big_Plane(sf::Vector2f location): Enemy(location, 100, 31, "Enemy2_100x31.png")
{
    health = 2;
    speed = 0.3f;
    shoot_speed = 0.9f;
    shoot_clock.restart();
}
bool Big_Plane::tick(sf::Time delta, World & world)
{
    if(shoot_clock.getElapsedTime().asSeconds() > shoot_speed)
    {
        shoot_clock.restart();
        //sf::Vector2f temp{location.x, location.y + 5 + float(height) / 2};
        sf::Vector2f temp(location.x, location.y + 5 + (float)height / 2 );
        world.insert_object(std::make_shared<Enemy_Bullet>(Enemy_Bullet{temp}));
    }
    return Entity::tick(delta, world);
}