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

    shared_ptr<State> tick(sf::Time delta);

    void render(sf::RenderWindow & window);

    /* Lägger till poäng */
    void add_score(int num);

    void freeze();

private:
    //Kallar på alla spelobjekts kollisionfunktioner
    void manage_collision();

    vector <shared_ptr <Entity>> objects{}; //Sparar alla spelobjekt
    shared_ptr<Player> player{};
    int score;
    int counter;
    sf::Font font;
    sf::Text life_info;
    sf::Text shield_info;
    sf::Text score_info;
    sf::Clock spawn_timer;
    sf::Time spawn_time;
    sf::Clock game_timer;
    sf::Time game_time;
    Level level;
    string level_name;
    bool freeze_state;

};
#endif
