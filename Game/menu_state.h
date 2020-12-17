
#include <functional>

#include "common.h"
#include "state.h"
#include "game_state.h"
#include "Level.h"

 /* State responsible for showing either the start menu or the pause menu. */

class Menu_State : public State {
public:

    Menu_State();


    void on_key_press(sf::Keyboard::Key key) override;


    shared_ptr<State> tick(sf::Time time) override;


    void render(sf::RenderWindow &window) override;

protected:

     //Vad ska göras när ett föremål är valt?
    using Action = function<shared_ptr<State>()>;

    struct Entry {
        sf::Text text;

        //Bestämmer hur ifylld färgen på ett föremål är (0-1)
        float state;

        //Vad som ska göras när ett föremål valts
        Action action;
    };


    sf::Font font;


    vector<Entry> entries;


    size_t selected;


    bool enter_pressed;

    //Animationsfördröjning
    sf::Time delay;

    //Vilket läge (om något) som ska visas som bakgrund
    shared_ptr<State> background;

    //Lägger till ett element i menyn
    void add(const string &text, Action action);
};

//Huvudmenyn
class Main_Menu_State: public Menu_State
{
public:
    Main_Menu_State();
};

//Hjälpsidan
class Help_State: public Menu_State
{
public:
    Help_State();
    void render(sf::RenderWindow &window) override;

private:
    sf::Sprite keyboard_guide;
    sf::Texture texture;
};

//Nivåsidan
class Level_Selection_State: public Menu_State
{
public:
    Level_Selection_State();
};

//Pausmenyn
class Pause_State : public Menu_State
{
public:
    Pause_State(shared_ptr<State> resume, string current_level);

};

//Menyn som visas om man har vunnit eller förlorat
class End_State : public Menu_State
{
public:
    End_State(int player_health, int player_score, string const& level_name, int max_score);

    void render(sf::RenderWindow &window) override;

private:

    sf::Text status_text;
    sf::Texture texture;
    sf::Sprite rating;
    sf::Text score_info;
};