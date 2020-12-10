#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <memory>

#include "Entity.h"
#include "Bullet.h"

class Player: public Textured_object
{
public:
    explicit Player(sf::Vector2f location);
    ~Player() override = default;

    bool tick(sf::Time delta, World & world) override;
    void collision(std::vector<std::shared_ptr<Entity>> const& objects) override;

    std::string get_type() override {return "Player";};
    std::string get_shield_time() const;
    bool has_shield() const {return shield;};
private:
    float shoot_speed;
    sf::Clock shoot_clock;
    bool shield;
    sf::Clock shield_clock;
};

#endif
