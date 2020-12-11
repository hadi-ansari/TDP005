#include <string>

#include "Enemy.h"
#include "Bullet.h"
#include "World.h"
// Enemy
Enemy::Enemy(sf::Vector2f location, int width, int height, std::string const& texture_name)
:Textured_object(location, width, height, texture_name)
{}
void Enemy::collision(std::vector<std::shared_ptr<Entity>> const& objects, World &world)
{
    for(auto const& object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            //std::cout << "Colliding " << get_type() << " with " << object -> get_type()<< std::endl;
            std::string type = object -> get_type();
            if (type == "Player")
                health -= 2;
            else if(type == "Player-Bullet") {
                health -= 1;
                if(health < 1 && get_type() == "Big Plane") world.add_score(100);
                else if(health < 1 && get_type() == "Small Plane") world.add_score(150);
                else if(health < 1 && get_type() == "Bomb") world.add_score(50);
            }
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
    speed = 0.4f;
    shoot_speed = 0.7f;
    symmetry_line = location.x;
    wave_height = 300;
    shoot_clock.restart();
    vertical_timer.restart();
}
bool Small_Plane::tick(sf::Time delta, World & world)
{
    if(shoot_clock.getElapsedTime().asSeconds() > shoot_speed)
    {
        shoot_clock.restart();
        sf::Vector2f temp{location.x , location.y + 5 + float(height) / 2};
        world.insert_object(std::make_shared<Enemy_Bullet>(Enemy_Bullet{temp}));
    }
    vertical_move(delta);

    return Entity::tick(delta, world);
}

void Small_Plane::vertical_move(sf::Time delta)
{
    if(vertical_timer.getElapsedTime().asMilliseconds() > 500)
    {
        if (upp_state)
            upp_state = false;
        else
            upp_state = true;
        vertical_timer.restart();
    }
    if(upp_state)
    {
        float temp = location.y - delta.asMilliseconds() * speed / 2;
        if(temp >= 0)
            location.y = temp;
    }
    else
    {
        float temp = location.y + delta.asMilliseconds() * speed / 2;
        if(temp < 900)
            location.y = temp;
    }

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
        sf::Vector2f temp(location.x, location.y + 5 + (float)height / 2 );
        world.insert_object(std::make_shared<Enemy_Bullet>(Enemy_Bullet{temp}));
    }
    return Entity::tick(delta, world);
}