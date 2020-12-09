#ifndef POWERUP_H
#define POWERUP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Entity.h"

class Powerup : public Entity
{
public:
    Powerup(std::string name, sf::Vector2f location);

    ~Powerup() override = default;

    void tick(sf::Time const& delta) override;
    void collision(std::vector<Entity*> const& objects) override;
    std::string get_type() override;

private:
    std::string name;
};


/*class Heal : public Powerup
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
};*/
#endif
