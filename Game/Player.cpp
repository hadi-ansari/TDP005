#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>

#include "Player.h"
#include "Bullet.h"

Player::Player()
{
    location = {0, 0};
    if(!texture.loadFromFile("Player65x21.png", sf::IntRect(0, 0, 65, 21)))
    {
        std::cerr << "Error" << std::endl;
    }
    sprite.setTexture(texture);
    health = 3;
    speed = 150.0f;
    shoot_speed = 0.30f;
    sht = false;
    t1 = clock1.restart();

}

sf::Vector2f Player::process_event()
{
    const float speed = 0.5;
    sf::Vector2f v;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        v.y -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        v.y += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        v.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        v.x += speed;
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
  // if(up)
  //   {
  //     location.y -= delta.asMicroseconds() * speed / 1000000.0f;
  //     up = false;
  //   }
  // else if(down)
  //   {
  //     location.y += delta.asMicroseconds() * speed / 1000000.0f;
  //     down = false;
  //   }
  // else if(right)
  //   {
  //     location.x -= delta.asMicroseconds() * speed / 1000000.0f;
  //     right = false;
  //   }
  // else if(left)
  //   {
  //     location.x += delta.asMicroseconds() * speed / 1000000.0f;
  //   left = false;
  // }


//  if(up)
//    {
//      if(location.y - 10 > 0){
//          location.y -= 10;
//      }
//        up = false;
//    }
//  else if(down)
//    {
//        if(location.y + 10 < 747){
//            location.y += 10;
//        }
//      down = false;
//    }
//  else if(right)
//    {
//        if(location.x - 10 > 0){
//            location.x -= 10;
//        }
//      right = false;
//    }
//  else if(left)
//    {
//        if(location.x + 75 < 1024){
//            location.x += 10;
//        }
//        left = false;
//    }
  sprite.setPosition(location += process_event());
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