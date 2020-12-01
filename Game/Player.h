#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"
#include "Bullet.h"

class Player: public Entity
{
public:
  Player();
  
  void process_event(sf::Keyboard::Key const& key);
  Bullet* shoot();
  void tick(sf::Time const& delta) override;
  bool want_shoot();
  
private:
  int health{};
  bool up;
  bool down;
  bool right;
  bool left;
  bool sht;
};

#endif
