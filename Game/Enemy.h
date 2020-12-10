#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Entity.h"

struct Enemy: public Entity
{
    explicit Enemy(sf::Vector2f location);
    ~Enemy() override = default;

    void collision(std::vector<Entity*> const& objects) override;
};
class Bomb : public Enemy
{
public:
    explicit Bomb(sf::Vector2f location);
    ~Bomb() override= default;

    std::string get_type() override {return "Bomb";};
};
class Small_Plane: public Enemy
{
public:
    explicit Small_Plane(sf::Vector2f location);
    ~Small_Plane() override = default;

    bool tick(sf::Time delta, World & world) override;
    std::string get_type() override {return "Small Plane";};

private:
    float shoot_speed;
    sf::Clock shoot_clock;
};

class Big_Plane: public Enemy
{
public:
    explicit Big_Plane(sf::Vector2f location);
    ~Big_Plane() override = default;

    bool tick(sf::Time delta, World & world) override;
    std::string get_type() override {return "Big Plane";};

private:
    float shoot_speed;
    sf::Clock shoot_clock;
};
#endif
