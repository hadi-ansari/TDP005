
#include "game_state.h"
#include "menu_state.h"

shared_ptr<State> Game_State::tick(sf::Time delta) {

    if(auto state = world.tick(delta))
        return state;

    // pause?
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return std::make_shared<Pause_State>(shared_from_this());

    return nullptr;
}

void Game_State::render(sf::RenderWindow &window) {
    world.render(window);
}
