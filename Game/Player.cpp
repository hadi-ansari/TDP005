#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"


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
    default:
      break;
    }
}
void Player::tick(sf::Time const& delta)
{
  // location += delta.asmilliseconds() * speed / 1000.0f;
  // sprite.setPosition(location);
  if(up)
    {
      location.y -= delta.asMilliseconds() * speed / 1000.0f;
      up = false;
    }
  else if(down)
    {
      location.y += delta.asMilliseconds() * speed / 1000.0f;
      down = false;
    }
  else if(right)
    {
      location.x -= delta.asMilliseconds() * speed / 1000.0f;
      right = false;
    }
  else if(left)
    {
      location.x += delta.asMilliseconds() * speed / 1000.0f;
      left = false;
    }
  sprite.setPosition(location);
}
