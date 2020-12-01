#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>

struct Entity
{
  virtual void tick(sf::Time const& delta) = 0;
  virtual bool kill_me() = 0;

  sf::Vector2f location{};
  sf::Texture texture;
  sf::Sprite sprite;
  float speed{};
};

#endif
