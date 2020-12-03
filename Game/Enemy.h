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

};
class Bomb : public Enemy
{
public:
    explicit Bomb(sf::Vector2f location);
    ~Bomb() override= default;

    void tick(sf::Time const& delta) override;
    bool want_shoot() const override;
    bool kill_me() override;
    void collision(std::vector<Entity*> const& objects) override;
    std::string get_type() override;
};
class Small_Plane: public Enemy
{
public:
    explicit Small_Plane(sf::Vector2f location);
    ~Small_Plane() override = default;

    void tick(sf::Time const& delta) override;
    bool want_shoot() const override;
    bool kill_me() override;
    void collision(std::vector<Entity*> const& objects) override;
    std::string get_type() override;
};

class Big_Plane: public Enemy
{
public:
    explicit Big_Plane(sf::Vector2f location);
    ~Big_Plane() override = default;

    void tick(sf::Time const& delta) override;
    bool want_shoot() const override;
    bool kill_me() override;
    void collision(std::vector<Entity*> const& objects) override;
    std::string get_type() override;
};
#endif
