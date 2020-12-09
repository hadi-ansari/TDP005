#include <SFML/Graphics.hpp>
#include <iostream>
//#include <algorithm>

#include "World.h"
#include "Player.h"
#include "Enemy.h"

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

void World::manage_text(sf::Text & player_life, sf::Text & shield_time, sf::Font & font)
{

    if(!font.loadFromFile("Lato-HeavyItalic.ttf"))
    {
        std::cerr << "Error loading font!" << std::endl;
    }
    player_life.setFont(font);
    shield_time.setFont(font);

    player_life.setPosition(1500, 0);
    shield_time.setPosition(750, 0);
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

void World::run(sf::RenderWindow & window)
{
    sf::Clock clock;
    sf::Font font;

    sf::Text player_life;
    sf::Text shield_time;
    manage_text(player_life, shield_time, font);

    while(window.isOpen())
    {
        sf::Event event{};

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color(76, 208, 255));

        sf::Time delta = clock.restart();


        // manage_collision();

        tick(delta);

        draw(window);
        // liv
        player_life.setString("Life: " + std::to_string(player -> get_health()));
        window.draw(player_life);

        // shield
        if(player -> has_shield())
        {
            shield_time.setString( player -> get_shield_time());
            window.draw(shield_time);
        }
        window.display();
    }
}
void World::tick(sf::Time delta)
{

    for(size_t i = 0 ; i < objects.size(); i++)
    {
        if(!objects[i] -> tick(delta, *this))
        {
            objects.erase(objects.begin() + i);
            i--;
        }
    }
}
void World::draw(sf::RenderWindow &window)
{
    for(auto object: objects)
    {
        window.draw(object -> get_sprite());
    }
}