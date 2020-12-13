#ifndef STATE_H
#define STATE_H

#include "common.h"

/**
 * A state that represents a large-scale state of the application. For example,
 * if we're in a menu, if we're in the game, etc.
 */
class State : public enable_shared_from_this<State> {
public:
	/**
	 * Default creation.
	 */
	State() = default;

	/**
	 * Make sure the destructor is virtual.
	 */
	virtual ~State() = default;

	/**
	 * Called when a key is pressed.
	 */
	virtual void on_key_press(sf::Keyboard::Key key);

	/**
	 * Called when a key is released.
	 */
	virtual void on_key_release(sf::Keyboard::Key key);

	/**
	 * Called before each screen refresh. May switch states.
	 */
	virtual shared_ptr<State> tick(sf::Time time) = 0;

	/**
	 * Called to draw the screen.
	 */
	virtual void render(sf::RenderWindow &to) = 0;

	/**
	 * Run a state, handling state-switches, until completion.
	 */
	static void run(sf::RenderWindow &window, shared_ptr<State> state);

};

/**
 * Special state used to indicate that we should exit.
 */
class Exit_State : public State {
public:
	shared_ptr<State> tick(sf::Time) override { return nullptr; }
	void render(sf::RenderWindow &) override {}
};
#endif