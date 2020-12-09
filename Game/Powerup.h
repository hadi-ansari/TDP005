#ifndef POWERUP_H
#define POWERUP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Entity.h"

class Powerup : public Entity
{
public:
    Powerup(const std::string& name, sf::Vector2f location);

    ~Powerup() override = default;

    void collision(std::vector<Entity*> const& objects) override;
    std::string get_type() override {return name;};

private:
    std::string name;
};
#endif
