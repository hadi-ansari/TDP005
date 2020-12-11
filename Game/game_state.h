#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "state.h"
#include "World.h"

class Game_State : public State {
public:
    /**
     * Create it.
     */
    Game_State() = default;

    /**
     * Tick all game elements.
     */
    shared_ptr<State> tick(sf::Time delta) override;

    /**
     * Draw all game elements.
     */
    void render(sf::RenderWindow &to) override;

private:
    /**
     * The game world.
     */
    World world;
};
#endif