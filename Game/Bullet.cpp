#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bullet.h"


Bullet::Bullet(sf::Vector2f test)
{
  location = test;
  speed = 700.0f;
  if(!texture.loadFromFile("Bullet.png", sf::IntRect(0, 0, 15, 3)))
    {
      std::cerr << "Error" << std::endl;
    }
  sprite.setTexture(texture);
}
  
void Bullet::tick(sf::Time const& delta)
{
  location.x += speed * (delta.asMicroseconds() / 1000000.0f);
  sprite.setPosition(location);
}
