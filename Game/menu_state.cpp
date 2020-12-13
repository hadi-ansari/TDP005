
//#include <utility>

#include "menu_state.h"
#include "game_state.h"

Menu_State::Menu_State()
    : selected(0), enter_pressed(false), delay(sf::milliseconds(300)) {

    font.loadFromFile("RussoOne-Regular.ttf");
}

void Menu_State::add(const string &text, Action action) {
    entries.push_back({ sf::Text{text, font, 60}, 0.0f, move(action) });
}

void Menu_State::on_key_press(sf::Keyboard::Key key) {
    switch (key) {
    case sf::Keyboard::S:
        if (selected + 1 < entries.size())
            selected++;
        break;
    case sf::Keyboard::W:
        if (selected > 0)
            selected--;
        break;
    case sf::Keyboard::Return:
        enter_pressed = true;
        break;
    default:
        break;
    }
}

shared_ptr<State> Menu_State::tick(sf::Time time) {
    float diff = float(time.asMicroseconds()) / float(delay.asMicroseconds());

    for (size_t i = 0; i < entries.size(); i++) {
        Entry &e = entries[i];

        if (i == selected) {
            e.state += diff;
            if (e.state > 1.0f)
                e.state = 1.0f;
        } else {
            e.state -= diff;
            if (e.state < 0.0f)
                e.state = 0.0f;
        }
    }

    if (enter_pressed)
        return entries[selected].action();
    else
        return nullptr;
}

void Menu_State::render(sf::RenderWindow &window) {
    if (background)
        background->render(window);

    float y{400};
    auto windowSize = window.getSize();

    for (auto &e : entries) {
        auto bounds = e.text.getLocalBounds();
        e.text.setPosition((windowSize.x - bounds.width) / 2, y);
        y += bounds.height * 2.0f;

        int state = static_cast<int>(255 * e.state);
        e.text.setFillColor(sf::Color(state, 255, state));
        window.draw(e.text);
    }
}

//
Main_Menu_State::Main_Menu_State() {
    add("New game", []() { return make_shared<Game_State>(); });
    add("Exit", []() { return make_shared<Exit_State>(); });
}

//
Pause_State::Pause_State(shared_ptr<State> resume)
{
    background = resume;

    add("Resume", [resume]() { return resume; });
    add("Retry", []() {return make_shared<Game_State>(); });
    add("Main Menu", []() {return make_shared<Main_Menu_State>(); });
    add("Exit", []() { return make_shared<Exit_State>(); });
}

//
End_State::End_State(int player_health, int player_score) {
    status_text.setFont(font);
    status_text.setCharacterSize(70);
    status_text.setPosition(550, 60);

   if (player_health < 1) {
        status_text.setFillColor(sf::Color::Red);
        status_text.setString("Mission failed!");
        texture.loadFromFile("Images/Rating_stars.png", sf::IntRect(0, 0, 580, 180));
    } else {
        status_text.setFillColor(sf::Color::Green);
        status_text.setString("Mission passed!");
        if (player_score < 1000) {
            texture.loadFromFile("Images/Rating_stars.png", sf::IntRect(0, 0, 580, 180));
            rating.setTexture(texture);
        } else if (player_score < 1500) {
            texture.loadFromFile("Images/Rating_stars.png", sf::IntRect(0, 180, 580, 180));
            rating.setTexture(texture);
        } else if (player_score < 2000) {
            texture.loadFromFile("Images/Rating_stars.png", sf::IntRect(0, 360, 580, 180));
            rating.setTexture(texture);
        } else if (player_score < 2500) {
            texture.loadFromFile("Images/Rating_stars.png", sf::IntRect(0, 540, 580, 180));
            rating.setTexture(texture);
        }
    }
    rating.setPosition(540, 200);
    rating.setTexture(texture);

    add("Retry", []() {return make_shared<Game_State>(); });
    add("Main Menu", []() { return make_shared<Main_Menu_State>(); });
    add("Exit", []() { return make_shared<Exit_State>(); });
}

void End_State::render(sf::RenderWindow &window) {
    Menu_State::render(window);
    window.draw(status_text);
    window.draw(rating);
}

