#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Entity.h"
#include "Player.h"

class World
{
public:
    World();
    ~World() = default;

    void insert_object(std::shared_ptr<Entity> const& object);
    void run(sf::RenderWindow & window);
    void tick(sf::Time delta);
    void render(sf::RenderWindow & window);

private:
    /* Tar hand om font och text på skärmen */
    void manage_text(sf::Text & player_life, sf::Text & shield_time,sf::Font & font);

    /* Kontrollerar om det ska skapas nya skott i spelplanen och  ägger till nya skott i spelplanen */
    //void new_bullets();

    /* Uppdaterar position för alla spelobjekt */
    //void update_objects(sf::Time const& delta, sf::RenderWindow & window);

    /* Åtgärdar konsekvenser för kollision mellan varje spelobjekt */
    void manage_collision();

    /* Tar bort spelobjekt som ska förstöras */
   // void remove_objects();

    std::vector <std::shared_ptr <Entity>> objects{};
    std::shared_ptr<Player> player{};
};
#endif
