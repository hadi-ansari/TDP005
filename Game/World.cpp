
#include "World.h"

World::World()
  : objects{}, player{make_shared<Player>(Player{sf::Vector2f(0 , 450)})}
  , counter{0}, score{0}, level()
{
    game_clock.restart();
    objects.push_back(player);
    //font.loadFromFile("Lato-HeavyItalic.ttf");
    font.loadFromFile("RussoOne-Regular.ttf");
    life_info.setFont(font);
    life_info.setPosition(1450, 0);
    life_info.setOutlineColor(sf::Color::Black);
    life_info.setOutlineThickness(1);
    shield_info.setFont(font);
    shield_info.setPosition(750, 0);
    shield_info.setOutlineColor(sf::Color::Black);
    shield_info.setOutlineThickness(1);
    score_info.setFont(font);
    score_info.setOutlineColor(sf::Color::Black);
    score_info.setOutlineThickness(1);
    score_info.setPosition(50,0);
}
void World::insert_object(std::shared_ptr<Entity> const& object)
{
  objects.push_back(object);
}

void World::manage_collision()
{
    for(auto object: objects)
    {
        std::vector <shared_ptr<Entity>> new_vector(objects.size());
        std::copy(objects.begin(), objects.end(), new_vector.begin());
        new_vector.erase(std::remove_if(new_vector.begin(), new_vector.end(),
                                        [&object](shared_ptr<Entity> & x)
                                        {
                                            return x == object;
                                        }
        ), new_vector.end());
        object -> collision(new_vector, *this);
    }
}

bool World::tick(sf::Time delta)
{
    manage_collision();


    if (game_clock.getElapsedTime().asSeconds() > 3)
    {
        game_clock.restart();
        for( auto const& i: level.load_enemy(counter))
        {
            insert_object(i);
        }
        counter ++;
    }
    for (size_t i = 0; i < objects.size(); i++) {
        if (!objects[i]->tick(delta, *this)) {
            objects.erase(objects.begin() + i);
            i--;
        }
    }


    if(player->get_health() < 1)
        return false;
    return true;
}
void World::render(sf::RenderWindow &window)
{
    for(auto const& object: objects)
    {
        object -> render(window);
    }
    // liv
    life_info.setString("Life: " + std::to_string(player -> get_health()));
    window.draw(life_info);
    // shield
    if(player -> has_shield())
    {
        shield_info.setString( player -> get_shield_time());
        window.draw(shield_info);
    }
    score_info.setString("Score : " + std::to_string(score));
    window.draw(score_info);

}

void World::add_score(int num) {
    score += num;
}