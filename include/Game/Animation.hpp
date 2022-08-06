#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
private:
    sf::Vector2u imgCount;
    sf::Vector2u currentImg;
    float totalTime;
    float switchTime;

    void initVariables();

public:
    // Variables
    sf::IntRect uvRect;

    // Constructor-Destructor
    Animation(sf::Texture *texture, sf::Vector2u imgCount, float switchTime);
    ~Animation();

    // Functions
    void update(int row, float deltaTime, bool faceRight);
};