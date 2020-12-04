#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>

#include "Player.h"
#include "Bullet.h"

Player::Player(sf::Vector2f location) : Entity(location)
{
    location = {0, 0};
    health = 3;
    speed = 0.5f;
    width = 75;
    height = 22;
    shoot_speed = 0.30f;
    sht = false;
    t1 = clock1.restart();
    if(!texture.loadFromFile("Player_75x22.png", sf::IntRect(0, 0, width, height)))
    {
        std::cerr << "Error" << std::endl;
    }
    sprite.setTexture(texture);
}

sf::Vector2f Player::process_event(sf::Time delta)
{
    sf::Vector2f v;
    float ElapsedTime = delta.asMilliseconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        v.y -= speed * ElapsedTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        v.y += speed * ElapsedTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        v.x -= speed * ElapsedTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        v.x += speed * ElapsedTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        if (t1.asSeconds() > shoot_speed) {
            sht = true;
            t1 = clock1.restart();
        }
    return v;
}
void Player::tick(sf::Time const& delta)
{
    t1 = clock1.getElapsedTime();
  /* Speed dependent  */
    sf::Vector2f temp = location + process_event(delta);
    if (temp.x < (float)(1600 - width) && temp.x >= 0 && temp.y < (float)(900 - height)  && temp.y >= 0 )
        sprite.setPosition(location += process_event(delta));
}
bool Player::want_shoot() const
{
    return sht;
}
Entity* Player::shoot()
{
    sht = false;
    sf::Vector2f temp{location.x + 65, location.y + 10};
    return (new Player_Bullet{temp});
}
bool Player::kill_me()
{
    return health < 1;
}
void Player::collision(std::vector<Entity*> const& objects)
{
    for(auto object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> sprite).getGlobalBounds()) )
        {
            //std::cout << "Colliding Player with " << object -> get_type() <<  std::endl;
            std::string type = object -> get_type();

            if(type == "Big Plane"  || type == "Bomb")
                    health -= 2;
            else if(type == "Small Plane" || type == "Enemy-Bullet")
                    health -= 1;
        }
    }
}

std::string Player::get_type() {
    return "Player";
}