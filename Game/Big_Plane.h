#ifndef BIG_PLANE_H
#define BIG_PLANE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Enemy.h"

class Big_Plane: public Enemy
{
public:
  Big_Plane();
  
  void tick(sf::Time const& delta, sf::Keyboard::Key const& key) override;
  
};

#endif
