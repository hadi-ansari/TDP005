//
// Created by hadan326 on 2020-12-11.
//
#ifndef LEVEL_H
#define LEVEL_H

#include <fstream>
#include <map>

#include "Enemy.h"
#include "Enemy.h"
#include "Powerup.h"

using namespace std;

class Level
{
public:
    Level(string const& file_name);
    ~Level() = default;

    //Laddar objekt från nivån
    vector <shared_ptr <Entity>> load_enemy(int index);

    //Den maximala mängden poäng som kan fås från nivån
    int max_score() const;

private:
    //Sparar textfilen som representerar varje level
    vector < map<int, string> > data{};
};

#endif
