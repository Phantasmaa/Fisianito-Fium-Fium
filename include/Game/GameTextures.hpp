#pragma once

#include <SFML/Graphics.hpp>

class GameTextures
{
public:
    GameTextures();
    sf::Texture playerTexture;
    sf::Texture platformTexture;
    sf::Texture trampTexture;
    sf::Texture bulletTexture;
    sf::Texture ghostTexture;
    sf::Texture bgTexture;
};
