#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"

class Bullet : public Entity
{
public:
    explicit Bullet(sf::Vector2f location);
    ~Bullet() override = default;
};

class Player_Bullet : public Bullet
{
public:
    explicit Player_Bullet(sf::Vector2f location);
    ~Player_Bullet() override = default;

    void tick(sf::Time const& delta) override;
    bool want_shoot() const override;
    bool kill_me() override;
    void collision(std::vector<Entity*> const& objects) override;
    std::string get_type() override;
};

class Enemy_Bullet : Bullet
{
public:
    explicit Enemy_Bullet(sf::Vector2f location);
    ~Enemy_Bullet() override = default;

    void tick(sf::Time const& delta) override;
    bool want_shoot() const override;
    bool kill_me() override;
    void collision(std::vector<Entity*> const& objects) override;
    std::string get_type() override;

private:

};

#endif
