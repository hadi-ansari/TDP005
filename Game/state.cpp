#include "state.h"

void State::on_key_press(sf::Keyboard::Key) {}

void State::on_key_release(sf::Keyboard::Key) {}

void State::run(sf::RenderWindow &window, shared_ptr<State> state) {
    sf::Clock clock;

//    --variabler för fps-mätare--
//    float fps;
//    sf::Clock fps_clock;
//    sf::Time previousTime = fps_clock.getElapsedTime();
//    sf::Time currentTime;

    sf::Texture back_image;
    back_image.loadFromFile("Images/Background.png");
    sf::Sprite background(back_image);

    while (state) {

//        --Skriver ut fps i terminalen--
//        currentTime = fps_clock.getElapsedTime();
//        fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds()); // the asSeconds returns a float
//        std::cout << "fps =" << floor(fps) << std::endl; // flooring it will make the frame rate a rounded number
//        previousTime = currentTime;

        sf::Event event;

        while (window.pollEvent(event)) {

            switch (event.type) {
            case sf::Event::Closed:
                return;
            case sf::Event::KeyPressed:
                state->on_key_press(event.key.code);
                break;
            case sf::Event::KeyReleased:
                state->on_key_release(event.key.code);
                break;
            default:
                break;


            }
        }
        window.draw(background);
        if (auto new_state = state -> tick(clock.restart())) {
            if (dynamic_pointer_cast<Exit_State>(new_state)) {
                return;
            } else {
                state = new_state;
            }
            continue;
        }

        state -> render(window);
        window.display();
    }
}
