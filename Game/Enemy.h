#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"

struct Enemy: public Entity
{
    virtual ~Enemy() = default;
  
    int health{};
};

class Big_Plane: public Enemy
{
public:
    Big_Plane();
    ~Big_Plane() = default;

  void tick(sf::Time const& delta) override;
  bool kill_me()override;
};



#endif
