#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Entity.h"
#include "Player.h"
#include "Level.h"

class World
{
public:
    World();
    ~World() = default;

    /* Lägger till en objekt */
    void insert_object(std::shared_ptr<Entity> const& object);

    /* Uppdaterar alla objekt*/
    bool tick(sf::Time delta);

    /* Ritar på skärmen*/
    void render(sf::RenderWindow & window);

    /* Lägger till poäng */
    void add_score(int num);

private:
    /* Tar hand om font och text på skärmen */
    //void manage_text(sf::Text & player_life, sf::Text & shield_time,sf::Font & font);

    /* Åtgärdar konsekvenser för kollision mellan varje spelobjekt */
    void manage_collision();

    std::vector <std::shared_ptr <Entity>> objects{};
    std::shared_ptr<Player> player{};
    int score;
    int counter;
    sf::Font font;
    sf::Text life_info;
    sf::Text shield_info;
    sf::Text score_info;
    sf::Clock game_clock;
    Level level;
};
#endif
