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

void World::manage_text(sf::Text & player_life, sf::Font & font)
{

    if(!font.loadFromFile("Lato-HeavyItalic.ttf"))
    {
        std::cerr << "Error loading font!" << std::endl;
    }
    player_life.setFont(font);
    player_life.setPosition(1500, 0);
}

void World::new_bullets()
{
    std::vector<Entity*> new_bullets{};
    for(auto & object: objects)
    {
        if(object -> want_shoot())
        {
            new_bullets.push_back( object -> shoot());
        }
    }
    for(auto & bullet: new_bullets)
    {
        insert_object( bullet );
    }
}
void World::update_objects(sf::Time const& delta, sf::RenderWindow & window)
{
    for(auto & object: objects)
    {
        object -> tick(delta);
        window.draw(object -> sprite);
    }

}
void World::manage_collision()
{
    for(auto & object: objects)
    {
        std::vector <Entity*> new_vector(objects.size());
        std::copy(objects.begin(), objects.end(), new_vector.begin());
        new_vector.erase(std::remove_if(new_vector.begin(), new_vector.end(),
                                        [&object](Entity* & x)
                                        {
                                            return x == object;
                                        }
        ), new_vector.end());
        object -> collision(new_vector);
    }
}
void World::remove_objects()
{
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
}

void World::run(sf::RenderWindow & window)
{
    sf::Clock clock;
    sf::Font font;

    sf::Text player_life;
    manage_text(player_life, font);

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
        new_bullets();

        sf::Time delta = clock.restart();
        update_objects(delta, window);

        manage_collision();
        remove_objects();

        player_life.setString("Life: " + std::to_string(player -> health));
        window.draw(player_life);
        window.display();
    }
}
