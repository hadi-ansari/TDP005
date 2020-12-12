
#include "Player.h"
#include "World.h"

Player::Player(sf::Vector2f location) : Textured_object(location, 65, 20,"Player_75x22.png")
{
    health = 3;
    speed = 0.5f;
    width = 75;
    height = 22;
    shoot_speed = 0.30f;
    shoot_clock.restart();
    shield = false;
}
bool Player::tick(sf::Time delta, World &world)
{
    if(shield && shield_clock.getElapsedTime().asSeconds() > 10)
    {
        shield = false;
    }

    /* Förflyttning av player  */
    sf::Vector2f temp;
    float ElapsedTime = delta.asMilliseconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        temp.y -= speed * ElapsedTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        temp.y += speed * ElapsedTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        temp.x -= speed * ElapsedTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        temp.x += speed * ElapsedTime;

    temp += location;
    if (temp.x < (float)(1600 - width) && temp.x >= 0 && temp.y < (float)(900 - height)  && temp.y >= 0 )
    {
        location = temp;
        sprite.setPosition(location);
    }
    // skjuta skott
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
        && shoot_clock.getElapsedTime().asSeconds() > shoot_speed)
    {
        shoot_clock.restart();
        temp = {location.x + 65, location.y + 10};
        world.insert_object(make_shared<Player_Bullet>(Player_Bullet{temp}));
    }

    return health >= 1;
}

void Player::collision(vector<shared_ptr<Entity>> const& objects, World &)
{
    for(auto const& object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            //cout << "Colliding Player with " << object -> get_type() <<  endl;
            string type = object -> get_type();

            if((type == "Big Plane"  || type == "Bomb") && !shield)
                    health -= 2;
            else if( (type == "Small Plane" || type == "Enemy-Bullet") && !shield)
                    health -= 1;
            else if((type == "Big Plane"  || type == "Bomb" || type == "Small Plane") && shield)
                shield = false;
            else if(type == "Heal" && health < 3)
            {
                health += 1;
            }
            else if(type == "Shield")
            {
                shield = true;
                shield_clock.restart();
            }
            else if(type == "Shield" && shield)
            {
                shield_clock.restart();
            }
        }
    }
}

string Player::get_shield_time() const
{
    int time = 10 - (int)shield_clock.getElapsedTime().asSeconds();
    return "Shield Time: " + to_string(time);
}
