
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <map>

class Texture_Manager {
public:
    //Laddar en texture, antingen från fil eller minnet
    static sf::Texture *get(const std::string &name, int width, int height);

private:

    Texture_Manager() = default;

    static Texture_Manager instance; //Den enda instansen av klassen


    std::map<std::string, std::unique_ptr<sf::Texture>> textures; //Sparar alla laddede texturer
};
