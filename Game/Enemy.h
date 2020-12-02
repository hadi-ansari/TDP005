#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Entity.h"

struct Enemy: public Entity
{
    ~Enemy() override = default;

};
class Bomb : public Enemy
{
public:
    Bomb();
    ~Bomb() override= default;

    void tick(sf::Time const& delta) override;
    bool kill_me() override;
    void collision(std::vector<Entity*> const& objects) override;
    std::string get_type() override;
};
class Big_Plane: public Enemy
{
public:
    Big_Plane();
    ~Big_Plane() override= default;

    void tick(sf::Time const& delta) override;
    bool kill_me() override;
    void collision(std::vector<Entity*> const& objects) override;
    std::string get_type() override;
};
#endif
