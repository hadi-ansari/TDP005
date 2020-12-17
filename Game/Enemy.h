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
    void freeze() override;

    string get_type() override {return "Small Plane";};

private:
    void vertical_move(sf::Time delta); //Flyttar small plane vertikalt upp/ner baserat på tid. Skapar en vågrörelse tillsammans med tick

    float shoot_speed;
    sf::Clock shoot_timer;
    sf::Time shoot_time;

    bool upp_state; //Ska small plane färdas uppåt (true) eller nedåt (false)?
    sf::Clock vertical_timer;
    sf::Time vertical_time;

    bool freeze_state; //Är spelet pausat?
};

class Big_Plane: public Enemy
{
public:
    explicit Big_Plane(sf::Vector2f location);
    ~Big_Plane() override = default;

    bool tick(sf::Time delta, World & world) override;
    void freeze() override;

    string get_type() override {return "Big Plane";};

private:
    float shoot_speed;
    sf::Clock shoot_timer;
    sf::Time shoot_time;
    bool freeze_state;
};
#endif
