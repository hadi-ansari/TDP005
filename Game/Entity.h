#ifndef ENTITY_H
#define ENTITY_H

#include "common.h"

class World;

class Entity
{
public:
    Entity() = delete;
    explicit Entity(sf::Vector2f location, int width, int height);
    virtual ~Entity() = default;

    virtual bool tick(sf::Time delta, World &world); //Uppdaterar spelobjektets beteende
    virtual void render(sf::RenderWindow &window) = 0; //Ritar ut spelobjektet på skärmen
    bool kill_me() const; //Kontrollerar om spelobjektet ska förstöras
    virtual void collision(vector<shared_ptr<Entity>> const& objects, World &world) = 0; //Kontrollerar om spelobjektet har kolliderat
    virtual void freeze() {}; //Kontrollerar om spelet är i paus-läge

    virtual std::string get_type() = 0; //Returnerar objektets typ i form av sträng
    virtual sf::Sprite get_sprite() const {return sprite;}
    int get_health() const;

protected:
    sf::Vector2f location{};
    float speed{};
    int health{};
    int width{};
    int height{};
    sf::Sprite sprite{};
};

class Textured_object : public Entity
{
public:
    Textured_object(sf::Vector2f location, int width, int height, std::string const& texture_name);
    void render(sf::RenderWindow &window) override;
    void set_texture(string const& texture_name); //Används ej
};
#endif
