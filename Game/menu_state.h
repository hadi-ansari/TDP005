
#include <functional>

#include "common.h"
#include "state.h"
#include "game_state.h"
#include "Level.h"

 /* State responsible for showing either the start menu or the pause menu. */

class Menu_State : public State {
public:

    /* Create the state. If 'resume' is set, the menu will show a "resume"
     * option to return to that state.*/
    Menu_State();

     /* Handle key presses. */
    void on_key_press(sf::Keyboard::Key key) override;

    /* Tick. */
    shared_ptr<State> tick(sf::Time time) override;

     /* Render. */
    void render(sf::RenderWindow &window) override;

protected:

     /* What to do when an item is selected. */
    using Action = function<shared_ptr<State>()>;

    /* Menu item. */
    struct Entry {
        /* Text to draw. */
        sf::Text text;

        /* Determine the color (i.e. how selected it is). 0-1. */
        float state;

        /* Action to perform when selected. */
        Action action;
    };

    /* Font to use. */
    sf::Font font;

    /* All menu entries. */
    vector<Entry> entries;

    /* Which one is currently selected? */
    size_t selected;

    /* Was the enter key pressed? */
    bool enter_pressed;

    /* Animation delay. */
    sf::Time delay;

    /* State to use as a background (if any). */
    shared_ptr<State> background;

    /* Helper to add an element. */
    void add(const string &text, Action action);
};

class Main_Menu_State: public Menu_State
{
public:
    Main_Menu_State();
};
class Help_State: public Menu_State
{
public:
    Help_State();
    void render(sf::RenderWindow &window) override;

private:
    sf::Sprite keyboard_guide;
    sf::Texture texture;
};
class Level_Selection_State: public Menu_State
{
public:
    Level_Selection_State();
};

class Pause_State : public Menu_State
{
public:
    Pause_State(shared_ptr<State> resume, string current_level);

};
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