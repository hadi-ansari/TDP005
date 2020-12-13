
#include "Level.h"

using namespace std;

Level::Level(string const& file_name)
:data{}
{
    ifstream ifs{file_name};
    map<pair<int, int>, string> m;
    pair<int, int> p{};

    string name;
    int x;
    int y;

    while (ifs >> x >> y >> name) {
        p = make_pair<int, int>((int) x, (int) y);
        if (name == "None") {
            data.push_back(m);
            m.clear();
        } else
            m[p] = name;

    }
}
vector <shared_ptr <Entity>> Level::load_enemy(int index)
{
    vector <shared_ptr <Entity>> temp{};
    int x;
    int y;
    string name;
    if(index >= (int)data.size())
        return temp;
    for(auto const& i: data[index])
    {
        x = i.first.first;
        y = i.first.second;
        name = i.second;
        if(name == "Big_Plane")
            temp.push_back( make_shared<Big_Plane>(Big_Plane{sf::Vector2f(x, y)}));
        else if(name == "Small_Plane")
            temp.push_back(make_shared<Small_Plane>(Small_Plane{sf::Vector2f(x, y)}));
        else if(name == "Bomb")
            temp.push_back(make_shared<Bomb>(Bomb{sf::Vector2f(x, y)}));
        else if(name == "Heal")
            temp.push_back(make_shared<Powerup>(Powerup{name, "Images/Health_sprite.png",sf::Vector2f(x, y)}));
        else if(name == "Shield")
            temp.push_back(make_shared<Powerup>(Powerup{name, "Images/Shield_sprite.png",sf::Vector2f(x, y)}));
        else if(name == "Tripleshot")
            temp.push_back(make_shared<Powerup>(Powerup{name, "Images/Tripleshot_sprite.png",sf::Vector2f(x, y)}));
    }
    return temp;
}