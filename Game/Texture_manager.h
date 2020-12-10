
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <map>

class Texture_Manager {
public:

    static sf::Texture *get(const std::string &name, int width, int height);

private:

    Texture_Manager() = default;

    static Texture_Manager instance;

    std::map<std::string, std::unique_ptr<sf::Texture>> textures;
};
