#include "Enemy.h"

Big_Plane::Big_Plane()
{
  health = 2;
  location = {700, 0};
  speed = 150.0f;
  if(!texture.loadFromFile("Enemy2_85x27.png", sf::IntRect(0, 0, 85, 27)))
    {
      std::cerr << "Error" << std::endl;
    }
  sprite.setTexture(texture);
}


void Big_Plane::tick(sf::Time const& delta)
{
  // location.x -= 1;
  location.x -= delta.asMicroseconds() * speed / 1000000.0f;
  sprite.setPosition(location);
}
bool Big_Plane::kill_me()
{
    return (location.x < 0 || location.y < 0 || location.y > 768);
}