#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"

struct Enemy: public Entity
{  
  virtual void tick(sf::Time const& delta, sf::Keyboard::Key const& key) = 0;
  
  int health{};
};

#endif
