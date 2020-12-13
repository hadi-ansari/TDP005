
#include "Bullet.h"

//Bullet
Bullet::Bullet(sf::Vector2f location, int bullet_width, int bullet_height, std::string const& texture_name)
: Textured_object(location, bullet_width, bullet_height, texture_name)
{
    speed = 0.65f;
    health = 1;
    //width = bullet_width;
    //height = bullet_height;
}

// Player-Bullet
Player_Bullet::Player_Bullet(sf::Vector2f location)
: Bullet(location, 36, 14, "Images/Player_Bullet_New.png")
{}

bool Player_Bullet::tick(sf::Time delta, World &)
{
  location.x += speed * delta.asMilliseconds() * 2;
  return !kill_me();
}
void Player_Bullet::collision(vector<shared_ptr<Entity>> const& objects, World &)
{
    for(auto const& object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            //cout << "Colliding Player-Bullet with " << object -> get_type() << endl;
            string type = object -> get_type();

            if (type == "Big Plane" || type == "Small Plane" || type == "Bomb")
                health -= 1;
         }
    }
}

// Enemy Bullet
Enemy_Bullet::Enemy_Bullet(sf::Vector2f location)
: Bullet(location, 13, 13, "Images/Enemy_Bullet_New.png")
{}

void Enemy_Bullet::collision(vector<shared_ptr<Entity>> const& objects, World &)
{
    for(auto const& object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            //cout << "Colliding Enemy-Bullet with " << object -> get_type() << endl;
            string type = object -> get_type();
            if (type == "Player")
                health -= 1;
        }
    }
}


