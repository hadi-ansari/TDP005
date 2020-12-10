
#include "Texture_manager.h"
#include <stdexcept>

sf::Texture *Texture_Manager::get(const std::string &name, int width, int height) {
    auto found = instance.textures.find(name);
    if (found != instance.textures.end())
        return found->second.get();

    sf::Texture *t = new sf::Texture();
    if (!t->loadFromFile(name, sf::IntRect(0, 0, width, height)))
        throw std::logic_error("Failed to load texture!");

    instance.textures.insert(std::make_pair(name, std::unique_ptr<sf::Texture>(t)));
    return t;
}

Texture_Manager Texture_Manager::instance;