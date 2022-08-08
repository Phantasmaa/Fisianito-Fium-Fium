#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
private:
    void initVariables();

public:
    // Variables
    int numSheet; //cuantas animaciones hay por spriteSheet
    sf::IntRect uvRect; //Rectangulo que contiene lo mostrado

    // Constructor-Destructor
    Animation(int rectWidth,int rectHeight, int numSheet);
    ~Animation();

    void update(bool isMoving, bool faceRight,sf::Clock clock);
};

class Frame
{
    public:
    //Variables
    int leftX;//coordenada x del Spreadsheet (Frame a utilizar)
    class Frame *nextFrame; //punteor al siguiente
};