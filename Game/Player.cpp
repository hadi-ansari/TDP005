#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>

#include "Player.h"
#include "Bullet.h"

Player::Player(sf::Vector2f location) : Entity(location) {
    location = {0, 0};
    if(!texture.loadFromFile("Player65x21.png", sf::IntRect(0, 0, 65, 21)))
    {
        std::cerr << "Error" << std::endl;
    }
    sprite.setTexture(texture);
    health = 3;
    speed = 0.5f;
    shoot_speed = 0.30f;
    sht = false;
    t1 = clock1.restart();

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

Bullet* Player::shoot()
{
    sht = false;
    sf::Vector2f temp{location.x + 65, location.y + 10};
    return (new Player_Bullet{temp});
}

void Player::tick(sf::Time const& delta)
{
    t1 = clock1.getElapsedTime();
  /* Speed dependent  */
    sf::Vector2f temp = location + process_event(delta);
    if (temp.x < 959 && temp.x >= 0 && temp.y < 747  && temp.y >= 0 )
        sprite.setPosition(location += process_event(delta));
}
bool Player::want_shoot() const
{
    return sht;
}
bool Player::kill_me()
{
    return (location.x < 0 || location.y < 0 || location.y > 768 || health < 1);
}
void Player::collision(std::vector<Entity*> const& objects)
{
    for(auto object: objects)
    {
        if ( sprite.getGlobalBounds().intersects((object -> sprite).getGlobalBounds()) )
        {
            std::cout << "Colliding Player with " << object -> get_type() <<  std::endl;
            std::string type = object -> get_type();

            if(type == "Big Plane" || type == "Enemy-Bullet" || type == "Bomb")
                    health -= 2;
            else if(type == "Small Plane")
                    health -= 1;
        }
    }
}

std::string Player::get_type() {
    return "Player";
}