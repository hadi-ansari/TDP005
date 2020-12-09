#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Entity.h"
#include "Bullet.h"

class Player: public Entity
{
public:
    explicit Player(sf::Vector2f location);
    ~Player() override = default;

    bool tick(sf::Time delta, World & world) override;
    //void shoot(std::vector<Entity*> & new_bullets);
    void collision(std::vector<Entity*> const& objects) override;

    std::string get_type() override;
    std::string get_shield_time() const;
    bool has_shield() const;
private:
    float shoot_speed;
    sf::Clock shoot_clock;
    bool shield;
    sf::Clock shield_clock;
};

#endif
