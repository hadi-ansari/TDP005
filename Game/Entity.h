#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

struct Entity
{
    virtual ~Entity() = default;

    virtual void tick(sf::Time const& delta) = 0;
    virtual bool kill_me() = 0;
    virtual void collision(std::vector<Entity*> const& objects) = 0;
    virtual std::string get_type() = 0;

    sf::Vector2f location;
    sf::Texture texture;
    sf::Sprite sprite;
    float speed;
    int health;
};

#endif
