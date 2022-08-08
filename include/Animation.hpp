#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
private:
    void initVariables();

public:
    //Nested Class para hacer listas circulares con los frames
        class Frame{
            //Variables
            int leftX;
            class Frame *nextFrame;
        };

    // Variables
    int numSheet; //cuantas animaciones hay por spriteSheet
    sf::IntRect uvRect; //Rectangulo que contiene lo mostrado

    // Constructor-Destructor
    Animation(int rectWidth,int rectHeight, int numSheet);
    ~Animation();

    // Functions
    Frame *initFrames(int frames,int rectWidth);
    void update(float deltaTime, bool isMoving, bool faceRight);
};