
#include "Enemy.h"
#include "Bullet.h"
#include "World.h"
#include "Player.h"

// Enemy
Enemy::Enemy(sf::Vector2f location, int width, int height, string const& texture_name)
:Textured_object(location, width, height, texture_name)
{}
void Enemy::collision(vector<std::shared_ptr<Entity>> const& objects, World &world)
{

    for(auto const& object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            //std::cout << "Colliding " << get_type() << " with " << object -> get_type()<< std::endl;
            std::string type = object -> get_type();
            if (type == "Player" && !Player::is_invincible()){
                //Player::set_invincibility();
                health -= 2;


            }

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
Bomb::Bomb(sf::Vector2f location):Enemy(location, 70, 70, "Images/Bomb70x70.png")
{
    health = 1;
    speed = 0.2;
}

// Small Plane
Small_Plane::Small_Plane(sf::Vector2f location): Enemy(location, 115, 30, "Images/Small_Plane_Texture.png")
{
    health = 1;
    speed = 0.3f;
    shoot_speed = 1.1f;
    shoot_clock.restart();
    upp_state = true;
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
    if(vertical_timer.getElapsedTime().asMilliseconds() > 1000)
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
Big_Plane::Big_Plane(sf::Vector2f location): Enemy(location, 150, 48, "Images/Big_Plane150x48.png")
{
    health = 2;
    speed = 0.25f;
    shoot_speed = 1.3f;
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