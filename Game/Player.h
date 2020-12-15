#ifndef PLAYER_H
#define PLAYER_H

#include "common.h"
#include "Bullet.h"

class Player: public Textured_object
{
public:
    explicit Player(sf::Vector2f location);
    ~Player() override = default;

    bool tick(sf::Time delta, World & world) override;
    void collision(vector<shared_ptr<Entity>> const& objects, World &world) override;

    string get_type() override {return "Player";};
    string get_shield_time() const;
    bool has_shield() const {return shield;};
    static bool is_invincible() {return invincible;};
    static void set_invincibility();


private:
    float shoot_speed;
    sf::Clock shoot_timer;
    sf::Time shoot_time;

    bool shield;
    sf::Clock shield_clock;
    sf::Time shield_time;

    bool tripleshot;
    sf::Clock triple_timer;

    static bool invincible;
    sf::Clock invincibility_timer;

    bool give_invincible;

};

#endif
