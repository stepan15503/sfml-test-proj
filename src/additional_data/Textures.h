#pragma once

#include <SFML/Graphics.hpp>

namespace textures {
    sf::Texture player_texture;

    static void setTextures() {
        player_texture.loadFromFile("assets/placeholder.png");
    }
}