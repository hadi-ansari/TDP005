
#include "common.h"
#include "menu_state.h"

size_t const width = 1600;
size_t const height = 900;
int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Sky Wars", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(144);
    // window.setKeyRepeatEnabled(false);
    
    State::run(window, make_shared<Main_Menu_State>());

    return 0;
}
