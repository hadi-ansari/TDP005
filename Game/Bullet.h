#ifndef BULLET_H
#define BULLET_H

#include "common.h"
#include "Entity.h"

class Bullet : public Textured_object
{
public:
    explicit Bullet(sf::Vector2f location, int bullet_width, int bullet_height, std::string const& texture_name);
    ~Bullet() override = default;
};

//Denna bullet används enbart av spelaren
class Player_Bullet : public Bullet
{
public:
    explicit Player_Bullet(sf::Vector2f location);
    ~Player_Bullet() override = default;

    bool tick(sf::Time delta, World & world) override;
    void collision(vector<shared_ptr<Entity>> const& objects, World &world) override;
    string get_type() override {return "Player-Bullet";};
};

//Denna bullet används enbart av fiender, specifikt Small Plane och Big Plane
class Enemy_Bullet : public Bullet
{
public:
    explicit Enemy_Bullet(sf::Vector2f location);
    ~Enemy_Bullet() override = default;

    void collision(vector<shared_ptr<Entity>> const& objects, World &world) override;
    string get_type() override {return "Enemy-Bullet";};

private:

};

#endif
