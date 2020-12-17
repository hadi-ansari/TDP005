#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "state.h"
#include "World.h"

class Game_State : public State {
public:

    Game_State() = default;

    Game_State(string const& level_path);


    shared_ptr<State> tick(sf::Time delta) override;


    void render(sf::RenderWindow &to) override;

private:
    //Spelvärlden
    World world;

    //Sparar sökväg till nuvarande nivå
    string const level_path;


};
#endif