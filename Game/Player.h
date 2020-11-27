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
  void tick(sf::Time const& delta, sf::Keyboard::Key const& key) override;
  
private:
  int health{};
};

#endif
