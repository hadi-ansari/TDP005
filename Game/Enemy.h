#ifndef ENEMY_H
#define ENEMY_H

#include "common.h"
#include "Entity.h"

struct Enemy: public Textured_object
{
    explicit Enemy(sf::Vector2f location, int width, int height, const string& texture_name);
    ~Enemy() override = default;

    void collision(vector<shared_ptr<Entity>> const& objects, World &world) override;
};
class Bomb : public Enemy
{
public:
    explicit Bomb(sf::Vector2f location);
    ~Bomb() override= default;

    string get_type() override {return "Bomb";};
};
class Small_Plane: public Enemy
{
public:
    explicit Small_Plane(sf::Vector2f location);
    ~Small_Plane() override = default;

    bool tick(sf::Time delta, World & world) override;
    string get_type() override {return "Small Plane";};

private:
    void vertical_move(sf::Time delta);

    float shoot_speed;
    sf::Clock shoot_clock;
    bool upp_state;
    sf::Clock vertical_timer;
};

class Big_Plane: public Enemy
{
public:
    explicit Big_Plane(sf::Vector2f location);
    ~Big_Plane() override = default;

    bool tick(sf::Time delta, World & world) override;
    string get_type() override {return "Big Plane";};

private:
    float shoot_speed;
    sf::Clock shoot_clock;
};
#endif
