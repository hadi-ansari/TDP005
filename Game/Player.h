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

    sf::Vector2f process_event(sf::Time delta);
    void tick(sf::Time const& delta) override;
    void shoot(std::vector<Entity*> & new_bullets);
    bool kill_me() override;
    void collision(std::vector<Entity*> const& objects) override;

    std::string get_type() override;
    std::string get_shield_time() const;
    bool has_shield() const;
private:
    bool sht;
    float shoot_speed;
    sf::Clock clock1;
    sf::Time t1;
    bool shield;
    sf::Clock shield_clock;
};

#endif
