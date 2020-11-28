#include <SFML/Graphics.hpp>
#include <iostream>

#include "World.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Big_Plane.h"
#include "Bullet.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Test game");
  window.setVerticalSyncEnabled(true);
  // window.setKeyRepeatEnabled(false);

  sf::Vector2f test{0, 10};
  World world{};
  world.insert_object(new Big_Plane{});
  world.insert_object(new Bullet{test});
  //  world.insert_object(new Bullet{test});
  world.run(window);
  
  // float speed{150.0f};
  // sf::CircleShape shape{40.0f};
  // shape.setFillColor(sf::Color(100, 250, 50));
  // sf::Vector2f location{700, 300};
  // sf::Sprite sprite;
  // sf::Texture texture;
  // if(!texture.loadFromFile("Enemy2_85x27.png", sf::IntRect(0, 0, 85, 27)))
  //   {
  //     std::cerr << "Error" << std::endl;
  //   }
  // sprite.setTexture(texture);
  

  //   }
    
  return 0;
}
