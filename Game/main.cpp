#include <SFML/Graphics.hpp>
#include <iostream>

#include "World.h"
#include "Enemy.h"
#include "Bullet.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Test game");
  window.setVerticalSyncEnabled(true);
  // window.setKeyRepeatEnabled(false);

  sf::Vector2f test{0, 10};
  
  World world{};
  world.insert_object(new Big_Plane{});
  world.run(window);

  return 0;
}
