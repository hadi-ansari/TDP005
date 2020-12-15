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

    void freeze();

private:
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
    sf::Clock enemy_timer;
    sf::Time enemy_time;
    sf::Clock game_timer;
    sf::Time game_time;
    Level level;
    string level_name;
    bool freeze_state;

};
#endif
