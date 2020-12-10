#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <memory>

class World;

class Entity
{
public:
    Entity() = delete;
    explicit Entity(sf::Vector2f location, int width, int height);
    virtual ~Entity() = default;

    virtual bool tick(sf::Time delta, World &world);
    virtual void render(sf::RenderWindow &window) = 0;
    bool kill_me() const;
    virtual void collision(std::vector<std::shared_ptr<Entity>> const& objects) = 0;
    virtual std::string get_type() = 0;

    virtual sf::Sprite get_sprite() const {return sprite;}

    int get_health() const;
protected:
    sf::Vector2f location{};
    float speed{};
    int health{};
    int width{};
    int height{};
    sf::Sprite sprite{};
};

class Textured_object : public Entity
{
public:
    Textured_object(sf::Vector2f location, int width, int height, std::string const& texture_name);
    void render(sf::RenderWindow &window) override;
};
#endif
