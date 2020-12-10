#ifndef POWERUP_H
#define POWERUP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Entity.h"

class Powerup : public Textured_object
{
public:
    Powerup(std::string name, std::string const& texture_name ,sf::Vector2f location);

    ~Powerup() override = default;

    void collision(std::vector<std::shared_ptr<Entity>> const& objects, World &world) override;
    std::string get_type() override {return name;};

private:
    std::string const name;
};
#endif
