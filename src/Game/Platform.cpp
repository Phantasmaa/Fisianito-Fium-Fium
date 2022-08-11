#include "Game/Platform.hpp"

Platform::Platform()
{
    this->initShape();
    //this->shape.setOrigin(sf::Vector2f(500.0f, 50.0f) / 2.0f);
    this->shape.setPosition(posX, posY);
}

Platform::~Platform()
{
}

void Platform::initVariables()
{
}

/*
void Platform::initShape()
{
    this->shape.setSize(size);
    this->shape.setOrigin(size / 2.0f);
    this->shape.setFillColor(sf::Color::White);
}
*/
void Platform::update()
{
    // Windows collision
}