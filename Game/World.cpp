#include <SFML/Graphics.hpp>
#include <iostream>

#include "World.h"

World::World()
  : objects{}, player{}
{
  
}

World::~World()
{
  for(auto object: objects)
    {
      delete object;
    }
}

void World::insert_object(Entity* const object)
{
  objects.push_back(object);
}
std::vector <Entity*> World::get_objects() const
{
  return objects;
}

void World::run(sf::RenderWindow & window)
{
  sf::Clock clock;
  
  while(window.isOpen())
    {
      sf::Event event;
      // bool key_w_pressed{false};
      // bool key_s_pressed{false};
      // bool key_d_pressed{false};
      // bool key_a_pressed{false};
      
      while(window.pollEvent(event))
      	{
	  if(event.type == sf::Event::Closed)
	    {
	      window.close();
	    }
	  else
	    {
	      player.process_event(event.key.code);
	    }
	  // else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	  //   {
	  //     key_w_pressed = true;
	  //   }
	  // else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	  //   {
	  //     key_s_pressed = true;
	  //   }
	  // else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	  //   {
	  //     key_d_pressed = true;
	  //   }
	  // else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	  //   {
	  //     key_a_pressed = true;
	  //   }
	}

      window.clear();
      sf::Time delta = clock.restart();
      for(auto object: objects)
      	{
      	  object -> tick(delta);
	  window.draw(object -> sprite);
      	}
      player.tick(delta);
      window.draw(player.sprite);
      
      window.display();

    }
}
