#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"

class Bullet : public Entity
{
public:
    virtual ~Bullet() = default;
};

class Player_Bullet : public Bullet
{
public:
    Player_Bullet(sf::Vector2f test);
    ~Player_Bullet() = default;

    void tick(sf::Time const& delta) override;
    bool kill_me() override;
    void collision(std::vector<Entity*> const& objects) override;
    std::string get_type() override;
};

#endif
