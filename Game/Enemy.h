#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"

struct Enemy: public Entity
{  
  virtual void tick(sf::Time const& delta) = 0;
  
  int health{};
};

class Big_Plane: public Enemy
{
public:
  Big_Plane();
  
  void tick(sf::Time const& delta) override;
  
};



#endif
