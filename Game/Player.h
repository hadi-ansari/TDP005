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
    Player();
    ~Player() override = default;

    void process_event(sf::Keyboard::Key const& key);
    Bullet* shoot();
    void tick(sf::Time const& delta) override;
    bool want_shoot() const;
    bool kill_me() override;
    void collision(std::vector<Entity*> const& objects) override;

    std::string get_type() override;
private:
    bool up;
    bool down;
    bool right;
    bool left;
    bool sht;
};

#endif
