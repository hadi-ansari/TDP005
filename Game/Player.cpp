
#include "Player.h"
#include "World.h"
#include "state.h"
#include "menu_state.h"

bool Player::invincible;

/*void Player::set_invincibility()
{
    Player::invincible = true;
    std::cout << "setting invincibility" << std::endl;
}*/

Player::Player(sf::Vector2f location) : Textured_object(location, 90, 29,"Images/Player_90X29.png")
{
    health = 3;
    speed = 0.5f;
    width = 75;
    height = 22;
    shoot_speed = 0.5f;
    shield = false;
    tripleshot = false;
    invincible = false;
    freeze_state = false;
}
bool Player::tick(sf::Time delta, World &world)
{
    cheat();

    update_status();

    set_position(delta);

    shoot(world);

    return health >= 1;
}
void Player::cheat()
{
    //Fusktangenter
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
        health = 999;
}
void Player::update_status()
{
    if(freeze_state)
    {
        freeze_state = false;
        shoot_timer.restart();
        shield_timer.restart();
        triple_timer.restart();
        invincibility_timer.restart();
    }

    if(give_invincible){
        invincible = true;
        invincibility_time = sf::seconds(0);
        invincibility_timer.restart();
        give_invincible = false;
    }

    if(invincible)
    {
        invincibility_time += invincibility_timer.restart();
        if( invincibility_time.asSeconds() > 3)
        {
            invincible = false;
        }
    }

    if(shield)
    {
        shield_time += shield_timer.restart();
        if(shield_time.asSeconds() > 10)
        {
            shield = false;
        }
    }

    if(tripleshot)
    {
        triple_time += triple_timer.restart();
        if(triple_time.asSeconds() > 10)
        {
            tripleshot = false;
        }
    }
}

void Player::set_position(sf::Time delta)
{
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
}
void Player::shoot(World &world)
{
    shoot_time += shoot_timer.restart();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
        && shoot_time.asSeconds() > shoot_speed)
    {
        shoot_time = sf::seconds(0);
        sf::Vector2f temp = {location.x + 65, location.y + 10};
        world.insert_object(make_shared<Player_Bullet>(Player_Bullet{temp}));
        // Lägger till 2 extra skott om den har tripleshot aktiv
        if(tripleshot)
        {
            sf::Vector2f upper_bullet = {location.x + 65, location.y + 28};
            sf::Vector2f lower_bullet = {location.x + 65, location.y - 8 };
            world.insert_object(make_shared<Player_Bullet>(Player_Bullet{upper_bullet}));
            world.insert_object(make_shared<Player_Bullet>(Player_Bullet{lower_bullet}));
        }
    }
}

void Player::collision(vector<shared_ptr<Entity>> const& objects, World &)
{
    for(auto const& object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> get_sprite()).getGlobalBounds()) )
        {
            string type = object -> get_type();

            if((type == "Big Plane"  || type == "Bomb") && !shield && !invincible)
            {
                health -= 2;
                give_invincible = true;
            }
            else if( (type == "Small Plane" || type == "Enemy-Bullet") && !shield && !invincible)
            {
                health -= 1;
                give_invincible = true;
            }
            else if((type == "Big Plane"  || type == "Bomb" || type == "Small Plane") && shield && !invincible)
                shield = false;
            else if(type == "Heal" && health < 3)
            {
                health += 1;
            }
            else if(type == "Heal" && health  >= 3)
            {
                //World::add_score(5);
            }
            else if(type == "Tripleshot" && !tripleshot)
            {
                tripleshot = true;
                triple_time = sf::seconds(0);
                triple_timer.restart();
            }
            else if(type == "Tripleshot" && tripleshot)
            {
                triple_time = sf::seconds(0);
                triple_timer.restart();
            }
            else if(type == "Shield" && !shield)
            {
                shield = true;
                shield_time = sf::seconds(0);
                shield_timer.restart();
            }
            else if(type == "Shield" && shield)
            {
                shield_time = sf::seconds(0);
                shield_timer.restart();
            }
        }
    }
}
void Player::freeze() {
    freeze_state = true;
}

string Player::get_shield_time() const
{
    int time = 10 - (int)shield_time.asSeconds();
    return "Shield Time: " + to_string(time);
}

