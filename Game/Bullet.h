#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"

class Bullet : public Entity
{
public:
  Bullet(sf::Vector2f test);
  void tick(sf::Time const& delta) override;
};

#endif