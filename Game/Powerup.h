#ifndef POWERUP_H
#define POWERUP_H

#include "common.h"
#include "Entity.h"

class Powerup : public Textured_object
{
public:
    Powerup(string name, string const& texture_name ,sf::Vector2f location);

    ~Powerup() override = default;

    void collision(vector<shared_ptr<Entity>> const& objects, World &world) override;
    string get_type() override {return name;};

private:
    string const name;
};
#endif
