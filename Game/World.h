#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"
#include "Player.h"

class World
{
public:
  World();
  ~World();

  void insert_object(Entity* const object);
  Player get_player() const;
  std::vector <Entity*> get_objects() const;
  
private:
  std::vector <Entity*> objects{};
};

#endif
