
#include "Level.h"

using namespace std;

Level::Level(string const& file_name)
:data{}
{
    ifstream ifs{file_name};
    map<int, string> m;
    string name;
    int y;

    while (ifs >> y >> name) {

        if (name == "None") {
            data.push_back(m);
            m.clear();
        } else
            m[y] = name;

    }
}
vector <shared_ptr <Entity>> Level::load_enemy(int index)
{
    vector <shared_ptr <Entity>> temp{};
    int y;
    string name;

    if(index >= (int)data.size())
        return temp;
    for(auto const& i: data[index])
    {
        y = i.first;
        name = i.second;
        if(name == "BP")
            temp.push_back( make_shared<Big_Plane>(Big_Plane{sf::Vector2f(1600, y)}));
        else if(name == "SP")
            temp.push_back(make_shared<Small_Plane>(Small_Plane{sf::Vector2f(1600, y)}));
        else if(name == "BO")
            temp.push_back(make_shared<Bomb>(Bomb{sf::Vector2f(1600, y)}));
        else if(name == "HP")
            temp.push_back(make_shared<Powerup>(Powerup{"Heal", "Images/Health_sprite.png",sf::Vector2f(1600, y)}));
        else if(name == "SHP")
            temp.push_back(make_shared<Powerup>(Powerup{"Shield", "Images/Shield_sprite.png",sf::Vector2f(1600, y)}));
        else if(name == "TSP")
            temp.push_back(make_shared<Powerup>(Powerup{"Tripleshot", "Images/Tripleshot_sprite.png",sf::Vector2f(1600, y)}));
    }
    return temp;
}

int Level::max_score() const
{
    int sum{0};
    map<int, string> temp;

    for (auto const& i: data)
    {
        temp = i;
        for (auto const& p: temp)
        {
            if(p.second == "BP")
                sum += 100;
            else if(p.second == "SP")
                sum += 150;
            else if(p.second == "BO")
                sum += 50;
        }
    }
    return sum;
}