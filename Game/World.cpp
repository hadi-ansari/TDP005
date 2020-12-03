#include <SFML/Graphics.hpp>
#include <iostream>
//#include <algorithm>

#include "World.h"

World::World()
  : objects{}, player{new Player{sf::Vector2f(0 , 0)}}
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
void World::run(sf::RenderWindow & window)
{
  sf::Clock clock;

  while(window.isOpen())
  {
      sf::Event event{};
      
      while(window.pollEvent(event))
      {
          if(event.type == sf::Event::Closed)
          {
              window.close();
          }
          else
          {
              sf::Time delta = clock.getElapsedTime();
              player -> process_event(delta);
          }
      }

      window.clear(sf::Color(76, 208, 255));
      if(player -> want_shoot())
      {
          insert_object(player -> shoot());
      }




      sf::Time delta = clock.restart();
      for(auto object: objects)
      {
          object -> tick(delta);
          window.draw(object -> sprite);
      }

      for(auto object: objects)
      {
          std::vector <Entity*> new_vector(objects.size());
          std::copy(objects.begin(), objects.end(), new_vector.begin());
          new_vector.erase(std::remove_if(new_vector.begin(), new_vector.end(),
                                          [&object](Entity* x)
                                          {
                                              return x == object;
                                          }
          ), new_vector.end());
          object -> collision(new_vector);
      }
      objects.erase(std::remove_if(objects.begin(), objects.end(),
                                   [](Entity* & x)
                                   {
                                       if( x -> kill_me())
                                       {
                                           delete x;
                                           return true;
                                       }
                                       return false;
                                   }
      ), objects.end());


    /*
      std::vector<Entity*> new_vector;
      new_vector.push_back(objects[1]);
      player -> collision(new_vector);
*/
      window.display();
  }
}
