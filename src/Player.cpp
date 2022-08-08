#include "Player.hpp"

// Constructor-Destructor
Player::Player()
{
    this->initVariables();
    this->shape.setOrigin(shape.getSize() / 2.0f);
    this->shape.setTexture(&texture.playerTexture);
    this->initObjects();
    //this->shape.setFillColor(sf::Color::Green);
}

Player::~Player()
{
}

// Private functions
void Player::initVariables()
{
    // Position
    groundHeight = 600;
    roofHeight = 300;
    // Dimensions
    this->initAttributes(20, groundHeight, 50.f, 50.f);
    // Speed
    moveSpeed = 80.f;
    gravitySpeed = 0.98f;
    // Status
    isJumping = false;
    isOnPlatform = false;
    isMoving=false;
    

}

void Player::initObjects()
{  
    this->animation = new Animation(getWitdh(),getHeight(),4);
    shape.setTextureRect(this->animation->uvRect);
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
}

void Player::updateInput()
{
    float deltaTime = 0.07f;
    sf::Vector2f movement(0.0f, 0.0f);
    // Keyboard inputs
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        movement.y -= moveSpeed * deltaTime;
        isJumping = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement.x -= moveSpeed * deltaTime;
        faceRight=false;
        isMoving=true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += moveSpeed * deltaTime;
        faceRight=true;
        isMoving=true;
    }
    
    shape.move(movement);
    updateCords();
    
}

void Player::update(sf::Clock clock)
{
    //Animacion
    animation->update(isMoving,faceRight,clock);
    shape.setTextureRect(this->animation->uvRect);

    gravity();
    updateInput();
}
