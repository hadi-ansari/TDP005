
#include "common.h"
#include "menu_state.h"
#include "SFML/Audio.hpp"

size_t const width = 1600;
size_t const height = 900;
int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Sky Wars", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(144);
    // window.setKeyRepeatEnabled(false);

    sf::Music music;
    music.setLoop(true);
    music.setVolume(10);
    if (!music.openFromFile("Sound/music.ogg"))
        return -1;
    music.play();
    
    State::run(window, make_shared<Main_Menu_State>());

    return 0;
}
