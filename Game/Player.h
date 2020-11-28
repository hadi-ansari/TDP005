#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"

class Player: public Entity
{
public:
  Player();
  
  void process_event(sf::Keyboard::Key const& key);
  void shoot();
  void tick(sf::Time const& delta) override;
  
private:
  int health{};
  bool up;
  bool down;
  bool right;
  bool left;
};

#endif
