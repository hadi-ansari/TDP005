#include <SFML/Graphics.hpp>
#include <iostream>

#include "World.h"

World::World()
  : objects{}
{
  objects.push_back(new Player{});
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
