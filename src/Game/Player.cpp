#include "Game/Player.hpp"
#include <iostream>
#include <math.h>

// Constructor-Destructor
Player::Player()
{
    this->initVariables();
    // this->shape.setOrigin(shape.getSize() / 2.0f);
    this->initPlayer();
    this->initObjects();
}

Player::~Player()
{
}

// Private functions
void Player::initVariables()
{
    // Position
    groundHeight = 620;
    roofHeight = 300;
    // Dimensions
    this->initAttributes(20, groundHeight, 50.f, 50.f);
    // Speed
    moveSpeed = 80.f;
    gravitySpeed = 1.0f;
    jumpSpeed = 20.0f;
    accelerationY = 0.0f;
    jumpStatus = Neutral;
    // Status
    isJumping = false;
    isOnPlatform = false;
}

void Player::initPlayer()
{
    this->initAttributes(20, groundHeight, 50.f, 50.f);
    this->shape.setOrigin(shape.getSize() / 2.0f);
    this->shape.setFillColor(sf::Color::Green);
}

void Player::initObjects()
{
    this->animation = new Animation(&texture.playerTexture, sf::Vector2u(2, 5), 1.0f);
}

// Functions

void Player::gravity()
{
    if (isOnFloor() || isOnPlatform && !isJumping)
    {
        accelerationY = 0.0;
        movementDirection = Directions::Static;
    }
    else
    {
        if (accelerationY + posY < groundHeight)
            accelerationY += gravitySpeed;
        else
            accelerationY = 0.0;
    }
}

void Player::updateInput()
{
    float deltaTime = 0.07f;
    sf::Vector2f movement(0.0f, 0.0f);
    float velocityY = 0.0f;
    // Keyboard inputs

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && movementDirection != Directions::Down)
    {
        // salta carajito
        velocityY -= jumpSpeed;
        movementDirection = Directions::Up;
        isJumping = true;
    }

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
    velocityY = fabs(velocityY);

    if (movementDirection == Directions::Up)
    {
        velocityY *= -1.0f;
        std::cout << "Arribaaa" << std::endl;
    }
    else if (movementDirection == Directions::Down)
    {

        std::cout << "Abajooo" << std::endl;
    }
    velocityY += accelerationY;

    std::cout << "Velocity: " << velocityY << std::endl;
    movement.y = velocityY;
    shape.move(movement);
    updateCords();
}

void Player::handleKeyPressed()
{
}
void Player::update(EntityNode *platforms)
{
    updateInput();
    checkCollisionWithPlatforms(platforms);
    gravity();
    windowsCollision();
}
// Collision Player
void Player::windowsCollision()
{
    // Left collision
    if (shape.getPosition().x < 0.0f)
        shape.setPosition(0.0f, shape.getPosition().y);
    // Top collision
    if (shape.getPosition().y < 0.0f)
        shape.setPosition(shape.getPosition().x, 0.0f);
    // RIght collision
    if (shape.getPosition().x + shape.getGlobalBounds().width > 1280.0f)
        shape.setPosition(1280.0f - shape.getGlobalBounds().width, shape.getPosition().y);
}

void Player::checkCollisionWithPlatforms(EntityNode *platforms)
{
    EntityNode *head = platforms;

    while (head->next_node)
    {

        Entity platform = head->value;
        switch (this->checkCollision(platform))
        {
        case CollisionDirection::Top:
        {
            std::cout << "Collision with top\n";
            isOnPlatform = true;
            isJumping = false;
            movementDirection = Directions::Static;
            return;
        }
        /* code */
        case CollisionDirection::Bottom:
        {

            std::cout << "Collision with bottom\n";
            accelerationY *= 3.0f;
            isJumping = false;
            movementDirection = Directions::Down;
            return;
        }
        case CollisionDirection::Null:
            isOnPlatform = false;
        default:
            break;
        }

        head = head->next_node;
    }
}

void Player::checkCollisionWithObjects(EntityNode *objects)
{
    EntityNode *head = objects;
    while (head)
    {
        if (shape.getGlobalBounds().intersects(head->value.getShape().getGlobalBounds()))
        {
            shape.setFillColor(sf::Color::Red);
            std::cout << "muere" << std::endl;
            return;
        }
        shape.setFillColor(sf::Color::Green);
        head = head->next_node;
    }
}
inline bool epsilonEquals(const float x, const float y, const float epsilon = 1E-5f)
{

    return fabs(x - y) <= epsilon;
}

bool Player::isOnFloor()
{
    return getYCord() == groundHeight;
}
