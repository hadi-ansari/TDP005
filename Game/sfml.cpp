#include <SFML/Graphics.hpp>
#include <iostream>

#include "World.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Big_Plane.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Test game");
  window.setVerticalSyncEnabled(true);

  sf::Clock clock;
  World w{};
  Big_Plane b1{};
  
  float speed{150.0f};
  sf::CircleShape shape{40.0f};
  shape.setFillColor(sf::Color(100, 250, 50));
  sf::Vector2f location{700, 300};
  sf::Sprite sprite;
  sf::Texture texture;
  if(!texture.loadFromFile("Enemy2_85x27.png", sf::IntRect(0, 0, 85, 27)))
    {
      std::cerr << "Error" << std::endl;
    }
  sprite.setTexture(texture);
  
  while(window.isOpen())
    {

      
      sf::Event event;
      sf::Time delta;
      while(window.pollEvent(event))
      	{
      	  if(event.type == sf::Event::Closed)
      	    {
      	      window.close();
      	    }
      	  else
      	    {
	      delta = clock.restart();
      	      for(auto object: w.get_objects())
      	  	{
      	  	  object -> tick(delta, event.key.code);
      	  	}
	        
      	    }
      	}
	
     
      window.clear();
      delta += clock.restart();
      for(auto object: w.get_objects())
      	{
      	  object -> tick(delta, event.key.code);
	  window.draw(object -> sprite);
      	}
      location.x -= delta.asMicroseconds() * speed / 1000000.0f;
      sprite.setPosition(location);
      window.draw(sprite);
      
      // for(auto object: w.get_objects())
      // 	{
      // 	  object -> tick(delta, event.key.code);
      // 	}
      // for(auto object: w.get_objects())
      // 	{
      // 	  window.draw(object -> sprite);
      // 	}
      window.display();
    }
    
  return 0;
}
