
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
        if(health < 1) break;
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            string type = object -> get_type();
            if (type == "Player" && !Player::is_invincible()){
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
    upp_state = true;
    freeze_state = false;
}
bool Small_Plane::tick(sf::Time delta, World & world)
{
    if(freeze_state)
    {
        freeze_state = false;
        shoot_timer.restart();
        vertical_timer.restart();
    }
    shoot_time += shoot_timer.restart();
    if(shoot_time.asSeconds() > shoot_speed)
    {
        shoot_time = sf::seconds(0);
        sf::Vector2f temp{location.x , location.y + 5 + float(height) / 2};
        world.insert_object(std::make_shared<Enemy_Bullet>(Enemy_Bullet{temp}));
    }
    vertical_move(delta);

    return Entity::tick(delta, world);
}

void Small_Plane::vertical_move(sf::Time delta)
{
    vertical_time += vertical_timer.restart();
    if(vertical_time.asMilliseconds() > 1000)
    {
        if (upp_state)
            upp_state = false;
        else
            upp_state = true;
        vertical_time = sf::seconds(0);
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
void Small_Plane::freeze() {
    freeze_state = true;
}

// Big Plane
Big_Plane::Big_Plane(sf::Vector2f location): Enemy(location, 150, 48, "Images/Big_Plane150x48.png")
{
    health = 2;
    speed = 0.25f;
    shoot_speed = 1.3f;
    freeze_state = false;
}
bool Big_Plane::tick(sf::Time delta, World & world)
{
    if(freeze_state)
    {
        freeze_state = false;
        shoot_timer.restart();
    }
    shoot_time += shoot_timer.restart();
    if(shoot_time.asSeconds() > shoot_speed)
    {
        shoot_time = sf::seconds(0);
        sf::Vector2f temp(location.x, location.y + 5 + (float)height / 2 );
        world.insert_object(std::make_shared<Enemy_Bullet>(Enemy_Bullet{temp}));
    }
    return Entity::tick(delta, world);
}
void Big_Plane::freeze() {
    freeze_state = true;
}