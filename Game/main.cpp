
#include "common.h"
#include "game_state.h"

size_t const width = 1600;
size_t const height = 900;
int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Sky Wars", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    // window.setKeyRepeatEnabled(false);
    
    State::run(window, std::make_shared<Game_State>());

    return 0;
}
