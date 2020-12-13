#ifndef WORLD_H
#define WORLD_H

#include "common.h"
#include "state.h"
#include "Entity.h"
#include "Player.h"
#include "Level.h"

class World
{
public:
    World(string level);
    ~World() = default;

    /* Lägger till en objekt */
    void insert_object(shared_ptr<Entity> const& object);

    /* Uppdaterar alla objekt*/
    shared_ptr<State> tick(sf::Time delta);

    /* Ritar på skärmen*/
    void render(sf::RenderWindow & window);

    /* Lägger till poäng */
    void add_score(int num);

private:
    /* Tar hand om font och text på skärmen */

    /* Åtgärdar konsekvenser för kollision mellan varje spelobjekt */
    void manage_collision();

    vector <shared_ptr <Entity>> objects{};
    shared_ptr<Player> player{};
    int score;
    int counter;
    sf::Font font;
    sf::Text life_info;
    sf::Text shield_info;
    sf::Text score_info;
    sf::Clock enemy_clock;
    sf::Clock game_clock;
    sf::Clock cloud_clock;
    Level level;
    string level_name;
};
#endif
