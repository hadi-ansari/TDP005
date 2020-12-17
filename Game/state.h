#ifndef STATE_H
#define STATE_H

#include "common.h"
#include <SFML/Audio.hpp>

class State : public enable_shared_from_this<State> {
public:

	State() = default;

	virtual ~State() = default;

    //Kallas på när en tangent trycks ned
	virtual void on_key_press(sf::Keyboard::Key key);

    //Kallas på när en tangent släpps upp
	virtual void on_key_release(sf::Keyboard::Key key);

    //Uppdaterar alla spelobjekt
	virtual shared_ptr<State> tick(sf::Time time) = 0;

    //Ritar ut alla spelobjekt
	virtual void render(sf::RenderWindow &to) = 0;

	 //Kör ett läge (state) och hanterar byten mellan lägen
	static void run(sf::RenderWindow &window, shared_ptr<State> state);

};

//Detta läge indikerar att spelet ska stängas av
class Exit_State : public State {
public:
	shared_ptr<State> tick(sf::Time) override { return nullptr; }
	void render(sf::RenderWindow &) override {}
};
#endif