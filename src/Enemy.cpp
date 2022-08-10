#include "Enemy.hpp"


// Constructor-Destructor
Enemy::Enemy()
{
    this->initVariables();
    this->shape.setOrigin(shape.getSize() / 2.0f);
    this->initObjects();
}

Enemy::~Enemy()
{
}

// Private functions
void Enemy::initVariables()
{
    // Position
    groundHeight = 600;
    roofHeight = 600;
    // Dimensions
    this->initAttributes(200, groundHeight, 50.f, 50.f);
    // Speed
    moveSpeed = 80.f;
    gravitySpeed = 0.98f;
    // Status
    isOnPlatform = false;
}

void Enemy::initObjects()
{
    this->animation = new Animation(&texture.playerTexture, sf::Vector2u(2, 5), 1.0f);
}

// Functions


void Enemy::gravity()
{
    if (getYCord() < groundHeight && !isJumping && !isOnPlatform)
    {
        moveEntity(0.f, gravitySpeed);
    }
    if (getYCord() > roofHeight)
    {
    }
}


void Enemy::update()
{
    shape.setFillColor(sf::Color::Green);
	float deltatime = 0.07f;
	sf::Vector2f movement(0.0f,0.0f);

    if(this->getPosition().x < 100 || this->getPosition().x > 500){
        moveSpeed *= -1;
    }

    movement.x += moveSpeed*deltatime;

    shape.move(movement);
    this->updateCords();
    gravity();
}
