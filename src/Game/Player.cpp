#include "Game/Player.hpp"
#include <iostream>

// Constructor-Destructor
Player::Player()
{
    this->initVariables();
    this->shape.setOrigin(shape.getSize() / 2.0f);
    this->initObjects();
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
    gravitySpeed = 2.0f;
    jumpSpeed = 10.0f;
    accelerationY = 0.0f;
    jumpStatus = Neutral;
    // Status
    isJumping = false;
    isOnPlatform = false;
}

void Player::initObjects()
{
    this->animation = new Animation(&texture.playerTexture, sf::Vector2u(2, 5), 1.0f);
}

// Functions

void Player::gravity()
{
    if ((isOnFloor() || isOnPlatform) && !isJumping)
    {
        accelerationY = 0.0;
    } else {
        accelerationY += gravitySpeed;
    }
     
    moveEntity(0.0f, accelerationY);
}

void Player::updateInput()
{
    float deltaTime = 0.07f;
    sf::Vector2f movement(0.0f, 0.0f);
    // Keyboard inputs

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement.x -= moveSpeed * deltaTime;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += moveSpeed * deltaTime;
    }

    if (movement.x == 0.0f)
    {
        row = 0;
    }
    else
    {
        row = 1;
        if (movement.x > 0.0f)
        {
            faceRight = true;
        }
        else
        {
            faceRight = false;
        }
    }
    animation->update(row, deltaTime, faceRight);
    shape.setTextureRect(this->animation->uvRect);
    shape.move(movement);
    updateCords();
}

void Player::update()
{
    gravity();
    updateInput();
}

void Player::handleJump()
{
    if(isOnFloor() || isOnPlatform){
        jumpStatus == Neutral;
    }
    switch (jumpStatus)
    {
    case JumpStatus::Neutral:
    {
        std::cout << "Neutral" << std::endl;
        jumpStatus = FirstJump;
        isJumping = true;
        accelerationY -= jumpSpeed;
        break;
    }
    case JumpStatus::FirstJump:
    {
        std::cout << "First Jump" << std::endl;
        jumpStatus = SecondJump;
        accelerationY -= jumpSpeed;
        isJumping = true;
        break;
    }
    case JumpStatus::SecondJump:
    {
        if (isOnFloor() || isOnPlatform)
        {
            accelerationY -= jumpSpeed;
            jumpStatus = Neutral;
            isJumping = true;
        } else {
            isJumping = false;
        }
        std::cout << "Second Jump" << std::endl;
        
        break;
    }

    default:
        break;
    }
    updateCords();
}

void Player::checkCollisionWithPlatforms(EntityNode *platforms)
{
    EntityNode *head = platforms;
    while (head)
    {
        if (playerIsOnPlatform(head->value))
        {
            isOnPlatform = true;
            return;
        }
        head = head->next_node;
    }
    isOnPlatform = false;
}

inline bool epsilonEquals(const float x, const float y, const float epsilon = 1E-5f)
{
    return abs(x - y) <= epsilon;
}

bool Player::isOnFloor()
{
    return getYCord() == groundHeight;
}
bool Player::playerIsOnPlatform(Entity platform)
{
    /*
    Si la coordenada Y de player es platform.y - 50
    y la coordenada X de player está entre platform.X y platform.X + platform.width
    entonces player está sobre platform
    */
    int minusLimitOnX = platform.getXCord() - width;
    int superiorLimitOnX = platform.getXCord() + platform.getWitdh();
    int limitOnY = platform.getYCord() - this->height;

    if (posX > minusLimitOnX && posX < superiorLimitOnX && epsilonEquals(posY, limitOnY))
        return true;
    return false;
}