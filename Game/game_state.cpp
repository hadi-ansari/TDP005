
#include "game_state.h"
#include "menu_state.h"

Game_State::Game_State(string level_path) : world(level_path)
{
    level_path = level_path;
    test = 4;
}

shared_ptr<State> Game_State::tick(sf::Time delta) {


    // pause?
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return make_shared<Pause_State>( shared_from_this());

    return world.tick(delta);
}

void Game_State::render(sf::RenderWindow &window) {
    world.render(window);
}