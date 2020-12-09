#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class World;

class Entity
{
public:
    explicit Entity(sf::Vector2f location);
    virtual ~Entity() = default;

    virtual bool tick(sf::Time delta, World &world);
    bool kill_me() const;
    virtual void collision(std::vector<Entity*> const& objects) = 0;
    virtual std::string get_type() = 0;

    sf::Sprite get_sprite() const;
    int get_health() const;

protected:
    sf::Vector2f location;
    sf::Texture texture;
    sf::Sprite sprite;
    float speed{};
    int health{};
    int width{};
    int height{};
};
#endif
