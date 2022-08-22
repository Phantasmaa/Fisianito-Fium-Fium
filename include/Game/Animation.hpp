#pragma once

#include <SFML/Graphics.hpp>
#include "Frame.hpp"

class Animation
{
private:
    void initVariables();

public:
    // Variables
    int numSheet;     // cuantas animaciones hay por spriteSheet
    float switchTime; // second per frame de la animacion
    float totalTime;

    sf::IntRect uvRect; // Rectangulo que contiene lo mostrado

    // Constructor-Destructor
    Animation(int rectWidth, int rectHeight, int numSheet, float switchTime);
    ~Animation();

    void update(int animationRow, Frame *&frameCycle, float deltaTime);
};