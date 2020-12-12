
#include "game_state.h"

#include "menu_state.h"

/*Game_State::Game_State() {
    //world.add(std::make_shared<Player>(sf::Vector2f{width / 2.0f, height * 4.0f / 5.0f}));
}*/

shared_ptr<State> Game_State::tick(sf::Time delta) {

    if(!world.tick(delta))
        return std::make_shared<Exit_State>();

    // Pause?
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        return std::make_shared<Menu_State>(shared_from_this());

    return nullptr;
}

void Game_State::render(sf::RenderWindow &window) {
    world.render(window);
}
