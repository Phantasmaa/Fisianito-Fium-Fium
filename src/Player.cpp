#include "Player.hpp"
#include <iostream>
// Constructor-Destructor
Player::Player()
{
    initVariables();
    initShape();
}

Player::~Player()
{
}

// Private functions
void Player::initVariables()
{
    // Position
    groundHeight = 300;
    roofHeight = 300;
    posX = 20;
    posY = groundHeight;
    // Dimensions
    width = 50.0;
    height = 50.0;
    // Speed
    moveSpeed = 10.f;
    gravitySpeed = 10.f;
    // Status
    isJumping = false;
    isOnPlatform = false;
}

// Functions
void Player::gravity()
{
    if (getYCord() < groundHeight && !isJumping && !isOnPlatform)
    {
        moveEntity(0.f, gravitySpeed);
    }
    if (getYCord() > roofHeight)
    {
    }
    updateCords();
}

void Player::updateInput()
{
    // Keyboard inputs
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        moveEntity(0.f, -moveSpeed);
        isJumping = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        moveEntity(-moveSpeed, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveEntity(moveSpeed, 0.f);
    }
    updateCords();
}
void Player::update(Entity platform)
{
    // Windows collision
    //checkIfIsOnPlatform(platform);
    gravity();
    updateInput();
}

void Player::checkIfIsOnPlatform(Entity platform)
{
    /*
    Si la coordenada Y de player es platform.y - 50
    y la coordenada X de player está entre platform.X y platform.X + platform.width 
    entonces player está sobre platform
    */
    
    int minusLimitOnX = platform.getXCord() - width;
    int superiorLimitOnX = platform.getXCord() + platform.getWitdh();
    int limitOnY = platform.getYCord() - this->height;
    if (posX > minusLimitOnX && posX < superiorLimitOnX && posY == limitOnY){
        std::cout<<"Is on platform"<<std::endl;
        isOnPlatform = true;
    } else {
            isOnPlatform = false;
    }
    
}
