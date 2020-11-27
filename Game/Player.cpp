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
}

void Player::process_event(sf::Keyboard::Key const& key)
{
  switch(key)
    {
    case sf::Keyboard::W:
      location.y -= 1;
      break;
    case sf::Keyboard::S:
      location.y += 1;
      break;
    case sf::Keyboard::A:
      location.x -= 1;
      break;
    case sf::Keyboard::D:
      location.x += 1;
      break;
    default:
      break;
    }
}
void Player::tick(sf::Time const& delta, sf::Keyboard::Key const& key)
{
  // location += delta.milliseconds() * speed / 1000.0f;
  // sprite.setPosition(location);
  process_event(key);
  sprite.setPosition(location);
}
