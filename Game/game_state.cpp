
#include "game_state.h"
#include "menu_state.h"

Game_State::Game_State(string const& level_p) : level_path {level_p}, world(level_p)
{}

shared_ptr<State> Game_State::tick(sf::Time delta) {


    // pause?
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return make_shared<Pause_State>( shared_from_this(), level_path);

    return world.tick(delta);
}

void Game_State::render(sf::RenderWindow &window) {
    world.render(window);
}