#ifndef POWERUP_H
#define POWERUP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Entity.h"

struct Powerup : public Entity
{
    explicit Powerup(sf::Vector2f location);
    ~Powerup() override = default;
};


class Heal : public Powerup
{
public:
    explicit Heal(sf::Vector2f location);
    ~Heal() override= default;

    void tick(sf::Time const& delta) override;
    void collision(std::vector<Entity*> const& objects) override;
    std::string get_type() override;
};

class Shield : public Powerup
{
public:
    explicit Shield(sf::Vector2f location);
    ~Shield() override= default;

    void tick(sf::Time const& delta) override;
    void collision(std::vector<Entity*> const& objects) override;
    std::string get_type() override;
};

class Tripleshot : public Powerup
{
public:
    explicit Tripleshot(sf::Vector2f location);
    ~Tripleshot() override= default;

    void tick(sf::Time const& delta) override;
    void collision(std::vector<Entity*> const& objects) override;
    std::string get_type() override;
};
#endif
