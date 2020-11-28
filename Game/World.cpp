#include <SFML/Graphics.hpp>
#include <iostream>

#include "World.h"

World::World()
  : objects{}, player{new Player{}}
{
  objects.push_back(player);
}

World::~World()
{
  for(auto object: objects)
    {
      delete object;
    }
}

void World::insert_object(Entity* object)
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
      
      while(window.pollEvent(event))
      	{
	  if(event.type == sf::Event::Closed)
	    {
	      window.close();
	    }
	  else
	    {
	      player -> process_event(event.key.code);
	    }
	}

      window.clear(sf::Color(76, 208, 255));
      sf::Time delta = clock.restart();
      for(auto object: objects)
      	{
      	  object -> tick(delta);
	  window.draw(object -> sprite);
      	}
      
      window.display();

    }
}
