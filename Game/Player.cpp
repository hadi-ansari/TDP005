#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "Bullet.h"
#include "World.h"

Player::Player()
{
  health = 3;
  location = {0, 0};
  speed = 150.0f;
  if(!texture.loadFromFile("Player65x21.png", sf::IntRect(0, 0, 65, 21)))
    {
      std::cerr << "Error" << std::endl;
    }
  sprite.setTexture(texture);
  up = false;
  down = false;
  right = false;
  left = false;
  sht = false;
}

void Player::process_event(sf::Keyboard::Key const& key)
{
  switch(key)
  {
      case sf::Keyboard::W:
          up = true;
          break;
      case sf::Keyboard::S:
          down = true;
          break;
      case sf::Keyboard::A:
          right = true;
          break;
      case sf::Keyboard::D:
          left = true;
          break;
      case sf::Keyboard::Space:
          sht = true;
          break;
      default:
          break;
  }
}

Bullet* Player::shoot()
{
    sht = false;
    sf::Vector2f temp{location.x + 65, location.y + 10};
    return (new Bullet{temp});
}

void Player::tick(sf::Time const& delta)
{
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
  
  if(up)
    {
      location.y -= 10;
      up = false;
    }
  else if(down)
    {
      location.y += 10;
      down = false;
    }
  else if(right)
    {
      location.x -= 10;
      right = false;
    }
  else if(left)
    {
      location.x += 10;
      left = false;
    }
  sprite.setPosition(location);
}
bool Player::want_shoot()
{
    return sht;
}