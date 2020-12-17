
#include "common.h"
#include "menu_state.h"
#include "SFML/Audio.hpp"

size_t const width = 1600;
size_t const height = 900;
int main()
{
    //Ställer in fönstret
    sf::RenderWindow window(sf::VideoMode(width, height), "Sky Wars", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    
    State::run(window, make_shared<Main_Menu_State>());

    return 0;
}
