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

void Platform::movePlatform(){
    float deltatime = 0.07f;
    float moveSpeed = 30.0f;
    sf::Vector2f movement(0.0f, 0.0f);

    if (this->shape.getPosition().x < 250 || this->shape.getPosition().x + this->shape.getGlobalBounds().width > 850)
    {
        moveSpeed *= -1;
    }

    movement.x += moveSpeed * deltatime;
    this->moveEntity(movement.x,movement.y);
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
    movePlatform();
    // Windows collision
}