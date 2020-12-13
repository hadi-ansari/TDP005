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

    vector <shared_ptr <Entity>> load_enemy(int index);

private:
    vector <map<pair <int, int>, string> > data{};
};

#endif
